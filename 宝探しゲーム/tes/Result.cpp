#include "GV.h"


void Result(){
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw, TRUE);
	//DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	//DrawFormatString( 50, 450, Green, "座標[%d,%d]", x, y );
	DrawFormatString(120, 145, White, "宝箱を見つけた回数　%d/10", hit);
	if (0 <= hit&&hit <= 3){
		DrawStringToHandle(120, 240, "残念！もっと頑張ろう！", White, FontHandle);
		if (game == 0){
			DrawFormatString(20, 330, White, "もう一度かんたんでゲームを始めるなら右シフトキーを、");
		}
		if (game == 1){
			DrawFormatString(20, 330, White, "もう一度ふつうでゲームを始めるなら右シフトキーを、");
		}
		if (game == 2){
			DrawFormatString(20, 330, White, "もう一度むずかしいでゲームを始めるなら右シフトキーを、");
		}
		DrawFormatString(20, 350, White, "タイトルに戻るならEnterキーを押してね");

		if (Key[KEY_INPUT_RETURN] == 1){
			hit = 0;
			gamecount = 1;
			Menucount = 1;
		}
		if (Key[KEY_INPUT_RSHIFT] == 1){
			hit = 0;
			gamecount = 1;
			if (game == 0){
				Menucount = 2;
			}
			if (game == 1){
				Menucount = 3;
			}
			if (game == 2){
				Menucount = 4;
			}
		}
	}

	if (4 <= hit&&hit <= 6){
		DrawStringToHandle(120, 240, "まあまあだね！この調子！", White, FontHandle);
		if (game == 0){
			DrawFormatString(20, 330, White, "もう一度かんたんでゲームを始めるなら右シフトキーを、");
		}
		if (game == 1){
			DrawFormatString(20, 330, White, "もう一度ふつうでゲームを始めるなら右シフトキーを、");
		}
		if (game == 2){
			DrawFormatString(20, 330, White, "もう一度むずかしいでゲームを始めるなら右シフトキーを、");
		}
		DrawFormatString(20, 350, White, "タイトルに戻るならEnterキーを押してね");

		if (Key[KEY_INPUT_RETURN] == 1){
			hit = 0;
			gamecount = 1;
			Menucount = 1;
		}
		if (Key[KEY_INPUT_RSHIFT] == 1){
			hit = 0;
			gamecount = 1;
			if (game == 0){
				Menucount = 2;
			}
			if (game == 1){
				Menucount = 3;
			}
			if (game == 2){
				Menucount = 4;
			}
		}
	}

	if (7 <= hit&&hit <= 9){
		DrawStringToHandle(50, 180, "かなり良いね！パーフェクト目指せ！", White, FontHandle);
		DrawStringToHandle(20, 220, "ふつう、むずかしいのレベルにも挑戦してね ", White, FontHandle);
		if (game == 0){
			DrawFormatString(20, 330, White, "もう一度かんたんでゲームを始めるなら右シフトキーを、");
		}
		if (game == 1){
			DrawFormatString(20, 330, White, "もう一度ふつうでゲームを始めるなら右シフトキーを、");
		}
		if (game == 2){
			DrawFormatString(20, 330, White, "もう一度むずかしいでゲームを始めるなら右シフトキーを、");
		}
		DrawFormatString(20, 350, White, "タイトルに戻るならEnterキーを押してね");


		if (Key[KEY_INPUT_RETURN] == 1){
			hit = 0;
			gamecount = 1;
			Menucount = 1;
		}
		if (Key[KEY_INPUT_RSHIFT] == 1){
			hit = 0;
			gamecount = 1;
			if (game == 0){
				Menucount = 2;
			}
			if (game == 1){
				Menucount = 3;
			}
			if (game == 2){
				Menucount = 4;
			}
		}
	}

	if (hit == 10){
		DrawStringToHandle(50, 180, "パーフェクト！君は宝箱マスターだ！", White, FontHandle);
		DrawStringToHandle(20, 220, "ふつう、むずかしいのレベルにも挑戦してね", White, FontHandle);
		if (game == 0){
			DrawFormatString(20, 330, White, "もう一度かんたんでゲームを始めるなら右シフトキーを、");
		}
		if (game == 1){
			DrawFormatString(20, 330, White, "もう一度ふつうでゲームを始めるなら右シフトキーを、");
		}
		if (game == 2){
			DrawFormatString(20, 330, White, "もう一度むずかしいでゲームを始めるなら右シフトキーを、");
		}
		DrawFormatString(20, 350, White, "タイトルに戻るならEnterキーを押してね");


		if (Key[KEY_INPUT_RETURN] == 1){
			hit = 0;
			gamecount = 1;
			Menucount = 1;
		}
		if (Key[KEY_INPUT_RSHIFT] == 1){
			hit = 0;
			gamecount = 1;
			if (game == 0){
				Menucount = 2;
			}
			if (game == 1){
				Menucount = 3;
			}
			if (game == 2){
				Menucount = 4;
			}
		}
	}
}