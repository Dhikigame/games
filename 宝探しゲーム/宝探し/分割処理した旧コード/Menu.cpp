#include "GV.h"


void Menu(){

	MenuElement_t MenuElement[4] = {
		{ 170, 300, "���񂽂�" }, // �^�O�̒��g�̏��ԂŊi�[�����B
		{ 280, 300, "�ӂ�" },
		{ 380, 300, "�ނ�������" },
		{ 280, 350, "�w���v" },
	};
	int SelectNum = 0;

	DrawRotaGraph(320, 240, 1.0, 0.0, Draw, TRUE);
	DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	DrawStringToHandle(50, 140, "            ��T���Q�[��", White, FontHandle);
	DrawFormatString(130, 450, Green, "�ǂꂩ�ɑI�����ăX�y�[�X�L�[�������ĂˁI(���L�[�ړ��j");
	DrawFormatString( 50, 450, Green, "���W[%d,%d]", x, y ); 

	for (int i = 0; i<4; i++){ // ���j���[���ڂ�`��
		DrawFormatString(MenuElement[i].a, MenuElement[i].b, GetColor(255, 255, 255), MenuElement[i].name);
	}
	if (x >= 165 && x <= 310 && y >= 290 && 320 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
		Boxset();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
		infor = "   ";
		game = 0;
		Menucount = 2;
	}
	if (x >= 275 && x <= 335 && y >= 290 && 320 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
		Boxset();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
		infor = "   ";
		game = 1;
		Menucount = 3;
	}
	if (x >= 375 && x <= 470 && y >= 290 && 320 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
		Boxset();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
		infor = "   ";
		game = 2;
		Menucount = 4;
	}
	if (x >= 275 && x <= 335 && y >= 345 && 375 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
		Menucount = 6;
	}
}