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

	//methods
	////////////////
	double get_min_disp_dim();
	void plot_connections();

	void draw_connection(GraphicalNode * graphical1, GraphicalNode * graphical2);
	GraphicalNode * get_associated_graphical_node(FullServiceNode * graph_node);
	FullServiceNode * get_associated_node(GraphicalNode * graph_node);

	//properties
	///////////////

	std::vector<GraphicalNode*> *network;							//graphical network
	std::map<GraphicalNode*, FullServiceNode *> *graph_logical_map;		
	std::map<FullServiceNode*, GraphicalNode *> *logical_graph_map;
	
	double display_height;
	double display_width;
	ALLEGRO_DISPLAY * display;

	double node_display_height;
	double node_display_width;
	ALLEGRO_DISPLAY * node_display;			//window to be shown in case a node is double-clicked.

	//to show on screen.
	double average_mining_time;		
	int amount_of_mined_blocks;
};

