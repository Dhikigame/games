#include "GV.h"

void left_addset(){
for(int i=0;i<4;i++){
		if(set.box[0][i]==0 && set.box[1][i]==0 && set.box[2][i]==0 && set.box[3][i]==0
		|| set.box[0][i]==1 && set.box[1][i]==0 && set.box[2][i]==0 && set.box[3][i]==0
		|| set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==0 && set.box[3][i]==0
		|| set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==0
		|| set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1){
		add_left++;
		if(add_left==4)
			add=1;
			}
		}
		add_left=0;
}

void right_addset(){
	for(int i=0;i<4;i++){
		if(set.box[0][i]==0 && set.box[1][i]==0 && set.box[2][i]==0 && set.box[3][i]==0
		|| set.box[0][i]==0 && set.box[1][i]==0 && set.box[2][i]==0 && set.box[3][i]==1
		|| set.box[0][i]==0 && set.box[1][i]==0 && set.box[2][i]==1 && set.box[3][i]==1
		|| set.box[0][i]==0 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1
		|| set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1){
		add_right++;
		if(add_right==4)
			add=1;
			}
		}
		add_right=0;
	}	

void up_addset(){
	for(int i=0;i<4;i++){
		if(set.box[i][0]==0 && set.box[i][1]==0 && set.box[i][2]==0 && set.box[i][3]==0
		|| set.box[i][0]==1 && set.box[i][1]==0 && set.box[i][2]==0 && set.box[i][3]==0
		|| set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==0 && set.box[i][3]==0
		|| set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==0
		|| set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1){
		add_up++;
		if(add_up==4)
			add=1;
			}
		}
		add_up=0;
}

void down_addset(){
	for(int i=0;i<4;i++){
		if(set.box[i][0]==0 && set.box[i][1]==0 && set.box[i][2]==0 && set.box[i][3]==0
		|| set.box[i][0]==0 && set.box[i][1]==0 && set.box[i][2]==0 && set.box[i][3]==1
		|| set.box[i][0]==0 && set.box[i][1]==0 && set.box[i][2]==1 && set.box[i][3]==1
		|| set.box[i][0]==0 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1
		|| set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1){
		add_down++;
		if(add_down==4)
			add=1;
			}
		}
		add_down=0;
	}	