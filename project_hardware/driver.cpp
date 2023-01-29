#include "driver.h"

void driver::prc_driver() {
    n = 30, W = 20;

    for (int i = 0; i < 30; i++) {
        ready = true;
        wait(1, SC_NS);

        ready = false;
        wait(9, SC_NS);
    }
}