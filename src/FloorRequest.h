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

enum Direction {
  down,
  up
};

class FloorRequest: public Request {
public:
  FloorRequest();
  // Hmmm, maybe this should be a value type
  FloorRequest(unsigned);
  virtual ~FloorRequest();
private:
  unsigned floor;
  Direction direction;
};

} /* namespace Elevator */

#endif /* FLOORREQUEST_H_ */
