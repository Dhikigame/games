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
	//DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	//DrawStringToHandle(50, 140, "            ��T���Q�[��", White, FontHandle);
	DrawStringToHandle(270, 200, "var2.1", White, FontHandle);
	DrawFormatString(230, 450, Green, "�ǂꂩ�L�[�������ĂˁI");
	//�i�f�o�b�O�p�jDrawFormatString( 50, 450, Green, "���W[%d,%d]", x, y ); 

	DrawRotaGraph(320, 240, logorate, 0.0, logo, TRUE); //�^�C�g�����S�̕`��
	/*if (big == 0){
		logorate += 0.01;
		if (logorate == 1.25)
			big = 1;
	}
	if (big == 1){
		logorate -= 0.01;
		if (logorate == 1.15)
			big = 0;
	}�^�C�g�����S���g��k������A�j���[�V������낤�Ƃ��������܂������ĂȂ�*/

	DrawStringToHandle(170, 320, "E�L�[", White, FontMenuHandle);
	DrawStringToHandle(280, 320, "N�L�[", White, FontMenuHandle);
	DrawStringToHandle(380, 320, "H�L�[", White, FontMenuHandle);
	//DrawStringToHandle(380, 335, "�H����", White, FontMenuHandle);
	DrawStringToHandle(280, 370, "Space�L�[", White, FontMenuHandle);

	for (int i = 0; i<4; i++){ // ���j���[���ڂ�`��
		DrawFormatString(MenuElement[i].a, MenuElement[i].b, GetColor(255, 255, 255), MenuElement[i].name);
	}
	/*if (x >= 165 && x <= 310 && y >= 290 && 320 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
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
	}*/
	if (Key[KEY_INPUT_E] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		Boxset();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
		infor = "   ";
		game = 0;
		Menucount = 2;
		for (i = 0; i <= 5; i++)
			boxKeystore[i] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��i���񂽂�p)
	}
	if (Key[KEY_INPUT_N] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		BoxsetN();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂� 
		infor = "   ";
		game = 1;
		Menucount = 3;
		for (i = 0; i <= 2; i++){
			for (j = 0; j <= 2; j++){
				boxKeystoreN[i][j] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��i�ӂ��p)
			}
		}
	}
	if (Key[KEY_INPUT_H] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		BoxsetH();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
		infor = "   ";
		game = 2;
		Menucount = 4;
		for (i = 0; i <= 3; i++){
			for (j = 0; j <= 3; j++){
				boxKeystoreH[i][j] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��i�ނ��������p)
			}
		}
	}
	if (Key[KEY_INPUT_SPACE] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		Menucount = 6;
	}
}