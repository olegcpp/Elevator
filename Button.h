/*
 * RealButton.h
 *
 *  Created on: Sep 29, 2017
 *      Author: oleg
 */

#ifndef BUTTON_H_
#define BUTTON_H_

namespace Elevator {

class Button {
public:
	void reset() {isButtonPushed = false;}
	void push() {isButtonPushed = true;}
	bool isPushed() {return isButtonPushed;}

public:
	Button();
	virtual ~Button();

private:
	bool isButtonPushed;
};

} /* namespace Hardware */

#endif /* BUTTON_H_ */
