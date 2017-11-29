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
class ButtonAPI;

class CabinAPI {
public:
	enum MoveStatus {UP, DOWN, REST};
	enum DoorsStatus {OPEN, CLOSE, OPENING, CLOSING};

	virtual void moveUp() = 0;
	virtual void moveDown() = 0;
	virtual void stop() = 0; //stops at the nearest floor
	virtual MoveStatus getMoveStatus() const = 0;
	virtual unsigned getNearestFloor() const = 0;

	virtual void openDoors() = 0;
	virtual void closeDoors() = 0;
	virtual DoorsStatus getDoorsStatus() const = 0;

	std::vector<std::unique_ptr<ButtonAPI>>& buttons();

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

struct FloorAPI {
	std::unique_ptr<ButtonAPI> up;
	std::unique_ptr<ButtonAPI> down;
};

struct SystemAPI {
	unsigned numberOfFloors;
	std::vector<std::unique_ptr<CabinAPI>> cabins;
	std::vector<FloorAPI>& floorUIs;

public:
	SystemAPI();
	virtual ~SystemAPI();
};

} //namespace Hardware

#endif /* API_H_ */
