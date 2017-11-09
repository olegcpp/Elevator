#include "catch.hpp"
#include "Bank.h"
#include "Controller.h"
#include "FloorRequest.h"
#include "SensorStub.h"
#include "Cabin.h"

TEST_CASE("Elevator Acceptance Tests", "") {

  SECTION("When the elevator(s) are stopped and a user pushes the button") {
    /* Original psuedocode
       UI->Tracker:addRequest(FloorReq(3, down))
       Tracker->Controller:ACCEPT = processFloorReq(3, down)
       Controller->Cabin:SUCCESS = tryGoDown()
       Controller->Cabin:goDown()
       Sensor->Controller:atFloor(2)
       Sensor->Controller:atFloor(3)
       Controller->Cabin:stop()
       Controller->Cabin:openDoors()
       Controller->Controller:wait()
       Controller->Cabin:closeDoors()
       Controller->Tracker:ready()*/
    Elevator::Bank b;
    Elevator::Controller c;
    Elevator::SensorStub s(c);
    Elevator::Cabin cabin;
    b.addCabin(cabin);
    b.addRequest(Elevator::FloorRequest(3));

    s.arrivingAtFloor(3);

    // how do I time that the doors are closed
    REQUIRE(cabin.areDoorsClosed());
    REQUIRE(b.isReady());
  }

  SECTION("Elevator is empty, and moving to pick up one user. Another pushes the button.") {
    /*
    title Use case 2: Elevator called, is empty passing floor 4 to pick up Cliff on 7. Joe pushes up button on floor 3, Cliff pushes 2
      Sensor->Controller:atFloor(4)
      UI->Tracker:addRequest(FloorReq(3,up)) //from Joe
      Tracker->Controller: REJECT = processFloorRequest(3, up)
      Tracker->Tracker: addToQueue(Floor(3,up))
      Sensor->Controller:atFloor(5)
      Sensor->Controller:atFloor(6)
      Sensor->Controller:atFloor(7)
      Controller->Cabin:stop()
      Controller->Cabin:openDoors()
      Controller->Controller:wait()
      UI->Tracker:addRequest(CabinRequest(2))
      Tracker->Controller:ACCEPT = processCabinRequest(2)
      Controller->Cabin:closeDoors()
      Controller->Cabin:goDown()
      Sensor->Controller:atFloor(6)
      Sensor->Controller:atFloor(5)
      Sensor->Controller:atFloor(4)
      Sensor->Controller:atFloor(3)
      Sensor->Controller:atFloor(2)
      Controller->Cabin:stop()
      Controller->Cabin:openDoors()
      Controller->Controller:wait()
      Controller->Cabin:closeDoors()
      Controller->Tracker:ready()
      Tracker->Tracker:req = getRequestFromQueue() //req = FloorReq(3,up)
      Tracker->Controller:ACCEPT = processFloorRequest(3,up)
      note right of Tracker
      Now reduced to Use case 1
      end note*/

    // First problem - how do I setup a sensor at a spot?
    //    Sensor->Controller:atFloor(4);
    Elevator::Bank b;
    b.addRequest(Elevator::FloorRequest(3));
  }
}
