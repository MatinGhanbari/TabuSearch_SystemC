#pragma once
#include "SystemC.h"
#include <stdio.h>
#include <iostream>
#include <iomanip>
#include "neighbor.h"

SC_MODULE(tabu_serach) {
	//sc_vector<sc_uint<9>> tabu;
	sc_in<sc_uint<9>> number;
	sc_in<sc_uint<9>> object_in;
	sc_in<sc_vector<sc_uint<9>>> tabu_in;
	sc_in<sc_vector<sc_uint<9>>> tabu_tenur;
	sc_out<sc_uint<9>> result;
	sc_vector<sc_signal<sc_uint<9>>> tabu_out;
	sc_vector<sc_out<sc_uint<9>>> temp_result;



	neighbor* temp_neighbor;

	void func() {
		
		

	}

	SC_CTOR(tabu_serach) {
		SC_METHOD(func);
		temp_neighbor = new neighbor("temp_neighbor");
		temp_neighbor->object_in  (object_in);
		temp_neighbor->tabu_in (tabu_in);
		//temp_neighbor->tabu_out (tabu_in);
		temp_neighbor->object_in(object_in);
		sensitive << number;
	}
};
