#include "GV.h"

//yesboxまたはnoboxをせっていするためのモジュール
//Easy
void Boxset(){
	//6つの箱に0〜5までそれぞれかぶらない違う値を入れる　参考サイト http://q.hatena.ne.jp/1307178107 
	for (i = 0; i <= 5; i++){
		flag = TRUE;
		while (flag){
			flag = FALSE;
			boxopen[i] = GetRand(5);
			for (j = 0; j<i; j++){
				if (boxopen[j] == boxopen[i]){
					flag = TRUE;
					break;
				}
			}
		}
	}

	if (boxopen[0] == 0){
		boxopen[0] = yesbox;
	}
	if (1 <= boxopen[0] && boxopen[0] <= 5){
		boxopen[0] = nobox;
	}

	if (boxopen[1] == 0){
		boxopen[1] = yesbox;
	}
	if (1 <= boxopen[1] && boxopen[1] <= 5){
		boxopen[1] = nobox;
	}


	if (boxopen[2] == 0){
		boxopen[2] = yesbox;
	}
	if (1 <= boxopen[2] && boxopen[2] <= 5){
		boxopen[2] = nobox;
	}


	if (boxopen[3] == 0){
		boxopen[3] = yesbox;
	}
	if (1 <= boxopen[3] && boxopen[3] <= 5){
		boxopen[3] = nobox;
	}


	if (boxopen[4] == 0){
		boxopen[4] = yesbox;
	}
	if (1 <= boxopen[4] && boxopen[4] <= 5){
		boxopen[4] = nobox;
	}


	if (boxopen[5] == 0){
		boxopen[5] = yesbox;
	}
	if (1 <= boxopen[5] && boxopen[5] <= 5){
		boxopen[5] = nobox;
	}

}
//Normal
void BoxsetN(){
	
	for (i = 0; i <= 2; i++){
		for (j = 0; j <= 2; j++){
				boxopenN[i][j] = 0;//初期化
			}
		}

	//3×3でセット
		i = GetRand(2);
		j = GetRand(2);
		boxopenN[i][j] = 1;

}
//Hard
void BoxsetH(){
	//4×4でセット
	i = GetRand(3);
	j = GetRand(3);

	boxopenN[i][j] = 1;//boxopenHが1のものがyesboxになる

	for (i = 0; i <= 3; i++){
		for (j = 0; j <= 3; j++){
			if (boxopenN[i][j] != 1)
				boxopenN[i][j] = 0;//boxopenHが1以外のものがnoboxになる
		}
	}
}