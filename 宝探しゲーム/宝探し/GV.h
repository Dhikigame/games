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
/*
#include <stdlib.h>
#include <math.h>
#include <time.h>*/
//#define PI 3.141592654

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
<<<<<<< HEAD
GLOBAL int FontMenuHandle;
GLOBAL int FontBoxHandle;
GLOBAL int FontBoxHandleN;
GLOBAL int Handle;//æÊÅ®©·|C^FREEfÞ
GLOBAL int Draw;//wiFREEfÞ
GLOBAL int Draw2;//wiFREEfÞ
GLOBAL int box;//©ªÅ`¢½ó ÌGiºè³j
=======
GLOBAL int Handle;//ç»é¢ã§åãããã¤ã³ã¿FREEç´ æ
GLOBAL int Draw;//èæ¯FREEç´ æ
GLOBAL int Draw2;//èæ¯FREEç´ æ
GLOBAL int box;//èªåã§æããå®ç®±ã®çµµï¼ä¸æç³ï¼
>>>>>>> 157b8d7b7241ac808c8a5854df35c691c81ecd3a
GLOBAL int nobox;
GLOBAL int yesbox;
GLOBAL int bombbox;
GLOBAL int Green;
GLOBAL int White;


GLOBAL int x, y;//ãã¤ã³ã¿åº§æ¨

/*GLOBAL Menuinfo::Menutype Menucount;*/

<<<<<<< HEAD
GLOBAL int game;//gameª0ÌÆ«©ñ½ñA1ÌÆ«ÓÂ¤A2ÌÆ«Þ¸©µ¢
=======
GLOBAL int boxopen[6];

GLOBAL int game;//gameã0ã®ã¨ãããããã1ã®ã¨ããµã¤ãã2ã®ã¨ãããããã
>>>>>>> 157b8d7b7241ac808c8a5854df35c691c81ecd3a


