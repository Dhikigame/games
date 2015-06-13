#include "DxLib.h"
#include <stdlib.h>

int x,y,Mouse;
int	Image,reset,black,blue,green,red,pink,Color,Frame;
int Font1,Font2;
int flag;
int i=0;
int j=0;
int k=0;
int number[25];
int numberstore[25];
int reach[12];//reach[0~5]までnumber[0]~[4]=reach[0],number[5]~[9]=reach[1]としていく
int store=0;
int t=0;
int yt=0;
int fla[12];//構成はreachと同じ初期値は0だが、列、縦がビンゴしたらfla++でその列がビンゴしたフラグ　1ビンゴとみなす（意味不明）
int bingo=0;

void Numberset();

void Numberset(){
	//25つの中に1～75までの数字をそれぞれかぶらない違う値を入れる　参考サイト http://q.hatena.ne.jp/1307178107 
	for(i=0;i<25;i++){
		flag=TRUE;
		while(flag){
		flag=FALSE;
		number[i]=GetRand(74)+1;
			for(j=0;j<i;j++){
				if(number[j]==number[i]){
				flag=TRUE;
				break;
					}
				}
			}
		}
	for(i=0;i<25;i++){
		numberstore[i] = 0;
	}
	for(i=0;i<12;i++){
		fla[i] = 0;
	}
	bingo=0;
	}


