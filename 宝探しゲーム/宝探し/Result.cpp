#include "GV.h"


void Result(){
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw, TRUE);
	//DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	//DrawFormatString( 50, 450, Green, "���W[%d,%d]", x, y );
	DrawFormatString(120, 145, White, "�󔠂��������񐔁@%d/10", hit);
	if (0 <= hit&&hit <= 3){
		DrawStringToHandle(120, 240, "�c�O�I�����Ɗ撣�낤�I", White, FontHandle);
		if (game == 0){
			DrawFormatString(20, 330, White, "������x���񂽂�ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if (game == 1){
			DrawFormatString(20, 330, White, "������x�ӂ��ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if (game == 2){
			DrawFormatString(20, 330, White, "������x�ނ��������ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		DrawFormatString(20, 350, White, "�^�C�g���ɖ߂�Ȃ�Enter�L�[�������Ă�");

		if (Key[KEY_INPUT_RETURN] == 1){
			hit = 0;
			gamecount = 1;
			Menucount = 1;
		}
		if (Key[KEY_INPUT_RSHIFT] == 1){
			hit = 0;
			gamecount = 1;
			if (game == 0){
				Menucount = 2;
			}
			if (game == 1){
				Menucount = 3;
			}
			if (game == 2){
				Menucount = 4;
			}
		}
	}

	if (4 <= hit&&hit <= 6){
		DrawStringToHandle(120, 240, "�܂��܂����ˁI���̒��q�I", White, FontHandle);
		if (game == 0){
			DrawFormatString(20, 330, White, "������x���񂽂�ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if (game == 1){
			DrawFormatString(20, 330, White, "������x�ӂ��ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if (game == 2){
			DrawFormatString(20, 330, White, "������x�ނ��������ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		DrawFormatString(20, 350, White, "�^�C�g���ɖ߂�Ȃ�Enter�L�[�������Ă�");

		if (Key[KEY_INPUT_RETURN] == 1){
			hit = 0;
			gamecount = 1;
			Menucount = 1;
		}
		if (Key[KEY_INPUT_RSHIFT] == 1){
			hit = 0;
			gamecount = 1;
			if (game == 0){
				Menucount = 2;
			}
			if (game == 1){
				Menucount = 3;
			}
			if (game == 2){
				Menucount = 4;
			}
		}
	}

	if (7 <= hit&&hit <= 9){
		DrawStringToHandle(50, 180, "���Ȃ�ǂ��ˁI�p�[�t�F�N�g�ڎw���I", White, FontHandle);
		DrawStringToHandle(20, 220, "�ӂ��A�ނ��������̃��x���ɂ����킵�Ă� ", White, FontHandle);
		if (game == 0){
			DrawFormatString(20, 330, White, "������x���񂽂�ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if (game == 1){
			DrawFormatString(20, 330, White, "������x�ӂ��ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if (game == 2){
			DrawFormatString(20, 330, White, "������x�ނ��������ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		DrawFormatString(20, 350, White, "�^�C�g���ɖ߂�Ȃ�Enter�L�[�������Ă�");


		if (Key[KEY_INPUT_RETURN] == 1){
			hit = 0;
			gamecount = 1;
			Menucount = 1;
		}
		if (Key[KEY_INPUT_RSHIFT] == 1){
			hit = 0;
			gamecount = 1;
			if (game == 0){
				Menucount = 2;
			}
			if (game == 1){
				Menucount = 3;
			}
			if (game == 2){
				Menucount = 4;
			}
		}
	}

	if (hit == 10){
		DrawStringToHandle(50, 180, "�p�[�t�F�N�g�I�N�͕󔠃}�X�^�[���I", White, FontHandle);
		DrawStringToHandle(20, 220, "�ӂ��A�ނ��������̃��x���ɂ����킵�Ă�", White, FontHandle);
		if (game == 0){
			DrawFormatString(20, 330, White, "������x���񂽂�ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if (game == 1){
			DrawFormatString(20, 330, White, "������x�ӂ��ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if (game == 2){
			DrawFormatString(20, 330, White, "������x�ނ��������ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		DrawFormatString(20, 350, White, "�^�C�g���ɖ߂�Ȃ�Enter�L�[�������Ă�");


		if (Key[KEY_INPUT_RETURN] == 1){
			hit = 0;
			gamecount = 1;
			Menucount = 1;
		}
		if (Key[KEY_INPUT_RSHIFT] == 1){
			hit = 0;
			gamecount = 1;
			if (game == 0){
				Menucount = 2;
			}
			if (game == 1){
				Menucount = 3;
			}
			if (game == 2){
				Menucount = 4;
			}
		}
	}
}