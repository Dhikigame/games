//�}�E�X�p��x,y��
typedef struct{
	int x,y;
}pointer_t;
//������z��Z�b�g���邽�߂�[x][y],4x4�̃}�X�Z�b�gbox[4][4]
typedef struct{
	int x,y;
	int box[4][4];
}set_t;
//number2,4,8...,2048�܂ł̐���
typedef struct{
	int box[4][4];
}number_t;

typedef struct{
	int box[4][4];
	int total;
}score_t;
