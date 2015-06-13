#include "GV.h"

void score_total(){
	for(int i=0;i<4;i++){
		for(int j=0;j<4;j++){
			score.total += score.box[i][j];
			score.box[i][j]=0;
		}
	}
}