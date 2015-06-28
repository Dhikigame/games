#include "DxLib.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.141592654

 char Key[256];

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
	 Title=1,
	 Eas,
	 Nor,
	 Har,
	 Res,
	 Hel
 };

 int Menucount=1;
 int Count=0;
 int Green=GetColor( 0, 255, 0 ); 
 int White=GetColor(255,255,255);
 int FontHandle;
 int x,y;
 int Handle;
 int Draw;
 int Handle2;
 int Draw2;
 int box;
 int nobox;
 int yesbox;
 int bombbox;
 int i,j,flag;
 int boxopen[6];
 int boxstore1;//箱の状態
 int boxstore2;
 int boxstore3;
 int boxstore4;
 int boxstore5;
 int boxstore6;
 char *infor;
 int boxcount=0;//何回箱を開いたかカウント
 int boxflag=0;//宝箱は見つかったよ！等　下に出たら他の箱を開けなくするためのフラグ
 int yes=0;//yesboxを見つけたときにyes=1にして宝箱は見つかったよ！と表示
 int hit=0;//何回yesboxを開けたか
 int gamecount=1;//10回ゲームしたときの何回か
 int ote=0;//おてつきの回数
 int game;//gameが0のときかんたん、1のときふつう、2のときむずかしい

 typedef struct{
        int a, b;       // 座標格納用変数
        char name[128]; // 項目名格納用変数
} MenuElement_t;

 void Menu();//メニュー（タイトル）
 void Boxset();//空箱、宝箱等の場所の位置を決める
 void Easy();//かんたんゲーム開始
 void Normal();
 void Hard();
 void Result();
 void Help();
 
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
        ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //ウィンドウモード変更と初期化と裏画面設定
     x=320,y=240;
	 FontHandle=CreateFontToHandle( NULL , 30 , 3 );
	Handle=LoadGraph("arrow37-032.png");//画面で動かすポインタFREE素材
	 Draw=LoadGraph("futta0796m.png");//背景FREE素材
	 Draw2=LoadGraph("beach.png");//背景FREE素材
	 box=LoadGraph("閉じた宝箱.png");//自分で描いた宝箱の絵（下手糞）
	 nobox=LoadGraph("空の宝箱.png");
	 yesbox=LoadGraph("宝の宝箱.png");
	 bombbox=LoadGraph("爆弾の宝箱.png");

		while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0){
			ClsDrawScreen();
		if( Key[ KEY_INPUT_RIGHT ] >= 1 ){ // 右キーが押されていたら
			x=x+5;                       // 右へ移動
		}
		if( Key[ KEY_INPUT_DOWN  ] >= 1 ){ // 下キーが押されていたら
			y=y+5;                       // 下へ移動
		}
		if( Key[ KEY_INPUT_LEFT  ] >= 1 ){ // 左キーが押されていたら
			x=x-5;                       // 左へ移動
		}
		if( Key[ KEY_INPUT_UP    ] >= 1 ){ // 上キーが押されていたら
			y=y-5;                      // 上へ移動
		}
		
		 switch(Menucount){
		 case Title:Menu();break;
		 case Eas:Easy();break;
		 case Nor:Normal();break;
		 case Har:Hard();break;
		 case Res:Result();break;
		 case Hel:Help();break;
		 }
		 
		}
		 DxLib_End(); // DXライブラリ終了処理
	     return 0;
		 }

