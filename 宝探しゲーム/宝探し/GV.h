#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif

#include <windows.h>
#include "DxLib.h"

#include "FPS.h"
#include "func.h"
#include "Menu.h"
#include "box.h"
#include "score.h"

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
GLOBAL int FontMenuHandle;
GLOBAL int FontBoxHandle;//�Q�[�������L�[�Ƃ��镶���̑傫���̕ύX�i���񂽂�j
GLOBAL int FontBoxHandleN;//�Q�[�������L�[�Ƃ��镶���̑傫���̕ύX�i�ӂ��j
GLOBAL int FontBoxHandleH;//�Q�[�������L�[�Ƃ��镶���̑傫���̕ύX�i�ނ��������j
GLOBAL int logo;//�^�C�g�����S
GLOBAL int Handle;//��ʂœ������|�C���^FREE�f��
GLOBAL int Draw;//�w�iFREE�f��
GLOBAL int Draw2;//�w�iFREE�f��
GLOBAL int box;//�����ŕ`�����󔠂̊G�i���蕳�j
GLOBAL int nobox;//��̕�
GLOBAL int yesbox;//��̕�
GLOBAL int bombbox;//���e�̕󔠁i�܂�������g�����Q�[�����ł��Ă��Ȃ��j
GLOBAL int Green;//�����̐F����
GLOBAL int White;//�����̐F����

GLOBAL int gamemusic;
GLOBAL int boxopensound;
GLOBAL int boxfoundsound;


GLOBAL int x, y;//�|�C���^���W

/*GLOBAL Menuinfo::Menutype Menucount;*/

GLOBAL int game;//game��0�̂Ƃ����񂽂�A1�̂Ƃ��ӂ��A2�̂Ƃ��ނ�������

GLOBAL Score_t score;//�X�R�A�\����

GLOBAL int musicstop;//1�񂾂����J����Ƃ��̌��ʉ��炷���߂̃t���O