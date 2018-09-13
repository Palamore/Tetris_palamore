#pragma once

#include "value.h"
#include "Block.h"
#include "GameManager.h"


class Handler
{

	Block*		Current_moving_block;
	_pos		Block_pos;
	int			Realtime_map[15][10];

	
public:
	Handler();
	~Handler();



	void H_init(GameManager *GM);
	void H_D_init();

	bool blocking_check();

	void make_rotate();
	void move_left();
	void move_right();
	void down();
	void drop();

	int* push_map_render();

	void H_test_print();



};

