#pragma once
#include "systemc.h"
#include <iostream>

SC_MODULE(driver) {
    sc_out<int> n, W;
    sc_out<bool> ready;

    void prc_driver();

    SC_CTOR(driver) {
        SC_THREAD(prc_driver);
    }
};
