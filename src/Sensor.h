/*
 * Sensor.h
 *
 *  Created on: Oct 9, 2017
 *      Author: oleg
 */

#ifndef SENSOR_H_
#define SENSOR_H_

#include "Controller.h"

namespace Elevator {

class Sensor {

public:
	Sensor(Controller& controller)
: controller(controller) {}

	virtual ~Sensor();
public:
	Controller& controller;
};

} /* namespace Elevator */

#endif /* SENSOR_H_ */
