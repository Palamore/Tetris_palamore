#pragma once

#include "value.h"
class Block
{
public:
	Block();
	~Block() = default;

	int* GetBlockValue();
	void Rotate();
	void RotateReverse();

private:
	int block[16] = { 0, };
};

