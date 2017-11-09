/*
 * Bank.h
 *
 *  Created on: Oct 9, 2017
 *      Author: oleg
 */

#ifndef BANK_H_
#define BANK_H_

#include "Request.h"
#include "Controller.h"
#include "Cabin.h"

namespace Elevator {

class Bank {
public:
	void ready(Controller& controller);
	void addRequest(const Request& req);
  void addCabin(const Cabin &);
  bool isReady() { return false; }
private:
	void addToQueue(Request& req);
public:
	Bank();
	virtual ~Bank();
};

} /* namespace Elevator */

#endif /* TRACKER_H_ */
