#include "GameManager.h"



GameManager::GameManager()
{
	InsertNewBlock();
	PopBlock();
}


void GameManager::InsertNewBlock()
{
	mBlockContainer.push(make_unique<Block>());
}

void GameManager::PopBlock()
{
	mBlock = move(mBlockContainer.front());
	mBlockContainer.pop();
	InsertNewBlock();
}


void GameManager::ClearLine()
{
	vector<int> v;
	int fullLine[MAP_WIDTH];
	for (int i = 0; i < MAP_WIDTH; i++)
		fullLine[i] = 1;
	for (int i = 0; i < MAP_HEIGHT; i++) {
		if (memcmp(mCurrentMap[i], fullLine, MAP_WIDTH * sizeof(int)) == 0) {
			v.push_back(i);
			mScore += 100;
		}
	}
	DownLines(v);
}

void GameManager::DownLines(vector<int> v)
{
	auto iter = v.begin();
	int size = v.size();
	int empty[MAP_WIDTH];
	memset(empty, 0, MAP_WIDTH * sizeof(int));
	for (int i = 0; i < size; i++) {
		for (int j = (*iter) - 1; j >= 0; j--) {
			memcpy(mCurrentMap[j + 1], mCurrentMap[j], MAP_WIDTH * sizeof(int));
		}
		memcpy(mCurrentMap[0], empty, MAP_WIDTH * sizeof(int));
		iter++;
	}
}

void GameManager::UpdateMap(int x, int y, int blockValue[])
{
	int index = 0;
	for (int i = y - 1; i < y + 3; i++) { // x,y의 최소값은 1이기때문에 인덱스값 보정.
		for (int j = x - 1; j < x + 3; j++) {
			if (blockValue[index])
				mCurrentMap[i][j] = 1;
			index++;
		}
	}
}

unique_ptr<Block> GameManager::GetBlock()
{
	return move(mBlock);
}


int* GameManager::GetMapValue()
{
	return *mCurrentMap; //주소값만 넘어가면 된다.
}