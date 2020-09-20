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
	void ClearLine();			   // ����� ������ �� ������ �ϼ��Ǹ� Ŭ����.
	void DownLines(vector<int> v); // ���� Ŭ���� �� �� ���� ��ĭ�� �Ʒ��� ������
	void UpdateMap(int x, int y, int blockValue[]);
	unique_ptr<Block> GetBlock();
	int* GetMapValue();

private:
	queue<unique_ptr<Block>> mBlockContainer;
	unique_ptr<Block> mBlock;
	int	mCurrentMap[15][10] = { 0, };
	int mScore = 0;
};