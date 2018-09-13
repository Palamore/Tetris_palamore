#include "GameManager.h"



GameManager::GameManager()
{
	for (int i = 0; i < 3; i++) {
		Block_maker = new Block();
		Block_q.push(*Block_maker);
	}
	Current_handled_block = new Block();//최초 slot_rotate 실행시의 delete를 위한 더미블럭
	slot_rotate();

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 10; j++) {
			Current_map[i][j] = 0;
		}
	}
//	Current_map[0][0] = 1; 

}


GameManager::~GameManager()
{
}

void GameManager::slot_rotate()
{
	delete Current_handled_block;	//기존 핸들에 있던 블럭 딜리트
	Block_maker = new Block();		//새로운 블럭 생성
	Block_q.push(*Block_maker);		//블럭을 큐안에 푸시
	Current_handled_block = &Block_q.front();	// 큐의 가장 앞쪽 블럭을 핸들포인터로 지정
	Block_q.pop();					//큐의 가장 앞쪽 블럭을 팝.
	Next_block = &Block_q.front();  //다음 블럭을 next block 포인터로 지정.
}

void GameManager::line_clear()
{
	int cleared_cnt = 0;
	int empty[10] = { 0, 0, 0, 0, 0, 0, 0, 0, 0, 0 };
	int tmp[10] = { 1, 1, 1, 1, 1, 1, 1, 1, 1, 1 };
	for (int i = 0; i < 15; i++) {
		if (memcmp(Current_map[i], tmp, 40) == 0) {
			cleared_cnt++;
			score += 100;
		}
	}
	for (int i = 0; i < cleared_cnt; i++) {
		for (int j = 14; j >= 0; j--) {
			memcpy(Current_map[j + 1], Current_map[j], 40);
			//	Current_map[j + 1] = Current_map[j];
		}
		memcpy(Current_map[0], empty, 40);
	}

}

void GameManager::renew_map(int x, int y, int block[])
{
	int tmp = 0;
	for (int i = y - 1; i < y + 3; i++) { // x,y의 최소값은 1이기때문에 인덱스값 보정.
		for (int j = x - 1; j < x + 3; j++) {
			if (block[tmp])
				Current_map[i][j] = 1;
			tmp++;
		}
	}

}

Block * GameManager::get_current_block()
{
	return Current_handled_block;
}

Block * GameManager::get_next_block()
{
	return Next_block;
}

int * GameManager::get_map()
{
	return *Current_map;		//받을때 포인터로 받은 후 새로운 배열 생성.그 배열로 memcpy해줄것
}

void GameManager::test_print()
{
	int *tmp;
	tmp = Current_handled_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];  // 현재 핸들블럭 출력
		if (i % 4 == 3)
			cout << endl;
	}
	cout << endl;
	tmp = Next_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];			  // 다음 블럭 출력
		if (i % 4 == 3)
			cout << endl;
	}
	cout << endl;
	Current_handled_block->rotate();
	tmp = Current_handled_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];  // 로테이트 후 출력
		if (i % 4 == 3)
			cout << endl;
	}

	slot_rotate();

	tmp = Current_handled_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];  // 현재 핸들블럭 출력
		if (i % 4 == 3)
			cout << endl;
	}
	cout << endl;
	tmp = Next_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];			  // 다음 블럭 출력
		if (i % 4 == 3)
			cout << endl;
	}



}
