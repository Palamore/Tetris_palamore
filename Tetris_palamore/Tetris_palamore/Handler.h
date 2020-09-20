#pragma once

#include "value.h"
#include "Block.h"
#include "GameManager.h"


class Handler
{
public:
	Handler() = default;
	~Handler() = default;

	void SetNextBlock(GameManager *GM);
	void UpdateRealtimeMap(GameManager *GM);
	bool CheckBlocking();
	bool CheckSideBlocking(int a);
	void GetBlockIntoMap();
	bool ValidateRotation();
	void Rotate();
	void MoveLeft();
	void MoveRight();
	int  MoveDown();
	void Drop();
	Block GetCurrentBlock();
	int GetX(), GetY();
	int* GetRealtimeMapValue();

private:
	unique_ptr<Block> mBlock;
	_pos		mBlockPosition;
	int			mRealtimeMap[15][10] = { 0, };
	int			mCurrentMap[15][10] = { 0, };
};

