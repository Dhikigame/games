#include "GV.h"



void Normal(){
	if (boxcount == 0){
		boxstore1 = box;
		boxstore2 = box;
		boxstore3 = box;
		boxstore4 = box;
		boxstore5 = box;
		boxstore6 = box;
	}
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw2, TRUE);
	DrawRotaGraph(120, 110, 1.0, 0.0, boxstore1, TRUE);
	DrawRotaGraph(320, 110, 1.0, 0.0, boxstore2, TRUE);
	DrawRotaGraph(520, 110, 1.0, 0.0, boxstore3, TRUE);
	DrawRotaGraph(120, 300, 1.0, 0.0, boxstore4, TRUE);
	DrawRotaGraph(320, 300, 1.0, 0.0, boxstore5, TRUE);
	DrawRotaGraph(520, 300, 1.0, 0.0, boxstore6, TRUE);
	DrawRotaGraph(x, y, 1.0, 0.0, Handle, TRUE);
	//DrawFormatString( 0, 450, White, "���W[%d,%d],%d,%d,%d,%d,%d,%d", x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
	DrawFormatString(280, 20, Green, "%s", infor);
	DrawFormatString(35, 415, White, "%d/10���", gamecount);
	DrawFormatString(35, 435, White, "���Ă��@%d/1", ote);
	//67502085��yesbox�̂Ƃ��̗����A67436548��nobox�̂Ƃ��̗���(�V�������Ő��삵�Ȃ������̂Œl���ς���Ă���)
	if (x >= 30 && x <= 210 && y >= 35 && 185 >= y&&Key[KEY_INPUT_SPACE] == 1 && boxflag == 0){

		if (boxopen[0] == 67502085){
			boxstore1 = yesbox;
			yes = 1;
		}
		if (boxopen[0] == 67436548){
			boxstore1 = nobox;
		}
		boxcount++;
		if (boxcount == 1 && x >= 30 && x <= 210 && y >= 35 && 185 >= y&&Key[KEY_INPUT_SPACE] == 1){

			if (boxopen[1] == 67502085 || boxopen[3] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[2] == 67502085 || boxopen[4] == 67502085 || boxopen[5] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}


	if (x >= 230 && x <= 410 && y >= 35 && 185 >= y&&Key&&Key[KEY_INPUT_SPACE] == 1 && boxflag == 0){

		if (boxopen[1] == 67502085){
			boxstore2 = yesbox;
			yes = 1;
		}
		if (boxopen[1] == 67436548){
			boxstore2 = nobox;
		}
		boxcount++;
		if (boxcount == 1 && x >= 230 && x <= 410 && y >= 35 && 185 >= y&&Key[KEY_INPUT_SPACE] == 1){
			if (boxopen[0] == 67502085 || boxopen[2] == 67502085 || boxopen[4] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[3] == 67502085 || boxopen[5] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	if (x >= 430 && x <= 610 && y >= 35 && 185 >= y&&Key[KEY_INPUT_SPACE] == 1 && boxflag == 0){

		if (boxopen[2] == 67502085){
			boxstore3 = yesbox;
			yes = 1;
		}
		if (boxopen[2] == 67436548){
			boxstore3 = nobox;
		}
		boxcount++;
		if (boxcount == 1 && x >= 430 && x <= 610 && y >= 35 && 185 >= y&&Key[KEY_INPUT_SPACE] == 1){
			if (boxopen[1] == 67502085 || boxopen[5] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[3] == 67502085 || boxopen[4] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	if (x >= 30 && x <= 210 && y >= 225 && 375 >= y&&Key[KEY_INPUT_SPACE] == 1 && boxflag == 0){

		if (boxopen[3] == 67502085){
			boxstore4 = yesbox;
			yes = 1;
		}
		if (boxopen[3] == 67436548){
			boxstore4 = nobox;
		}
		boxcount++;
		if (boxcount == 1 && x >= 30 && x <= 210 && y >= 225 && 375 >= y&&Key[KEY_INPUT_SPACE] == 1){
			if (boxopen[0] == 67502085 || boxopen[4] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[1] == 67502085 || boxopen[2] == 67502085 || boxopen[5] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	if (x >= 230 && x <= 410 && y >= 225 && 375 >= y&&Key[KEY_INPUT_SPACE] == 1 && boxflag == 0){

		if (boxopen[4] == 67502085){
			boxstore5 = yesbox;
			yes = 1;
		}
		if (boxopen[4] == 67436548){
			boxstore5 = nobox;
		}
		boxcount++;
		if (boxcount == 1 && x >= 230 && x <= 410 && y >= 225 && 375 >= y&&Key[KEY_INPUT_SPACE] == 1){
			if (boxopen[1] == 67502085 || boxopen[3] == 67502085 || boxopen[5] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[2] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

	if (x >= 430 && x <= 610 && y >= 225 && 375 >= y&&Key[KEY_INPUT_SPACE] == 1 && boxflag == 0){

		if (boxopen[5] == 67502085){
			boxstore6 = yesbox;
			yes = 1;
		}
		if (boxopen[5] == 67436548){
			boxstore6 = nobox;
		}
		boxcount++;
		if (boxcount == 1 && x >= 430 && x <= 610 && y >= 225 && 375 >= y&&Key[KEY_INPUT_SPACE] == 1){
			if (boxopen[2] == 67502085 || boxopen[4] == 67502085){
				infor = "�߂��ɔ����I"; ote++;
			}
			if (boxopen[0] == 67502085 || boxopen[1] == 67502085 || boxopen[3] == 67502085){
				infor = "�����ɔ����I"; ote++;
			}

		}
	}

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
		}
	}

	if (yes == 1 && boxcount == 2 && x >= -99999 && y >= -99999){
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
		}
	}

	if (yes == 0 && boxcount == 2 && x >= -99999 && y >= -99999){
		boxflag = 1;
		DrawFormatString(200, 450, Green, "�󔠂͌�����Ȃ������E�E�E�iEnter�L�[�Ői�ށj");
		if (Key[KEY_INPUT_RETURN] == 1){
			Boxset();
			boxcount = 0;
			boxflag = 0;
			yes = 0;
			ote = 0;
			gamecount++;
			infor = "   ";
		}
	}

	if (gamecount == 11){
		Menucount = 5;
	}
}