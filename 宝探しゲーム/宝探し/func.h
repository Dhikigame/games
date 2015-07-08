//初期化用・画像、音楽ロード系モジュール
GLOBAL void init();
GLOBAL void load();
GLOBAL void sound();
//FPS用モジュール
GLOBAL bool Update();	//更新
GLOBAL void FPSDraw();	//描画
GLOBAL void Wait();		//待機
//それぞれのメニュー用モジュール
GLOBAL void Menu();
GLOBAL void Easy();
GLOBAL void Normal();
GLOBAL void Hard();
GLOBAL void Result();
GLOBAL void Help();
//キー入力モジュール
GLOBAL int gpUpdateKey();
//yesbox、noboxを設定するためのモジュール
GLOBAL void Boxset();
GLOBAL void BoxsetN();
GLOBAL void BoxsetH();
//スコア計算モジュール
GLOBAL void Score();