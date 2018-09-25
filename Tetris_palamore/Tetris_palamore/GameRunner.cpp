#include "GameRunner.h"



GameRunner::GameRunner()
{

	HD.H_init(&GM);

}


GameRunner::~GameRunner()
{
}

void GameRunner::UI_renew_render()
{
	

	HD.H_D_init(&GM);

	UC.get_Map_value(&HD);
	
	UC.Render();

}

void GameRunner::Run()
{

	while (true) {

		if (_kbhit()) {
			cout << "kbhit executed" << endl;
			get_KB_input();
			UI_renew_render();
		}

	//	cout << "kbhit over" << endl;


		start = GetTickCount();

		if (interval > 0.1) {
			interval -= 0.1;
			cout << "interval executed" << endl;

			if (HD.down()) {
				
				GM.renew_map(HD.get_x(), HD.get_y(), HD.get_Current_block().get_block());
				GM.line_clear();
				GM.slot_rotate();

			}

			UI_renew_render();


		}

		end = GetTickCount();

		gap_time = (end - start) / (double)1000;
		interval += gap_time;



	}
	

}

void GameRunner::get_KB_input()
{
	kb_input = _getch();
	switch (kb_input) {
	default:
		break;
	case 72:            // �� ����Ű
		HD.make_rotate();  //�ȵ��ư�.
		break;
	case 75:            // ���� ����Ű
		HD.move_left();
		break;
	case 77:            // ������ ����Ű
		HD.move_right();
		break;
	case 80:            // �Ʒ��� ����Ű
		HD.down();
		break;
	case 10:            // ���� Ű
		HD.drop();
		break;
	}



}

