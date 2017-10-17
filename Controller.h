/*
 * Controller.h
 *
 *  Created on: Oct 9, 2017
 *      Author: oleg
 */

#ifndef CONTROLLER_H_
#define CONTROLLER_H_

namespace Elevator {

class Controller {
public:
	bool processFloorRequest(unsigned floor, int direction); //-1=down, 1=up
	bool processCabinRequest(unsigned floor);

	void atFloor(unsigned floor); //to be called by sensor
public:
	Controller();
	virtual ~Controller();
};

} /* namespace Elevator */

#endif /* CONTROLLER_H_ */
