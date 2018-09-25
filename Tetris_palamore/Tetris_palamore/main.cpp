#include "value.h"
#include "Block.h"
#include "GameManager.h"
#include "Handler.h"
#include "UIContainer.h"
#include "GameRunner.h"


int main() {

	GameRunner GR;

	GR.Run();

/*
	GameManager GM;
	Handler HD;
	UIContainer UC;

	HD.H_init(&GM);
	HD.H_D_init(&GM);

//	HD.H_test_print();
	UC.get_Map_value(&HD);
	UC.Render();

	Sleep(1000);
	system("cls");

	HD.drop();

	HD.H_D_init(&GM);

	UC.get_Map_value(&HD);
	UC.Render();



/*
	for (int i = 0; i < 7; i++) {
		HD.down();
	}
	
	system("cls");

	HD.H_D_init(&GM);

	HD.H_test_print();

	Sleep(1000);
	for (int i = 0; i < 5; i++) {
		HD.down();
	}


	system("cls");

	HD.H_D_init(&GM);

	HD.H_test_print();

	Sleep(1000);
	HD.down();
	system("cls");
	HD.H_D_init(&GM);

	HD.H_test_print();

	*/


	return 0;
}