#define GLOBAL_INSTANCE
#include "GV.h"

int WINAPI WinMain( HINSTANCE hInstance, HINSTANCE hPrevInstance,LPSTR lpCmdLine, int nCmdShow ){
    
    ChangeWindowMode(TRUE);//�E�B���h�E���[�h
    if(DxLib_Init() == -1 || SetDrawScreen( DX_SCREEN_BACK )!=0) return -1;//�������Ɨ���ʉ�

	int Menu = 1;
	load();
	ini();

    while(ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey(Key)==0 && Key[KEY_INPUT_ESCAPE]==0){
          //��ү���ޏ���         ����ʂ�ر    �@�@�@     �����͏�Ԃ�ۑ��@�@�@�@�@�@�@��ESC��������Ă��Ȃ�

		if(Key[ KEY_INPUT_SPACE ]==1 || Key[ KEY_INPUT_RETURN ]==1)
         Menu = 2;

		switch(Menu){
		 case 1:back_graph();break;
		 case 2:main_graph();break;
		 }
        ScreenFlip();//����ʔ��f�֐�
    }

    DxLib_End();//DX���C�u�����I������
    return 0;
}