#include "value.h"
#include "Block.h"
#include "GameManager.h"
#include "Handler.h"
#include "Renderer.h"
#include "GameRunner.h"


int main() {
	CONSOLE_CURSOR_INFO curInfo;
	GetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);
	curInfo.bVisible = 0;
	SetConsoleCursorInfo(GetStdHandle(STD_OUTPUT_HANDLE), &curInfo);

	GameRunner GR;
	GR.Run();

	return 0;
}