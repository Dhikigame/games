#include "GV.h"

 int gpUpdateKey(int KeyStateBuf[]){
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll( tmpKey ); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for( int i=0; i<256; i++ ){ 
		if( tmpKey[i] != 0 ){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
		    KeyStateBuf[i]++;     // ���Z
		} else {              // ������Ă��Ȃ����
			KeyStateBuf[i] = 0;   // 0�ɂ���
		}
	}
	return 0;
}