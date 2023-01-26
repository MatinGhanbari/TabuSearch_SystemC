#include "systemc.h"
//#include "TabuSearch.h"

SC_MODULE(TabuSearch) {
    sc_in<sc_uint<8>> n; // The number of search rounds

    void printResult() {
        cout << "Counter: " << n << endl;
    }

	SC_CTOR(TabuSearch) {
        SC_METHOD(printResult);
        sensitive << n;
	}
};

int sc_main(int argc, char* argv[]) {
    sc_signal<sc_uint<8>> a=1;

    TabuSearch ts();
    ts << a;

    sc_start();
    return(0);
}