#include "systemc.h"
#include <iostream>

SC_MODULE(monitor){
    sc_in<sc_uint<9>> cNode;

    void prc_print();

    SC_CTOR(monitor){
        SC_METHOD(prc_print);
        sensitive << cNode;
    }
};