/*
 * sevent_segment_display.cpp
 *
 * rluna
 * Apr 21, 2018
 *
 */

#include "catch.hpp"
#include <iostream>
#include <vector>

#include "MLP.h"

/**
 *
 * Thinking of using this test as a base for your project?
 * Don't forget to put these lines in your main file:
 *
 * #include "easylogging++.h"
 *
 * INITIALIZE_EASYLOGGINGPP
 *
 *
 */


/*
 * A little more complex example: the implementation of
 * the sevent segment problem: given seven inputs
 * that represent the segment on a display, the
 * network must "learn" the correct numbers
 * (0, 1, 2,... ) and must give a somewhat correct
 * output for those cases that some segments are
 * off by errors.
 */
TEST_CASE( "sevenSegmentTest", "[sevenSegmentTest]" )
{
	REQUIRE( true );

	SECTION( "training of a seven segment test" )
	{
		std::vector<TrainingSample> training_set;

		// populate training set with the following
		// values:
		//  input
		// segment							number
	    //	0	1	2	3	4	5	6	0	1	2	3	4	5	6	7	8	9
	    //	1	1	1	1	1	1	0	1	0	0	0	0	0	0	0	0	0
	    //	0	1	1	0	0	0	0	0	1	0	0	0	0	0	0	0	0
	    //	1	1	0	1	1	0	1	0	0	1	0	0	0	0	0	0	0
	    //	1	1	1	1	0	0	1	0	0	0	1	0	0	0	0	0	0
	    //	0	1	1	0	0	1	1	0	0	0	0	1	0	0	0	0	0
	    //	1	0	1	1	0	1	1	0	0	0	0	0	1	0	0	0	0
	    //	1	0	1	1	1	1	1	0	0	0	0	0	0	1	0	0	0
	    //	1	1	1	0	0	0	0	0	0	0	0	0	0	0	1	0	0
	    //	1	1	1	1	1	1	1	0	0	0	0	0	0	0	0	1	0
	    //	1	1	1	1	0	1	1	0	0	0	0	0	0	0	0	0	1
		//
		//
		//S0   S1    S2    S3    S4    S5    S6      N0    N1    N2    N3    N4    N5    N6    N7    N8    N9
		training_set.push_back( TrainingSample( {1.0L, 1.0L, 1.0L, 1.0L, 1.0L, 1.0L, 0.0L}, {1.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {0.0L, 1.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L}, {0.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 1.0L, 0.0L, 1.0L, 1.0L, 0.0L, 1.0L}, {0.0L, 0.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 1.0L, 1.0L, 1.0L, 0.0L, 0.0L, 1.0L}, {0.0L, 0.0L, 0.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {0.0L, 1.0L, 1.0L, 0.0L, 0.0L, 1.0L, 1.0L}, {0.0L, 0.0L, 0.0L, 0.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 0.0L, 1.0L, 1.0L, 0.0L, 1.0L, 1.0L}, {0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 0.0L, 1.0L, 1.0L, 1.0L, 1.0L, 1.0L}, {0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 1.0L, 0.0L, 0.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 1.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L}, {0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 1.0L, 0.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 1.0L, 1.0L, 1.0L, 1.0L, 1.0L, 1.0L}, {0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 1.0L, 0.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 1.0L, 1.0L, 1.0L, 0.0L, 1.0L, 1.0L}, {0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 0.0L, 1.0L} ) );

		// 7 inputs
		// 1 hidden layer(s) of 2 neurons.
		// 10 outputs
		MLP my_mlp({ 7, 2, 10 }, { "sigmoid", "linear" }, false);

		int loops = 15000;
		my_mlp.Train(training_set, .01L, loops, 0.10L, false);

		// now, let's test what the output should
		// be and if the network have learnt the
		// patterns
		std::vector<double> output;
		std::cout << "Output for the 0 digit" << std::endl;
		my_mlp.GetOutput( {1.0L, 1.0L, 1.0L, 1.0L, 0.0L, 1.0L, 1.0L}, &output );

		for( int i = 0; i < 10; i++ )
			if( output[i] > 0.5 )
				std::cout << i << " " << output[i] << std::endl;
			else
				std::cout << i << " " << 0 << std::endl;

		std::cout << "Output for the 1 digit" << std::endl;
		my_mlp.GetOutput( {0.0L, 1.0L, 1.0L, 0.0L, 0.0L, 0.0L, 0.0L}, &output );

		for( int i = 0; i < 10; i++ )
			if( output[i] > 0.5 )
				std::cout << i << " " << output[i] << std::endl;
			else
				std::cout << i << " " << 0 << std::endl;

		// check to be done after some code is run
		CHECK( true );
	} // section to cover this part of the test
}


