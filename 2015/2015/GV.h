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

GLOBAL int left,right,up,down;//����������ɁA������x���������ɓ������Ă��}�X�ɐ����������Ȃ��悤�ɂ��邽�߂̃t���O
GLOBAL int add_left,add_right,add_up,add_down;//�������Đ����̈ʒu�����Ȃ��������̑傫�����ς��Ȃ��Ƃ���if(add==1)���N�����ϐ�
GLOBAL int add_leftx,add_rightx,add_upx,add_downx;//�������Đ����̈ʒu�����܂��͐����̑傫�����ς��Ƃ���if(add==1)���N�����Ȃ��ϐ�

