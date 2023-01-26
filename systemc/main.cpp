#include "systemc.h"
#include <iostream>

#include "tabu_search.cpp"
#include "monitor.cpp"

int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<8>> n;
    sc_signal<sc_uint<9>> startNode;

    n = 30;
    startNode = 0b000000000;
    
    tabu_search ts("ts1");
    ts.n(n);
    ts.startNode(startNode);

    monitor monitor("monitor1");
    monitor.cNode(startNode);
    
    sc_start();
    return(0);
}