void Menu(){
	
		MenuElement_t MenuElement[4]={
                { 170, 300, "かんたん" }, // タグの中身の順番で格納される。xに80が、yに100が、nameに"ゲームスタート"が
                { 280, 300, "ふつう" },
                { 380, 300, "むずかしい" },
                { 280, 350, "ヘルプ" },
        };
        int SelectNum = 0;
	
	 DrawRotaGraph( 320, 240, 1.0,  0.0, Draw, TRUE );
     DrawRotaGraph( x, y, 1.0, 0.0, Handle, TRUE );
     DrawStringToHandle( 50, 140, "            宝探しゲーム", White, FontHandle);
     DrawFormatString( 130, 450, Green, "どれかに選択してスペースキーを押してね！(矢印キー移動）");
	 //デバック用DrawFormatString( 50, 450, Green, "座標[%d,%d]", x, y ); 

		 for( int i=0; i<4; i++ ){ // メニュー項目を描画
            DrawFormatString( MenuElement[i].a, MenuElement[i].b, GetColor(255,255,255), MenuElement[i].name );
                }
		 if(x>=165&&x<=310&&y>=290&&320>=y&&Key&&Key[KEY_INPUT_SPACE]==1){
			 Boxset();//空箱、宝箱等の場所の位置を決める
			 infor="   ";
			 game=0;
			 Menucount=Eas;}
		 if(x>=275&&x<=335&&y>=290&&320>=y&&Key&&Key[KEY_INPUT_SPACE]==1){
			 Boxset();//空箱、宝箱等の場所の位置を決める
			 infor="   ";
			 game=1;
			 Menucount=Nor;}
		 if(x>=375&&x<=470&&y>=290&&320>=y&&Key&&Key[KEY_INPUT_SPACE]==1){
			 Boxset();//空箱、宝箱等の場所の位置を決める
			 infor="   ";
			 game=2;
			 Menucount=Har;}
		 if(x>=275&&x<=335&&y>=345&&375>=y&&Key&&Key[KEY_INPUT_SPACE]==1){
			 Menucount=Hel;}
}


