#include "tabu_search.h"

void tabu_search::prc_search() {
    if (ready.read() != 1)
        return;

    prc_findNeighbors();

    double best_benefit = cbenefit;
    sc_uint<9> best_neighbor; best_neighbor = 0;
    for (const int& i : neighbors) {
        sc_uint<9> node;
        node = i;

        double benefit = 0.00;
        for (int j = 0; j < 9; j++)
            benefit += (node[j]) * (prices[j] / weights[j]);

        if (benefit >= best_benefit) {
            best_neighbor = node;
            best_benefit = benefit;
        }

    }
    if (best_benefit > cbenefit) {
        cNode = best_neighbor;
        cbenefit = best_benefit;
        tabuList.push_back(cNode);
        tabuListOutTime.push_back(5);
    }

    cout << sc_time_stamp() << endl;
    cout << "# Search " << counter << ", cNode: " << cNode << endl;

    counter++;
}

void tabu_search::prc_findNeighbors() {
    std::vector<int> tneighbors;
    bool tabu;
    prc_aspirationCriterion();
    for (int i = 0; i < 9; i++) {
        tempNode = cNode;
        tabu = false;
        tempNode[i] = (cNode[i] == 0);

        for (const int& i : tabuList)
            if (tempNode == i) {
                tabu = true;
                break;
            }

        int tweight = 0;
        for (int j = 0; j < 9; j++)
            tweight += (weights[j] * tempNode[j]);

        if (tweight <= W)
            if (tabu == false)
                tneighbors.push_back(tempNode);
    }
    neighbors = tneighbors;
}

void tabu_search::prc_findStartNode() {
    cNode = 0b000000011;

    tabuList.push_back(cNode);
    tabuListOutTime.push_back(5);

    cbenefit = 0;
    for (int i = 0; i < 9; i++)
        cbenefit += cNode[i] * (prices[i] / weights[i]);
}

void tabu_search::prc_aspirationCriterion() {
    std::vector<int> newtabuList;
    std::vector<int> newtabuListTimes;
    double bnf;
    sc_uint<9> node;

    for (int i = 0; i < tabuList.size(); i++) {

        node = tabuList[i];
        bnf = 0;

        for (int j = 0; j < 9; j++)
            bnf += node[j] * (prices[j] / weights[j]);

        int remain = tabuListOutTime[i] - 1;
        if (bnf <= cbenefit || remain > 2) {
            if (remain > 0) {
                newtabuList.push_back(node);
                newtabuListTimes.push_back(remain);
            }
            else {
                cout << "node " << node << " remved from tabu list." << endl;
            }
        }
        else {
            cout << "node " << node << " remved from tabu list." << endl;
        }
    }

    tabuList = newtabuList;
    tabuListOutTime = newtabuListTimes;

    cout << "\n====================" << endl;
    cout << "# Tabu List:" << endl;
    for (int i = 0; i < tabuList.size(); i++) {
        cout << "  - node " << tabuList[i] << ", time: " << tabuListOutTime[i] << endl;
    }

}