#include "DxLib.h"
#include <stdlib.h>
#include <math.h>
#define PI 3.1415926f

int Key[256];

 int gpUpdateKey(){
	char tmpKey[256]; // 現在のキーの入力状態を格納する
	GetHitKeyStateAll( tmpKey ); // 全てのキーの入力状態を得る
	for( int i=0; i<256; i++ ){ 
		if( tmpKey[i] != 0 ){ // i番のキーコードに対応するキーが押されていたら
			Key[i]++;     // 加算
		} else {              // 押されていなければ
			Key[i] = 0;   // 0にする
		}
	}
	return 0;
}

 enum{
	 Title,
	 one,
	 two,
	 three,
	 four,
	 help,
	 anime,
	 burn,
	 clear
 };


int Image,Font1,Font2,CD,Bomb,Fire,Burn;
int x,y;
int i,j,flag,k=10;
int Keycount =0;
int Menucount = 0;
int count;
int sec=0;//秒数
int cd[10];
int bombflag;
int x0;


void Menu();
void Set();
void One();
void Anime();
void Burning();
void Clear();

int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
        ChangeWindowMode(TRUE);
		if(DxLib_Init()==-1)return -1;
		SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更,初期化,裏画面設定
		

		 //PlaySound( "tw051.mp3" , DX_PLAYTYPE_LOOP ) ;
		 Image = LoadGraph("white.png");
		 CD =  LoadGraph("cd.png");
		 Fire = LoadGraph("火.png");
		 Burn = LoadGraph("爆発後.png");
		 Font1 = CreateFontToHandle( "NULL", 50,  9, DX_FONTTYPE_NORMAL ) ; 
		 Font2 = CreateFontToHandle( "NULL", 30,  9, DX_FONTTYPE_NORMAL ) ; 
		
		 Bomb = LoadSoundMem("爆発.wav");
		

		while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0 ){
			ClsDrawScreen();
			GetMousePoint( &x, &y );
			DrawRotaGraph( 320, 240, 1.0, 0.0, Image, TRUE );	
			//DrawFormatString( 500, 450, GetColor(0,0,0), "座標[%d,%d]", x, y);
			/*DrawFormatString( 250, 450, GetColor(0,0,0), "%d", Keycount);

			if(Key[KEY_INPUT_C]==1){
				Keycount++;
			}
			else Keycount = 0;*/

			switch(Menucount){
		 case Title:Menu();break;
		 case one:One();break;
		 /*case two:Two();break;
		 case three:Three();break;
		 case four:Four();break;
		 case help:Help();break;*/
		 case anime:Anime();break;
		 case burn:Burning();break;
		 case clear:Clear();break;
		 }
			
		}

	  DxLib_End();
        return 0;
}

void Menu(){

	  
	  DrawRotaGraph( 195, 73, 1.0, PI/20*i, CD, TRUE );
	  DrawStringToHandle( 190, 50,"CD Burning ", GetColor(255,0,0),Font1);
	  //DrawRotaGraph( 120, 300, 1.0, 0.0, CD, TRUE );	

	  DrawRotaGraph( 100, 300, 1.0, PI/80*i, CD, TRUE );

	  DrawStringToHandle( 200, 200,"Normal Burning     C Key", GetColor(255,0,0),Font2);
	  DrawStringToHandle( 200, 250,"50 Burning No.1    D Key", GetColor(255,0,0),Font2);
	  DrawStringToHandle( 200, 300,"50 Burning No.2    R Key", GetColor(255,0,0),Font2);
	  DrawStringToHandle( 200, 350,"CD Burning         O Key", GetColor(255,0,0),Font2);
	  DrawStringToHandle( 200, 400,"Help               M Key", GetColor(255,0,0),Font2);

	  i++;

	  if(Key[KEY_INPUT_C]==1){
		   //StopMusic();
		  count=0;
		  Set();
		   Menucount=one;
		  PlaySoundMem( Bomb , DX_PLAYTYPE_BACK ) ;
	  }
	  
}


void Set(){
	for(i=0;i<k;i++){
		flag=TRUE;
		while(flag){
		flag=FALSE;
		cd[i]=GetRand(k-1);
			for(j=0;j<i;j++){
				if(cd[j]==cd[i]){
				flag=TRUE;
				break;
			}
		}
	}
}
	k--;
}

