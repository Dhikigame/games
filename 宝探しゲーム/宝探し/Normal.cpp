#include "GV.h"



void Normal(){

	if (boxcount == 0){
		for (i = 0; i <= 2; i++){
			for (j = 0; j <= 2; j++){
					boxstoreN[i][j] = box;//1�Q�[�����Ƃɏ����Ɂh�����󔠁h���Z�b�g
			}
		}
	}
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw2, TRUE);
	/*
	�󔠂�`��@�E���z��̏ꍇ�̔z�u
	���@���@���@[0][0] [0][1] [0][2]
	���@���@���@[1][0] [1][1] [1][2]
	���@���@��  [2][0] [2][1] [2][2]
	*/
	for (i = 0; i <= 2; i++){
		k = 130*i;
		for (j = 0; j <= 2; j++){
			l = 200 * j;
			if (j== 0)
				DrawRotaGraph(120+l, 90+k, 0.8, 0.0, boxstoreN[i][j], TRUE);
			if (j== 1)
				DrawRotaGraph(120+l, 90+k, 0.8, 0.0, boxstoreN[i][j], TRUE);
			if (j == 2)
				DrawRotaGraph(120+l, 90+k, 0.8, 0.0, boxstoreN[i][j], TRUE);
		}
	}
	/*�f�o�b�O�p�@Boxset�̃����_���z�u
	if (Key[KEY_INPUT_A] == 1){
		BoxsetN();
	}
	*/

	//DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);

	//�f�o�b�O�p�@boxopenN�̔z�u�m�F
	//DrawFormatString(50, 450, Green, "���W[%d,%d]", x, y);
	//DrawFormatString(250, 420, White, "%d %d %d", boxopenN[0][0], boxopenN[0][1], boxopenN[0][2]);
	//DrawFormatString(250, 440, White, "%d %d %d", boxopenN[1][0], boxopenN[1][1], boxopenN[1][2]);
	//DrawFormatString(250, 460, White, "%d %d %d", boxopenN[2][0], boxopenN[2][1], boxopenN[2][2]);
	//DrawFormatString(300, 460, White, "%d %d", i, j);
	
	DrawFormatString(280, 20, Green, "%s", infor);//�q���g�o�́@�߂��ɔ����I�܂��͉����ɔ����I
	DrawFormatString(35, 415, White, "%d/10���", gamecount);//�P�O��Q�[���s�����Ƃ��̉���
	DrawFormatString(35, 435, White, "���Ă��@%d/2", ote);//���Ă��͂Q��܂�(�����ύX����܂���)
	//1��yesbox�̂Ƃ��̗����A0��nobox�̂Ƃ��̗���(���񂽂�Ƃ͎������Ⴄ)

	if (boxKeystoreN[0][0] == 0)
		DrawStringToHandle(95, 45, "Q�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[0][0] == 1)
		DrawStringToHandle(95, 30, "Q�L�[", White, FontBoxHandleN);
	if (boxKeystoreN[0][1] == 0)
		DrawStringToHandle(295, 45, "W�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[0][1] == 1)
		DrawStringToHandle(295, 30, "W�L�[", White, FontBoxHandleN);
	if (boxKeystoreN[0][2] == 0)
		DrawStringToHandle(495, 45, "E�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[0][2] == 1)
		DrawStringToHandle(495, 30, "E�L�[", White, FontBoxHandleN);

	if (boxKeystoreN[1][0] == 0)
		DrawStringToHandle(95, 175, "A�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[1][0] == 1)
		DrawStringToHandle(95, 160, "A�L�[", White, FontBoxHandleN);
	if (boxKeystoreN[1][1] == 0)
		DrawStringToHandle(295, 175, "S�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[1][1] == 1)
		DrawStringToHandle(295, 160, "S�L�[", White, FontBoxHandleN);
	if (boxKeystoreN[1][2] == 0)
		DrawStringToHandle(495, 175, "D�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[1][2] == 1)
		DrawStringToHandle(495, 160, "D�L�[", White, FontBoxHandleN);

	if (boxKeystoreN[2][0] == 0)
		DrawStringToHandle(95, 305, "Z�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[2][0] == 1)
		DrawStringToHandle(95, 290, "Z�L�[", White, FontBoxHandleN);
	if (boxKeystoreN[2][1] == 0)
		DrawStringToHandle(295, 305, "X�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[2][1] == 1)
		DrawStringToHandle(295, 290, "X�L�[", White, FontBoxHandleN);
	if (boxKeystoreN[2][2] == 0)
		DrawStringToHandle(495, 305, "C�L�[", White, FontBoxHandleN);
	else if (boxKeystoreN[2][2] == 1)
		DrawStringToHandle(495, 290, "C�L�[", White, FontBoxHandleN);

	//���ꂼ��L�[�őI�������Ƃ�yesbox��nobox�����肵�A���Ă��̏ꍇ��infor�Ńq���g�o��
	if (Key[KEY_INPUT_Q] == 1 && boxflag == 0){

		if (boxopenN[0][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[0][0] = yesbox;
			yes = 1;
		}
		if (boxopenN[0][0] == 0){
			boxstoreN[0][0] = nobox;
		}
		boxcount++;
		boxKeystoreN[0][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_Q] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][1] == 1 || boxopenN[1][0] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[0][0] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}


	if (Key[KEY_INPUT_W] == 1 && boxflag == 0){

		if (boxopenN[0][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[0][1] = yesbox;
			yes = 1;
		}
		if (boxopenN[0][1] == 0){
			boxstoreN[0][1] = nobox;
		}
		boxcount++;
		boxKeystoreN[0][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_W] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][0] == 1 || boxopenN[1][1] == 1 || boxopenN[0][2] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[0][1] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_E] == 1 && boxflag == 0){

		if (boxopenN[0][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[0][2] = yesbox;
			yes = 1;
		}
		if (boxopenN[0][2] == 0){
			boxstoreN[0][2] = nobox;
		}
		boxcount++;
		boxKeystoreN[0][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_E] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][1] == 1 || boxopenN[1][2] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[0][2] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_A] == 1 && boxflag == 0){

		if (boxopenN[1][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[1][0] = yesbox;
			yes = 1;
		}
		if (boxopenN[1][0] == 0){
			boxstoreN[1][0] = nobox;
		}
		boxcount++;
		boxKeystoreN[1][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_A] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][0] == 1 || boxopenN[1][1] == 1 || boxopenN[2][0] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[1][0] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_S] == 1 && boxflag == 0){

		if (boxopenN[1][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[1][1] = yesbox;
			yes = 1;
		}
		if (boxopenN[1][1] == 0){
			boxstoreN[1][1] = nobox;
		}
		boxcount++;
		boxKeystoreN[1][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_S] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[0][1] == 1 || boxopenN[1][0] == 1 || boxopenN[1][2] == 1 || boxopenN[2][1] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[1][1] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_D] == 1 && boxflag == 0){

		if (boxopenN[1][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[1][2] = yesbox;
			yes = 1;
		}
		if (boxopenN[1][2] == 0){
			boxstoreN[1][2] = nobox;
		}
		boxcount++;
		boxKeystoreN[1][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_D] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[1][1] == 1 || boxopenN[0][2] == 1 || boxopenN[2][2] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[1][2] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_Z] == 1 && boxflag == 0){

		if (boxopenN[2][0] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[2][0] = yesbox;
			yes = 1;
		}
		if (boxopenN[2][0] == 0){
			boxstoreN[2][0] = nobox;
		}
		boxcount++;
		boxKeystoreN[2][0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_Z] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[1][0] == 1 || boxopenN[2][1] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[2][0] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_X] == 1 && boxflag == 0){

		if (boxopenN[2][1] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[2][1] = yesbox;
			yes = 1;
		}
		if (boxopenN[2][1] == 0){
			boxstoreN[2][1] = nobox;
		}
		boxcount++;
		boxKeystoreN[2][1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_X] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[2][0] == 1 || boxopenN[1][1] == 1 || boxopenN[2][2] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[2][1] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	if (Key[KEY_INPUT_C] == 1 && boxflag == 0){

		if (boxopenN[2][2] == 1){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstoreN[2][2] = yesbox;
			yes = 1;
		}
		if (boxopenN[2][2] == 0){
			boxstoreN[2][2] = nobox;
		}
		boxcount++;
		boxKeystoreN[2][2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_C] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopenN[2][1] == 1 || boxopenN[1][2] == 1){
				infor = "�߂��ɔ����I"; ote++;
			}
			else if (boxopenN[2][2] == 1)
				infor = " ";
			else
				infor = "�����ɔ����I"; ote++;
		}
	}

	//yesbox�������ꍇ�Ƃ��Ă����ׂĎg���Č�����Ȃ������ꍇ�ɕ�������o��
	if (yes == 1 && boxcount == 1 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "�󔠔����I�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetN();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			boxKeystoreN[0][0] = 0;
			boxKeystoreN[0][1] = 0;
			boxKeystoreN[0][2] = 0;
			boxKeystoreN[1][0] = 0;
			boxKeystoreN[1][1] = 0;
			boxKeystoreN[1][2] = 0;
			boxKeystoreN[2][0] = 0;
			boxKeystoreN[2][1] = 0;
			boxKeystoreN[2][2] = 0;
		}
	}

	if (yes == 1 && boxcount >= 2 && boxcount <= 3 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "�󔠂͌���������I�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetN();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			boxKeystoreN[0][0] = 0;
			boxKeystoreN[0][1] = 0;
			boxKeystoreN[0][2] = 0;
			boxKeystoreN[1][0] = 0;
			boxKeystoreN[1][1] = 0;
			boxKeystoreN[1][2] = 0;
			boxKeystoreN[2][0] = 0;
			boxKeystoreN[2][1] = 0;
			boxKeystoreN[2][2] = 0;
		}
	}

	if (yes == 0 && boxcount == 3 && x >= -99999 && y >= -99999){
		if (musicstop == 0)
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
		boxflag = 1;
		musicstop = 1;
		DrawFormatString(200, 450, Green, "�󔠂͌�����Ȃ������E�E�E�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			BoxsetN();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			ote = 0;
			gamecount++;
			infor = "   ";
			musicstop = 0;
			boxKeystoreN[0][0] = 0;
			boxKeystoreN[0][1] = 0;
			boxKeystoreN[0][2] = 0;
			boxKeystoreN[1][0] = 0;
			boxKeystoreN[1][1] = 0;
			boxKeystoreN[1][2] = 0;
			boxKeystoreN[2][0] = 0;
			boxKeystoreN[2][1] = 0;
			boxKeystoreN[2][2] = 0;
		}
	}

	//10��Q�[���I������猋�ʉ�ʂɈڍs
	if (gamecount == 11){
		Menucount = 5;
	}

}