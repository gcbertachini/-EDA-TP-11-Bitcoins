#pragma once

#include <allegro5/allegro.h>
#include <allegro5/allegro_color.h>
#include <allegro5/allegro_primitives.h>
#include <allegro5/allegro_image.h>
#include <map>
#include "Network.h"
#include "GraphicalNode.h"
class GraphPlotter
{
public:
	GraphPlotter(Network * net, double display_height,double display_width);
	~GraphPlotter();

	bool init_gui();
	void plot_graph(unsigned int num_nodes);

private:

	std::vector<GraphicalNode*> *network;
	std::map<GraphicalNode*, FullServiceNode *> *graph_logical_map;
	std::map<FullServiceNode*, GraphicalNode *> *logical_graph_map;


	double get_min_disp_dim();
	void plot_connections();
	double display_height;
	double display_width;
	void draw_connection(GraphicalNode * graphical1, GraphicalNode * graphical2);
	GraphicalNode * get_associated_graphical_node(FullServiceNode * graph_node);
	FullServiceNode * get_associated_node(GraphicalNode * graph_node);
	ALLEGRO_DISPLAY * display;
};

