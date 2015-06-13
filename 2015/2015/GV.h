#ifdef GLOBAL_INSTANCE
#define GLOBAL
#else
#define GLOBAL extern
#endif



#include <windows.h>
#include "DxLib.h"
#include "func.h"
#include "struct.h"

GLOBAL int Key[256];

GLOBAL pointer_t pointer;
GLOBAL set_t set;
GLOBAL number_t number;
GLOBAL score_t score;

GLOBAL int Two;
GLOBAL int Four;
GLOBAL int Eight;
GLOBAL int Sixteen;
GLOBAL int Thirtytwo;
GLOBAL int Sixtyfour;
GLOBAL int Onehundred_twentyeight;
GLOBAL int Twohundred_fiftysix;
GLOBAL int Fivehundred_twelve;
GLOBAL int Thousand_twentyfour;
GLOBAL int Two_thousand_fortyeight;

GLOBAL int main;
GLOBAL int white;
GLOBAL int Green;

GLOBAL int first;
GLOBAL int add;

GLOBAL int left,right,up,down;//動かした後に、もう一度同じ方向に動かしてもマスに数字が増えないようにするためのフラグ
GLOBAL int add_left,add_right,add_up,add_down;//動かして数字の位置動かない＆数字の大きさも変わらないときにif(add==1)を起こす変数
GLOBAL int add_leftx,add_rightx,add_upx,add_downx;//動かして数字の位置動くまたは数字の大きさも変わるときにif(add==1)を起こさない変数

