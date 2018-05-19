/*
 * test_mlp.cpp
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
TEST_CASE( "verySimpleTest", "[verySimpleTest]" )
{
	REQUIRE( true );

	SECTION( "A very simple simple test" )
	{
		std::vector<TrainingSample> training_set;

		// populate training set with the following
		// value:
		//     input     output
		//  1, 1, 1, 1     0
		std::vector<double> input = {1.0L, 1.0L, 1.0L, 1.0L};
		std::vector<double> output = {0.0L};
		TrainingSample t1( input, output );
		training_set.push_back( t1 );

		// assuming 4 inputs
		// 1 hidden layer(s) of 4 neurons.
		// 1 outputs
		MLP my_mlp({ 4, 4, 1 }, { "sigmoid", "linear" }, false);

		int loops = 15000;
		my_mlp.Train(training_set, .01L, loops, 0.10L, false);

		// let's see if the network have learnt the
		// only input value
		std::vector<double> learntOutput;

		my_mlp.GetOutput( input, &learntOutput );

		std::cout << "{1.0L, 1.0L, 1.0L, 1.0L} -> " << learntOutput[0] << std::endl;

	} // section to cover this part of the test
}

