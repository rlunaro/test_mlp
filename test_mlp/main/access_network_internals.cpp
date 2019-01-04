/*
 * access_network_internals.cpp
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

bool softEqual( double d1, double d2 );

/*
 * Test for access the internals of the network, once
 * created. Concretely, to access the weights of the
 * network and set/retrieve values.
 */
TEST_CASE( "accessNetworkInternals", "[accessNetworkInternals]" )
{

	SECTION( "test to access the network internal structure" )
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
		// be and if the network have learned the
		// patterns
		std::vector<double> outputBeforeWeightAdjustment[4];
        std::vector<double> outputAfterWeightAdjustment[4];
        double desiredValueBefore[4] = { 0.426029L, 0.52653L, 0.522139L, 0.559975L };
        double desiredValueAfter[4] = { 0.0L, 0.0L, 0.0L, 0.0L };

		my_mlp.GetOutput( {0.0L, 0.0L}, &outputBeforeWeightAdjustment[0] );
		CHECK( softEqual( outputBeforeWeightAdjustment[0][0], desiredValueBefore[0] ) );
		my_mlp.GetOutput( {0.0L, 1.0L}, &outputBeforeWeightAdjustment[1] );
        CHECK( softEqual( outputBeforeWeightAdjustment[1][0], desiredValueBefore[1] ) );
		my_mlp.GetOutput( {1.0L, 0.0L}, &outputBeforeWeightAdjustment[2] );
        CHECK( softEqual( outputBeforeWeightAdjustment[2][0], desiredValueBefore[2] ) );
		my_mlp.GetOutput( {1.0L, 1.0L}, &outputBeforeWeightAdjustment[3] );
        CHECK( softEqual( outputBeforeWeightAdjustment[3][0], desiredValueBefore[3] ) );

		// remove the internal weights
        std::vector<std::vector<double>> zeroWeightsLayer0 = { {0.0L, 0.0L}, {0.0L, 0.0L} };
        std::vector<std::vector<double>> zeroWeightsLayer1 = { {0.0L, 0.0L} };
        my_mlp.SetLayerWeights( 0, zeroWeightsLayer0 );
        my_mlp.SetLayerWeights( 1, zeroWeightsLayer1 );

        my_mlp.GetOutput( {0.0L, 0.0L}, &outputAfterWeightAdjustment[0] );
        CHECK( softEqual( outputAfterWeightAdjustment[0][0], desiredValueAfter[0] ) );
        my_mlp.GetOutput( {0.0L, 1.0L}, &outputAfterWeightAdjustment[1] );
        CHECK( softEqual( outputAfterWeightAdjustment[1][0], desiredValueAfter[1] ) );
        my_mlp.GetOutput( {1.0L, 0.0L}, &outputAfterWeightAdjustment[2] );
        CHECK( softEqual( outputAfterWeightAdjustment[2][0], desiredValueAfter[2] ) );
        my_mlp.GetOutput( {1.0L, 1.0L}, &outputAfterWeightAdjustment[3] );
        CHECK( softEqual( outputAfterWeightAdjustment[3][0], desiredValueAfter[3] ) );



	} // section to cover this part of the test

}

bool softEqual( double d1, double d2 )
{
    return -0.0001L <= d1-d2 && d1-d2 <= 0.0001L;
}



