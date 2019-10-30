/*
 * Production.h
 *
 *  Created on: Sep 27, 2019
 *      Author: jasondykstra
 */

#ifndef PRODUCTION_H_
#define PRODUCTION_H_

#include "Board.h"
#include <stdio.h>
#include <string.h>
#include <stdbool.h>
#include <iostream>
#include <fstream>
#include <cstring>
#include <random>
#include <stdlib.h>
#include <time.h>

namespace std {

class Production {
public:
	Production();
	virtual ~Production();
	bool production(int argc, char* argv[]);
};

} /* namespace std */

#endif /* PRODUCTION_H_ */
