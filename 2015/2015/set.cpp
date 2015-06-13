#include "GV.h"



void left_set(){
	add_leftx=0;
	for(int i=0;i<4;i++){
		for(int j=1;j<4;j++){

		if(j==1){
			if(set.box[j-1][i]==0 && set.box[j+1][i]==0 && set.box[j+2][i]==0 && set.box[j][i]==1){
			set.box[j-1][i]=1;
			set.box[j][i]=0;
			number.box[j-1][i]=number.box[j][i];
			number.box[j][i]=0;
			add_leftx=1;
		}
			if(set.box[j-1][i]==1 && set.box[j+1][i]==0 && set.box[j+2][i]==0 && set.box[j][i]==1){
			continue;
		}
	}

		if(j==2){
			if(set.box[j-1][i]==0 && set.box[j-2][i]==0 && set.box[j+1][i]==0 && set.box[j][i]==1){
			set.box[j-2][i]=1;
			set.box[j][i]=0;
			number.box[j-2][i]=number.box[j][i];
			number.box[j][i]=0;
			add_leftx=1;
		}
			if(set.box[j-1][i]==0 && set.box[j-2][i]==1 && set.box[j+1][i]==0 && set.box[j][i]==1){
			set.box[j-1][i]=1;
			set.box[j][i]=0;
			number.box[j-1][i]=number.box[j][i];
			number.box[j][i]=0;
			add_leftx=1;
		}
			if(set.box[j-1][i]==1 && set.box[j-2][i]==0 && set.box[j+1][i]==0 && set.box[j][i]==1){
			set.box[j-2][i]=1;
			set.box[j-1][i]=1;
			set.box[j][i]=0;
			number.box[j-2][i]=number.box[j-1][i];
			number.box[j-1][i]=number.box[j][i];
			number.box[j][i]=0;
			add_leftx=1;
		}
			if(set.box[j-1][i]==1 && set.box[j-2][i]==1 && set.box[j+1][i]==0 && set.box[j][i]==1){
			continue;
		}
	}

		if(j==3){
			if(set.box[j-1][i]==0 && set.box[j-2][i]==0 && set.box[j-3][i]==0 && set.box[j][i]==1){
				set.box[j-3][i]=1;
				set.box[j][i]=0;
				number.box[j-3][i]=number.box[j][i];
				number.box[j][i]=0;
				add_leftx=1;
		}
			if(set.box[j-1][i]==0 && set.box[j-2][i]==0 && set.box[j-3][i]==1 && set.box[j][i]==1){
				set.box[j-2][i]=1;
				set.box[j][i]=0;
				number.box[j-2][i]=number.box[j][i];
				number.box[j][i]=0;
				add_leftx=1;
		}
			if(set.box[j-1][i]==0 && set.box[j-2][i]==1 && set.box[j-3][i]==0 && set.box[j][i]==1){
				set.box[j-3][i]=1;
				set.box[j][i]=0;
				number.box[j-3][i]=number.box[j-2][i];
				number.box[j-2][i]=number.box[j][i];
				number.box[j][i]=0;
				add_leftx=1;
		}
			if(set.box[j-1][i]==1 && set.box[j-2][i]==0 && set.box[j-3][i]==0 && set.box[j][i]==1){
				set.box[j-3][i]=1;
				set.box[j-2][i]=1;
				set.box[j-1][i]=0;
				set.box[j][i]=0;
				number.box[j-3][i]=number.box[j-1][i];
				number.box[j-2][i]=number.box[j][i];
				number.box[j-1][i]=0;
				number.box[j][i]=0;
				add_leftx=1;
		}
			if(set.box[j-1][i]==0 && set.box[j-2][i]==1 && set.box[j-3][i]==1 && set.box[j][i]==1){
				set.box[j-1][i]=1;
				set.box[j][i]=0;
				number.box[j-1][i]=number.box[j][i];
				number.box[j][i]=0;
				add_leftx=1;
		}
			if(set.box[j-1][i]==1 && set.box[j-2][i]==0 && set.box[j-3][i]==1 && set.box[j][i]==1){
				set.box[j-2][i]=1;
				set.box[j][i]=0;
				number.box[j-2][i]=number.box[j-1][i];
				number.box[j-1][i]=number.box[j][i];
				number.box[j][i]=0;
				add_leftx=1;
		}
			if(set.box[j-1][i]==1 && set.box[j-2][i]==1 && set.box[j-3][i]==0 && set.box[j][i]==1){
				set.box[j-3][i]=1;
				set.box[j][i]=0;
				number.box[j-3][i]=number.box[j-2][i];
				number.box[j-2][i]=number.box[j-1][i];
				number.box[j-1][i]=number.box[j][i];
				number.box[j][i]=0;
				add_leftx=1;
		}
			if(set.box[j-1][i]==1 && set.box[j-2][i]==1 && set.box[j-3][i]==1 && set.box[j][i]==1){
				continue;
		}
	}

		}
	}
	left=1;
	horizontal_numberset();
}

