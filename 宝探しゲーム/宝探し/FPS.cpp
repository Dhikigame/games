#include "GV.h"
/*
FPS制御を行う
...このモジュールは私が考えて書いたのではなく、ほとんど参考したもののコードそのままです...
参考：http://dixq.net/g/03_14.html
*/
const int N = 60;	//平均を取るサンプル数
const int FPS = 60;	//設定したFPS

bool Update(){
	if (mCount == 0){ //1フレーム目なら時刻を記憶
		mStartTime = GetNowCount();
	}
	if (mCount == N){ //60フレーム目なら平均を計算する
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
	int tookTime = GetNowCount() - mStartTime;	//かかった時間
	int waitTime = mCount * 1000 / FPS - tookTime;	//待つべき時間
	if (waitTime > 0){
		Sleep(waitTime);	//待機
	}
}

