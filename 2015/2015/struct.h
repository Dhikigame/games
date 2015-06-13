//マウス用のx,y軸
typedef struct{
	int x,y;
}pointer_t;
//数字を配列セットするための[x][y],4x4のマスセットbox[4][4]
typedef struct{
	int x,y;
	int box[4][4];
}set_t;
//number2,4,8...,2048までの数字
typedef struct{
	int box[4][4];
}number_t;

typedef struct{
	int box[4][4];
	int total;
}score_t;
