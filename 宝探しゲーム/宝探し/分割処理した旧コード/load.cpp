#include "GV.h"

void load(){
	FontHandle = CreateFontToHandle(NULL, 30, 3);
	Handle = LoadGraph("arrow37-032.png");//æÊÅ®©·|C^FREEfÞ
	Draw = LoadGraph("futta0796m.png");//wiFREEfÞ
	Draw2 = LoadGraph("beach.png");//wiFREEfÞ
	box = LoadGraph("Â¶½ó .png");//©ªÅ`¢½ó ÌGiºè³j
	nobox = LoadGraph("óÌó .png");
	yesbox = LoadGraph("óÌó .png");
	bombbox = LoadGraph("eÌó .png");
	Green = GetColor(0, 255, 0);
	White = GetColor(255, 255, 255);
}