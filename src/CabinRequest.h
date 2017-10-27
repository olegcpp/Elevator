/*
 * CabinRequest.h
 *
 *  Created on: Oct 9, 2017
 *      Author: oleg
 */

#ifndef CABINREQUEST_H_
#define CABINREQUEST_H_

#include "Request.h"

namespace Elevator {

class CabinRequest: public Request {
public:
	CabinRequest();
	virtual ~CabinRequest();
public:
	unsigned floor;
};

} /* namespace Elevator */

#endif /* CABINREQUEST_H_ */
