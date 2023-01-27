#include "systemc.h"
#include <iostream>

#include "tabu_search.cpp"
#include "monitor.cpp"
#include "driver.cpp"


int sc_main(int argc, char* argv[]) {
    sc_signal<int> n, W;
    sc_signal<bool> ready;

    tabu_search ts("ts1");
    ts.n(n);
    ts.W(W);
    ts.ready(ready);

    driver d1("Driver");
    d1.n(n);
    d1.W(W);
    d1.ready(ready);
    
    monitor m1("monitor1");
    m1.ready(ready);
    
    sc_start(300, SC_NS);
    return(0);
}