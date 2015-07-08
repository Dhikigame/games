typedef struct{//メニュー用の座標、項目
	int a, b;       //座標
	char name[128]; //項目
} MenuElement_t;

GLOBAL double logorate;//タイトルロゴの大きさ
GLOBAL int big;//拡大縮小アニメーション作るために必要なフラグ
//GLOBAL int Count = 0;