/*
 * FloorRequest.h
 *
 *  Created on: Oct 9, 2017
 *      Author: oleg
 */

#ifndef FLOORREQUEST_H_
#define FLOORREQUEST_H_

#include "Request.h"

namespace Elevator {

class FloorRequest: public Request {
public:
	FloorRequest();
	virtual ~FloorRequest();
private:
	unsigned floor;
	int direction;
};

} /* namespace Elevator */

#endif /* FLOORREQUEST_H_ */
