//初期化
GLOBAL void init();
GLOBAL void load();
GLOBAL void sound();
//FPS
GLOBAL bool Update();	//更新
GLOBAL void FPSDraw();		//描画
GLOBAL void Wait();		//待機
//Menu
GLOBAL void Menu();
GLOBAL void Easy();
GLOBAL void Normal();
GLOBAL void Hard();
GLOBAL void Result();
GLOBAL void Help();
//func
GLOBAL int gpUpdateKey();
//yesboxまたはnoboxをせっていするためのモジュール
GLOBAL void Boxset();
GLOBAL void BoxsetN();
GLOBAL void BoxsetH();