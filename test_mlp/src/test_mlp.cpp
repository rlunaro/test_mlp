/*
 * test_mlp.cpp
 *
 * rluna
 * Apr 21, 2018
 *
 */

#include <iostream>
#include <vector>

#include "MLP.h"
#include "easylogging++.h"

INITIALIZE_EASYLOGGINGPP

int main( int argc, char *argv[] )
{
	std::cout << "hello" << std::endl;

	std::vector<TrainingSample> training_set;

	// populate training set with the following
	// values:
	//     input     output
	//  1, 1, 1, 1     0
	//  0, 1, 1, 0     1
	//  1, 1, 1, 0     7
	std::vector<double> input = {1.0L, 1.0L, 1.0L, 1.0L};
	std::vector<double> output = {0.0L};
	TrainingSample t1( input, output );
	training_set.push_back( t1 );

	// assuming 4 inputs
	// 1 hidden layer(s) of 4 neurons.
	// 1 outputs
	MLP my_mlp({ 4, 4, 1 }, { "sigmoid", "linear" }, false);

	int loops = 5000;
	my_mlp.Train(training_set, .01L, loops, 0.10L, false);




//	for (int j = 0; j < samples; ++j) {
//	  std::vector<double> guess;
//	  my_mlp.GetOutput(training_set[j].input_vector(), &guess);
//	  size_t class_id;
//	  my_mlp.GetOutputClass(guess, &class_id);
//	  // Compare class_id with gold class id for each instance
//	}

}