void Boxset(){
	//6つの箱に0～5までそれぞれかぶらない違う値を入れる　参考サイト http://q.hatena.ne.jp/1307178107 
	for(i=0;i<=5;i++){
		flag=TRUE;
		while(flag){
		flag=FALSE;
		boxopen[i]=GetRand(5);
			for(j=0;j<i;j++){
				if(boxopen[j]==boxopen[i]){
				flag=TRUE;
				break;
			}
		}
	}
}

	if(boxopen[0]==0){
		boxopen[0]=yesbox;
	}
	if(1<=boxopen[0]&&boxopen[0]<=5){
		boxopen[0]=nobox;
	}

	if(boxopen[1]==0){
		boxopen[1]=yesbox;
	}
	if(1<=boxopen[1]&&boxopen[1]<=5){
		boxopen[1]=nobox;
	}


	if(boxopen[2]==0){
		boxopen[2]=yesbox;
	}
	if(1<=boxopen[2]&&boxopen[2]<=5){
		boxopen[2]=nobox;
	}


	if(boxopen[3]==0){
		boxopen[3]=yesbox;
	}
	if(1<=boxopen[3]&&boxopen[3]<=5){
		boxopen[3]=nobox;
	}


	if(boxopen[4]==0){
		boxopen[4]=yesbox;
	}
	if(1<=boxopen[4]&&boxopen[4]<=5){
		boxopen[4]=nobox;
	}


	if(boxopen[5]==0){
		boxopen[5]=yesbox;
	}
	if(1<=boxopen[5]&&boxopen[5]<=5){
		boxopen[5]=nobox;
	}

}

 void Easy(){
	 if(boxcount==0){
        boxstore1=box;
        boxstore2=box;
        boxstore3=box;
        boxstore4=box;
        boxstore5=box;
        boxstore6=box;
	 }
         DrawRotaGraph( 320, 240, 1.0,  0.0, Draw2, TRUE );
		 DrawRotaGraph( 120, 110, 1.0, 0.0, boxstore1, TRUE );
		 DrawRotaGraph( 320, 110, 1.0, 0.0, boxstore2, TRUE );
		 DrawRotaGraph( 520, 110, 1.0, 0.0, boxstore3, TRUE );
		 DrawRotaGraph( 120, 300, 1.0, 0.0, boxstore4, TRUE );
		 DrawRotaGraph( 320, 300, 1.0, 0.0, boxstore5, TRUE );
		 DrawRotaGraph( 520, 300, 1.0, 0.0, boxstore6, TRUE );
		 DrawRotaGraph( x, y, 1.0, 0.0, Handle, TRUE );
	     //DrawFormatString( 0, 450, White, "座標[%d,%d],%d,%d,%d,%d,%d,%d", x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
		 DrawFormatString( 280, 20, Green, "%s",infor);
		 DrawFormatString( 35, 415, White, "%d/10回目", gamecount); 
		  DrawFormatString( 35, 435, White, "おてつき　%d/2", ote); 
		//67829769はyesboxのときの乱数、67764232はnoboxのときの乱数
		 if(x>=30&&x<=210&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[0]==67829769){
		     boxstore1=yesbox;
			 yes=1;
	       }
	         if(boxopen[0]==67764232){
		     boxstore1=nobox;
			 }
			 boxcount++;
			 if(boxcount>=1&&boxcount<=2&&x>=30&&x<=210&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1){

		if(boxopen[1]==67829769||boxopen[3]==67829769){
			 infor="近くに反応！";ote++;
	       }
			 if(boxopen[2]==67829769||boxopen[4]==67829769||boxopen[5]==67829769){
			 infor="遠くに反応！";ote++;
	       }
			 
		 }
	 }


		 if(x>=230&&x<=410&&y>=35&&185>=y&&Key&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[1]==67829769){
		     boxstore2=yesbox;
			 yes=1;
	       }
	         if(boxopen[1]==67764232){
		     boxstore2=nobox;		 
	       }
		     boxcount++;
			 if(boxcount>=1&&boxcount<=2&&x>=230&&x<=410&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1){
		 if(boxopen[0]==67829769||boxopen[2]==67829769||boxopen[4]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[3]==67829769||boxopen[5]==67829769){
				infor="遠くに反応！";ote++;
	         }
			
		 }
	}

		 if(x>=430&&x<=610&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[2]==67829769){
		     boxstore3=yesbox;
			 yes=1;
	       }
	         if(boxopen[2]==67764232){
		     boxstore3=nobox;
	       }
		     boxcount++;
			 if(boxcount>=1&&boxcount<=2&&x>=430&&x<=610&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1){
		 if(boxopen[1]==67829769||boxopen[5]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[3]==67829769||boxopen[4]==67829769){
				 infor="遠くに反応！";ote++;
	       }
			 
		 }
		 }

		 if(x>=30&&x<=210&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			 
			 if(boxopen[3]==67829769){
		     boxstore4=yesbox;
			 yes=1;
	       }
	         if(boxopen[3]==67764232){
		     boxstore4=nobox;
	       }
		     boxcount++;
			 if(boxcount>=1&&boxcount<=2&&x>=30&&x<=210&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1){
		 if(boxopen[0]==67829769||boxopen[4]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[1]==67829769||boxopen[2]==67829769||boxopen[5]==67829769){
				 infor="遠くに反応！";ote++;
	       }
			 
		 }
		 }

		 if(x>=230&&x<=410&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			
			 if(boxopen[4]==67829769){
		     boxstore5=yesbox;
			 yes=1;
	       }
	         if(boxopen[4]==67764232){
		     boxstore5=nobox;
	       }
		     boxcount++;
			 if(boxcount>=1&&boxcount<=2&&x>=230&&x<=410&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1){
		 if(boxopen[1]==67829769||boxopen[3]==67829769||boxopen[5]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[2]==67829769){
				 infor="遠くに反応！";ote++;
	       }
			
		}
		 }

		 if(x>=430&&x<=610&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			 
			 if(boxopen[5]==67829769){
		     boxstore6=yesbox;
			 yes=1;
	       }
	         if(boxopen[5]==67764232){
		     boxstore6=nobox;
	       }
		     boxcount++;
			 if(boxcount>=1&&boxcount<=2&&x>=430&&x<=610&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1){
		  if(boxopen[2]==67829769||boxopen[4]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[1]==67829769||boxopen[3]==67829769){
				 infor="遠くに反応！";ote++;
	       }
			
		 }
		 }

		 if(yes==1&&boxcount==1&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "宝箱発見！（Enterキーで進む）");
		     if(Key[KEY_INPUT_RETURN]==1){
			 Boxset();
			 boxcount=0;
			 boxflag=0;
			 yes=0;
			 hit++;
			 gamecount++;
			 ote=0;
			 infor="   ";
			 }
		 }

		 if(yes==1&&boxcount>=2&&boxcount<=3&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "宝箱は見つかったよ！（Enterキーで進む）");
		     if(Key[KEY_INPUT_RETURN]==1){
			 Boxset();
			 boxcount=0;
			 boxflag=0;
			 yes=0;
			 hit++;
			 gamecount++;
			 ote=0;
			 infor="   ";
			 }
		 }

		 if(yes==0&&boxcount==3&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "宝箱は見つからなかった・・・（Enterキーで進む）");
		     if(Key[KEY_INPUT_RETURN]==1){
			 Boxset();
			 boxcount=0;
			 boxflag=0;
			 yes=0;
			 ote=0;
			 gamecount++;
			 infor="   ";
			 }
		 }

		 if(gamecount==11){
			 Menucount=Res;
		 }
	}

	void Normal(){
	 if(boxcount==0){
        boxstore1=box;
        boxstore2=box;
        boxstore3=box;
        boxstore4=box;
        boxstore5=box;
        boxstore6=box;
	 }
         DrawRotaGraph( 320, 240, 1.0,  0.0, Draw2, TRUE );
		 DrawRotaGraph( 120, 110, 1.0, 0.0, boxstore1, TRUE );
		 DrawRotaGraph( 320, 110, 1.0, 0.0, boxstore2, TRUE );
		 DrawRotaGraph( 520, 110, 1.0, 0.0, boxstore3, TRUE );
		 DrawRotaGraph( 120, 300, 1.0, 0.0, boxstore4, TRUE );
		 DrawRotaGraph( 320, 300, 1.0, 0.0, boxstore5, TRUE );
		 DrawRotaGraph( 520, 300, 1.0, 0.0, boxstore6, TRUE );
		 DrawRotaGraph( x, y, 1.0, 0.0, Handle, TRUE );
	     //DrawFormatString( 0, 450, White, "座標[%d,%d],%d,%d,%d,%d,%d,%d", x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
		 DrawFormatString( 280, 20, Green, "%s",infor);
		 DrawFormatString( 35, 415, White, "%d/10回目", gamecount); 
		  DrawFormatString( 35, 435, White, "おてつき　%d/1", ote); 
		//67829769はyesboxのときの乱数、67764232はnoboxのときの乱数
		 if(x>=30&&x<=210&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[0]==67829769){
		     boxstore1=yesbox;
			 yes=1;
	       }
	         if(boxopen[0]==67764232){
		     boxstore1=nobox;
			 }
			 boxcount++;
			 if(boxcount==1&&x>=30&&x<=210&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1){

		if(boxopen[1]==67829769||boxopen[3]==67829769){
			 infor="近くに反応！";ote++;
	       }
			 if(boxopen[2]==67829769||boxopen[4]==67829769||boxopen[5]==67829769){
			 infor="遠くに反応！";ote++;
	       }
			 
		 }
	 }


		 if(x>=230&&x<=410&&y>=35&&185>=y&&Key&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[1]==67829769){
		     boxstore2=yesbox;
			 yes=1;
	       }
	         if(boxopen[1]==67764232){
		     boxstore2=nobox;		 
	       }
		     boxcount++;
			 if(boxcount==1&&x>=230&&x<=410&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1){
		 if(boxopen[0]==67829769||boxopen[2]==67829769||boxopen[4]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[3]==67829769||boxopen[5]==67829769){
				infor="遠くに反応！";ote++;
	         }
			
		 }
	}

		 if(x>=430&&x<=610&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[2]==67829769){
		     boxstore3=yesbox;
			 yes=1;
	       }
	         if(boxopen[2]==67764232){
		     boxstore3=nobox;
	       }
		     boxcount++;
			 if(boxcount==1&&x>=430&&x<=610&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1){
		 if(boxopen[1]==67829769||boxopen[5]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[3]==67829769||boxopen[4]==67829769){
				 infor="遠くに反応！";ote++;
	       }
			 
		 }
		 }

		 if(x>=30&&x<=210&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			 
			 if(boxopen[3]==67829769){
		     boxstore4=yesbox;
			 yes=1;
	       }
	         if(boxopen[3]==67764232){
		     boxstore4=nobox;
	       }
		     boxcount++;
			 if(boxcount==1&&x>=30&&x<=210&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1){
		 if(boxopen[0]==67829769||boxopen[4]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[1]==67829769||boxopen[2]==67829769||boxopen[5]==67829769){
				 infor="遠くに反応！";ote++;
	       }
			 
		 }
		 }

		 if(x>=230&&x<=410&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			
			 if(boxopen[4]==67829769){
		     boxstore5=yesbox;
			 yes=1;
	       }
	         if(boxopen[4]==67764232){
		     boxstore5=nobox;
	       }
		     boxcount++;
			 if(boxcount==1&&x>=230&&x<=410&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1){
		 if(boxopen[1]==67829769||boxopen[3]==67829769||boxopen[5]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[2]==67829769){
				 infor="遠くに反応！";ote++;
	       }
			
		}
		 }

		 if(x>=430&&x<=610&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			 
			 if(boxopen[5]==67829769){
		     boxstore6=yesbox;
			 yes=1;
	       }
	         if(boxopen[5]==67764232){
		     boxstore6=nobox;
	       }
		     boxcount++;
			 if(boxcount==1&&x>=430&&x<=610&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1){
		  if(boxopen[2]==67829769||boxopen[4]==67829769){
				 infor="近くに反応！";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[1]==67829769||boxopen[3]==67829769){
				 infor="遠くに反応！";ote++;
	       }
			
		 }
		 }

		 if(yes==1&&boxcount==1&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "宝箱発見！（Enterキーで進む）");
		     if(Key[KEY_INPUT_RETURN]==1){
			 Boxset();
			 boxcount=0;
			 boxflag=0;
			 yes=0;
			 hit++;
			 gamecount++;
			 ote=0;
			 infor="   ";
			 }
		 }

		 if(yes==1&&boxcount==2&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "宝箱は見つかったよ！（Enterキーで進む）");
		     if(Key[KEY_INPUT_RETURN]==1){
			 Boxset();
			 boxcount=0;
			 boxflag=0;
			 yes=0;
			 hit++;
			 gamecount++;
			 ote=0;
			 infor="   ";
			 }
		 }

		 if(yes==0&&boxcount==2&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "宝箱は見つからなかった・・・（Enterキーで進む）");
		     if(Key[KEY_INPUT_RETURN]==1){
			 Boxset();
			 boxcount=0;
			 boxflag=0;
			 yes=0;
			 ote=0;
			 gamecount++;
			 infor="   ";
			 }
		 }

		 if(gamecount==11){
			 Menucount=Res;
		 }
	}

	void Hard(){
	 if(boxcount==0){
        boxstore1=box;
        boxstore2=box;
        boxstore3=box;
        boxstore4=box;
        boxstore5=box;
        boxstore6=box;
	 }
         DrawRotaGraph( 320, 240, 1.0,  0.0, Draw2, TRUE );
		 DrawRotaGraph( 120, 110, 1.0, 0.0, boxstore1, TRUE );
		 DrawRotaGraph( 320, 110, 1.0, 0.0, boxstore2, TRUE );
		 DrawRotaGraph( 520, 110, 1.0, 0.0, boxstore3, TRUE );
		 DrawRotaGraph( 120, 300, 1.0, 0.0, boxstore4, TRUE );
		 DrawRotaGraph( 320, 300, 1.0, 0.0, boxstore5, TRUE );
		 DrawRotaGraph( 520, 300, 1.0, 0.0, boxstore6, TRUE );
		 DrawRotaGraph( x, y, 1.0, 0.0, Handle, TRUE );
	     //DrawFormatString( 0, 450, White, "座標[%d,%d],%d,%d,%d,%d,%d,%d", x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
		 DrawFormatString( 280, 20, Green, "%s",infor);
		 DrawFormatString( 35, 415, White, "%d/10回目", gamecount);  
		//67829769はyesboxのときの乱数、67764232はnoboxのときの乱数
		 if(x>=30&&x<=210&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[0]==67829769){
		     boxstore1=yesbox;
			 yes=1;
	       }
	         if(boxopen[0]==67764232){
		     boxstore1=nobox;
			 }
			 boxcount++;
		 }


		 if(x>=230&&x<=410&&y>=35&&185>=y&&Key&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[1]==67829769){
		     boxstore2=yesbox;
			 yes=1;
	       }
	         if(boxopen[1]==67764232){
		     boxstore2=nobox;		 
	       }
		     boxcount++;	
	}

		 if(x>=430&&x<=610&&y>=35&&185>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){

			 if(boxopen[2]==67829769){
		     boxstore3=yesbox;
			 yes=1;
	       }
	         if(boxopen[2]==67764232){
		     boxstore3=nobox;
	       }
		     boxcount++;
		 }

		 if(x>=30&&x<=210&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			 
			 if(boxopen[3]==67829769){
		     boxstore4=yesbox;
			 yes=1;
	       }
	         if(boxopen[3]==67764232){
		     boxstore4=nobox;
	       }
		     boxcount++;
		 }

		 if(x>=230&&x<=410&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			
			 if(boxopen[4]==67829769){
		     boxstore5=yesbox;
			 yes=1;
	       }
	         if(boxopen[4]==67764232){
		     boxstore5=nobox;
	       }
		     boxcount++;

		 }

		 if(x>=430&&x<=610&&y>=225&&375>=y&&Key[KEY_INPUT_SPACE]==1&&boxflag==0){
			 
			 if(boxopen[5]==67829769){
		     boxstore6=yesbox;
			 yes=1;
	       }
	         if(boxopen[5]==67764232){
		     boxstore6=nobox;
	       }
		     boxcount++;
		 }

		 if(yes==1&&boxcount==1&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "宝箱発見！（Enterキーで進む）");
		     if(Key[KEY_INPUT_RETURN]==1){
			 Boxset();
			 boxcount=0;
			 boxflag=0;
			 yes=0;
			 hit++;
			 gamecount++;
			 ote=0;
			 infor="   ";
			 }
		 }

		 if(yes==0&&boxcount==1&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "宝箱は見つからなかった・・・（Enterキーで進む）");
		     if(Key[KEY_INPUT_RETURN]==1){
			 Boxset();
			 boxcount=0;
			 boxflag=0;
			 yes=0;
			 ote=0;
			 gamecount++;
			 infor="   ";
			 }
		 }

		 if(gamecount==11){
			 Menucount=Res;
		 }
	}

