#include "GV.h"

void Help(){
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw, TRUE);
	DrawFormatString(100, 50, White, "���T���Q�[���ł��B����ȊO�̉��҂ł��Ȃ��ł��B");
	DrawFormatString(100, 70, White, "�����̈ӎv�𗊂�ɕ�𓖂ĂĂ݂Ă��������B");
	DrawFormatString(100, 100, White, "�₳�����@:���Ă�2��܂�(�����^���K�v�ȂƂ�������)");
	DrawFormatString(100, 120, White, "�ӂ��@�@:���Ă�1��܂�(�قډ^���K�v)");
	DrawFormatString(100, 140, White, "�ނ�������:���Ă��͂�邹��(�^)");
	DrawFormatString(100, 170, White, "���Ă��������Փx�Ɋւ��Ă�");
	DrawFormatString(100, 190, White, "�����������Ȃ��Ă���Ɂ@�߂��ɔ���!");
	DrawFormatString(100, 210, White, "�܂��́@�����ɔ���!���\������܂��B");
	DrawFormatString(100, 230, White, "�߂��ɂ̏ꍇ�͏c�܂��͉��ׂ̕󔠂ɕ󂪂���A");
	DrawFormatString(100, 250, White, "�����ɂ̏ꍇ�͋߂��ɂ̈ȊO�̂Ƃ���ɕ󂪂���킯�ł��B");
	DrawFormatString(100, 280, White, "���L�[�F�ړ��@�X�y�[�X�L�[�F�󔠂��J��");
	DrawFormatString(200, 310, White, "�X�y�[�X�L�[�Ń^�C�g���ɖ߂�");

	if (Key[KEY_INPUT_SPACE] == 1){
		Menucount = 1;
	}
}