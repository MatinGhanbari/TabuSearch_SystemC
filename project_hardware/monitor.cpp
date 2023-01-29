#include "monitor.h"

void monitor::prc_print() {
    cout << sc_time_stamp() << " ready: " << ready << endl;
}