#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <vector>

#include "general.h"
#include "Network.h"
#include "GraphPlotter.h"

#define DISPLAY_W 800.0
#define DISPLAY_H 600.0

std::vector<FullServiceNode*> * create_network(unsigned int num_miners, unsigned int num_full_s);

int main(int argc, char *argv[]) {

	unsigned int num_miners = 0, num_full_s =0 ;			//get the values from command line!! (parser!!)
	//call to parser 
	srand(time(NULL));
	Network * network = new Network(num_miners, num_full_s);

	 GraphPlotter plotter = GraphPlotter(network, DISPLAY_H, DISPLAY_W);
	 plotter.plot_graph(num_miners + num_full_s);
}

