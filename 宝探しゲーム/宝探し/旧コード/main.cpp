#include "DxLib.h"
#include <stdlib.h>
#include <math.h>
#include <time.h>
#define PI 3.141592654

 char Key[256];

 int gpUpdateKey(){
	char tmpKey[256]; // ���݂̃L�[�̓��͏�Ԃ��i�[����
	GetHitKeyStateAll( tmpKey ); // �S�ẴL�[�̓��͏�Ԃ𓾂�
	for( int i=0; i<256; i++ ){ 
		if( tmpKey[i] != 0 ){ // i�Ԃ̃L�[�R�[�h�ɑΉ�����L�[��������Ă�����
			Key[i]++;     // ���Z
		} else {              // ������Ă��Ȃ����
			Key[i] = 0;   // 0�ɂ���
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
 int boxstore1;//���̏��
 int boxstore2;
 int boxstore3;
 int boxstore4;
 int boxstore5;
 int boxstore6;
 char *infor;
 int boxcount=0;//���񔠂��J�������J�E���g
 int boxflag=0;//�󔠂͌���������I���@���ɏo���瑼�̔����J���Ȃ����邽�߂̃t���O
 int yes=0;//yesbox���������Ƃ���yes=1�ɂ��ĕ󔠂͌���������I�ƕ\��
 int hit=0;//����yesbox���J������
 int gamecount=1;//10��Q�[�������Ƃ��̉���
 int ote=0;//���Ă��̉�
 int game;//game��0�̂Ƃ����񂽂�A1�̂Ƃ��ӂ��A2�̂Ƃ��ނ�������

 typedef struct{
        int a, b;       // ���W�i�[�p�ϐ�
        char name[128]; // ���ږ��i�[�p�ϐ�
} MenuElement_t;

 void Menu();//���j���[�i�^�C�g���j
 void Boxset();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
 void Easy();//���񂽂�Q�[���J�n
 void Normal();
 void Hard();
 void Result();
 void Help();
 
int WINAPI WinMain(HINSTANCE,HINSTANCE,LPSTR,int){
        ChangeWindowMode(TRUE), DxLib_Init(), SetDrawScreen( DX_SCREEN_BACK ); //�E�B���h�E���[�h�ύX�Ə������Ɨ���ʐݒ�
     x=320,y=240;
	 FontHandle=CreateFontToHandle( NULL , 30 , 3 );
	Handle=LoadGraph("arrow37-032.png");//��ʂœ������|�C���^FREE�f��
	 Draw=LoadGraph("futta0796m.png");//�w�iFREE�f��
	 Draw2=LoadGraph("beach.png");//�w�iFREE�f��
	 box=LoadGraph("������.png");//�����ŕ`�����󔠂̊G�i���蕳�j
	 nobox=LoadGraph("��̕�.png");
	 yesbox=LoadGraph("��̕�.png");
	 bombbox=LoadGraph("���e�̕�.png");

		while( ScreenFlip()==0 && ProcessMessage()==0 && ClearDrawScreen()==0 && gpUpdateKey()==0){
			ClsDrawScreen();
		if( Key[ KEY_INPUT_RIGHT ] >= 1 ){ // �E�L�[��������Ă�����
			x=x+5;                       // �E�ֈړ�
		}
		if( Key[ KEY_INPUT_DOWN  ] >= 1 ){ // ���L�[��������Ă�����
			y=y+5;                       // ���ֈړ�
		}
		if( Key[ KEY_INPUT_LEFT  ] >= 1 ){ // ���L�[��������Ă�����
			x=x-5;                       // ���ֈړ�
		}
		if( Key[ KEY_INPUT_UP    ] >= 1 ){ // ��L�[��������Ă�����
			y=y-5;                      // ��ֈړ�
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
		 DxLib_End(); // DX���C�u�����I������
	     return 0;
		 }

void Menu(){
	
		MenuElement_t MenuElement[4]={
                { 170, 300, "���񂽂�" }, // �^�O�̒��g�̏��ԂŊi�[�����Bx��80���Ay��100���Aname��"�Q�[���X�^�[�g"��
                { 280, 300, "�ӂ�" },
                { 380, 300, "�ނ�������" },
                { 280, 350, "�w���v" },
        };
        int SelectNum = 0;
	
	 DrawRotaGraph( 320, 240, 1.0,  0.0, Draw, TRUE );
     DrawRotaGraph( x, y, 1.0, 0.0, Handle, TRUE );
     DrawStringToHandle( 50, 140, "            ��T���Q�[��", White, FontHandle);
     DrawFormatString( 130, 450, Green, "�ǂꂩ�ɑI�����ăX�y�[�X�L�[�������ĂˁI(���L�[�ړ��j");
	 //�f�o�b�N�pDrawFormatString( 50, 450, Green, "���W[%d,%d]", x, y ); 

		 for( int i=0; i<4; i++ ){ // ���j���[���ڂ�`��
            DrawFormatString( MenuElement[i].a, MenuElement[i].b, GetColor(255,255,255), MenuElement[i].name );
                }
		 if(x>=165&&x<=310&&y>=290&&320>=y&&Key&&Key[KEY_INPUT_SPACE]==1){
			 Boxset();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
			 infor="   ";
			 game=0;
			 Menucount=Eas;}
		 if(x>=275&&x<=335&&y>=290&&320>=y&&Key&&Key[KEY_INPUT_SPACE]==1){
			 Boxset();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
			 infor="   ";
			 game=1;
			 Menucount=Nor;}
		 if(x>=375&&x<=470&&y>=290&&320>=y&&Key&&Key[KEY_INPUT_SPACE]==1){
			 Boxset();//�󔠁A�󔠓��̏ꏊ�̈ʒu�����߂�
			 infor="   ";
			 game=2;
			 Menucount=Har;}
		 if(x>=275&&x<=335&&y>=345&&375>=y&&Key&&Key[KEY_INPUT_SPACE]==1){
			 Menucount=Hel;}
}


void Boxset(){
	//6�̔���0�`5�܂ł��ꂼ�ꂩ�Ԃ�Ȃ��Ⴄ�l������@�Q�l�T�C�g http://q.hatena.ne.jp/1307178107 
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
	     //DrawFormatString( 0, 450, White, "���W[%d,%d],%d,%d,%d,%d,%d,%d", x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
		 DrawFormatString( 280, 20, Green, "%s",infor);
		 DrawFormatString( 35, 415, White, "%d/10���", gamecount); 
		  DrawFormatString( 35, 435, White, "���Ă��@%d/2", ote); 
		//67829769��yesbox�̂Ƃ��̗����A67764232��nobox�̂Ƃ��̗���
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
			 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[2]==67829769||boxopen[4]==67829769||boxopen[5]==67829769){
			 infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[3]==67829769||boxopen[5]==67829769){
				infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[3]==67829769||boxopen[4]==67829769){
				 infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[1]==67829769||boxopen[2]==67829769||boxopen[5]==67829769){
				 infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[2]==67829769){
				 infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[1]==67829769||boxopen[3]==67829769){
				 infor="�����ɔ����I";ote++;
	       }
			
		 }
		 }

		 if(yes==1&&boxcount==1&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "�󔠔����I�iEnter�L�[�Ői�ށj");
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
			 DrawFormatString( 200, 450, Green, "�󔠂͌���������I�iEnter�L�[�Ői�ށj");
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
			 DrawFormatString( 200, 450, Green, "�󔠂͌�����Ȃ������E�E�E�iEnter�L�[�Ői�ށj");
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
	     //DrawFormatString( 0, 450, White, "���W[%d,%d],%d,%d,%d,%d,%d,%d", x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
		 DrawFormatString( 280, 20, Green, "%s",infor);
		 DrawFormatString( 35, 415, White, "%d/10���", gamecount); 
		  DrawFormatString( 35, 435, White, "���Ă��@%d/1", ote); 
		//67829769��yesbox�̂Ƃ��̗����A67764232��nobox�̂Ƃ��̗���
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
			 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[2]==67829769||boxopen[4]==67829769||boxopen[5]==67829769){
			 infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[3]==67829769||boxopen[5]==67829769){
				infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[3]==67829769||boxopen[4]==67829769){
				 infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[1]==67829769||boxopen[2]==67829769||boxopen[5]==67829769){
				 infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[2]==67829769){
				 infor="�����ɔ����I";ote++;
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
				 infor="�߂��ɔ����I";ote++;
	       }
			 if(boxopen[0]==67829769||boxopen[1]==67829769||boxopen[3]==67829769){
				 infor="�����ɔ����I";ote++;
	       }
			
		 }
		 }

		 if(yes==1&&boxcount==1&&x>=-99999&&y>=-99999){
			 boxflag=1;
			 DrawFormatString( 200, 450, Green, "�󔠔����I�iEnter�L�[�Ői�ށj");
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
			 DrawFormatString( 200, 450, Green, "�󔠂͌���������I�iEnter�L�[�Ői�ށj");
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
			 DrawFormatString( 200, 450, Green, "�󔠂͌�����Ȃ������E�E�E�iEnter�L�[�Ői�ށj");
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
	     //DrawFormatString( 0, 450, White, "���W[%d,%d],%d,%d,%d,%d,%d,%d", x, y, boxopen[0],boxopen[1],boxopen[2],boxopen[3],boxopen[4],boxopen[5]); 
		 DrawFormatString( 280, 20, Green, "%s",infor);
		 DrawFormatString( 35, 415, White, "%d/10���", gamecount);  
		//67829769��yesbox�̂Ƃ��̗����A67764232��nobox�̂Ƃ��̗���
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
			 DrawFormatString( 200, 450, Green, "�󔠔����I�iEnter�L�[�Ői�ށj");
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
			 DrawFormatString( 200, 450, Green, "�󔠂͌�����Ȃ������E�E�E�iEnter�L�[�Ői�ށj");
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
		//DrawFormatString( 50, 450, Green, "���W[%d,%d]", x, y );
		DrawFormatString( 120, 145, White, "�󔠂��������񐔁@%d/10", hit);
	if(0<=hit&&hit<=3){
        DrawStringToHandle( 120, 240, "�c�O�I�����Ɗ撣�낤�I", White, FontHandle);
		if(game==0){
		DrawFormatString( 20, 330, White, "������x���񂽂�ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if(game==1){
		DrawFormatString( 20, 330, White, "������x�ӂ��ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if(game==2){
		DrawFormatString( 20, 330, White, "������x�ނ��������ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		DrawFormatString( 20, 350, White, "�^�C�g���ɖ߂�Ȃ�Enter�L�[�������Ă�");

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
        DrawStringToHandle( 120, 240, "�܂��܂����ˁI���̒��q�I", White, FontHandle);
		if(game==0){
		DrawFormatString( 20, 330, White, "������x���񂽂�ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if(game==1){
		DrawFormatString( 20, 330, White, "������x�ӂ��ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if(game==2){
		DrawFormatString( 20, 330, White, "������x�ނ��������ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		DrawFormatString( 20, 350, White, "�^�C�g���ɖ߂�Ȃ�Enter�L�[�������Ă�");

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
        DrawStringToHandle( 50, 180, "���Ȃ�ǂ��ˁI�p�[�t�F�N�g�ڎw���I", White, FontHandle);
	    DrawStringToHandle( 20, 220, "�ӂ��A�ނ��������̃��x���ɂ����킵�Ă� ", White, FontHandle);
		if(game==0){
		DrawFormatString( 20, 330, White, "������x���񂽂�ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if(game==1){
		DrawFormatString( 20, 330, White, "������x�ӂ��ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if(game==2){
		DrawFormatString( 20, 330, White, "������x�ނ��������ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		DrawFormatString( 20, 350, White, "�^�C�g���ɖ߂�Ȃ�Enter�L�[�������Ă�");


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
        DrawStringToHandle( 50, 180, "�p�[�t�F�N�g�I�N�͕󔠃}�X�^�[���I", White, FontHandle);
		DrawStringToHandle( 20, 220, "�ӂ��A�ނ��������̃��x���ɂ����킵�Ă�", White, FontHandle);
		if(game==0){
		DrawFormatString( 20, 330, White, "������x���񂽂�ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if(game==1){
		DrawFormatString( 20, 330, White, "������x�ӂ��ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		if(game==2){
		DrawFormatString( 20, 330, White, "������x�ނ��������ŃQ�[�����n�߂�Ȃ�E�V�t�g�L�[���A");
		}
		DrawFormatString( 20, 350, White, "�^�C�g���ɖ߂�Ȃ�Enter�L�[�������Ă�");


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
	DrawFormatString( 100, 50, White, "���T���Q�[���ł��B����ȊO�̉��҂ł��Ȃ��ł��B");
	DrawFormatString( 100, 70, White, "�����̈ӎv�𗊂�ɕ�𓖂ĂĂ݂Ă��������B");
	DrawFormatString( 100, 100, White, "�₳�����@:���Ă�2��܂�(�����^���K�v�ȂƂ�������)");
	DrawFormatString( 100, 120, White, "�ӂ��@�@:���Ă�1��܂�(�قډ^���K�v)");
	DrawFormatString( 100, 140, White, "�ނ�������:���Ă��͂�邹��(�^)");
	DrawFormatString( 100, 170, White, "���Ă��������Փx�Ɋւ��Ă�");
	DrawFormatString( 100, 190, White, "�����������Ȃ��Ă���Ɂ@�߂��ɔ���!");
	DrawFormatString( 100, 210, White, "�܂��́@�����ɔ���!���\������܂��B");
	DrawFormatString( 100, 230, White, "�߂��ɂ̏ꍇ�͏c�܂��͉��ׂ̕󔠂ɕ󂪂���A");
	DrawFormatString( 100, 250, White, "�����ɂ̏ꍇ�͋߂��ɂ̈ȊO�̂Ƃ���ɕ󂪂���킯�ł��B");
	DrawFormatString( 100, 280, White, "���L�[�F�ړ��@�X�y�[�X�L�[�F�󔠂��J��");
	DrawFormatString( 200, 310, White, "�X�y�[�X�L�[�Ń^�C�g���ɖ߂�");

	if(Key[KEY_INPUT_SPACE]==1){
		Menucount=Title;
		}
}

