#pragma once
#include "systemc.h"
#include <iostream>

SC_MODULE(tabu_search) {
    sc_in<int> n;
    sc_in<int> W;
    sc_in<bool> ready;

    sc_uint<9> cNode;
    sc_uint<9> lNode;
    sc_uint<9> tempNode;

    double cbenefit = -1;
    int counter = 0;

    std::vector<int> prices = { 6,5,8,5,4,7,3,6,8 };
    std::vector<int> weights = { 2,3,6,7,5,9,3,4,5 };
    std::vector<int> neighbors;
    std::vector<int> tabuList;
    std::vector<int> tabuListOutTime;

    void prc_search();
    void prc_findNeighbors();
    int prc_findStartNode();
    void prc_aspirationCriterion();

    SC_CTOR(tabu_search) {
        SC_METHOD(prc_findStartNode);
        SC_METHOD(prc_aspirationCriterion);
        SC_METHOD(prc_findNeighbors);

        SC_METHOD(prc_search);
        sensitive << ready;
    }

};