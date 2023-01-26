#include "systemc.h"
#include "tabu_search.cpp"
#include <iostream>

int sc_main(int argc, char* argv[]) {
    tabu_search ts("ts");
    
    sc_start();
    return(0);
}