#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif

#include <windows.h>
#include "DxLib.h"

#include "func.h"
#include "Menu.h"
#include "box.h"
/*
#include <stdlib.h>
#include <math.h>
#include <time.h>*/
#define PI 3.141592654

/*namespace Menuinfo{

	enum Menutype{
		Title = 1,
		Eas,//2
		Nor,//3
		Har,//4
		Res,//5
		Hel//6
	};
}*/
GLOBAL char Key[256];

GLOBAL int Menucount;

//GLOBAL int Count = 0;

GLOBAL int FontHandle;
GLOBAL int Handle;//��ʂœ������|�C���^FREE�f��
GLOBAL int Draw;//�w�iFREE�f��
GLOBAL int Draw2;//�w�iFREE�f��
GLOBAL int box;//�����ŕ`�����󔠂̊G�i���蕳�j
GLOBAL int nobox;
GLOBAL int yesbox;
GLOBAL int bombbox;
GLOBAL int Green;
GLOBAL int White;


GLOBAL int x, y;//�|�C���^���W

/*GLOBAL Menuinfo::Menutype Menucount;*/

GLOBAL int boxopen[6];

GLOBAL int game;//game��0�̂Ƃ����񂽂�A1�̂Ƃ��ӂ��A2�̂Ƃ��ނ�������


