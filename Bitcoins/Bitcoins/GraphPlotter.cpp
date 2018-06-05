#include "GraphPlotter.h"
#include <iostream>
#define _USE_MATH_DEFINES
#include <math.h>

/*******************************************
***************GraphPlotter*****************
********************************************
*GraphPlotter needs a posterior call to init_gui().
*initializes the maps for the logical_graphical correspondance, sets the display dimensions, 
*and creates the graphical nodes associates
*INPUT:
*	1) net : network with the logical nodes of the graph.
*	2) display_height : self-explanatory.
*	3) display_width : self-explanatory.
*
*OUTPUT:
*	void.
*/
GraphPlotter::GraphPlotter(Network * net, double display_height, double display_width)
{
	graph_logical_map = new std::map<GraphicalNode *, FullServiceNode *>();
	logical_graph_map = new std::map<FullServiceNode*, GraphicalNode * >();

	display = NULL;
	std::vector<FullServiceNode*> *net_nodes = net->get_nodes();

	network = new std::vector<GraphicalNode * >();

	std::vector<FullServiceNode*>::iterator it;
	for (it = net->get_nodes()->begin(); it != net->get_nodes()->end(); ++it){
		GraphicalNode * graph_node = new GraphicalNode(*it);
		network->push_back(graph_node);
		graph_logical_map->insert(std::pair<GraphicalNode*, FullServiceNode*> (graph_node, *it));
		logical_graph_map->insert(std::pair<FullServiceNode*, GraphicalNode*>(*it, graph_node));
	}
	this->display_width = display_width;
	this->display_height = display_height;


	amount_of_mined_blocks = 0;
	average_mining_time = 0;

}

GraphPlotter::~GraphPlotter()
{
}


/*******************************************
***************plot_graph*******************
********************************************
*plot_graph plots the graph with its connections and 
*with different colors for the selected, not selected, miners and full service nodes.
*INPUT:
*	1) num_nodes : amount of nodes in the graph.
*
*OUTPUT:
*	void.
*/
void GraphPlotter::plot_graph(unsigned int num_nodes) {
	al_clear_to_color(al_color_name("Black"));

	double portion_rads = (2* M_PI) / (double) num_nodes;
	double circle_of_nodes_radio = get_min_disp_dim() * 6.0/16.0;

	double node_circle_radio = ( get_min_disp_dim() - circle_of_nodes_radio )/20.0;

	std::vector<GraphicalNode*>::iterator it;
	int i = 0;
	for (it = network->begin(); it != network->end(); ++it) {
		GraphicalNode * current = (*it);
		double x_coord = circle_of_nodes_radio * cos(portion_rads*(1+i)) + display_width/2.0;
		double y_coord = circle_of_nodes_radio * sin(portion_rads*(1 + i))+display_height/2.0;
		current->set_pos_x(x_coord);
		current->set_pos_y(y_coord);
		current->set_radius(node_circle_radio);
		al_draw_filled_circle(x_coord, y_coord, node_circle_radio, current->get_color(get_associated_node(current)->is_miner()));
		i++;
	}
	plot_connections();
	al_flip_display();
}

/*******************************************
***************plot_connections*******************
********************************************
*plot_connections plots the connections between all the different nodes in the graph!
*INPUT:
*	1) void.
*
*OUTPUT:
*	void.
*/
void GraphPlotter::plot_connections() {

	std::vector<GraphicalNode*>::iterator it;
	for (it = network->begin(); it != network->end(); ++it) {
		GraphicalNode * current_graphical = (*it);
		if(!current_graphical->is_marked_drawn()){
			current_graphical->mark_drawn();

			Node * current_logical = get_associated_node(current_graphical);
			int i = 0;
			while(current_logical->get_connection(i) != NULL)
			{
				GraphicalNode * connected = get_associated_graphical_node((FullServiceNode *)current_logical->get_connection(i));
				draw_connection(current_graphical, connected);
				i++;
			}
		}
	}
}

