/*
 * Test1.cpp
 *
 *  Created on: Sep 8, 2017
 *      Author: oleg
 */
#include <CppUTest/TestHarness.h>
#include <memory>

#include "Cabin.h"

TEST_GROUP(Cabin) {
};

TEST(Cabin, Test1) {
	Elevator::Cabin cabin;
	LONGS_EQUAL(0, 0);
}
