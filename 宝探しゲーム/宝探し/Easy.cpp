#include "GV.h"


void Easy(){
	//1�Q�[�����Ƃɏ����Ɂh�����󔠁h���Z�b�g
	if (boxcount == 0){
		boxstore1 = box;
		boxstore2 = box;
		boxstore3 = box;
		boxstore4 = box;
		boxstore5 = box;
		boxstore6 = box;
	}
	/*
	�󔠂�`��@�E���z��̏ꍇ�̔z�u
	���@���@���@[0] [1] [2]
	���@���@���@[3] [4] [5]
	*/
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw2, TRUE);
	DrawRotaGraph(120, 110, 1.0, 0.0, boxstore1, TRUE);
	DrawRotaGraph(320, 110, 1.0, 0.0, boxstore2, TRUE);
	DrawRotaGraph(520, 110, 1.0, 0.0, boxstore3, TRUE);
	DrawRotaGraph(120, 300, 1.0, 0.0, boxstore4, TRUE);
	DrawRotaGraph(320, 300, 1.0, 0.0, boxstore5, TRUE);
	DrawRotaGraph(520, 300, 1.0, 0.0, boxstore6, TRUE);
	
	//DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	//�f�o�b�O�p�@boxopen�̔z�u�m�F
	//DrawFormatString( 0, 450, White, "���W[%d,%d],%d,%d,%d,%d,%d,%d",
	//	x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
	DrawFormatString(280, 20, Green, "%s", infor);//�q���g�o�́@�߂��ɔ����I�܂��͉����ɔ����I
	DrawFormatString(35, 415, White, "%d/10���", gamecount);//�P�O��Q�[���s�����Ƃ��̉���
	DrawFormatString(35, 435, White, "���Ă��@%d/2", ote);//���Ă��͂Q��܂�
	
	if (boxKeystore[0] == 0)
		DrawStringToHandle(90, 50, "A�L�[", White, FontBoxHandle);
	else if(boxKeystore[0] == 1)
		DrawStringToHandle(90, 35, "A�L�[", White, FontBoxHandle);
	
	if (boxKeystore[1] == 0)
		DrawStringToHandle(290, 50, "S�L�[", White, FontBoxHandle);
	else if (boxKeystore[1] == 1)
		DrawStringToHandle(290, 35, "S�L�[", White, FontBoxHandle);

	if (boxKeystore[2] == 0)
		DrawStringToHandle(490, 50, "D�L�[", White, FontBoxHandle);
	else if (boxKeystore[2] == 1)
		DrawStringToHandle(490, 35, "D�L�[", White, FontBoxHandle);

	if (boxKeystore[3] == 0)
		DrawStringToHandle(90, 240, "Z�L�[", White, FontBoxHandle);
	else if (boxKeystore[3] == 1)
		DrawStringToHandle(90, 225, "Z�L�[", White, FontBoxHandle);

	if (boxKeystore[4] == 0)
		DrawStringToHandle(290, 240, "X�L�[", White, FontBoxHandle);
	else if (boxKeystore[4] == 1)
		DrawStringToHandle(290, 225, "X�L�[", White, FontBoxHandle);

	if (boxKeystore[5] == 0)
		DrawStringToHandle(490, 240, "C�L�[", White, FontBoxHandle);
	else if (boxKeystore[5] == 1)
		DrawStringToHandle(490, 225, "C�L�[", White, FontBoxHandle);

	//67502085��yesbox�̂Ƃ��̗����A67436548��nobox�̂Ƃ��̗���(�V�������Ő��삵�Ȃ������̂Œl���ς���Ă���)

	//���ꂼ��L�[�őI�������Ƃ�yesbox��nobox�����肵�A���Ă��̏ꍇ��infor�Ńq���g�o��
	if (Key[KEY_INPUT_A] == 1 && boxflag == 0){
		
		if (boxopen[0] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore1 = yesbox;
			yes = 1;
		}
		if (boxopen[0] == 67436548){
			boxstore1 = nobox;
		}
		boxcount++;
		boxKeystore[0] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_A] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[1] == 67502085 || boxopen[3] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[2] == 67502085 || boxopen[4] == 67502085 || boxopen[5] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}


	if (Key[KEY_INPUT_S] == 1 && boxflag == 0){
		
		if (boxopen[1] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore2 = yesbox;
			yes = 1;
		}
		if (boxopen[1] == 67436548){
			boxstore2 = nobox;
		}
		boxcount++;
		boxKeystore[1] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_S] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[0] == 67502085 || boxopen[2] == 67502085 || boxopen[4] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[3] == 67502085 || boxopen[5] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	if (Key[KEY_INPUT_D] == 1 && boxflag == 0){
		
		if (boxopen[2] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore3 = yesbox;
			yes = 1;
		}
		if (boxopen[2] == 67436548){
			boxstore3 = nobox;
		}
		boxcount++;
		boxKeystore[2] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_D] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[1] == 67502085 || boxopen[5] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[3] == 67502085 || boxopen[4] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	if (Key[KEY_INPUT_Z] == 1 && boxflag == 0){
		
		if (boxopen[3] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore4 = yesbox;
			yes = 1;
		}
		if (boxopen[3] == 67436548){
			boxstore4 = nobox;
		}
		boxcount++;
		boxKeystore[3] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_Z] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[0] == 67502085 || boxopen[4] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[1] == 67502085 || boxopen[2] == 67502085 || boxopen[5] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	if (Key[KEY_INPUT_X] == 1 && boxflag == 0){
		
		if (boxopen[4] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore5 = yesbox;
			yes = 1;
		}
		if (boxopen[4] == 67436548){
			boxstore5 = nobox;
		}
		boxcount++;
		boxKeystore[4] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_X] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[1] == 67502085 || boxopen[3] == 67502085 || boxopen[5] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[2] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	if (Key[KEY_INPUT_C] == 1 && boxflag == 0){
		
		if (boxopen[5] == 67502085){
			PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
			boxstore6 = yesbox;
			yes = 1;
		}
		if (boxopen[5] == 67436548){
			boxstore6 = nobox;
		}
		boxcount++;
		boxKeystore[5] = 1;
		if (boxcount >= 1 && boxcount <= 2 && Key[KEY_INPUT_C] == 1){
			PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
			if (boxopen[2] == 67502085 || boxopen[4] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[1] == 67502085 || boxopen[3] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	//yesbox�������ꍇ�Ƃ��Ă����ׂĎg���Č�����Ȃ������ꍇ�ɕ�������o��
	if (yes == 1 && boxcount == 1 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "�󔠔����I�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			Boxset();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			boxKeystore[0] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��(������)
			boxKeystore[1] = 0;
			boxKeystore[2] = 0;
			boxKeystore[3] = 0;
			boxKeystore[4] = 0;
			boxKeystore[5] = 0;
		}
	}

	if (yes == 1 && boxcount >= 2 && boxcount <= 3 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "�󔠂͌���������I�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			Boxset();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			hit++;
			gamecount++;
			ote = 0;
			infor = "   ";
			boxKeystore[0] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��(������)
			boxKeystore[1] = 0;
			boxKeystore[2] = 0;
			boxKeystore[3] = 0;
			boxKeystore[4] = 0;
			boxKeystore[5] = 0;
		}
	}

	if (yes == 0 && boxcount == 3 && x >= -99999 && y >= -99999){
		if(musicstop == 0)
		PlaySoundMem(boxopensound, DX_PLAYTYPE_BACK, TRUE);
		boxflag = 1;
		musicstop = 1;
		DrawFormatString(200, 450, Green, "�󔠂͌�����Ȃ������E�E�E�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			Boxset();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			ote = 0;
			gamecount++;
			infor = "   ";
			musicstop = 0;
			boxKeystore[0] = 0;//�󔠂��J�����Ƃ���"���L�["�̈ʒu��ύX����z��(������)
			boxKeystore[1] = 0;
			boxKeystore[2] = 0;
			boxKeystore[3] = 0;
			boxKeystore[4] = 0;
			boxKeystore[5] = 0;
		}
	}

	//10��Q�[���I������猋�ʉ�ʂɈڍs
	if (gamecount == 11){
		Menucount = 5;
	}
}