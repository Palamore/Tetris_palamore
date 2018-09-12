#pragma once

#include "value.h"
class Block
{
	int block[16] = { 0, };
	int b;
public:
	Block();

	~Block();

	int* get_block();
	void rotate();
	void test_printing();
};