void Anime(){//6
	DrawRotaGraph( 320, 240, 0.5, 0.0, Fire, TRUE );

   if(x0<320)x0++;

	if(bombflag==1){
    DrawRotaGraph( x0, 240, 1.0, PI/60*i, CD, TRUE );
	if(x0==320){
		i=0;
		Menucount=7;
		PlaySoundMem( Bomb , DX_PLAYTYPE_BACK ) ;
	}
}

	if(bombflag==0){
    DrawRotaGraph( x0, 240, 1.0, PI/60*i, CD, TRUE );
	
	if(x0==320&&count<=8){
		x0=320;i=0;
		DrawStringToHandle( 280, 20,"SAFE!", GetColor(0,255,0),Font2);
		DrawFormatString( 445, 350,GetColor(0,255,0),"続ける　    →C Key");
	    DrawFormatString( 445, 400,GetColor(0,255,0),"諦める？＾＾→D Key");
		if(Key[KEY_INPUT_C]==1){ 
			Menucount=1;
			count++;
			Set();
		}
		if(Key[KEY_INPUT_D]==1){ 
			PlaySoundMem( Bomb , DX_PLAYTYPE_BACK ) ;
			Menucount=7;
		}
		
		if(x0==320&&count==9){
		    Menucount=8;
	    }

		
	}

}
	i++;
}

void Burning(){//7
	DrawRotaGraph( 320, 240, 1.0, 0.0, Burn, TRUE );
	//DrawFormatString( 500, 450, GetColor(0,0,0), "座標[%d,%d]", x, y);
	if(sec>=150){
		if(bombflag==0){
		DrawStringToHandle( 240, 180,"GAME OVER", GetColor(255,0,0),Font2);
		DrawFormatString( 500, 350,GetColor(0,0,0),"Title→ C");
		DrawFormatString( 350, 460,GetColor(0,0,0),"やっぱ続行！！→D Key");
		}
		if(bombflag==1){
		DrawStringToHandle( 240, 180,"GAME OVER", GetColor(255,0,0),Font2);
		DrawFormatString( 500, 350,GetColor(0,0,0),"Title→ C");
		DrawFormatString( 350, 460,GetColor(0,0,0),"もう一度爆発する→D Key");
		}
		if(Key[KEY_INPUT_C]==1){ 
			sec=0;count=0;k=10;
			Menucount=0;
		}
		if(Key[KEY_INPUT_D]==1){ 
			sec=0;x0=0;
			Menucount=6;
		}
	}

	sec++;
}

void Clear(){//8
	 DrawStringToHandle( 180, 170,"Congulatulaition!!", GetColor(0,255,0),Font2);
	DrawFormatString( 190, 280,GetColor(0,0,0),"おめでとう！　あなたは救われた");
	DrawFormatString( 500, 350,GetColor(0,0,0),"Title→ C");
	if(Key[KEY_INPUT_C]==1){ 
			Menucount=0;k=10;
		}
}

