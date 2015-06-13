#include "GV.h"

 int gpUpdateKey(int KeyStateBuf[]){
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll( tmpKey ); // 全てのキーの入力状態を得る
	for( int i=0; i<256; i++ ){ 
		if( tmpKey[i] != 0 ){ // i番のキーコードに対応するキーが押されていたら
		    KeyStateBuf[i]++;     // 加算
		} else {              // 押されていなければ
			KeyStateBuf[i] = 0;   // 0にする
		}
	}
	return 0;
}