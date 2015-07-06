#include "GV.h"

void init(){
	Menucount = 1;
	/*初期値は1でMenu関数を実行するように設定
	    case 1:Menu();	Menucount = 1
		case 2:Easy();	Menucount = 2
		case 3:Normal();Menucount = 3
		case 4:Hard();	Menucount = 4
		case 5:Result();Menucount = 5
		case 6:Help();	Menucount = 6
		*/
	boxcount = 0;//何回箱を開いたかカウント
	boxflag = 0;//宝箱は見つかったよ！等　下に出たら他の箱を開けなくするためのフラグ
	yes = 0;//yesboxを見つけたときにyes=1にして宝箱は見つかったよ！と表示
	hit = 0;//何回yesboxを開けたか
	gamecount = 1;//10回ゲームしたときの何回か
	ote = 0;//おてつきの回数
	x = 320, y = 240;//ポインタ初期座標
	musicstop = 0;//1回だけ箱開けるときの効果音鳴らすためのフラグ
}
