#include "GraphicalNode.h"
#include "allegro5/allegro_primitives.h"
#define _USE_MATH_DEFINES
#include <math.h>
GraphicalNode::GraphicalNode(FullServiceNode * node)
{
	selected = false;
	drawn_mark = false;

}

GraphicalNode::~GraphicalNode(){

}


ALLEGRO_COLOR GraphicalNode::get_color(bool is_miner) {
	ALLEGRO_COLOR color;

	if (!selected)
		color = (is_miner ? al_color_name("red") : al_color_name("blue"));
	else
		color = al_color_name("orange");

	return color;
}

bool GraphicalNode::is_selected() {
	return this->selected;
}

void GraphicalNode::set_pos_x(double pos_x) {
	this->pos_x = pos_x;
}
void GraphicalNode::set_pos_y(double pos_y) {
	this->pos_y = pos_y;
}
void GraphicalNode::set_radius(double rad) {
	this->radius = rad;
}

bool GraphicalNode::is_clicked(double x_click, double y_click) {
	double distance_from_circle_centre = sqrt(pow(x_click - pos_x, 2) + pow(y_click - pos_y, 2));
	return (distance_from_circle_centre <= radius);
}

void GraphicalNode::mark_drawn() {
	this->drawn_mark = true;
}

void GraphicalNode::unmark_drawn() {
	this->drawn_mark = false;
}

bool GraphicalNode::is_marked_drawn() {
	return drawn_mark;
}

double GraphicalNode::get_pos_x() {
	return pos_x;
}
double GraphicalNode::get_pos_y() {
	return pos_y;
}
double GraphicalNode::get_radius() {
	return radius;
}