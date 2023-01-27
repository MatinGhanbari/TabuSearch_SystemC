#include "systemc.h"
#include <iostream>

SC_MODULE(monitor){
    sc_in<bool> ready;

    void prc_print();

    SC_CTOR(monitor){
        SC_METHOD(prc_print);
        sensitive << ready;
    }
};