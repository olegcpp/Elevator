/*
 * API.h
 *
 *  Created on: Nov 26, 2017
 *      Author: oleg
 */

#ifndef API_H_
#define API_H_

#include <vector>
#include <memory>

namespace Hardware {

//Interface class for the physical cabin
class CabinAPI {
public:
	enum MoveStatus {UP, DOWN, REST};
	enum DoorsStatus {OPEN, CLOSE, OPENING, CLOSING};

	virtual int id() const = 0;

	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void stop() = 0; //stops at nearest floor

	virtual void openDoors() = 0;
	virtual void closeDoors() = 0;

	virtual unsigned getNearestFloor() const = 0;
	virtual MoveStatus getMoveStatus() const  = 0;
	virtual DoorsStatus getDoorsStatus() const = 0;

	CabinAPI() {};
	virtual ~CabinAPI();
};

class ButtonAPI {
public:
	virtual void reset() = 0;
	virtual void push() = 0;
	virtual bool isPushed() const = 0;

	public:
		ButtonAPI() {};
		virtual ~ButtonAPI() = 0;
};

class FloorUI {
public:
	std::unique_ptr<ButtonAPI> up;
	std::unique_ptr<ButtonAPI> down;
};

class System {
public:
	virtual unsigned numberOfFloors() const = 0;
	virtual std::vector<std::unique_ptr<CabinAPI>> cabins() = 0;
	virtual std::vector<std::unique_ptr<ButtonAPI>> cabinUIs() = 0;
	virtual std::vector<FloorUI> floorUIs() = 0;

public:
	System();
	virtual ~System() = 0;
};

} //namespace Hardware

#endif /* API_H_ */