void right_set(){
	add_rightx=0;
	for(int i=0;i<4;i++){
		for(int j=0;j<3;j++){

		if(j==0){
			if(set.box[j+1][i]==0 && set.box[j+2][i]==0 && set.box[j+3][i]==0 && set.box[j][i]==1){
				set.box[j+3][i]=1;
				set.box[j][i]=0;
				number.box[j+3][i]=number.box[j][i];
				number.box[j][i]=0;
				add_rightx=1;
		}
			if(set.box[j+1][i]==0 && set.box[j+2][i]==0 && set.box[j+3][i]==1 && set.box[j][i]==1){
				set.box[j+2][i]=1;
				set.box[j][i]=0;
				number.box[j+2][i]=number.box[j][i];
				number.box[j][i]=0;
				add_rightx=1;
		}
			if(set.box[j+1][i]==0 && set.box[j+2][i]==1 && set.box[j+3][i]==0 && set.box[j][i]==1){
				set.box[j+3][i]=1;
				set.box[j][i]=0;
				number.box[j+3][i]=number.box[j+2][i];
				number.box[j+2][i]=number.box[j][i];
				number.box[j][i]=0;
				add_rightx=1;
		}
			if(set.box[j+1][i]==1 && set.box[j+2][i]==0 && set.box[j+3][i]==0 && set.box[j][i]==1){
				set.box[j+3][i]=1;
				set.box[j+2][i]=1;
				set.box[j+1][i]=0;
				set.box[j][i]=0;
				number.box[j+3][i]=number.box[j+1][i];
				number.box[j+2][i]=number.box[j][i];
				number.box[j+1][i]=0;
				number.box[j][i]=0;
				add_rightx=1;
		}
			if(set.box[j+1][i]==0 && set.box[j+2][i]==1 && set.box[j+3][i]==1 && set.box[j][i]==1){
				set.box[j+1][i]=1;
				set.box[j][i]=0;
				number.box[j+1][i]=number.box[j][i];
				number.box[j][i]=0;
				add_rightx=1;
		}
			if(set.box[j+1][i]==1 && set.box[j+2][i]==0 && set.box[j+3][i]==1 && set.box[j][i]==1){
				set.box[j+2][i]=1;
				set.box[j][i]=0;
				number.box[j+2][i]=number.box[j+1][i];
				number.box[j+1][i]=number.box[j][i];
				number.box[j][i]=0;
				add_rightx=1;
		}
			if(set.box[j+1][i]==1 && set.box[j+2][i]==1 && set.box[j+3][i]==0 && set.box[j][i]==1){
				set.box[j+3][i]=1;
				set.box[j][i]=0;
				number.box[j+3][i]=number.box[j+2][i];
				number.box[j+2][i]=number.box[j+1][i];
				number.box[j+1][i]=number.box[j][i];
				number.box[j][i]=0;
				add_rightx=1;
		}
			if(set.box[j+1][i]==1 && set.box[j+2][i]==1 && set.box[j+3][i]==1 && set.box[j][i]==1){
				continue;
		}
	}

		if(j==1){
			if(set.box[j+1][i]==0 && set.box[j+2][i]==0 && set.box[j-1][i]==0 && set.box[j][i]==1){
			set.box[j+2][i]=1;
			set.box[j][i]=0;
			number.box[j+2][i]=number.box[j][i];
			number.box[j][i]=0;
			add_rightx=1;
		}
			if(set.box[j+1][i]==0 && set.box[j+2][i]==1 && set.box[j-1][i]==0 && set.box[j][i]==1){
			set.box[j+1][i]=1;
			set.box[j][i]=0;
			number.box[j+1][i]=number.box[j][i];
			number.box[j][i]=0;
			add_rightx=1;
		}
			if(set.box[j+1][i]==1 && set.box[j+2][i]==0 && set.box[j-1][i]==0 && set.box[j][i]==1){
			set.box[j+2][i]=1;
			set.box[j][i]=0;
			number.box[j+2][i]=number.box[j+1][i];
			number.box[j+1][i]=number.box[j][i];
			number.box[j][i]=0;
			add_rightx=1;
		}
			if(set.box[j+1][i]==1 && set.box[j+2][i]==1 && set.box[j-1][i]==0 && set.box[j][i]==1){
			continue;
		}
	}

		if(j==2){
			if(set.box[j+1][i]==0 && set.box[j-1][i]==0 && set.box[j-2][i]==0 && set.box[j][i]==1){
			set.box[j+1][i]=1;
			set.box[j][i]=0;
			number.box[j+1][i]=number.box[j][i];
			number.box[j][i]=0;
			add_rightx=1;
		}
			if(set.box[j+1][i]==1 && set.box[j-1][i]==0 && set.box[j-2][i]==0 && set.box[j][i]==1){
			continue;
			}
		}
	}
}
	right=1;
	horizontal_numberset();
}