void Result(){
		DrawRotaGraph( 320, 240, 1.0,  0.0, Draw, TRUE );
		DrawRotaGraph( x, y, 1.0, 0.0, Handle, TRUE );
		//DrawFormatString( 50, 450, Green, "座標[%d,%d]", x, y );
		DrawFormatString( 120, 145, White, "宝箱を見つけた回数　%d/10", hit);
	if(0<=hit&&hit<=3){
        DrawStringToHandle( 120, 240, "残念！もっと頑張ろう！", White, FontHandle);
		if(game==0){
		DrawFormatString( 20, 330, White, "もう一度かんたんでゲームを始めるなら右シフトキーを、");
		}
		if(game==1){
		DrawFormatString( 20, 330, White, "もう一度ふつうでゲームを始めるなら右シフトキーを、");
		}
		if(game==2){
		DrawFormatString( 20, 330, White, "もう一度むずかしいでゲームを始めるなら右シフトキーを、");
		}
		DrawFormatString( 20, 350, White, "タイトルに戻るならEnterキーを押してね");

		if(Key[KEY_INPUT_RETURN]==1){
		hit=0;
	    gamecount=1;
		Menucount=Title;
		}
		if(Key[KEY_INPUT_RSHIFT]==1){
        hit=0;
	    gamecount=1;
		if(game==0){
		Menucount=Eas;
		}
		if(game==1){
		Menucount=Nor;
		}
		if(game==2){
		Menucount=Har;
		}
		}
	  }

	if(4<=hit&&hit<=6){
        DrawStringToHandle( 120, 240, "まあまあだね！この調子！", White, FontHandle);
		if(game==0){
		DrawFormatString( 20, 330, White, "もう一度かんたんでゲームを始めるなら右シフトキーを、");
		}
		if(game==1){
		DrawFormatString( 20, 330, White, "もう一度ふつうでゲームを始めるなら右シフトキーを、");
		}
		if(game==2){
		DrawFormatString( 20, 330, White, "もう一度むずかしいでゲームを始めるなら右シフトキーを、");
		}
		DrawFormatString( 20, 350, White, "タイトルに戻るならEnterキーを押してね");

		if(Key[KEY_INPUT_RETURN]==1){
		hit=0;
	    gamecount=1;
		Menucount=Title;
		}
		if(Key[KEY_INPUT_RSHIFT]==1){
        hit=0;
	    gamecount=1;
		if(game==0){
		Menucount=Eas;
		}
		if(game==1){
		Menucount=Nor;
		}
		if(game==2){
		Menucount=Har;
		}
		}
	  }

	if(7<=hit&&hit<=9){
        DrawStringToHandle( 50, 180, "かなり良いね！パーフェクト目指せ！", White, FontHandle);
	    DrawStringToHandle( 20, 220, "ふつう、むずかしいのレベルにも挑戦してね ", White, FontHandle);
		if(game==0){
		DrawFormatString( 20, 330, White, "もう一度かんたんでゲームを始めるなら右シフトキーを、");
		}
		if(game==1){
		DrawFormatString( 20, 330, White, "もう一度ふつうでゲームを始めるなら右シフトキーを、");
		}
		if(game==2){
		DrawFormatString( 20, 330, White, "もう一度むずかしいでゲームを始めるなら右シフトキーを、");
		}
		DrawFormatString( 20, 350, White, "タイトルに戻るならEnterキーを押してね");


		if(Key[KEY_INPUT_RETURN]==1){
		hit=0;
	    gamecount=1;
		Menucount=Title;
		}
		if(Key[KEY_INPUT_RSHIFT]==1){
        hit=0;
	    gamecount=1;
		if(game==0){
		Menucount=Eas;
		}
		if(game==1){
		Menucount=Nor;
		}
		if(game==2){
		Menucount=Har;
		}
		}
	  }

	if(hit==10){
        DrawStringToHandle( 50, 180, "パーフェクト！君は宝箱マスターだ！", White, FontHandle);
		DrawStringToHandle( 20, 220, "ふつう、むずかしいのレベルにも挑戦してね", White, FontHandle);
		if(game==0){
		DrawFormatString( 20, 330, White, "もう一度かんたんでゲームを始めるなら右シフトキーを、");
		}
		if(game==1){
		DrawFormatString( 20, 330, White, "もう一度ふつうでゲームを始めるなら右シフトキーを、");
		}
		if(game==2){
		DrawFormatString( 20, 330, White, "もう一度むずかしいでゲームを始めるなら右シフトキーを、");
		}
		DrawFormatString( 20, 350, White, "タイトルに戻るならEnterキーを押してね");


		if(Key[KEY_INPUT_RETURN]==1){
		hit=0;
	    gamecount=1;
		Menucount=Title;
		}
		if(Key[KEY_INPUT_RSHIFT]==1){
        hit=0;
	    gamecount=1;
		if(game==0){
		Menucount=Eas;
		}
		if(game==1){
		Menucount=Nor;
		}
		if(game==2){
		Menucount=Har;
		}
		}
	  }
}

