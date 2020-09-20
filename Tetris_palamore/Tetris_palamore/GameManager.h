#pragma once

#include "value.h"
#include "Block.h"

class GameManager
{

public:
	GameManager();
	~GameManager() = default;

	void InsertNewBlock();
	void PopBlock();
	void ClearLine();			   // 블록이 떨어진 후 라인이 완성되면 클리어.
	void DownLines(vector<int> v); // 라인 클리어 후 윗 라인 한칸씩 아래로 내리기
	void UpdateMap(int x, int y, int blockValue[]);
	unique_ptr<Block> GetBlock();
	int* GetMapValue();

private:
	queue<unique_ptr<Block>> mBlockContainer;
	unique_ptr<Block> mBlock;
	int	mCurrentMap[15][10] = { 0, };
	int mScore = 0;
};