#include "GraphPlotter.h"

GraphPlotter::GraphPlotter(Network * net, double display_height, double display_width)
{
	std::vector<FullServiceNode*> *net_nodes = net->get_nodes();

	
	std::vector<FullServiceNode*>::iterator it;
	for (it = network->begin(); it != network->end(); ++it)
		network->push_back(new GraphicalNode((*it));
	
	this->display_width = display_width;
	this->display_height = display_height;

}

GraphPlotter::~GraphPlotter()
{
}

void GraphPlotter::plot_graph(unsigned int num_nodes) {

	double portion_rads = 360.0 / (double) num_nodes;
	double circle_of_nodes_radio = get_min_disp_dim() * 6.0/8.0;

	double node_circle_radio = ( get_min_disp_dim() - circle_of_nodes_radio * 2 )/2.0;

	std::vector<GraphicalNode*>::iterator it;
	for (it = network->begin(); it != network->end(); ++it) {
		GraphicalNode * current = (*it);
		double x_coord = circle_of_nodes_radio * cos(portion_rads);
		double y_coord = circle_of_nodes_radio * sin(portion_rads);
		//draw circle of node_circle_radio in x_coord and y_coord. 

		//The node's colour will depend on whether the node is a MinerNode or a FullServiceNode
		if(current->is_selected) {
			
		}


	}
}


double GraphPlotter::get_min_disp_dim() {
	return ((display_height < display_width)? display_height : display_width);
}