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
	//DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	//DrawStringToHandle(50, 140, "            宝探しゲーム", White, FontHandle);
	DrawStringToHandle(270, 200, "var2.1", White, FontHandle);
	DrawFormatString(230, 450, Green, "どれかキーを押してね！");
	//（デバッグ用）DrawFormatString( 50, 450, Green, "座標[%d,%d]", x, y ); 

	DrawRotaGraph(320, 240, logorate, 0.0, logo, TRUE); //タイトルロゴの描画
	/*if (big == 0){
		logorate += 0.01;
		if (logorate == 1.25)
			big = 1;
	}
	if (big == 1){
		logorate -= 0.01;
		if (logorate == 1.15)
			big = 0;
	}タイトルロゴを拡大縮小するアニメーション作ろうとしたがうまくいってない*/

	DrawStringToHandle(170, 320, "Eキー", White, FontMenuHandle);
	DrawStringToHandle(280, 320, "Nキー", White, FontMenuHandle);
	DrawStringToHandle(380, 320, "Hキー", White, FontMenuHandle);
	//DrawStringToHandle(380, 335, "工事中", White, FontMenuHandle);
	DrawStringToHandle(280, 370, "Spaceキー", White, FontMenuHandle);

	for (int i = 0; i<4; i++){ // メニュー項目を描画
		DrawFormatString(MenuElement[i].a, MenuElement[i].b, GetColor(255, 255, 255), MenuElement[i].name);
	}
	/*if (x >= 165 && x <= 310 && y >= 290 && 320 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1){
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
	}*/
	if (Key[KEY_INPUT_E] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		Boxset();//空箱、宝箱等の場所の位置を決める
		infor = "   ";
		game = 0;
		Menucount = 2;
		for (i = 0; i <= 5; i++)
			boxKeystore[i] = 0;//宝箱を開けたときに"○キー"の位置を変更する配列（かんたん用)
	}
	if (Key[KEY_INPUT_N] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		BoxsetN();//空箱、宝箱等の場所の位置を決める 
		infor = "   ";
		game = 1;
		Menucount = 3;
		for (i = 0; i <= 2; i++){
			for (j = 0; j <= 2; j++){
				boxKeystoreN[i][j] = 0;//宝箱を開けたときに"○キー"の位置を変更する配列（ふつう用)
			}
		}
	}
	if (Key[KEY_INPUT_H] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		BoxsetH();//空箱、宝箱等の場所の位置を決める
		infor = "   ";
		game = 2;
		Menucount = 4;
		for (i = 0; i <= 3; i++){
			for (j = 0; j <= 3; j++){
				boxKeystoreH[i][j] = 0;//宝箱を開けたときに"○キー"の位置を変更する配列（むずかしい用)
			}
		}
	}
	if (Key[KEY_INPUT_SPACE] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		Menucount = 6;
	}
}