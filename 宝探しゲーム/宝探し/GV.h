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
GLOBAL int Handle;//âÊñ Ç≈ìÆÇ©Ç∑É|ÉCÉìÉ^FREEëfçﬁ
GLOBAL int Draw;//îwåiFREEëfçﬁ
GLOBAL int Draw2;//îwåiFREEëfçﬁ
GLOBAL int box;//é©ï™Ç≈ï`Ç¢ÇΩïÛî†ÇÃäGÅiâ∫éËï≥Åj
=======
GLOBAL int Handle;//ÁîªÈù¢„ÅßÂãï„Åã„Åô„Éù„Ç§„É≥„ÇøFREEÁ¥†Êùê
GLOBAL int Draw;//ËÉåÊôØFREEÁ¥†Êùê
GLOBAL int Draw2;//ËÉåÊôØFREEÁ¥†Êùê
GLOBAL int box;//Ëá™ÂàÜ„ÅßÊèè„ÅÑ„ÅüÂÆùÁÆ±„ÅÆÁµµÔºà‰∏ãÊâãÁ≥ûÔºâ
>>>>>>> 157b8d7b7241ac808c8a5854df35c691c81ecd3a
GLOBAL int nobox;
GLOBAL int yesbox;
GLOBAL int bombbox;
GLOBAL int Green;
GLOBAL int White;


GLOBAL int x, y;//„Éù„Ç§„É≥„ÇøÂ∫ßÊ®ô

/*GLOBAL Menuinfo::Menutype Menucount;*/

<<<<<<< HEAD
GLOBAL int game;//gameÇ™0ÇÃÇ∆Ç´Ç©ÇÒÇΩÇÒÅA1ÇÃÇ∆Ç´Ç”Ç¬Ç§ÅA2ÇÃÇ∆Ç´ÇﬁÇ∏Ç©ÇµÇ¢
=======
GLOBAL int boxopen[6];

GLOBAL int game;//game„Åå0„ÅÆ„Å®„Åç„Åã„Çì„Åü„Çì„ÄÅ1„ÅÆ„Å®„Åç„Åµ„Å§„ÅÜ„ÄÅ2„ÅÆ„Å®„Åç„ÇÄ„Åö„Åã„Åó„ÅÑ
>>>>>>> 157b8d7b7241ac808c8a5854df35c691c81ecd3a


