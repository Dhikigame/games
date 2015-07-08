#include "GV.h"


void Hard(){

	if (boxcount == 0){
		for (i = 0; i <= 3; i++){
			for (j = 0; j <= 3; j++){
				boxstoreH[i][j] = box;//1�Q�[�����Ƃɏ����Ɂh�����󔠁h���Z�b�g
			}
		}
	}
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw2, TRUE);

	/*
	�󔠂�`��@�E���z��̏ꍇ�̔z�u
	���@���@���@���@[0][0] [0][1] [0][2] [0][3]
	���@���@���@���@[1][0] [1][1] [1][2] [1][3]
	���@���@��  ���@[2][0] [2][1] [2][2] [2][3]
	���@���@���@���@[3][0] [3][1] [3][2] [3][3]
	*/

	for (i = 0; i <= 3; i++){
		k = 100 * i;
		for (j = 0; j <= 3; j++){
			l = 150 * j;
			if (j == 0)
				DrawRotaGraph(90 + l, 70 + k, 0.6, 0.0, boxstoreH[i][j], TRUE);
			if (j == 1)
				DrawRotaGraph(90 + l, 70 + k, 0.6, 0.0, boxstoreH[i][j], TRUE);
			if (j == 2)
				DrawRotaGraph(90 + l, 70 + k, 0.6, 0.0, boxstoreH[i][j], TRUE);
			if (j == 3)
				DrawRotaGraph(90 + l, 70 + k, 0.6, 0.0, boxstoreH[i][j], TRUE);
		}
	}

	//�f�o�b�O�p�@Boxset�̃����_���z�u
	/*
	if (Key[KEY_INPUT_A] == 1){
	BoxsetH();
	}
	*/
	//RSHIFT�L�[�Ń^�C�g���ɖ߂�
	if (Key[KEY_INPUT_RSHIFT] == 1){
		init();
	}

	DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	/*
	DrawFormatString(50, 450, Green, "���W[%d,%d]", x, y);
	DrawFormatString(250, 410, White, "%d %d %d %d", boxopenH[0][0], boxopenH[0][1], boxopenH[0][2], boxopenH[0][3]);
	DrawFormatString(250, 430, White, "%d %d %d %d", boxopenH[1][0], boxopenH[1][1], boxopenH[1][2], boxopenH[1][3]);
	DrawFormatString(250, 450, White, "%d %d %d %d", boxopenH[2][0], boxopenH[2][1], boxopenH[2][2], boxopenH[2][3]);
	DrawFormatString(250, 470, White, "%d %d %d %d", boxopenH[3][0], boxopenH[3][1], boxopenH[3][2], boxopenH[3][3]);
	DrawFormatString(330, 460, White, "%d %d", i, j);
	*/
	DrawFormatString(280, 20, Green, "%s", infor);//�q���g�o�́@�߂��ɔ����I�܂��͉����ɔ����I
	DrawFormatString(35, 415, White, "%d/10���", gamecount);//�P�O��Q�[���s�����Ƃ��̉���
	DrawFormatString(35, 435, White, "���Ă��@%d/2", ote);//���Ă��͂Q��܂�(�����ύX����܂���)
	DrawFormatString(550, 420, White, "�X�R�A");//�X�R�A�o��
	DrawFormatString(550, 440, White, "%d", score.total);//�X�R�A�o��
	//1��yesbox�̂Ƃ��̗����A0��nobox�̂Ƃ��̗���(���񂽂�Ƃ͎������Ⴄ)

	if (boxKeystoreH[0][0] == 0)
		DrawStringToHandle(70, 35, "1�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[0][0] == 1)
		DrawStringToHandle(70, 25, "1�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[0][1] == 0)
		DrawStringToHandle(220, 35, "2�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[0][1] == 1)
		DrawStringToHandle(220, 25, "2�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[0][2] == 0)
		DrawStringToHandle(370, 35, "3�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[0][2] == 1)
		DrawStringToHandle(370, 25, "3�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[0][3] == 0)
		DrawStringToHandle(520, 35, "4�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[0][3] == 1)
		DrawStringToHandle(520, 25, "4�L�[", White, FontBoxHandleH);

	if (boxKeystoreH[1][0] == 0)
		DrawStringToHandle(70, 135, "Q�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[1][0] == 1)
		DrawStringToHandle(70, 125, "Q�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[1][1] == 0)
		DrawStringToHandle(220, 135, "W�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[1][1] == 1)
		DrawStringToHandle(220, 125, "W�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[1][2] == 0)
		DrawStringToHandle(370, 135, "E�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[1][2] == 1)
		DrawStringToHandle(370, 125, "E�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[1][3] == 0)
		DrawStringToHandle(520, 135, "R�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[1][3] == 1)
		DrawStringToHandle(520, 125, "R�L�[", White, FontBoxHandleH);

	if (boxKeystoreH[2][0] == 0)
		DrawStringToHandle(70, 235, "A�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[2][0] == 1)
		DrawStringToHandle(70, 225, "A�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[2][1] == 0)
		DrawStringToHandle(220, 235, "S�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[2][1] == 1)
		DrawStringToHandle(220, 225, "S�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[2][2] == 0)
		DrawStringToHandle(370, 235, "D�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[2][2] == 1)
		DrawStringToHandle(370, 225, "D�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[2][3] == 0)
		DrawStringToHandle(520, 235, "F�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[2][3] == 1)
		DrawStringToHandle(520, 225, "F�L�[", White, FontBoxHandleH);

	if (boxKeystoreH[3][0] == 0)
		DrawStringToHandle(70, 335, "Z�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[3][0] == 1)
		DrawStringToHandle(70, 325, "Z�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[3][1] == 0)
		DrawStringToHandle(220, 335, "X�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[3][1] == 1)
		DrawStringToHandle(220, 325, "X�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[3][2] == 0)
		DrawStringToHandle(370, 335, "C�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[3][2] == 1)
		DrawStringToHandle(370, 325, "C�L�[", White, FontBoxHandleH);
	if (boxKeystoreH[3][3] == 0)
		DrawStringToHandle(520, 335, "V�L�[", White, FontBoxHandleH);
	else if (boxKeystoreH[3][3] == 1)
		DrawStringToHandle(520, 325, "V�L�[", White, FontBoxHandleH);

	//���ꂼ��L�[�őI�������Ƃ�yesbox��nobox�����肵�A���Ă��̏ꍇ��infor�Ńq���g�o��
	if (Key[KEY_INPUT_1] == 1 && boxflag == 0){

		if (boxopenH[0][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[0][0] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[0][0] == 0){
			boxstoreH[0][0] = nobox;
		}
		boxcount++;
		boxKeystoreH[0][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_1] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[0][1] == 1 || boxopenH[1][0] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[0][0] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_2] == 1 && boxflag == 0){

		if (boxopenH[0][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[0][1] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[0][1] == 0){
			boxstoreH[0][1] = nobox;
		}
		boxcount++;
		boxKeystoreH[0][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_2] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[0][0] == 1 || boxopenH[1][1] == 1 || boxopenH[0][2] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[0][1] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_3] == 1 && boxflag == 0){

		if (boxopenH[0][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[0][2] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[0][2] == 0){
			boxstoreH[0][2] = nobox;
		}
		boxcount++;
		boxKeystoreH[0][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_3] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[0][1] == 1 || boxopenH[1][2] == 1 || boxopenH[0][3] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[0][2] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_4] == 1 && boxflag == 0){

		if (boxopenH[0][3] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[0][3] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[0][3] == 0){
			boxstoreH[0][3] = nobox;
		}
		boxcount++;
		boxKeystoreH[0][3] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_4] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[0][2] == 1 || boxopenH[1][3] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[0][3] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_Q] == 1 && boxflag == 0){

		if (boxopenH[1][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[1][0] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[1][0] == 0){
			boxstoreH[1][0] = nobox;
		}
		boxcount++;
		boxKeystoreH[1][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_Q] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[0][0] == 1 || boxopenH[1][1] == 1 || boxopenH[2][0] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[1][0] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_W] == 1 && boxflag == 0){

		if (boxopenH[1][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[1][1] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[1][1] == 0){
			boxstoreH[1][1] = nobox;
		}
		boxcount++;
		boxKeystoreH[1][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_W] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[0][1] == 1 || boxopenH[1][0] == 1 || boxopenH[2][1] == 1 || boxopenH[1][2] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[1][1] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_E] == 1 && boxflag == 0){

		if (boxopenH[1][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[1][2] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[1][2] == 0){
			boxstoreH[1][2] = nobox;
		}
		boxcount++;
		boxKeystoreH[1][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_E] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[0][2] == 1 || boxopenH[1][1] == 1 || boxopenH[2][2] == 1 || boxopenH[1][3] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[1][2] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}


	if (Key[KEY_INPUT_R] == 1 && boxflag == 0){

		if (boxopenH[1][3] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[1][3] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[1][3] == 0){
			boxstoreH[1][3] = nobox;
		}
		boxcount++;
		boxKeystoreH[1][3] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_R] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[1][2] == 1 || boxopenH[0][3] == 1 || boxopenH[2][3] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[1][3] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_A] == 1 && boxflag == 0){

		if (boxopenH[2][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[2][0] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[2][0] == 0){
			boxstoreH[2][0] = nobox;
		}
		boxcount++;
		boxKeystoreH[2][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_A] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[1][0] == 1 || boxopenH[2][1] == 1 || boxopenH[3][0] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[2][0] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_S] == 1 && boxflag == 0){

		if (boxopenH[2][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[2][1] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[2][1] == 0){
			boxstoreH[2][1] = nobox;
		}
		boxcount++;
		boxKeystoreH[2][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_S] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[2][0] == 1 || boxopenH[1][1] == 1 || boxopenH[3][1] == 1 || boxopenH[2][2] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[2][1] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_D] == 1 && boxflag == 0){

		if (boxopenH[2][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[2][2] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[2][2] == 0){
			boxstoreH[2][2] = nobox;
		}
		boxcount++;
		boxKeystoreH[2][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_D] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[2][1] == 1 || boxopenH[1][2] == 1 || boxopenH[2][3] == 1 || boxopenH[3][2] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[2][2] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_F] == 1 && boxflag == 0){

		if (boxopenH[2][3] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[2][3] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[2][3] == 0){
			boxstoreH[2][3] = nobox;
		}
		boxcount++;
		boxKeystoreH[2][3] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_F] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[2][2] == 1 || boxopenH[1][3] == 1 || boxopenH[3][3] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[2][3] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_Z] == 1 && boxflag == 0){

		if (boxopenH[3][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[3][0] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[3][0] == 0){
			boxstoreH[3][0] = nobox;
		}
		boxcount++;
		boxKeystoreH[3][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_Z] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[2][0] == 1 || boxopenH[3][1] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[3][0] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_X] == 1 && boxflag == 0){

		if (boxopenH[3][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[3][1] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[3][1] == 0){
			boxstoreH[3][1] = nobox;
		}
		boxcount++;
		boxKeystoreH[3][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_X] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[3][0] == 1 || boxopenH[2][1] == 1 || boxopenH[3][2] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[3][1] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_C] == 1 && boxflag == 0){

		if (boxopenH[3][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[3][2] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[3][2] == 0){
			boxstoreH[3][2] = nobox;
		}
		boxcount++;
		boxKeystoreH[3][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_C] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[3][1] == 1 || boxopenH[2][2] == 1 || boxopenH[3][3] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[3][2] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_V] == 1 && boxflag == 0){

		if (boxopenH[3][3] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreH[3][3] = yesbox;
			yes = 1;
			score.flag = 1;
		}
		if (boxopenH[3][3] == 0){
			boxstoreH[3][3] = nobox;
		}
		boxcount++;
		boxKeystoreH[3][3] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_V] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenH[3][2] == 1 || boxopenH[2][3] == 1){
				infor = "�߂��ɔ����I"; //ote++;
			}
			else if (boxopenH[3][3] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	//yesbox�������ꍇ�Ƃ��Ă����ׂĎg���Č�����Ȃ������ꍇ�ɕ�������o��
	if (yes == 1 && boxcount == 1 && x >= -99999 && y >= -99999){
		boxflag = 1;
		if (boxcount == 1 && score.flag == 1){
			score.boxcount = 1;
			Score();
		}
		score.flag = 0;
		DrawFormatString(200, 450, Green, "�󔠔����I�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetH();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			musicstop = 0;
			for (i = 0; i <= 3; i++){
				for (j = 0; j <= 3; j++){
					boxKeystoreN[i][j] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��i�ӂ��p)
				}
			}
		}
	}

	if (yes == 1 && boxcount >= 2 && boxcount <= 3 && x >= -99999 && y >= -99999){
		boxflag = 1;
		if (boxcount == 2 && score.flag == 1){
			score.boxcount = 2;
			Score();
		}
		if (boxcount == 3 && score.flag == 1){
			score.boxcount = 3;
			Score();
		}
		score.flag = 0;
		DrawFormatString(200, 450, Green, "�󔠂͌���������I�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetH();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			musicstop = 0;
			for (i = 0; i <= 3; i++){
				for (j = 0; j <= 3; j++){
					boxKeystoreN[i][j] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��i�ӂ��p)
				}
			}
		}
	}

	if (yes == 0 && boxcount == 3 && x >= -99999 && y >= -99999){
		if (musicstop == 0)
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
		boxflag = 1;
		musicstop = 1;
		DrawFormatString(200, 450, Green, "�󔠂͌�����Ȃ������E�E�E�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetH();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			ote = 0;
			gamecount++;
			infor = "   ";
			musicstop = 0;
			for (i = 0; i <= 3; i++){
				for (j = 0; j <= 3; j++){
					boxKeystoreH[i][j] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��i�ނ��������p)
				}
			}
		}
	}

	if (gamecount == 11){
		Menucount = 5;
	}
}

