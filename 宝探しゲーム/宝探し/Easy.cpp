#include "GV.h"


void Easy(){
	//1ゲームごとに初期に”閉じた宝箱”をセット
	if (boxcount == 0){
		boxstore1 = box;
		boxstore2 = box;
		boxstore3 = box;
		boxstore4 = box;
		boxstore5 = box;
		boxstore6 = box;
	}
	/*
	宝箱を描画　右が配列の場合の配置
	□　□　□　[0] [1] [2]
	□　□　□　[3] [4] [5]
	*/
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw2, TRUE);
	DrawRotaGraph(120, 110, 1.0, 0.0, boxstore1, TRUE);
	DrawRotaGraph(320, 110, 1.0, 0.0, boxstore2, TRUE);
	DrawRotaGraph(520, 110, 1.0, 0.0, boxstore3, TRUE);
	DrawRotaGraph(120, 300, 1.0, 0.0, boxstore4, TRUE);
	DrawRotaGraph(320, 300, 1.0, 0.0, boxstore5, TRUE);
	DrawRotaGraph(520, 300, 1.0, 0.0, boxstore6, TRUE);
	
	//DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	//デバッグ用　boxopenの配置確認
	//DrawFormatString( 0, 450, White, "座標[%d,%d],%d,%d,%d,%d,%d,%d",
	//	x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
	DrawFormatString(280, 20, Green, "%s", infor);//ヒント出力　近くに反応！または遠くに反応！
	DrawFormatString(35, 415, White, "%d/10回目", gamecount);//１０回ゲーム行ったときの何回か
	DrawFormatString(35, 435, White, "おてつき　%d/2", ote);//おてつきは２回まで
	
	if (boxKeystore[0] == 0)
		DrawStringToHandle(90, 50, "Aキー", White, FontBoxHandle);
	else if(boxKeystore[0] == 1)
		DrawStringToHandle(90, 35, "Aキー", White, FontBoxHandle);
	
	if (boxKeystore[1] == 0)
		DrawStringToHandle(290, 50, "Sキー", White, FontBoxHandle);
	else if (boxKeystore[1] == 1)
		DrawStringToHandle(290, 35, "Sキー", White, FontBoxHandle);

	if (boxKeystore[2] == 0)
		DrawStringToHandle(490, 50, "Dキー", White, FontBoxHandle);
	else if (boxKeystore[2] == 1)
		DrawStringToHandle(490, 35, "Dキー", White, FontBoxHandle);

	if (boxKeystore[3] == 0)
		DrawStringToHandle(90, 240, "Zキー", White, FontBoxHandle);
	else if (boxKeystore[3] == 1)
		DrawStringToHandle(90, 225, "Zキー", White, FontBoxHandle);

	if (boxKeystore[4] == 0)
		DrawStringToHandle(290, 240, "Xキー", White, FontBoxHandle);
	else if (boxKeystore[4] == 1)
		DrawStringToHandle(290, 225, "Xキー", White, FontBoxHandle);

	if (boxKeystore[5] == 0)
		DrawStringToHandle(490, 240, "Cキー", White, FontBoxHandle);
	else if (boxKeystore[5] == 1)
		DrawStringToHandle(490, 225, "Cキー", White, FontBoxHandle);

	//67502085はyesboxのときの乱数、67436548はnoboxのときの乱数(新しい環境で制作しなおしたので値が変わっている)

	//それぞれキーで選択したときyesboxかnoboxか判定し、おてつきの場合はinforでヒント出す
	if (Key[KEY_INPUT_A] == 1 && boxflag == 0){
		
		if (boxopen[0] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore1 = yesbox;
			yes = 1;
		}
		if (boxopen[0] == 67436548){
			boxstore1 = nobox;
		}
		boxcount++;
		boxKeystore[0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_A] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[1] == 67502085 || boxopen[3] == 67502085){
				infor = "近くに反応！"; ote++;
			}
			if (boxopen[2] == 67502085 || boxopen[4] == 67502085 || boxopen[5] == 67502085){
				infor = "遠くに反応！"; ote++;
			}

		}
	}


	if (Key[KEY_INPUT_S] == 1 && boxflag == 0){
		
		if (boxopen[1] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore2 = yesbox;
			yes = 1;
		}
		if (boxopen[1] == 67436548){
			boxstore2 = nobox;
		}
		boxcount++;
		boxKeystore[1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_S] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[0] == 67502085 || boxopen[2] == 67502085 || boxopen[4] == 67502085){
				infor = "近くに反応！"; ote++;
			}
			if (boxopen[3] == 67502085 || boxopen[5] == 67502085){
				infor = "遠くに反応！"; ote++;
			}

		}
	}

	if (Key[KEY_INPUT_D] == 1 && boxflag == 0){
		
		if (boxopen[2] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore3 = yesbox;
			yes = 1;
		}
		if (boxopen[2] == 67436548){
			boxstore3 = nobox;
		}
		boxcount++;
		boxKeystore[2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_D] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[1] == 67502085 || boxopen[5] == 67502085){
				infor = "近くに反応！"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[3] == 67502085 || boxopen[4] == 67502085){
				infor = "遠くに反応！"; ote++;
			}

		}
	}

	if (Key[KEY_INPUT_Z] == 1 && boxflag == 0){
		
		if (boxopen[3] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore4 = yesbox;
			yes = 1;
		}
		if (boxopen[3] == 67436548){
			boxstore4 = nobox;
		}
		boxcount++;
		boxKeystore[3] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_Z] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[0] == 67502085 || boxopen[4] == 67502085){
				infor = "近くに反応！"; ote++;
			}
			if (boxopen[1] == 67502085 || boxopen[2] == 67502085 || boxopen[5] == 67502085){
				infor = "遠くに反応！"; ote++;
			}

		}
	}

	if (Key[KEY_INPUT_X] == 1 && boxflag == 0){
		
		if (boxopen[4] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore5 = yesbox;
			yes = 1;
		}
		if (boxopen[4] == 67436548){
			boxstore5 = nobox;
		}
		boxcount++;
		boxKeystore[4] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_X] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[1] == 67502085 || boxopen[3] == 67502085 || boxopen[5] == 67502085){
				infor = "近くに反応！"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[2] == 67502085){
				infor = "遠くに反応！"; ote++;
			}

		}
	}

	if (Key[KEY_INPUT_C] == 1 && boxflag == 0){
		
		if (boxopen[5] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore6 = yesbox;
			yes = 1;
		}
		if (boxopen[5] == 67436548){
			boxstore6 = nobox;
		}
		boxcount++;
		boxKeystore[5] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_C] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[2] == 67502085 || boxopen[4] == 67502085){
				infor = "近くに反応！"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[1] == 67502085 || boxopen[3] == 67502085){
				infor = "遠くに反応！"; ote++;
			}

		}
	}

	//yesbox見つけた場合とおてつきすべて使って見つからなかった場合に文字列を出力
	if (yes == 1 && boxcount == 1 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "宝箱発見！（Enterキーで進む）");
		if (Key[KEY_INPUT_RETURN] == 1){
			Boxset();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			boxKeystore[0] = 0;//宝箱を開けたときに"○キー"の位置を変更する配列(初期化)
			boxKeystore[1] = 0;
			boxKeystore[2] = 0;
			boxKeystore[3] = 0;
			boxKeystore[4] = 0;
			boxKeystore[5] = 0;
		}
	}

	if (yes == 1 && boxcount >= 2 && boxcount <= 3 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "宝箱は見つかったよ！（Enterキーで進む）");
		if (Key[KEY_INPUT_RETURN] == 1){
			Boxset();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			boxKeystore[0] = 0;//宝箱を開けたときに"○キー"の位置を変更する配列(初期化)
			boxKeystore[1] = 0;
			boxKeystore[2] = 0;
			boxKeystore[3] = 0;
			boxKeystore[4] = 0;
			boxKeystore[5] = 0;
		}
	}

	if (yes == 0 && boxcount == 3 && x >= -99999 && y >= -99999){
		if(musicstop == 0)
		PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
		boxflag = 1;
		musicstop = 1;
		DrawFormatString(200, 450, Green, "宝箱は見つからなかった・・・（Enterキーで進む）");
		if (Key[KEY_INPUT_RETURN] == 1){
			Boxset();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			ote = 0;
			gamecount++;
			infor = "   ";
			musicstop = 0;
			boxKeystore[0] = 0;//宝箱を開けたときに"○キー"の位置を変更する配列(初期化)
			boxKeystore[1] = 0;
			boxKeystore[2] = 0;
			boxKeystore[3] = 0;
			boxKeystore[4] = 0;
			boxKeystore[5] = 0;
		}
	}

	//10回ゲーム終わったら結果画面に移行
	if (gamecount == 11){
		Menucount = 5;
	}
}