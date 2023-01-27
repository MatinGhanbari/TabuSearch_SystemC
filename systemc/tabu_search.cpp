#include "tabu_search.h"

void tabu_search::prc_search(){
    

}

void tabu_search::prc_findNeighbors(){
    cout << "prc_findNeighbors" << endl;
    std::vector<int> tneighbors;

    for (int i=0; i<9; i++){
        tempNode = cNode;
        tempNode[i] = (cNode[i]==0);

        int tweight = 0;
        for (int j = 0; j < 9; j++)
            tweight = tweight + (weights[j]*tempNode[j]);
        
        if (tweight <= W)
            tneighbors.push_back(tempNode);
    }

    for (const int& i : tneighbors)
        cout << i << ", ";
    cout << endl;

    neighbors = tneighbors;
}

void tabu_search::prc_findStartNode(){
    // tabu search : find neighbors
}