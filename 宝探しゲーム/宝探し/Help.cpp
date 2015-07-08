#include "GV.h"

void Help(){
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw, TRUE);
	DrawFormatString(100, 50, White, "宝を探すゲームです。それ以外の何者でもないです。");
	DrawFormatString(100, 70, White, "自分の意思を頼りに宝を当ててみてください。");
	DrawFormatString(70, 100, White, "やさしい　:箱の数は6個、おてつき2回まで(少し運が必要なときもある)");
	DrawFormatString(70, 120, White, "ふつう　　:箱の数は9個、おてつき2回まで(ほぼ運が必要)");
	DrawFormatString(70, 140, White, "むずかしい:箱の数は16個、おてつき2回まで(運がかなり強い)");
	DrawFormatString(100, 190, White, "おてつきがある間は見つけられなくても上に「近くに反応!」");
	DrawFormatString(100, 210, White, "または　「遠くに反応!」が表示されます。");
	DrawFormatString(100, 230, White, "近くにの場合は縦または横隣の宝箱に宝があり、");
	DrawFormatString(100, 250, White, "遠くにの場合は近くにの以外のところに宝があるわけです。");
	DrawFormatString(270, 280, White, "～操作方法～");
	DrawFormatString(100, 300, White, "指定キー：宝箱を開く");
	DrawFormatString(100, 320, White, "右シフトキー：ゲーム途中タイトル画面に戻る");
	DrawFormatString(100, 340, White, "ESCキー：ゲーム終了");
	DrawFormatString(200, 380, White, "スペースキーでタイトルに戻る");

	if (Key[KEY_INPUT_SPACE] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		Menucount = 1;
	}
}