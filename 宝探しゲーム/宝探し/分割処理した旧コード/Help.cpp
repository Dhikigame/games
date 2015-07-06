#include "GV.h"

void Help(){
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw, TRUE);
	DrawFormatString(100, 50, White, "宝を探すゲームです。それ以外の何者でもないです。");
	DrawFormatString(100, 70, White, "自分の意思を頼りに宝を当ててみてください。");
	DrawFormatString(100, 100, White, "やさしい　:おてつき2回まで(少し運が必要なときもある)");
	DrawFormatString(100, 120, White, "ふつう　　:おてつき1回まで(ほぼ運が必要)");
	DrawFormatString(100, 140, White, "むずかしい:おてつきはゆるせん(運)");
	DrawFormatString(100, 170, White, "おてつきがある難易度に関しては");
	DrawFormatString(100, 190, White, "もし見つけられなくても上に　近くに反応!");
	DrawFormatString(100, 210, White, "または　遠くに反応!が表示されます。");
	DrawFormatString(100, 230, White, "近くにの場合は縦または横隣の宝箱に宝があり、");
	DrawFormatString(100, 250, White, "遠くにの場合は近くにの以外のところに宝があるわけです。");
	DrawFormatString(100, 280, White, "矢印キー：移動　スペースキー：宝箱を開く");
	DrawFormatString(200, 310, White, "スペースキーでタイトルに戻る");

	if (Key[KEY_INPUT_SPACE] == 1){
		Menucount = 1;
	}
}