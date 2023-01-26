#include "systemc.h"
#include <iostream>

SC_MODULE(tabu_search){

    sc_in<sc_uint<8>> n;
    sc_in<sc_uint<9>> startNode;

    void print();

    SC_CTOR(tabu_search){
        SC_METHOD(print);
        sensitive << n;
    }
};