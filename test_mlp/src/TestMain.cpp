/*
 * TestMain.cpp
 *
 *  Created on: May 6, 2017
 *      Author: rluna
 */


#define CATCH_CONFIG_MAIN
#include "catch.hpp"

#include "easylogging++.h"


INITIALIZE_EASYLOGGINGPP


TEST_CASE("empty", "empty")
{
	CHECK( true );
} // empty test case
