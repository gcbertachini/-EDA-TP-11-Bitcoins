#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>

#include "Network.h"
#include "GraphicalNode.h"
class GraphPlotter
{
public:
	GraphPlotter(Network * net, double display_height,double display_width);
	~GraphPlotter();

	void plot_graph(unsigned int num_nodes);

private:
	std::vector<GraphicalNode*> *network;
	double get_min_disp_dim();
	double display_height;
	double display_width;

};

