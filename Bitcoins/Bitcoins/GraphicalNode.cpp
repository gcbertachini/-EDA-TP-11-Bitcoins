#include "GraphicalNode.h"
#include "allegro5/allegro_primitives.h"
#define COLORED_TAG UINT16_MAX
GraphicalNode::GraphicalNode(FullServiceNode * node)
{
	selected = false;
}


GraphicalNode::~GraphicalNode(){
}


ALLEGRO_COLOR GraphicalNode::get_color() {
	ALLEGRO_COLOR color;

	if (!selected)
		color = (this->is_miner() ? al_color_name("Red") : al_color_name("Blue"));
	else
		color = al_color_name("Orange");

	return color;
}

bool GraphicalNode::is_selected() {
	return this->selected;
}

void GraphicalNode::draw_connections() {

	if(this->is_marked_visited() != COLORED_TAG){
		this->mark_visited(COLORED_TAG);
		for (int i = 0; this->get_connection(i) != NULL;i++) {
			GraphicalNode * to_draw = (GraphicalNode *)this->get_connection(i);
			al_draw_line(pos_x, pos_y, to_draw->pos_x, to_draw->pos_y, al_color_name("White"), 1);
			to_draw->draw_connections();
		}
	}
}

void GraphicalNode::set_pos_x(double pos_x) {
	this->pos_x = pos_x;
}
void GraphicalNode::set_pos_y(double pos_y) {
	this->pos_y = pos_y;
}