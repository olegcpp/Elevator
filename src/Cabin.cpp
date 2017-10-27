/*
 * RealCabin.cpp
 *
 *  Created on: Sep 29, 2017
 *      Author: oleg
 */

#include "Cabin.h"

namespace Elevator {

Cabin::Cabin()
: moveStatus(REST), doorsStatus(CLOSE), floor(1) {}

Cabin::~Cabin() {}

} /* namespace Hardware */
