#pragma once
#include "SystemC.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>

SC_MODULE(neighbor) {
	sc_in<sc_uint<9>> object_in;
	sc_in<sc_vector<sc_uint<9>>> tabu_in;
	//sc_out<sc_vector<sc_uint<9>>> tabu_out;
	sc_vector<sc_out<sc_uint<9>>> result; // objects that have to pass to software

	void neighbor_func() {
		//tabu_out = tabu_in;
		sc_uint<9> object;
		object = object_in;
		sc_uint<9> prev_object;
		sc_uint<9> weight_result = 0;
		sc_vector<sc_uint<9>> weight;
		sc_uint<4> index = 0;
		weight[0] = 2, weight[1] = 3, weight[2] = 6, weight[3] = 7, weight[4] = 5, weight[5] = 9, weight[6] = 3, weight[7] = 4, weight[8] = 5;
		object = prev_object;
		index = 0;
		for (int i = 0;i < 9;i++)	 {
			object = prev_object;
			if (object[i] == 0) {
				object[i] = 1;
			}
			else {
				object[i] = 0;
			}
			weight_result = 0;
			for (int j = 0; j < 9; j++) {
				weight_result = weight_result + weight[j] * object[j];
			}
			if (weight_result <= 20) {
				cout << object; // result when neighbor nodes are ready!
				result[index++] = object;
			}
			
		}

	}

	SC_CTOR(neighbor) {
		SC_METHOD(neighbor_func);
		sensitive << object_in;
	}
};