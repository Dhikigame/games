#include "GV.h"

void Help(){
	DrawRotaGraph(320, 240, 1.0, 0.0, Draw, TRUE);
	DrawFormatString(100, 50, White, "���T���Q�[���ł��B����ȊO�̉��҂ł��Ȃ��ł��B");
	DrawFormatString(100, 70, White, "�����̈ӎv�𗊂�ɕ�𓖂ĂĂ݂Ă��������B");
	DrawFormatString(70, 100, White, "�₳�����@:���̐���6�A���Ă�2��܂�(�����^���K�v�ȂƂ�������)");
	DrawFormatString(70, 120, White, "�ӂ��@�@:���̐���9�A���Ă�2��܂�(�قډ^���K�v)");
	DrawFormatString(70, 140, White, "�ނ�������:���̐���16�A���Ă�2��܂�(�^�����Ȃ苭��)");
	DrawFormatString(100, 190, White, "���Ă�������Ԃ͌������Ȃ��Ă���Ɂu�߂��ɔ���!�v");
	DrawFormatString(100, 210, White, "�܂��́@�u�����ɔ���!�v���\������܂��B");
	DrawFormatString(100, 230, White, "�߂��ɂ̏ꍇ�͏c�܂��͉��ׂ̕󔠂ɕ󂪂���A");
	DrawFormatString(100, 250, White, "�����ɂ̏ꍇ�͋߂��ɂ̈ȊO�̂Ƃ���ɕ󂪂���킯�ł��B");
	DrawFormatString(270, 280, White, "�`������@�`");
	DrawFormatString(100, 300, White, "�w��L�[�F�󔠂��J��");
	DrawFormatString(100, 320, White, "�E�V�t�g�L�[�F�Q�[���r���^�C�g����ʂɖ߂�");
	DrawFormatString(100, 340, White, "ESC�L�[�F�Q�[���I��");
	DrawFormatString(200, 380, White, "�X�y�[�X�L�[�Ń^�C�g���ɖ߂�");

	if (Key[KEY_INPUT_SPACE] == 1){
		PlaySoundMem(boxfoundsound, DX_PLAYTYPE_BACK, TRUE);
		Menucount = 1;
	}
}