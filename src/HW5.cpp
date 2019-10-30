//============================================================================
// Name        : HW5.cpp
// Author      : Jason Dykstra
// Version     :
// Copyright   : Your copyright notice
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
using namespace std;

#include "Production.h"
#include "Tests.h"

int main(int argc, char* argv[]) {
	srand(time(NULL));
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	Tests test;
	Production prod;

	if(test.tests()){
		cout << "All tests passed!" << endl;
		prod.production(argc, argv);
	} else {
		cout << "tests did not pass." << endl;
	}

	return 0;
}
