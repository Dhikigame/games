#include "GV.h"

void init(){
	Menucount = 1;
	/*�����l��1��Menu�֐������s����悤�ɐݒ�
	    case 1:Menu();	Menucount = 1
		case 2:Easy();	Menucount = 2
		case 3:Normal();Menucount = 3
		case 4:Hard();	Menucount = 4
		case 5:Result();Menucount = 5
		case 6:Help();	Menucount = 6
		*/
	boxcount = 0;//���񔠂��J�������J�E���g
	boxflag = 0;//�󔠂͌���������I���@���ɏo���瑼�̔����J���Ȃ����邽�߂̃t���O
	yes = 0;//yesbox���������Ƃ���yes=1�ɂ��ĕ󔠂͌���������I�ƕ\��
	hit = 0;//����yesbox���J������
	gamecount = 1;//10��Q�[�������Ƃ��̉���
	ote = 0;//���Ă��̉�
	x = 320, y = 240;//�|�C���^�������W
	musicstop = 0;//1�񂾂����J����Ƃ��̌��ʉ��炷���߂̃t���O
}
