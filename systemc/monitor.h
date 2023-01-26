#include "systemc.h"
#include <iostream>

SC_MODULE(monitor){

    sc_in<sc_uint<9>> cNode;

    void print();

    SC_CTOR(monitor){
        SC_METHOD(print);
        sensitive << cNode;
    }
};