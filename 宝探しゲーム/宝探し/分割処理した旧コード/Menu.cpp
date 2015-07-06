#include "GV.h"


void Menu(){

	MenuElement_t MenuElement[4] = {
		{ 170, 300, "かんたん" }, // タグの中身の順番で格納される。
		{ 280, 300, "ふつう" },
		{ 380, 300, "むずかしい" },
		{ 280, 350, "ヘルプ" },
	};
	int SelectNum = 0;

	DrawRotaGraph(320, 240, 1.0, 0.0, Draw, TRUE);
	DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	DrawStringToHandle(50, 140, "            宝探しゲーム", White, FontHandle);
	DrawFormatString(130, 450, Green, "どれかに選択してスペースキーを押してね！(矢印キー移動）");
	DrawFormatString( 50, 450, Green, "座標[%d,%d]", x, y ); 

	for (int i = 0; i<4; i++){ // メニュー項目を描画
		DrawFormatString(MenuElement[i].a, MenuElement[i].b, GetColor(255, 255, 255), MenuElement[i].name);
	}
	if (x >= 165 && x <= 310 && y >= 290 && 320 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
		Boxset();//空箱、宝箱等の場所の位置を決める
		infor = "   ";
		game = 0;
		Menucount = 2;
	}
	if (x >= 275 && x <= 335 && y >= 290 && 320 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
		Boxset();//空箱、宝箱等の場所の位置を決める
		infor = "   ";
		game = 1;
		Menucount = 3;
	}
	if (x >= 375 && x <= 470 && y >= 290 && 320 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
		Boxset();//空箱、宝箱等の場所の位置を決める
		infor = "   ";
		game = 2;
		Menucount = 4;
	}
	if (x >= 275 && x <= 335 && y >= 345 && 375 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
		Menucount = 6;
	}
}