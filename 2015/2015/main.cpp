#define GLOBAL_INSTANCE
#include "GV.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
    
    ChangeWindowMode(TRUE);//ウィンドウモード
    if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//初期化と裏画面化

	int Menu = 1;
	load();
	ini();

    while(ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey(Key)==0 && Key[KEY_INPUT_ESCAPE]==0){
          //↑ﾒｯｾｰｼﾞ処理         ↑画面をｸﾘｱ    　　　     ↑入力状態を保存　　　　　　　↑ESCが押されていない

		if(Key[ KEY_INPUT_SPACE ]==1 || Key[ KEY_INPUT_RETURN ]==1)
         Menu = 2;

		switch(Menu){
		 case 1:back_graph();break;
		 case 2:main_graph();break;
		 }
        ScreenFlip();//裏画面反映関数
    }

    DxLib_End();//DXライブラリ終了処理
    return 0;
}