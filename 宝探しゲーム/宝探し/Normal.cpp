#include "GV.h"



void Normal(){

	if (boxcount == 0){
		for (i = 0; i <= 2; i++){
			for (j = 0; j <= 2; j++){
					boxstoreN[i][j] = box;//1ゲームごとに初期に”閉じた宝箱”をセット
			}
		}
	}
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw2, TRUE);
	/*
	宝箱を描画　右が配列の場合の配置
	□　□　□　[0][0] [0][1] [0][2]
	□　□　□　[1][0] [1][1] [1][2]
	□　□　□  [2][0] [2][1] [2][2]
	*/
	for (i = 0; i <= 2; i++){
		k = 130*i;
		for (j = 0; j <= 2; j++){
			l = 200 * j;
			if (j== 0)
				DrawRotaGraph(120+l, 90+k, 0.8, 0.0, boxstoreN[i][j], TRUE);
			if (j== 1)
				DrawRotaGraph(120+l, 90+k, 0.8, 0.0, boxstoreN[i][j], TRUE);
			if (j == 2)
				DrawRotaGraph(120+l, 90+k, 0.8, 0.0, boxstoreN[i][j], TRUE);
		}
	}
	/*デバッグ用　Boxsetのランダム配置
	if (Key[KEY_INPUT_A] == 1){
		BoxsetN();
	}
	*/

	//DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);

	//デバッグ用　boxopenNの配置確認
	//DrawFormatString(50, 450, Green, "座標[%d,%d]", x, y);
	//DrawFormatString(250, 420, White, "%d %d %d", boxopenN[0][0], boxopenN[0][1], boxopenN[0][2]);
	//DrawFormatString(250, 440, White, "%d %d %d", boxopenN[1][0], boxopenN[1][1], boxopenN[1][2]);
	//DrawFormatString(250, 460, White, "%d %d %d", boxopenN[2][0], boxopenN[2][1], boxopenN[2][2]);
	//DrawFormatString(300, 460, White, "%d %d", i, j);
	
	DrawFormatString(280, 20, Green, "%s", infor);//ヒント出力　近くに反応！または遠くに反応！
	DrawFormatString(35, 415, White, "%d/10回目", gamecount);//１０回ゲーム行ったときの何回か
	DrawFormatString(35, 435, White, "おてつき　%d/2", ote);//おてつきは２回まで(実装変更されました)
	//1はyesboxのときの乱数、0はnoboxのときの乱数(かんたんとは実装が違う)

	if (boxKeystoreN[0][0] == 0)
		DrawStringToHandle(95, 45, "Qキー", White, FontBoxHandleN);
	else if (boxKeystoreN[0][0] == 1)
		DrawStringToHandle(95, 30, "Qキー", White, FontBoxHandleN);
	if (boxKeystoreN[0][1] == 0)
		DrawStringToHandle(295, 45, "Wキー", White, FontBoxHandleN);
	else if (boxKeystoreN[0][1] == 1)
		DrawStringToHandle(295, 30, "Wキー", White, FontBoxHandleN);
	if (boxKeystoreN[0][2] == 0)
		DrawStringToHandle(495, 45, "Eキー", White, FontBoxHandleN);
	else if (boxKeystoreN[0][2] == 1)
		DrawStringToHandle(495, 30, "Eキー", White, FontBoxHandleN);

	if (boxKeystoreN[1][0] == 0)
		DrawStringToHandle(95, 175, "Aキー", White, FontBoxHandleN);
	else if (boxKeystoreN[1][0] == 1)
		DrawStringToHandle(95, 160, "Aキー", White, FontBoxHandleN);
	if (boxKeystoreN[1][1] == 0)
		DrawStringToHandle(295, 175, "Sキー", White, FontBoxHandleN);
	else if (boxKeystoreN[1][1] == 1)
		DrawStringToHandle(295, 160, "Sキー", White, FontBoxHandleN);
	if (boxKeystoreN[1][2] == 0)
		DrawStringToHandle(495, 175, "Dキー", White, FontBoxHandleN);
	else if (boxKeystoreN[1][2] == 1)
		DrawStringToHandle(495, 160, "Dキー", White, FontBoxHandleN);

	if (boxKeystoreN[2][0] == 0)
		DrawStringToHandle(95, 305, "Zキー", White, FontBoxHandleN);
	else if (boxKeystoreN[2][0] == 1)
		DrawStringToHandle(95, 290, "Zキー", White, FontBoxHandleN);
	if (boxKeystoreN[2][1] == 0)
		DrawStringToHandle(295, 305, "Xキー", White, FontBoxHandleN);
	else if (boxKeystoreN[2][1] == 1)
		DrawStringToHandle(295, 290, "Xキー", White, FontBoxHandleN);
	if (boxKeystoreN[2][2] == 0)
		DrawStringToHandle(495, 305, "Cキー", White, FontBoxHandleN);
	else if (boxKeystoreN[2][2] == 1)
		DrawStringToHandle(495, 290, "Cキー", White, FontBoxHandleN);

	//それぞれキーで選択したときyesboxかnoboxか判定し、おてつきの場合はinforでヒント出す
	if (Key[KEY_INPUT_Q] == 1 && boxflag == 0){

		if (boxopenN[0][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[0][0] = yesbox;
			yes = 1;
		}
		if (boxopenN[0][0] == 0){
			boxstoreN[0][0] = nobox;
		}
		boxcount++;
		boxKeystoreN[0][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_Q] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][1] == 1 || boxopenN[1][0] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[0][0] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}


	if (Key[KEY_INPUT_W] == 1 && boxflag == 0){

		if (boxopenN[0][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[0][1] = yesbox;
			yes = 1;
		}
		if (boxopenN[0][1] == 0){
			boxstoreN[0][1] = nobox;
		}
		boxcount++;
		boxKeystoreN[0][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_W] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][0] == 1 || boxopenN[1][1] == 1 || boxopenN[0][2] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[0][1] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}

	if (Key[KEY_INPUT_E] == 1 && boxflag == 0){

		if (boxopenN[0][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[0][2] = yesbox;
			yes = 1;
		}
		if (boxopenN[0][2] == 0){
			boxstoreN[0][2] = nobox;
		}
		boxcount++;
		boxKeystoreN[0][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_E] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][1] == 1 || boxopenN[1][2] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[0][2] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}

	if (Key[KEY_INPUT_A] == 1 && boxflag == 0){

		if (boxopenN[1][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[1][0] = yesbox;
			yes = 1;
		}
		if (boxopenN[1][0] == 0){
			boxstoreN[1][0] = nobox;
		}
		boxcount++;
		boxKeystoreN[1][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_A] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][0] == 1 || boxopenN[1][1] == 1 || boxopenN[2][0] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[1][0] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}

	if (Key[KEY_INPUT_S] == 1 && boxflag == 0){

		if (boxopenN[1][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[1][1] = yesbox;
			yes = 1;
		}
		if (boxopenN[1][1] == 0){
			boxstoreN[1][1] = nobox;
		}
		boxcount++;
		boxKeystoreN[1][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_S] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][1] == 1 || boxopenN[1][0] == 1 || boxopenN[1][2] == 1 || boxopenN[2][1] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[1][1] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}

	if (Key[KEY_INPUT_D] == 1 && boxflag == 0){

		if (boxopenN[1][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[1][2] = yesbox;
			yes = 1;
		}
		if (boxopenN[1][2] == 0){
			boxstoreN[1][2] = nobox;
		}
		boxcount++;
		boxKeystoreN[1][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_D] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[1][1] == 1 || boxopenN[0][2] == 1 || boxopenN[2][2] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[1][2] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}

	if (Key[KEY_INPUT_Z] == 1 && boxflag == 0){

		if (boxopenN[2][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[2][0] = yesbox;
			yes = 1;
		}
		if (boxopenN[2][0] == 0){
			boxstoreN[2][0] = nobox;
		}
		boxcount++;
		boxKeystoreN[2][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_Z] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[1][0] == 1 || boxopenN[2][1] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[2][0] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}

	if (Key[KEY_INPUT_X] == 1 && boxflag == 0){

		if (boxopenN[2][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[2][1] = yesbox;
			yes = 1;
		}
		if (boxopenN[2][1] == 0){
			boxstoreN[2][1] = nobox;
		}
		boxcount++;
		boxKeystoreN[2][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_X] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[2][0] == 1 || boxopenN[1][1] == 1 || boxopenN[2][2] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[2][1] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}

	if (Key[KEY_INPUT_C] == 1 && boxflag == 0){

		if (boxopenN[2][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[2][2] = yesbox;
			yes = 1;
		}
		if (boxopenN[2][2] == 0){
			boxstoreN[2][2] = nobox;
		}
		boxcount++;
		boxKeystoreN[2][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_C] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[2][1] == 1 || boxopenN[1][2] == 1){
				infor = "近くに反応！"; ote++;
			}
			else if (boxopenN[2][2] == 1)
				infor = " ";
			else
				infor = "遠くに反応！"; ote++;
		}
	}

	//yesbox見つけた場合とおてつきすべて使って見つからなかった場合に文字列を出力
	if (yes == 1 && boxcount == 1 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "宝箱発見！（Enterキーで進む）");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetN();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			boxKeystoreN[0][0] = 0;
			boxKeystoreN[0][1] = 0;
			boxKeystoreN[0][2] = 0;
			boxKeystoreN[1][0] = 0;
			boxKeystoreN[1][1] = 0;
			boxKeystoreN[1][2] = 0;
			boxKeystoreN[2][0] = 0;
			boxKeystoreN[2][1] = 0;
			boxKeystoreN[2][2] = 0;
		}
	}

	if (yes == 1 && boxcount >= 2 && boxcount <= 3 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "宝箱は見つかったよ！（Enterキーで進む）");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetN();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			boxKeystoreN[0][0] = 0;
			boxKeystoreN[0][1] = 0;
			boxKeystoreN[0][2] = 0;
			boxKeystoreN[1][0] = 0;
			boxKeystoreN[1][1] = 0;
			boxKeystoreN[1][2] = 0;
			boxKeystoreN[2][0] = 0;
			boxKeystoreN[2][1] = 0;
			boxKeystoreN[2][2] = 0;
		}
	}

	if (yes == 0 && boxcount == 3 && x >= -99999 && y >= -99999){
		if (musicstop == 0)
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
		boxflag = 1;
		musicstop = 1;
		DrawFormatString(200, 450, Green, "宝箱は見つからなかった・・・（Enterキーで進む）");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetN();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			ote = 0;
			gamecount++;
			infor = "   ";
			musicstop = 0;
			boxKeystoreN[0][0] = 0;
			boxKeystoreN[0][1] = 0;
			boxKeystoreN[0][2] = 0;
			boxKeystoreN[1][0] = 0;
			boxKeystoreN[1][1] = 0;
			boxKeystoreN[1][2] = 0;
			boxKeystoreN[2][0] = 0;
			boxKeystoreN[2][1] = 0;
			boxKeystoreN[2][2] = 0;
		}
	}

	//10回ゲーム終わったら結果画面に移行
	if (gamecount == 11){
		Menucount = 5;
	}

}