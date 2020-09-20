#include "Renderer.h"


void Renderer::GetMapValue(Handler *HD)
{
	memcpy(mRenderInfo, HD->GetRealtimeMapValue(), MAP_WIDTH * MAP_HEIGHT * sizeof(int));
}

void Renderer::Render()
{
	system("cls");
	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (mRenderInfo[i][j])
				cout << "бс";
			else
				cout << "бр";
		}
		cout << endl;
	}
}
