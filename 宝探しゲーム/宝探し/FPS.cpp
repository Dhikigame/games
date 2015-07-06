#include "GV.h"

const int N = 60;	//���ς����T���v����
const int FPS = 60;	//�ݒ肵��FPS

bool Update(){
	if (mCount == 0){ //1�t���[���ڂȂ玞�����L��
		mStartTime = GetNowCount();
	}
	if (mCount == N){ //60�t���[���ڂȂ畽�ς��v�Z����
		int t = GetNowCount();
		mFps = 1000 / ((t - mStartTime) / (float)N);
		mCount = 0;
		mStartTime = t;
	}
	mCount++;
	return true;
}

void FPSDraw(){
	DrawFormatString(600, 0, White, "%.1f", mFps);
}

void Wait(){
	int tookTime = GetNowCount() - mStartTime;	//������������
	int waitTime = mCount * 1000 / FPS - tookTime;	//�҂ׂ�����
	if (waitTime > 0){
		Sleep(waitTime);	//�ҋ@
	}
}

