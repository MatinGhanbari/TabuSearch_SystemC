#include "tabu_search.h"

void tabu_search::prc_search(){
    if (ready.read() != 1)
        return;

    cout << "prc_search" << endl;
    prc_findNeighbors();
    
    double best_benefit = -1;
    sc_uint<9> best_neighbor; best_neighbor = 0;
    for (const int& i : neighbors){
        sc_uint<9> node;
        node = i;
        double benefit=0.00;
        for (int j=0; j<9; j++)
            benefit +=  (node[j])*(prices[j]/weights[j]);
        if (benefit >= best_benefit && benefit >= cbenefit)
            best_neighbor = node, best_benefit = benefit;
        
    }
    cout<<"best_neighbor: "<<best_neighbor<<endl;
    cout<<"best_benefit: "<<best_benefit<<endl;

    cNode = best_neighbor;
    cbenefit = best_benefit;
}

void tabu_search::prc_findNeighbors(){
    cout << "prc_findNeighbors" << endl;
    std::vector<int> tneighbors;

    for (int i=0; i<9; i++){
        tempNode = cNode;
        tempNode[i] = (cNode[i]==0);

        int tweight = 0;
        for (int j = 0; j < 9; j++)
            tweight += (weights[j]*tempNode[j]);
        
        if (tweight <= W)
            tneighbors.push_back(tempNode);
    }

    for (const int& i : tneighbors)
        cout << i << ", ";
    cout << endl;

    neighbors = tneighbors;
}

void tabu_search::prc_findStartNode(){
    cout << "prc_findStartNode" << endl;
    cNode = 0b000000111;

    cbenefit = 0;

    bool high; high = 1;
    ready.write(high);
}