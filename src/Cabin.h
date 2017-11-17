/*
 * RealCabin.h
 *
 *  Created on: Sep 29, 2017
 *      Author: oleg
 */

#ifndef CABIN_H_
#define CABIN_H_

namespace Elevator {

class Cabin {

public:
	enum MoveStatus {UP, DOWN, REST};
	enum DoorsStatus {OPEN, CLOSE};

public:
	void goUp();
	void goDown();
	void stop();

	void openDoors();
	void closeDoors();

public:
	unsigned getFloor() {return floor;}
	MoveStatus getMoveStatus() {return moveStatus;}
	DoorsStatus getDoorsStatus() {return doorsStatus;}
  bool areDoorsClosed() {return false;}

public:
	Cabin();
	virtual ~Cabin();

private:
	MoveStatus moveStatus;
	DoorsStatus doorsStatus;
	unsigned floor;
};

} /* namespace Hardware */

#endif /* CABIN_H_ */