void up_set(){
	add_upx=0;
	for(int j=0;j<4;j++){
		for(int i=1;i<4;i++){

		if(i==1){
			if(set.box[j][i-1]==0 && set.box[j][i]==1 && set.box[j][i+1]==0 && set.box[j][i+2]==0){
			set.box[j][i-1]=1;
			set.box[j][i]=0;
			number.box[j][i-1]=number.box[j][i];
			number.box[j][i]=0;
			add_upx=1;
		}
			if(set.box[j][i-1]==1 && set.box[j][i]==1 && set.box[j][i+1]==0 && set.box[j][i+2]==0){
			continue;
		}
	}

		if(i==2){
			if(set.box[j][i-1]==0 && set.box[j][i-2]==0 && set.box[j][i]==1 && set.box[j][i+1]==0){
			set.box[j][i-2]=1;
			set.box[j][i]=0;
			number.box[j][i-2]=number.box[j][i];
			number.box[j][i]=0;
			add_upx=1;
		}
			if(set.box[j][i-1]==0 && set.box[j][i-2]==1 && set.box[j][i]==1 && set.box[j][i+1]==0){
			set.box[j][i-1]=1;
			set.box[j][i]=0;
			number.box[j][i-1]=number.box[j][i];
			number.box[j][i]=0;
			add_upx=1;
		}
			if(set.box[j][i-1]==1 && set.box[j][i-2]==0 && set.box[j][i]==1 && set.box[j][i+1]==0){
			set.box[j][i-2]=1;
			set.box[j][i]=0;
			number.box[j][i-2]=number.box[j][i-1];
			number.box[j][i-1]=number.box[j][i];
			number.box[j][i]=0;
			add_upx=1;
		}
			if(set.box[j][i-1]==1 && set.box[j][i-2]==1 && set.box[j][i]==1 && set.box[j][i+1]==0){
			continue;
		}
	}

		if(i==3){
			if(set.box[j][i-1]==0 && set.box[j][i-2]==0 && set.box[j][i-3]==0 && set.box[j][i]==1){
				set.box[j][i-3]=1;
				set.box[j][i]=0;
				number.box[j][i-3]=number.box[j][i];
				number.box[j][i]=0;
				add_upx=1;
		}
			if(set.box[j][i-1]==0 && set.box[j][i-2]==0 && set.box[j][i-3]==1 && set.box[j][i]==1){
				set.box[j][i-2]=1;
				set.box[j][i]=0;
				number.box[j][i-2]=number.box[j][i];
				number.box[j][i]=0;
				add_upx=1;
		}
			if(set.box[j][i-1]==0 && set.box[j][i-2]==1 && set.box[j][i-3]==0 && set.box[j][i]==1){
				set.box[j][i-3]=1;
				set.box[j][i]=0;
				number.box[j][i-3]=number.box[j][i-2];
				number.box[j][i-2]=number.box[j][i];
				number.box[j][i]=0;
				add_upx=1;
		}
			if(set.box[j][i-1]==1 && set.box[j][i-2]==0 && set.box[j][i-3]==0 && set.box[j][i]==1){
				set.box[j][i-3]=1;
				set.box[j][i-2]=1;
				set.box[j][i-1]=0;
				set.box[j][i]=0;
				number.box[j][i-3]=number.box[j][i-1];
				number.box[j][i-2]=number.box[j][i];
				number.box[j][i-1]=0;
				number.box[j][i]=0;
				add_upx=1;
		}
			if(set.box[j][i-1]==0 && set.box[j][i-2]==1 && set.box[j][i-3]==1 && set.box[j][i]==1){
				set.box[j][i-1]=1;
				set.box[j][i]=0;
				number.box[j][i-1]=number.box[j][i];
				number.box[j][i]=0;
				add_upx=1;
		}
			if(set.box[j][i-1]==1 && set.box[j][i-2]==0 && set.box[j][i-3]==1 && set.box[j][i]==1){
				set.box[j][i-2]=1;
				set.box[j][i]=0;
				number.box[j][i-2]=number.box[j][i-1];
				number.box[j][i-1]=number.box[j][i];
				number.box[j][i]=0;
				add_upx=1;
		}
			if(set.box[j][i-1]==1 && set.box[j][i-2]==1 && set.box[j][i-3]==0 && set.box[j][i]==1){
				set.box[j][i-3]=1;
				set.box[j][i]=0;
				number.box[j][i-3]=number.box[j][i-2];
				number.box[j][i-2]=number.box[j][i-1];
				number.box[j][i-1]=number.box[j][i];
				number.box[j][i]=0;
				add_upx=1;
		}
			if(set.box[j][i-1]==1 && set.box[j][i-2]==1 && set.box[j][i-3]==1 && set.box[j][i]==1){
				continue;
		}
	}
}
}
	up=1;
	vertical_numberset();
}