/*******************************************
***************draw_connection*******************
********************************************
*draw_connection draws the line that connects one graphical node one of its counterpart.
*INPUT:
*	1) void.
*
*OUTPUT:
*	void.
*/
void GraphPlotter::draw_connection(GraphicalNode * graphical1, GraphicalNode * graphical2) {
	al_draw_line(graphical1->get_pos_x(), graphical1->get_pos_y(), graphical2->get_pos_x(), graphical2->get_pos_y(), al_color_name("white"), 1);
}

/*******************************************
***************get_min_disp_dim*************
********************************************
*get_min_disp_dim draws returns the minimum dimension of the display (x or y dim).
*INPUT:
*	1) void.
*
*OUTPUT:
*	double with the minimum dimension.
*/
double GraphPlotter::get_min_disp_dim() {
	return ((display_height < display_width)? display_height : display_width);
}

/*******************************************
***************init_gui*************
********************************************
*init_gui initializes all neccesary allegro components for the Graph Plotter.
*INPUT:
*	1) void.
*
*OUTPUT:
*	a boolean that is true if the gui was correctly initialized. false if not.
*/
bool GraphPlotter::init_gui() {

	bool valid = true;
	if (!al_init())
	{
		std::cout << "No se pudo inicializar Allegro" << std::endl;
		valid = false;
	}
	/*
	else if (!al_init_font_addon())
	{
		std::cout << "No se pudo inicializar el addon de font" << std::endl;
		valid = false;
	}
	else if (!al_init_ttf_addon())
	{
		std::cout << "No se pudo inicializar el addon de ttf" << std::endl;
		al_shutdown_font_addon();
		valid = false;
	}
	*/
	else if (!al_init_primitives_addon())
	{
		std::cout << "No se pudo inicializar el addon de primitivas" << std::endl;
		//al_shutdown_ttf_addon();
		//al_shutdown_font_addon();
		valid = false;
	}
	else if (!al_init_image_addon())
	{
		std::cout << "No se pudo inicializar el addon de imagenes" << std::endl;
		al_shutdown_primitives_addon();
		//al_shutdown_ttf_addon();
		//al_shutdown_font_addon();
		al_shutdown_image_addon();
		valid = false;
	}




	////////////////////////creacion y personalizacion display/////////////////////////////
	al_set_new_display_option(ALLEGRO_SAMPLE_BUFFERS, 1, ALLEGRO_SUGGEST);
	al_set_new_display_option(ALLEGRO_SAMPLES, 8, ALLEGRO_SUGGEST);
	al_set_new_display_flags(ALLEGRO_RESIZABLE);
	
	if (!(display = al_create_display(display_width, display_height)))
	{
		std::cout << "No se pudo crear el display" << std::endl;
		valid = false;
	}
	else {
		al_clear_to_color(al_color_name("Black"));
		al_flip_display();
	}
	ALLEGRO_BITMAP * icon = al_load_bitmap("eda_coin.png");	
	if (icon == nullptr)
	{
		//No se pone valid en false ya que el programa puede correr sin el icono de la ventana
		std::cout << "No se pudo cargar el icono del display" << std::endl;
	}
	else
	{
		al_set_display_icon(display, icon);
	}
	al_set_window_title(display, "EDAcoin");

	return valid;
}


/*******************************************
***************get_associated_node**********
********************************************
*returns the FullsServiceNode that corresponds to a given graphical node.
*INPUT:
*	1) graph_node
*
*OUTPUT:
*	a FullServiceNode that corresponds to the given graphical node.
*/
FullServiceNode * GraphPlotter::get_associated_node(GraphicalNode * graph_node) {
	return (*graph_logical_map->find(graph_node)).second;
}

GraphicalNode * GraphPlotter::get_associated_graphical_node(FullServiceNode * graph_node) {
	return (*logical_graph_map->find(graph_node)).second;
}

