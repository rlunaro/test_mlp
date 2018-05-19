/*
 * templateTest.cpp
 *
 *  Created on: Jun 19, 2017
 *      Author: rluna
 */


#include "catch.hpp"

#include <string>

TEST_CASE( "templateTest", "[templateTest]" )
{
	REQUIRE( true );

	SECTION( "section to cover this part of the test" )
	{
		// some test that must be verified BEFORE some code is run
		REQUIRE( true );

		// check to be done after some code is run
		CHECK( true );
	} // section to cover this part of the test
}

