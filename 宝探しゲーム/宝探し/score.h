typedef struct{//スコア計算用構造体
	int boxcount;  //boxcountによってスコアを変更　boxcount=1なら20点　boxcount=2なら10点　boxcount=3なら5点
	int total; //スコアの合計
	int flag;//スコア増加の無限ループ防止用のフラグ
} Score_t;