#include "systemc.h"
#include <iostream>

SC_MODULE(tabu_search){

    sc_in<sc_uint<8>> n;
    sc_in<sc_uint<9>> startNode;

    void search();
    void findNeighbors();

    SC_CTOR(tabu_search){
        SC_METHOD(search);
        SC_METHOD(findNeighbors);
    }
};