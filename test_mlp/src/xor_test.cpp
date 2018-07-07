/*
 * xor_test.cpp
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
 * A very very simple test with only one input
 * and one output. It will perform a training
 * consisting of 5000 loops and that's all.
 */
TEST_CASE( "xorTest", "[xorTest]" )
{
	REQUIRE( true );

	SECTION( "the most simple test of all: learning an xor table" )
	{
		std::vector<TrainingSample> training_set;

		// populate training set with the following
		// values:
		//  input  output
		//  0, 0     0
		//  0, 1     1
		//  1, 0     1
		//  1, 1     0
		training_set.push_back( TrainingSample( {0.0L, 0.0L}, {0.0L} ) );
		training_set.push_back( TrainingSample( {0.0L, 1.0L}, {1.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 0.0L}, {1.0L} ) );
		training_set.push_back( TrainingSample( {1.0L, 1.0L}, {0.0L} ) );

		// assuming 2 inputs
		// 1 hidden layer(s) of 2 neurons.
		// 1 outputs
		MLP my_mlp({ 2, 2, 1 }, { "sigmoid", "linear" }, false);

		int loops = 15000;
		my_mlp.Train(training_set, .01L, loops, 0.10L, false);

		// now, let's test what the output should
		// be and if the network have learnt the
		// patterns
		std::vector<double> output;
		my_mlp.GetOutput( {0.0L, 0.0L}, &output );

		std::cout << " {0.0L, 0.0L} -> " << output[0] << std::endl;

		my_mlp.GetOutput( {0.0L, 1.0L}, &output );

		std::cout << " {0.0L, 1.0L} -> " << output[0] << std::endl;

		my_mlp.GetOutput( {1.0L, 0.0L}, &output );

		std::cout << " {1.0L, 0.0L} -> " << output[0] << std::endl;

		my_mlp.GetOutput( {1.0L, 1.0L}, &output );

		std::cout << " {1.0L, 1.0L} -> " << output[0] << std::endl;

		// check to be done after some code is run
		CHECK( true );
	} // section to cover this part of the test
}


