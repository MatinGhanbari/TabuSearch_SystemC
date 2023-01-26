#include "systemc.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>

SC_MODULE(TabuSearch) {
    sc_in<sc_uint<8>> n; // The number of search rounds
    sc_in<sc_uint<9>> startNode;
    sc_in<sc_uint<8>> W; // knapsack capacity
    sc_in<sc_vector<sc_uint<9>>> itemsWeight;
    sc_in<sc_vector<sc_uint<9>>> itemsPrice;
    
    sc_vector<sc_uint<9>> currentNode = 0;
    sc_vector<sc_uint<9>> lastNode = 0;
    sc_vector<sc_uint<9>> tempNode = 0;

    sc_uint<4> index = 0;
    sc_uint<4> weight = 0;

    sc_uint<4> counter = 0; // searches counter

	void search() {
        if (counter>=n)
            printResult(), return;
        index = 0;
        for (int i = 0; i < 9; i++) {
			object[i] = (object[i] == 0);

			weight = 0;
			for (int j = 0; j < 9; j++)
				weight = weight + (weight[j] * object[j]);
                
			if (weight <= 20)
				cout << tempNode, result[index++] = tempNode;
		}
        counter++;
	}

    void printResult() {
        cout << "Current Node: " << currentNode << endl;
        cout << "Counter: " << counter << endl;
    }

	SC_CTOR(TabuSerach) {
        SC_METHOD(printResult);
        sensitive << currentNode;
		SC_METHOD(search);
		sensitive << n; // It should be sensitive to the end of the previous search result
	}
};
