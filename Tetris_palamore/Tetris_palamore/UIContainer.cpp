#include "UIContainer.h"



UIContainer::UIContainer()
{
}


UIContainer::~UIContainer()
{
}

void UIContainer::get_Map_value(Handler *HD)
{
	memcpy(Map_value,HD->push_map_render(),600);

}

void UIContainer::Render()
{
	system("cls");

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			if (Map_value[i][j])
				cout << "бс";
			else
				cout << "бр";
		}
		cout << endl;
	}

}
