GLOBAL int i, j, k, l,flag;

GLOBAL int boxopen[6];//	���̒��g�̃t���O�i���񂽂�j 0�Ȃ�yesbox�A1�`5�Ȃ�nobox
GLOBAL int boxopenN[3][3];//���̒��g�̃t���O�i�ӂ��j  1�Ȃ�yesbox�A0�Ȃ�nobox
GLOBAL int boxopenH[4][4];//���̒��g�̃t���O�i�ނ��������j  1�Ȃ�yesbox�A0�Ȃ�nobox

GLOBAL int boxstore1;//���̏��(���񂽂�p)�@�z��ɂ���Ηǂ���(ry
GLOBAL int boxstore2;
GLOBAL int boxstore3;
GLOBAL int boxstore4;
GLOBAL int boxstore5;
GLOBAL int boxstore6;
GLOBAL int boxstoreN[3][3]; //���̏��(�ӂ��p)
GLOBAL int boxstoreH[4][4];	//���̏��(�ނ��������p)

GLOBAL int boxKeystore[6];//    Key�������ꂽ���ǂ�������t���O�i���񂽂�p�j
GLOBAL int boxKeystoreN[3][3];//Key�������ꂽ���ǂ�������t���O�i�ӂ��p�j
GLOBAL int boxKeystoreH[4][4];//Key�������ꂽ���ǂ�������t���O�i�ނ��������p�j

GLOBAL char *infor;
GLOBAL int boxcount;//���񔠂��J�������J�E���g
GLOBAL int boxflag;//�󔠂͌���������I���@���ɏo���瑼�̔����J���Ȃ����邽�߂̃t���O
GLOBAL int yes;//yesbox���������Ƃ���yes=1�ɂ��ĕ󔠂͌���������I�ƕ\��
GLOBAL int hit;//����yesbox���J������
GLOBAL int gamecount;//10��Q�[�������Ƃ��̉���
GLOBAL int ote;//���Ă��̉�

GLOBAL int musicstop;//1�񂾂����J����Ƃ��̌��ʉ��炷���߂̃t���O