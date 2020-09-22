#include "Handler.h"

void Handler::SetNextBlock(GameManager *GM)  // 새로운 블록 init
{
	mBlock = GM->GetBlock();
	memcpy(mCurrentMap, GM->GetMapValue(), MAP_WIDTH * MAP_HEIGHT * sizeof(int));
	mBlockPosition.x = 0;
	mBlockPosition.y = 0;
}

void Handler::UpdateRealtimeMap(GameManager *GM)  // 매 프레임마다 RealtimeMap에 블록 그래픽 덮어씌우기
{
	memcpy(mRealtimeMap, GM->GetMapValue(), MAP_WIDTH * MAP_HEIGHT * sizeof(int));
	int* blockValue = mBlock->GetBlockValue();
	int index = 0;
	for (int i = mBlockPosition.y; i < mBlockPosition.y + 4; i++) {
		for (int j = mBlockPosition.x; j < mBlockPosition.x + 4; j++) {
			if (blockValue[index] == 1)
				mRealtimeMap[i][j] = 1;
			index++;
		}
	}
}

bool Handler::CheckBlocking()
{
	int* blockValue = mBlock->GetBlockValue();
	int index = 0;
	for (int i = mBlockPosition.y; i < mBlockPosition.y + 4; i++) {
		for (int j = mBlockPosition.x; j < mBlockPosition.x + 4; j++) {
			if (blockValue[index] == 1) {
				if (i == 14) {
					return true;
				}
				if (mCurrentMap[i + 1][j] == 1) {
					return true;
				}
			}
			index++;
		}
	}
	return false;
}

bool Handler::CheckSideBlocking(int direction)
{
	int* blockValue = mBlock->GetBlockValue();
	int index = 0;
	if (direction == 1) { //왼쪽

		for (int i = mBlockPosition.y; i < mBlockPosition.y + 4; i++) {
			for (int j = mBlockPosition.x; j < mBlockPosition.x + 4; j++) {
				if (blockValue[index] == 1) {
					if (j == 0) //맵의 가장 왼쪽일 경우
						return true;
					if (mCurrentMap[i][j - 1] == 1) { // 왼쪽에 이미 쌓인 블럭이 있을 경우
						return true;
					}
				}
				index++;
			}
		}
	}
	else { //오른쪽
		for (int i = mBlockPosition.y; i < mBlockPosition.y + 4; i++) {
			for (int j = mBlockPosition.x; j < mBlockPosition.x + 4; j++) {
				if (blockValue[index] == 1) {
					if (j == 9)
						return true;
					if (mCurrentMap[i][j + 1] == 1) {
						return true;
					}
				}
				index++;
			}
		}
	}
	return false;
}

void Handler::GetBlockIntoMap()
{
	int* blockValue = mBlock->GetBlockValue();
	int index = 0;
	for (int i = mBlockPosition.y; i < mBlockPosition.y + 4; i++) {
		for (int j = mBlockPosition.x; j < mBlockPosition.x + 4; j++) {
			if (blockValue[index] == 1) {
				if (j < 0) {
					mBlockPosition.x++;
					return;
				}
				if (j > 9) {
					mBlockPosition.x--;
					return;
				}
			}
			index++;
		}
	}
}

bool Handler::ValidateRotation()
{
	int* blockValue = mBlock->GetBlockValue();
	int index = 0;
	for (int i = mBlockPosition.y; i < mBlockPosition.y + 4; i++) {
		for (int j = mBlockPosition.x; j < mBlockPosition.x + 4; j++) {
			if (blockValue[index] == 1) {
				if (mCurrentMap[i][j] == 1) {
					return false;
				}
			}
			index++;
		}
	}
	return true;
}

void Handler::Rotate()
{
	mBlock->Rotate();   //일단 rotate.
	GetBlockIntoMap(); // 로테이션 후 블록이 맵 밖으로 나갔을 경우
	GetBlockIntoMap(); // 맵 안으로 밀어넣기
	if (!ValidateRotation()) { // rotate 이후 겹치는 블록이 있을 경우 원상태로 복구
		mBlock->RotateReverse();
	}
}

void Handler::MoveLeft()
{
	if (!CheckSideBlocking(1))
		mBlockPosition.x--;
}

void Handler::MoveRight()
{
	if (!CheckSideBlocking(2))
		mBlockPosition.x++;
}

// 블록이 쌓인 후의 로직은 Running에서 down의 리턴값에 따라서 결정.
int Handler::MoveDown()    // down이 리턴하는 값에 따라서 down하느냐 맵을 갱신하느냐 결정.
{
	if (!CheckBlocking()) {
		mBlockPosition.y++;
		return 0;
	}
	else {
		cout << "Blocked !! " << endl;
		return 1;
	}
}

void Handler::Drop()
{
	while (!MoveDown());
}