void One(){

 DrawFormatString( 270, 30, GetColor(255,0,0), "ＣＤを選べ", x, y);
 /*DrawFormatString( 30, 420, GetColor(0,0,0), "%d %d %d %d %d %d %d %d %d %d", 
	 cd[0],cd[1],cd[2],cd[3],cd[4],cd[5],cd[6],cd[7],cd[8],cd[9]);*/

 if(count==0){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 580, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 60, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 580, 320, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);
 DrawFormatString( 320, 220, GetColor(0,0,0), "[D]", x, y);
 DrawFormatString( 450, 220, GetColor(0,0,0), "[F]", x, y);
 DrawFormatString( 580, 220, GetColor(0,0,0), "[G]", x, y);
 DrawFormatString( 60, 390, GetColor(0,0,0), "[Z]", x, y);
 DrawFormatString( 190, 390, GetColor(0,0,0), "[X]", x, y);
 DrawFormatString( 320, 390, GetColor(0,0,0), "[C]", x, y);
 DrawFormatString( 450, 390, GetColor(0,0,0), "[V]", x, y);
 DrawFormatString( 580, 390, GetColor(0,0,0), "[B]", x, y);
 

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_D]){
	 if(cd[2]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_F]){
	 if(cd[3]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_G]){
	 if(cd[4]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_Z]){
	 if(cd[5]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_X]){
	 if(cd[6]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_C]==1){
	 if(cd[7]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_V]){
	 if(cd[8]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_B]){
	 if(cd[9]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}
 }

 if(count==1){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 580, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 60, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 320, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);
 DrawFormatString( 320, 220, GetColor(0,0,0), "[D]", x, y);
 DrawFormatString( 450, 220, GetColor(0,0,0), "[F]", x, y);
 DrawFormatString( 580, 220, GetColor(0,0,0), "[G]", x, y);
 DrawFormatString( 60, 390, GetColor(0,0,0), "[Z]", x, y);
 DrawFormatString( 190, 390, GetColor(0,0,0), "[X]", x, y);
 DrawFormatString( 320, 390, GetColor(0,0,0), "[C]", x, y);
 DrawFormatString( 450, 390, GetColor(0,0,0), "[V]", x, y);

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_D]){
	 if(cd[2]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_F]){
	 if(cd[3]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_G]){
	 if(cd[4]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_Z]){
	 if(cd[5]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_X]){
	 if(cd[6]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_C]==1){
	 if(cd[7]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_V]){
	 if(cd[8]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}
 }

 if(count==2){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 580, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 60, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 320, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);
 DrawFormatString( 320, 220, GetColor(0,0,0), "[D]", x, y);
 DrawFormatString( 450, 220, GetColor(0,0,0), "[F]", x, y);
 DrawFormatString( 580, 220, GetColor(0,0,0), "[G]", x, y);
 DrawFormatString( 60, 390, GetColor(0,0,0), "[Z]", x, y);
 DrawFormatString( 190, 390, GetColor(0,0,0), "[X]", x, y);
 DrawFormatString( 320, 390, GetColor(0,0,0), "[C]", x, y);

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_D]){
	 if(cd[2]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_F]){
	 if(cd[3]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_G]){
	 if(cd[4]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_Z]){
	 if(cd[5]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_X]){
	 if(cd[6]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_C]==1){
	 if(cd[7]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}
 }

  if(count==3){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 580, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 60, 320, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 320, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);
 DrawFormatString( 320, 220, GetColor(0,0,0), "[D]", x, y);
 DrawFormatString( 450, 220, GetColor(0,0,0), "[F]", x, y);
 DrawFormatString( 580, 220, GetColor(0,0,0), "[G]", x, y);
 DrawFormatString( 60, 390, GetColor(0,0,0), "[Z]", x, y);
 DrawFormatString( 190, 390, GetColor(0,0,0), "[X]", x, y);

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_D]){
	 if(cd[2]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_F]){
	 if(cd[3]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_G]){
	 if(cd[4]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_Z]){
	 if(cd[5]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_X]){
	 if(cd[6]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 
 }


 if(count==4){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 580, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 60, 320, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);
 DrawFormatString( 320, 220, GetColor(0,0,0), "[D]", x, y);
 DrawFormatString( 450, 220, GetColor(0,0,0), "[F]", x, y);
 DrawFormatString( 580, 220, GetColor(0,0,0), "[G]", x, y);
 DrawFormatString( 60, 390, GetColor(0,0,0), "[Z]", x, y);

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_D]){
	 if(cd[2]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_F]){
	 if(cd[3]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_G]){
	 if(cd[4]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_Z]){
	 if(cd[5]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 
 }

 if(count==5){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 580, 150, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);
 DrawFormatString( 320, 220, GetColor(0,0,0), "[D]", x, y);
 DrawFormatString( 450, 220, GetColor(0,0,0), "[F]", x, y);
 DrawFormatString( 580, 220, GetColor(0,0,0), "[G]", x, y);

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_D]){
	 if(cd[2]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_F]){
	 if(cd[3]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_G]){
	 if(cd[4]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 
 }

  if(count==6){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 450, 150, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);
 DrawFormatString( 320, 220, GetColor(0,0,0), "[D]", x, y);
 DrawFormatString( 450, 220, GetColor(0,0,0), "[F]", x, y);

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_D]){
	 if(cd[2]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_F]){
	 if(cd[3]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 
 }

    if(count==7){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 320, 150, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);
 DrawFormatString( 320, 220, GetColor(0,0,0), "[D]", x, y);

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_D]){
	 if(cd[2]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 
 }
 

	 if(count==8){
 DrawRotaGraph( 60, 150, 1.0, 0.0, CD, TRUE );
 DrawRotaGraph( 190, 150, 1.0, 0.0, CD, TRUE );
 DrawFormatString( 60, 220, GetColor(0,0,0), "[A]", x, y);
 DrawFormatString( 190, 220, GetColor(0,0,0), "[S]", x, y);

 if(Key[KEY_INPUT_A]){
	 if(cd[0]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}

 if(Key[KEY_INPUT_S]){
	 if(cd[1]==0){
		 bombflag=1;
		 Menucount=6;
		 x0=0;
	 }
	 else{
		 x0=0;
		 bombflag=0;
		 Menucount=6;
	 }
}



 
 }

}