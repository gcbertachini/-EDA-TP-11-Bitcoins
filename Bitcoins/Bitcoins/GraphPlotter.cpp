#include "GraphPlotter.h"
#include <iostream>
#define DEFAULT_SCREEN_H 600
#define DEFAULT_SCREEN_W 600


GraphPlotter::GraphPlotter(Network * net, double display_height, double display_width)
{
	display = NULL;
	std::vector<FullServiceNode*> *net_nodes = net->get_nodes();

	network = new std::vector<GraphicalNode * >();

	std::vector<FullServiceNode*>::iterator it;
	for (it = net->get_nodes()->begin(); it != net->get_nodes()->end(); ++it)
		network->push_back(new GraphicalNode(*it));
	
	this->display_width = display_width;
	this->display_height = display_height;
	init_gui();
	al_clear_to_color(al_color_name("Black"));
	al_flip_display();
}

GraphPlotter::~GraphPlotter()
{
}

void GraphPlotter::plot_graph(unsigned int num_nodes) {
	al_clear_to_color(al_color_name("Black"));

	double portion_rads = 360.0 / (double) num_nodes;
	double circle_of_nodes_radio = get_min_disp_dim() * 6.0/8.0;

	double node_circle_radio = ( get_min_disp_dim() - circle_of_nodes_radio * 2 )/2.0;

	std::vector<GraphicalNode*>::iterator it;
	for (it = network->begin(); it != network->end(); ++it) {
		GraphicalNode * current = (*it);
		double x_coord = circle_of_nodes_radio * cos(portion_rads);
		double y_coord = circle_of_nodes_radio * sin(portion_rads);
		current->set_pos_x(x_coord);
		current->set_pos_y(y_coord);
		al_draw_filled_circle(x_coord, y_coord, node_circle_radio, current->get_color());
	}

	al_flip_display();
}


double GraphPlotter::get_min_disp_dim() {
	return ((display_height < display_width)? display_height : display_width);
}


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

	display_height = DEFAULT_SCREEN_H;
	display_width = DEFAULT_SCREEN_W;

	
	if (!(display = al_create_display(display_width, display_height)))
	{
		std::cout << "No se pudo crear el display" << std::endl;
		valid = false;
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