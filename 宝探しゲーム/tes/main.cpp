#define GLOBAL_INSTANCE
#include "GV.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�

	ini();
	load();
	Menucount = 1;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0){
		ClsDrawScreen();
		
		if (Key[KEY_INPUT_RIGHT] >= 1){ // �E�L�[��������Ă�����
			x = x + 5;                       // �E�ֈړ�
		}
		if (Key[KEY_INPUT_DOWN] >= 1){ // ���L�[��������Ă�����
			y = y + 5;                       // ���ֈړ�
		}
		if (Key[KEY_INPUT_LEFT] >= 1){ // ���L�[��������Ă�����
			x = x - 5;                       // ���ֈړ�
		}
		if (Key[KEY_INPUT_UP] >= 1){ // ��L�[��������Ă�����
			y = y - 5;                      // ��ֈړ�
		}

		switch (Menucount){
		case 1:Menu(); break;
		case 2:Easy(); break;
		case 3:Normal(); break;
		case 4:Hard(); break;
		case 5:Result(); break;
		case 6:Help(); break;
		}

	}
	DxLib_End(); // DX���C�u�����I������
	return 0;
}







