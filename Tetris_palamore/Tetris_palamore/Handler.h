#pragma once

#include "value.h"
#include "Block.h"
#include "GameManager.h"


class Handler
{

	Block*		Current_moving_block;
	_pos		Block_pos;
	int			Realtime_map[15][10];
	int			Current_stacked_map[15][10];
	
public:
	Handler();
	~Handler();



	void H_init(GameManager *GM);
	void H_D_init(GameManager *GM);

	bool blocking_check();
	
	void make_rotate();
	void move_left();
	void move_right();
	int  down();
	void drop();


	Block get_Current_block();
	int get_x(), get_y();


	int* push_map_render();

	void H_test_print();



};