void down_set(){
	add_downx=0;
	for(int j=0;j<4;j++){
		for(int i=0;i<3;i++){

			if(i==0){
			if(set.box[j][i+1]==0 && set.box[j][i+2]==0 && set.box[j][i+3]==0 && set.box[j][i]==1){
				set.box[j][i+3]=1;
				set.box[j][i]=0;
				number.box[j][i+3]=number.box[j][i];
				number.box[j][i]=0;
				add_downx=1;
		}
			if(set.box[j][i+1]==0 && set.box[j][i+2]==0 && set.box[j][i+3]==1 && set.box[j][i]==1){
				set.box[j][i+2]=1;
				set.box[j][i]=0;
				number.box[j][i+2]=number.box[j][i];
				number.box[j][i]=0;
				add_downx=1;
		}
			if(set.box[j][i+1]==0 && set.box[j][i+2]==1 && set.box[j][i+3]==0 && set.box[j][i]==1){
				set.box[j][i+3]=1;
				set.box[j][i]=0;
				number.box[j][i+3]=number.box[j][i+2];
				number.box[j][i+2]=number.box[j][i];
				number.box[j][i]=0;
				add_downx=1;
		}
			if(set.box[j][i+1]==1 && set.box[j][i+2]==0 && set.box[j][i+3]==0 && set.box[j][i]==1){
				set.box[j][i+3]=1;
				set.box[j][i+2]=1;
				set.box[j][i+1]=0;
				set.box[j][i]=0;
				number.box[j][i+3]=number.box[j][i+1];
				number.box[j][i+2]=number.box[j][i];
				number.box[j][i+1]=0;
				number.box[j][i]=0;
				add_downx=1;
		}
			if(set.box[j][i+1]==0 && set.box[j][i+2]==1 && set.box[j][i+3]==1 && set.box[j][i]==1){
				set.box[j][i+1]=1;
				set.box[j][i]=0;
				number.box[j][i+1]=number.box[j][i];
				number.box[j][i]=0;
				add_downx=1;
		}
			if(set.box[j][i+1]==1 && set.box[j][i+2]==0 && set.box[j][i+3]==1 && set.box[j][i]==1){
				set.box[j][i+2]=1;
				set.box[j][i]=0;
				number.box[j][i+2]=number.box[j][i+1];
				number.box[j][i+1]=number.box[j][i];
				number.box[j][i]=0;
				add_downx=1;
		}
			if(set.box[j][i+1]==1 && set.box[j][i+2]==1 && set.box[j][i+3]==0 && set.box[j][i]==1){
				set.box[j][i+3]=1;
				set.box[j][i]=0;
				number.box[j][i+3]=number.box[j][i+2];
				number.box[j][i+2]=number.box[j][i+1];
				number.box[j][i+1]=number.box[j][i];
				number.box[j][i]=0;
				add_downx=1;
		}
			if(set.box[j][i+1]==1 && set.box[j][i+2]==1 && set.box[j][i+3]==1 && set.box[j][i]==1){
				continue;
		}
	}

			if(i==1){
			if(set.box[j][i+1]==0 && set.box[j][i+2]==0 && set.box[j][i]==1 && set.box[j][i-1]==0){
			set.box[j][i+2]=1;
			set.box[j][i]=0;
			number.box[j][i+2]=number.box[j][i];
			number.box[j][i]=0;
			add_downx=1;
		}
			if(set.box[j][i+1]==0 && set.box[j][i+2]==1 && set.box[j][i]==1 && set.box[j][i-1]==0){
			set.box[j][i+1]=1;
			set.box[j][i]=0;
			number.box[j][i+1]=number.box[j][i];
			number.box[j][i]=0;
			add_downx=1;
		}
			if(set.box[j][i+1]==1 && set.box[j][i+2]==0 && set.box[j][i]==1 && set.box[j][i-1]==0){
			set.box[j][i+2]=1;
			set.box[j][i]=0;
			number.box[j][i+2]=number.box[j][i+1];
			number.box[j][i+1]=number.box[j][i];
			number.box[j][i]=0;
			add_downx=1;
		}
			if(set.box[j][i+1]==1 && set.box[j][i+2]==1 && set.box[j][i]==1 && set.box[j][i-1]==0){
			continue;
		}
	}

			if(i==2){
			if(set.box[j][i+1]==0 && set.box[j][i]==1 && set.box[j][i-1]==0 && set.box[j][i-2]==0){
			set.box[j][i+1]=1;
			set.box[j][i]=0;
			number.box[j][i+1]=number.box[j][i];
			number.box[j][i]=0;
			add_downx=1;
		}
			if(set.box[j][i+1]==1 && set.box[j][i]==1 && set.box[j][i-1]==0 && set.box[j][i-2]==0){
			continue;
		}
	}

		}
	}
	down=1;
	vertical_numberset();
}


void first_set(){

	//すべてのマスが埋まったらdo-whileにいかないように強制的にこの関数を終了させる(行ったらフリーズ状態で動かなくなる)
	if(set.box[0][0] == 1 && set.box[1][0] == 1 && set.box[2][0] == 1 && set.box[3][0] == 1 && 
	   set.box[0][1] == 1 && set.box[1][1] == 1 && set.box[2][1] == 1 && set.box[3][1] == 1 && 
	   set.box[0][2] == 1 && set.box[1][2] == 1 && set.box[2][2] == 1 && set.box[3][2] == 1 && 
	   set.box[0][3] == 1 && set.box[1][3] == 1 && set.box[2][3] == 1 && set.box[3][3] == 1 )
	   return;
	//はじめに1,2個マスに設置する同じところに重複しないようにdo-whileでループしてバラバラなとこに設置
	do{
	set.x = GetRand(3);
	set.y = GetRand(3);
		}while(set.box[set.x][set.y] == 1);

	set.box[set.x][set.y]=1;
	if(GetRand(9)==0)
		number.box[set.x][set.y]=4;
	else
		number.box[set.x][set.y]=2;
}
