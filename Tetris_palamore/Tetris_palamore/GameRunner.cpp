#include "GameRunner.h"

GameRunner::GameRunner()
	: start(0)
	, end(0)
	, mInput(0)
	, mBlockTouchedFlag(0)
{
	HD.SetNextBlock(&GM);
}

void GameRunner::RenderMap()
{
	HD.UpdateRealtimeMap(&GM);
	RD.GetMapValue(&HD);
	RD.Render();
}

void GameRunner::Run()
{
	double gapTime = 0.0;
	double interval = 0.0;
	while (true) {

		start = GetTickCount();

		if (_kbhit()) {
			GetKeyboardInput();
			RenderMap();
		}
		if (interval > 0.7) {
			interval -= 0.7;
			mBlockTouchedFlag = HD.MoveDown(); //Flag가 1리턴 시 블럭이 쌓임.
			if (mBlockTouchedFlag) { 
				GM.UpdateMap(HD.GetX() + 1, HD.GetY() + 1, HD.GetCurrentBlock().GetBlockValue());
				GM.ClearLine();
				GM.PopBlock();
				HD.SetNextBlock(&GM);
			}
			RenderMap();
		}
		end = GetTickCount();

		gapTime = (end - start) / 1000.0;
		interval += gapTime;
	}
}

void GameRunner::GetKeyboardInput()
{
	mInput = _getch();
	switch (mInput) {
	default:
		break;
	case 72:            // 위 방향키
		HD.Rotate();  
		break;
	case 75:            // 왼쪽 방향키
		HD.MoveLeft();
		break;
	case 77:            // 오른쪽 방향키
		HD.MoveRight();
		break;
	case 80:            // 아래쪽 방향키
		HD.MoveDown();
		break;
	case 32:            // 스페이스 키
		HD.Drop();
		break;
	}
}