void Help(){
	DrawRotaGraph( 320, 240, 1.0,  0.0, Draw, TRUE );
	DrawFormatString( 100, 50, White, "宝を探すゲームです。それ以外の何者でもないです。");
	DrawFormatString( 100, 70, White, "自分の意思を頼りに宝を当ててみてください。");
	DrawFormatString( 100, 100, White, "やさしい　:おてつき2回まで(少し運が必要なときもある)");
	DrawFormatString( 100, 120, White, "ふつう　　:おてつき1回まで(ほぼ運が必要)");
	DrawFormatString( 100, 140, White, "むずかしい:おてつきはゆるせん(運)");
	DrawFormatString( 100, 170, White, "おてつきがある難易度に関しては");
	DrawFormatString( 100, 190, White, "もし見つけられなくても上に　近くに反応!");
	DrawFormatString( 100, 210, White, "または　遠くに反応!が表示されます。");
	DrawFormatString( 100, 230, White, "近くにの場合は縦または横隣の宝箱に宝があり、");
	DrawFormatString( 100, 250, White, "遠くにの場合は近くにの以外のところに宝があるわけです。");
	DrawFormatString( 100, 280, White, "矢印キー：移動　スペースキー：宝箱を開く");
	DrawFormatString( 200, 310, White, "スペースキーでタイトルに戻る");

	if(Key[KEY_INPUT_SPACE]==1){
		Menucount=Title;
		}
}

