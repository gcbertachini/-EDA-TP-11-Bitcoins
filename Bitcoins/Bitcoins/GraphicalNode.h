#pragma once
#include "MinerNode.h"
#include <allegro5/allegro_color.h>
class GraphicalNode
{
public:
	GraphicalNode(FullServiceNode * node);
	~GraphicalNode();

	ALLEGRO_COLOR get_color(bool is_miner);
	void set_pos_x(double pos_x);
	void set_pos_y(double pos_y);

	void set_radius(double rad);

	double get_pos_x();
	double get_pos_y();
	double get_radius();

	bool is_selected();

	void mark_drawn();
	void unmark_drawn();
	bool is_clicked(double x_click, double y_click);
	bool is_marked_drawn();
private:

	bool selected;
	double pos_x;
	double pos_y;
	double radius;
	bool drawn_mark;

};

