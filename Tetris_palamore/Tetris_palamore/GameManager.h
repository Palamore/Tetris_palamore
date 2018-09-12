#pragma once

#include "value.h"
#include "Block.h"

class GameManager
{
	queue<Block>	Block_q;
	Block*			Block_maker;
	Block*			Next_block;
	Block*			Current_handled_block;
	int				Current_map[15][10];
	int score = 0;
public:
	GameManager();
	~GameManager();

	void slot_rotate();

	void line_clear();
	void renew_map(int x, int y, int block[]);

	Block* get_current_block();
	Block* get_next_block();
	int* get_map();


	void test_print();
};

