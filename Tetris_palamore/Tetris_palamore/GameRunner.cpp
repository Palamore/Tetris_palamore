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

		start = GetTickCount();

		if (_kbhit()) {
			//		cout << "kbhit executed" << endl;
			get_KB_input();
			UI_renew_render();
		}

		//	cout << "kbhit over" << endl;




		if (interval > 0.7) {
			interval -= 0.7;
			//		cout << "interval executed" << endl;

			tmp = HD.down();
			if (tmp) {

				GM.renew_map(HD.get_x() + 1, HD.get_y() + 1, HD.get_Current_block().get_block());
				GM.line_clear();
				GM.slot_rotate();
				HD.H_init(&GM);
			}

			UI_renew_render();


		}

		end = GetTickCount();

		//		cout << start << endl;

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
	case 100:            // ���� Ű
		HD.drop();
		break;
	}



}

