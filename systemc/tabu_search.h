#include "systemc.h"
#include <iostream>

SC_MODULE(tabu_search){

    sc_in<sc_uint<8>> n;
    sc_in<sc_uint<8>> W;
    sc_in<sc_uint<9>> startNode;

    sc_signal<sc_uint<9>> cNode;
    sc_signal<sc_uint<9>> lNode;
    sc_signal<sc_uint<9>> tempNode;

    sc_uint<4> index = 0;
    sc_uint<4> weight = 0;
    sc_uint<4> counter = 0; // searches counter

    void search();
    void findNeighbors();

    SC_CTOR(tabu_search){
        SC_METHOD(search);
        SC_METHOD(findNeighbors);
    }
};