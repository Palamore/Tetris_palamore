#include "Handler.h"

void Handler::SetNextBlock(GameManager *GM)  // ���ο� ��� init
{
	mBlock = GM->GetBlock();
	memcpy(mCurrentMap, GM->GetMapValue(), MAP_WIDTH * MAP_HEIGHT * sizeof(int));
	mBlockPosition.x = 0;
	mBlockPosition.y = 0;
}

void Handler::UpdateRealtimeMap(GameManager *GM)  // �� �����Ӹ��� RealtimeMap�� ��� �׷��� ������
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
	if (direction == 1) { //����

		for (int i = mBlockPosition.y; i < mBlockPosition.y + 4; i++) {
			for (int j = mBlockPosition.x; j < mBlockPosition.x + 4; j++) {
				if (blockValue[index] == 1) {
					if (j == 0) //���� ���� ������ ���
						return true;
					if (mCurrentMap[i][j - 1] == 1) { // ���ʿ� �̹� ���� ���� ���� ���
						return true;
					}
				}
				index++;
			}
		}
	}
	else { //������
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
	mBlock->Rotate();   //�ϴ� rotate.
	GetBlockIntoMap(); // �����̼� �� ����� �� ������ ������ ���
	GetBlockIntoMap(); // �� ������ �о�ֱ�
	if (!ValidateRotation()) { // rotate ���� ��ġ�� ����� ���� ��� �����·� ����
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

// ����� ���� ���� ������ Running���� down�� ���ϰ��� ���� ����.
int Handler::MoveDown()    // down�� �����ϴ� ���� ���� down�ϴ��� ���� �����ϴ��� ����.
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


