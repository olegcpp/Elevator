#ifndef SENSOR_STUB_H
#define SENSOR_STUB_H

#include "Sensor.h"

namespace Elevator {
  class SensorStub : public Sensor {

  public:
  SensorStub(Controller &c) : Sensor(c) {}
    void arrivingAtFloor(int floor) {
      this->controller.atFloor(3);
    }


  };
}

#endif
