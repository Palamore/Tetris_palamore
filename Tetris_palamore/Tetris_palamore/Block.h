#pragma once

#include "value.h"
class Block
{
public:
	Block();
	~Block() = default;

	inline int* GetBlockValue();
	void Rotate();
	void RotateReverse();

private:
	int block[16] = { 0, };
};

int* Block::GetBlockValue()
{
	return block;
}
