#include "GameManager.h"



GameManager::GameManager()
{
	for (int i = 0; i < 3; i++) {
		Block_maker = new Block();
		Block_q.push(*Block_maker);
	}
	Current_handled_block = new Block();//���� slot_rotate ������� delete�� ���� ���̺�
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
	delete Current_handled_block;	//���� �ڵ鿡 �ִ� �� ����Ʈ
	Block_maker = new Block();		//���ο� �� ����
	Block_q.push(*Block_maker);		//���� ť�ȿ� Ǫ��
	Current_handled_block = &Block_q.front();	// ť�� ���� ���� ���� �ڵ������ͷ� ����
	Block_q.pop();					//ť�� ���� ���� ���� ��.
	Next_block = &Block_q.front();  //���� ���� next block �����ͷ� ����.
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
	for (int i = y - 1; i < y + 3; i++) { // x,y�� �ּҰ��� 1�̱⶧���� �ε����� ����.
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
	return *Current_map;		//������ �����ͷ� ���� �� ���ο� �迭 ����.�� �迭�� memcpy���ٰ�
}

void GameManager::test_print()
{
	int *tmp;
	tmp = Current_handled_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];  // ���� �ڵ�� ���
		if (i % 4 == 3)
			cout << endl;
	}
	cout << endl;
	tmp = Next_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];			  // ���� �� ���
		if (i % 4 == 3)
			cout << endl;
	}
	cout << endl;
	Current_handled_block->rotate();
	tmp = Current_handled_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];  // ������Ʈ �� ���
		if (i % 4 == 3)
			cout << endl;
	}

	slot_rotate();

	tmp = Current_handled_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];  // ���� �ڵ�� ���
		if (i % 4 == 3)
			cout << endl;
	}
	cout << endl;
	tmp = Next_block->get_block();
	for (int i = 0; i < 16; i++) {
		cout << tmp[i];			  // ���� �� ���
		if (i % 4 == 3)
			cout << endl;
	}



}
