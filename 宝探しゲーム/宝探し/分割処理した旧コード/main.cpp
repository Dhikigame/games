#define GLOBAL_INSTANCE
#include "GV.h"



int WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int){
	ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen(DX_SCREEN_BACK); //ウィンドウモード変更と初期化と裏画面設定

	ini();
	load();
	Menucount = 1;

	while (ScreenFlip() == 0 && ProcessMessage() == 0 && ClearDrawScreen() == 0 && gpUpdateKey() == 0){
		ClsDrawScreen();
		
		if (Key[KEY_INPUT_RIGHT] >= 1){ // 右キーが押されていたら
			x = x + 5;                       // 右へ移動
		}
		if (Key[KEY_INPUT_DOWN] >= 1){ // 下キーが押されていたら
			y = y + 5;                       // 下へ移動
		}
		if (Key[KEY_INPUT_LEFT] >= 1){ // 左キーが押されていたら
			x = x - 5;                       // 左へ移動
		}
		if (Key[KEY_INPUT_UP] >= 1){ // 上キーが押されていたら
			y = y - 5;                      // 上へ移動
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
	DxLib_End(); // DXライブラリ終了処理
	return 0;
}







