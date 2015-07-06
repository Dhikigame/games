#include "GV.h"

void load(){
	FontHandle = CreateFontToHandle(NULL, 30, 3);
	FontMenuHandle = CreateFontToHandle(NULL, 15, 3);
	FontBoxHandle = CreateFontToHandle(NULL, 30, 3);
	FontBoxHandleN = CreateFontToHandle(NULL, 20, 3);
	Handle = LoadGraph("arrow37-032.png");//‰æ–Ê‚Å“®‚©‚·ƒ|ƒCƒ“ƒ^FREE‘fŞ
	Draw = LoadGraph("futta0796m.png");//”wŒiFREE‘fŞ
	Draw2 = LoadGraph("beach.png");//”wŒiFREE‘fŞ
	box = LoadGraph("•Â‚¶‚½•ó” .png");//©•ª‚Å•`‚¢‚½•ó” ‚ÌŠGi‰ºè•³j
	nobox = LoadGraph("‹ó‚Ì•ó” .png");
	yesbox = LoadGraph("•ó‚Ì•ó” .png");
	bombbox = LoadGraph("”š’e‚Ì•ó” .png");
	Green = GetColor(0, 255, 0);
	White = GetColor(255, 255, 255);
}

void sound(){
	gamemusic = LoadSoundMem("ƒƒCƒ“ƒe[ƒ}.ogg");
	boxopensound = LoadSoundMem("” ŠJ••.ogg");
	boxfoundsound = LoadSoundMem("•ó”­Œ©.ogg");
}