int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
        ChangeWindowMode(TRUE);
		if(DxLib_Init()==-1)return -1;
		SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更,初期化,裏画面設定

		Image = LoadGraph("white.png");
		black = LoadGraph("black.png");
		blue = LoadGraph("blue.png");
		green = LoadGraph("green.png");
		red = LoadGraph("red.png");
		pink = LoadGraph("pink.png");
		//Hole = LoadGraph("hole.png");
		reset = LoadGraph("リセットボタン.png");
		Font1 = CreateFontToHandle( "NULL", 50,  9, DX_FONTTYPE_NORMAL ) ;  
		Frame = black;

		Numberset();

  while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 ){
	  ClsDrawScreen();
	  Mouse = GetMouseInput();
	  GetMousePoint( &x, &y );
	DrawRotaGraph( 320, 240, 1.0, 0.0, Image, TRUE );	
	DrawRotaGraph( 220, 240, 0.85, 0.0, Frame, TRUE );
	DrawRotaGraph( 120, 425, 1.0, 0.0, reset, TRUE );
	DrawStringToHandle( 210, 10,"B i n g o ", Color,Font1);
	//DrawFormatString( 500, 450, Color, "座標[%d,%d]", x, y); 


	for(i=0;i<5;i++){
		if(t==0){
		 DrawFormatString( 60, 100, Color, "%d", number[i] );
		}
		if(t==1){
		 DrawFormatString( 130, 100, Color, "%d", number[i] );
		}
		if(t==2){
		 DrawFormatString( 195, 100, Color, "%d", number[i] );
		}
		if(t==3){
		 DrawFormatString( 262, 100, Color, "%d", number[i] );
		}
		if(t==4){
		 DrawFormatString( 328, 100, Color, "%d", number[i] );
		}
		 t++;
	}
	t=0;
	for(i=5;i<10;i++){
		 if(t==0){
		 DrawFormatString( 60, 158, Color, "%d", number[i] );
		}
		if(t==1){
		 DrawFormatString( 130, 158, Color, "%d", number[i] );
		}
		if(t==2){
		 DrawFormatString( 195, 158, Color, "%d", number[i] );
		}
		if(t==3){
		 DrawFormatString( 262, 158, Color, "%d", number[i] );
		}
		if(t==4){
		 DrawFormatString( 328, 158, Color, "%d", number[i] );
		}
		t++;
  }
	t=0;
	for(i=10;i<15;i++){
		if(t==0){
		 DrawFormatString( 60, 217, Color, "%d", number[i] );
		}
		if(t==1){
		 DrawFormatString( 130, 217, Color, "%d", number[i] );
		}
		if(t==2){
		 DrawFormatString( 195, 217, Color, "%d", number[i] );
		}
		if(t==3){
		 DrawFormatString( 262, 217, Color, "%d", number[i] );
		}
		if(t==4){
		 DrawFormatString( 328, 217, Color, "%d", number[i] );
		}
		t++;
  }
	t=0;
	for(i=15;i<20;i++){
		 if(t==0){
		 DrawFormatString( 60, 277, Color, "%d", number[i] );
		}
		if(t==1){
		 DrawFormatString( 130, 277, Color, "%d", number[i] );
		}
		if(t==2){
		 DrawFormatString( 195, 277, Color, "%d", number[i] );
		}
		if(t==3){
		 DrawFormatString( 262, 277, Color, "%d", number[i] );
		}
		if(t==4){
		 DrawFormatString( 328, 277, Color, "%d", number[i] );
		}
		t++;
  }
	t=0;
	for(i=20;i<25;i++){
		 if(t==0){
		 DrawFormatString( 60, 339, Color, "%d", number[i] );
		}
		if(t==1){
		 DrawFormatString( 130, 339, Color, "%d", number[i] );
		}
		if(t==2){
		 DrawFormatString( 195, 339, Color, "%d", number[i] );
		}
		if(t==3){
		 DrawFormatString( 262, 339, Color, "%d", number[i] );
		}
		if(t==4){
		 DrawFormatString( 328, 339, Color, "%d", number[i] );
		}
		t++;
  }
	t=0;

	if(x>=39&&x<=94&&y>=79&&y<=127&&Mouse==1&&MOUSE_INPUT_LEFT){
		number[0]=0;numberstore[0]=1;
	}
	if(x>=39&&x<=94&&y>=140&&y<=186&&Mouse&&MOUSE_INPUT_LEFT){
		number[5]=0;numberstore[5]=1;
	}
	if(x>=39&&x<=94&&y>=199&&y<=246&&Mouse&&MOUSE_INPUT_LEFT){
		number[10]=0;numberstore[10]=1;
	}
	if(x>=39&&x<=94&&y>=259&&y<=305&&Mouse&&MOUSE_INPUT_LEFT){
		number[15]=0;numberstore[15]=1;
	}
	if(x>=39&&x<=94&&y>=318&&y<=368&&Mouse&&MOUSE_INPUT_LEFT){
		number[20]=0;numberstore[20]=1;
	}

	if(x>=107&&x<=161&&y>=79&&y<=127&&Mouse&&MOUSE_INPUT_LEFT){
		number[1]=0;numberstore[1]=1;
	}
	if(x>=107&&x<=161&&y>=140&&y<=186&&Mouse&&MOUSE_INPUT_LEFT){
		number[6]=0;numberstore[6]=1;
	}
	if(x>=107&&x<=161&&y>=199&&y<=246&&Mouse&&MOUSE_INPUT_LEFT){
		number[11]=0;numberstore[11]=1;
	}
	if(x>=107&&x<=161&&y>=259&&y<=305&&Mouse&&MOUSE_INPUT_LEFT){
		number[16]=0;numberstore[16]=1;
	}
	if(x>=107&&x<=161&&y>=318&&y<=368&&Mouse&&MOUSE_INPUT_LEFT){
		number[21]=0;numberstore[21]=1;
	}

	if(x>=174&&x<=229&&y>=79&&y<=127&&Mouse&&MOUSE_INPUT_LEFT){
		number[2]=0;numberstore[2]=1;
	}
	if(x>=174&&x<=229&&y>=140&&y<=186&&Mouse&&MOUSE_INPUT_LEFT){
		number[7]=0;numberstore[7]=1;
	}
	if(x>=174&&x<=229&&y>=199&&y<=246&&Mouse&&MOUSE_INPUT_LEFT){
		number[12]=0;numberstore[12]=1;
	}
	if(x>=174&&x<=229&&y>=259&&y<=305&&Mouse&&MOUSE_INPUT_LEFT){
		number[17]=0;numberstore[17]=1;
	}
	if(x>=174&&x<=229&&y>=318&&y<=368&&Mouse&&MOUSE_INPUT_LEFT){
		number[22]=0;numberstore[22]=1;
	}

	if(x>=242&&x<=297&&y>=79&&y<=127&&Mouse&&MOUSE_INPUT_LEFT){
		number[3]=0;numberstore[3]=1;
	}
	if(x>=242&&x<=297&&y>=140&&y<=186&&Mouse&&MOUSE_INPUT_LEFT){
		number[8]=0;numberstore[8]=1;
	}
	if(x>=242&&x<=297&&y>=199&&y<=246&&Mouse&&MOUSE_INPUT_LEFT){
		number[13]=0;numberstore[13]=1;
	}
	if(x>=242&&x<=297&&y>=259&&y<=305&&Mouse&&MOUSE_INPUT_LEFT){
		number[18]=0;numberstore[18]=1;
	}
	if(x>=242&&x<=297&&y>=318&&y<=368&&Mouse&&MOUSE_INPUT_LEFT){
		number[23]=0;numberstore[23]=1;
	}

	if(x>=310&&x<=364&&y>=79&&y<=127&&Mouse&&MOUSE_INPUT_LEFT){
		number[4]=0;numberstore[4]=1;
	}
	if(x>=310&&x<=364&&y>=140&&y<=186&&Mouse&&MOUSE_INPUT_LEFT){
		number[9]=0;numberstore[9]=1;
	}
	if(x>=310&&x<=364&&y>=199&&y<=246&&Mouse&&MOUSE_INPUT_LEFT){
		number[14]=0;numberstore[14]=1;
	}
	if(x>=310&&x<=364&&y>=259&&y<=305&&Mouse&&MOUSE_INPUT_LEFT){
		number[19]=0;numberstore[19]=1;
	}
	if(x>=310&&x<=364&&y>=318&&y<=368&&Mouse&&MOUSE_INPUT_LEFT){
		number[24]=0;numberstore[24]=1;
	}
	//リーチ判定（未完成）
	if(numberstore[0]&&numberstore[1]&&numberstore[2]&&numberstore[3]==1||
	   numberstore[0]&&numberstore[1]&&numberstore[2]&&numberstore[4]==1||
	   numberstore[0]&&numberstore[1]&&numberstore[3]&&numberstore[4]==1||
	   numberstore[0]&&numberstore[2]&&numberstore[3]&&numberstore[4]==1||
	   numberstore[1]&&numberstore[2]&&numberstore[3]&&numberstore[4]==1){
	   reach[0]=1;
	}
	if(numberstore[5]&&numberstore[6]&&numberstore[7]&&numberstore[8]==1||
	   numberstore[5]&&numberstore[6]&&numberstore[7]&&numberstore[9]==1||
	   numberstore[5]&&numberstore[6]&&numberstore[8]&&numberstore[9]==1||
	   numberstore[5]&&numberstore[7]&&numberstore[8]&&numberstore[9]==1||
	   numberstore[6]&&numberstore[7]&&numberstore[8]&&numberstore[9]==1){
	   reach[1]=1;
	}
	if(numberstore[10]&&numberstore[11]&&numberstore[12]&&numberstore[13]==1||
	   numberstore[10]&&numberstore[11]&&numberstore[12]&&numberstore[14]==1||
	   numberstore[10]&&numberstore[11]&&numberstore[13]&&numberstore[14]==1||
	   numberstore[10]&&numberstore[12]&&numberstore[13]&&numberstore[14]==1||
	   numberstore[11]&&numberstore[12]&&numberstore[13]&&numberstore[14]==1){
	   reach[2]=1;
	}
	if(numberstore[15]&&numberstore[16]&&numberstore[17]&&numberstore[18]==1||
	   numberstore[15]&&numberstore[16]&&numberstore[17]&&numberstore[19]==1||
	   numberstore[15]&&numberstore[16]&&numberstore[18]&&numberstore[19]==1||
	   numberstore[15]&&numberstore[17]&&numberstore[18]&&numberstore[19]==1||
	   numberstore[16]&&numberstore[17]&&numberstore[18]&&numberstore[19]==1){
	   reach[3]=1;
	}
	
	//ビンゴ判定
	for(i=0;i<=11;i++){
	if(numberstore[0]==1&&numberstore[1]==1&&numberstore[2]==1&&numberstore[3]==1&&numberstore[4]==1&&bingo==i&&fla[0]==0){
		bingo++;fla[0]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[5]==1&&numberstore[6]==1&&numberstore[7]==1&&numberstore[8]==1&&numberstore[9]==1&&bingo==i&&fla[1]==0){
		bingo++;fla[1]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[10]==1&&numberstore[11]==1&&numberstore[12]==1&&numberstore[13]==1&&numberstore[14]==1&&bingo==i&&fla[2]==0){
		bingo++;fla[2]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[15]==1&&numberstore[16]==1&&numberstore[17]==1&&numberstore[18]==1&&numberstore[19]==1&&bingo==i&&fla[3]==0){
		bingo++;fla[3]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[20]==1&&numberstore[21]==1&&numberstore[22]==1&&numberstore[23]==1&&numberstore[24]==1&&bingo==i&&fla[4]==0){
		bingo++;fla[4]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[0]==1&&numberstore[5]==1&&numberstore[10]==1&&numberstore[15]==1&&numberstore[20]==1&&bingo==i&&fla[5]==0){
		bingo++;fla[5]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[1]==1&&numberstore[6]==1&&numberstore[11]==1&&numberstore[16]==1&&numberstore[21]==1&&bingo==i&&fla[6]==0){
		bingo++;fla[6]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[2]==1&&numberstore[7]==1&&numberstore[12]==1&&numberstore[17]==1&&numberstore[22]==1&&bingo==i&&fla[7]==0){
		bingo++;fla[7]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[3]==1&&numberstore[8]==1&&numberstore[13]==1&&numberstore[18]==1&&numberstore[23]==1&&bingo==i&&fla[8]==0){
		bingo++;fla[8]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[4]==1&&numberstore[9]==1&&numberstore[14]==1&&numberstore[19]==1&&numberstore[24]==1&&bingo==i&&fla[9]==0){
		bingo++;fla[9]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[0]==1&&numberstore[6]==1&&numberstore[12]==1&&numberstore[18]==1&&numberstore[24]==1&&bingo==i&&fla[10]==0){
		bingo++;fla[10]++;
		}
	}
	for(i=0;i<=11;i++){
	if(numberstore[4]==1&&numberstore[8]==1&&numberstore[12]==1&&numberstore[16]==1&&numberstore[20]==1&&bingo==i&&fla[11]==0){
		bingo++;fla[11]++;
		}
	}
	
    DrawFormatString( 410, 320, Color, "%dBINGO!",  bingo);


	DrawFormatString( 410, 200, Color, "色");
	//black
	DrawFormatString( 450, 200, GetColor(0,0,0), "■");
	//blue
	DrawFormatString( 470, 200, GetColor(0,0,255), "■");
	//green
	DrawFormatString( 490, 200, GetColor(0,128,0), "■");
	//red
	DrawFormatString( 510, 200, GetColor(255,0,0), "■");
	//pink
	DrawFormatString( 530, 200, GetColor(255,192,203), "■");

	//色変え
	if(x>=450&&x<=465&&y>=200&&y<=215&&Mouse==1&&MOUSE_INPUT_LEFT){
		Color=GetColor(0,0,0);Frame=black;
	}
	if(x>=470&&x<=485&&y>=200&&y<=215&&Mouse==1&&MOUSE_INPUT_LEFT){
		Color=GetColor(0,0,255);Frame=blue;
	}
	if(x>=490&&x<=505&&y>=200&&y<=215&&Mouse==1&&MOUSE_INPUT_LEFT){
		Color=GetColor(0,128,0);Frame=green;
	}
	if(x>=510&&x<=525&&y>=200&&y<=215&&Mouse==1&&MOUSE_INPUT_LEFT){
		Color=GetColor(255,0,0);Frame=red;
	}
	if(x>=530&&x<=545&&y>=200&&y<=215&&Mouse==1&&MOUSE_INPUT_LEFT){
		Color=GetColor(255,192,203);Frame=pink;
	}

    if(x>=20&&x<=220&&y>=400&&y<=450&&Mouse&&MOUSE_INPUT_LEFT){
		Numberset();
	}
	
  }
        DxLib_End();
        return 0;
}