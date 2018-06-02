#pragma once
#include "MinerNode.h"
#include <allegro5/allegro_color.h>
class GraphicalNode: public FullServiceNode
{
public:
	GraphicalNode(FullServiceNode * node);
	~GraphicalNode();

	ALLEGRO_COLOR get_color();
	void set_pos_x(double pos_x);
	void set_pos_y(double pos_y);
	bool is_selected();

private:
	void draw_connections();
	bool selected;
	double pos_x;
	double pos_y;

};

