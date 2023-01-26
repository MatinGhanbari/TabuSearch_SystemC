#include "systemc.h"
#include <iostream>

SC_MODULE(tabu_search){

    void print();

    SC_CTOR(tabu_search){
        SC_METHOD(print);
    }
};