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
GLOBAL int FontBoxHandle;//ゲーム中○キーとある文字の大きさの変更（かんたん）
GLOBAL int FontBoxHandleN;//ゲーム中○キーとある文字の大きさの変更（ふつう）
GLOBAL int FontBoxHandleH;//ゲーム中○キーとある文字の大きさの変更（むずかしい）
GLOBAL int logo;//タイトルロゴ
GLOBAL int Handle;//画面で動かすポインタFREE素材
GLOBAL int Draw;//背景FREE素材
GLOBAL int Draw2;//背景FREE素材
GLOBAL int box;//自分で描いた宝箱の絵（下手糞）
GLOBAL int nobox;//空の宝箱
GLOBAL int yesbox;//宝の宝箱
GLOBAL int bombbox;//爆弾の宝箱（まだこれを使ったゲームをできていない）
GLOBAL int Green;//文字の色が緑
GLOBAL int White;//文字の色が白

GLOBAL int gamemusic;
GLOBAL int boxopensound;
GLOBAL int boxfoundsound;


GLOBAL int x, y;//ポインタ座標

/*GLOBAL Menuinfo::Menutype Menucount;*/

GLOBAL int game;//gameが0のときかんたん、1のときふつう、2のときむずかしい

GLOBAL Score_t score;//スコア構造体

GLOBAL int musicstop;//1回だけ箱開けるときの効果音鳴らすためのフラグ