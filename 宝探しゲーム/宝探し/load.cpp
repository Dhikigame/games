#include "GV.h"

void load(){
	FontHandle = CreateFontToHandle(NULL, 30, 3);
	FontMenuHandle = CreateFontToHandle(NULL, 15, 3);
	FontBoxHandle = CreateFontToHandle(NULL, 30, 3);
	FontBoxHandleN = CreateFontToHandle(NULL, 20, 3);
	Handle = LoadGraph("arrow37-032.png");//��ʂœ������|�C���^FREE�f��
	Draw = LoadGraph("futta0796m.png");//�w�iFREE�f��
	Draw2 = LoadGraph("beach.png");//�w�iFREE�f��
	box = LoadGraph("������.png");//�����ŕ`�����󔠂̊G�i���蕳�j
	nobox = LoadGraph("��̕�.png");
	yesbox = LoadGraph("��̕�.png");
	bombbox = LoadGraph("���e�̕�.png");
	Green = GetColor(0, 255, 0);
	White = GetColor(255, 255, 255);
}

void sound(){
	gamemusic = LoadSoundMem("���C���e�[�}.ogg");
	boxopensound = LoadSoundMem("���J��.ogg");
	boxfoundsound = LoadSoundMem("�󔭌�.ogg");
}