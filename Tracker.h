/*
 * Tracker.h
 *
 *  Created on: Oct 9, 2017
 *      Author: oleg
 */

#ifndef TRACKER_H_
#define TRACKER_H_

#include "Request.h"
#include "Controller.h"
namespace Elevator {

class Tracker {
public:
	void ready(Controller& controller);
	void addRequest(Request& req);
private:
	void addToQueue(Request& req);
public:
	Tracker();
	virtual ~Tracker();
};

} /* namespace Elevator */

#endif /* TRACKER_H_ */
