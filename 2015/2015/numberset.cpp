#include "GV.h"

void horizontal_numberset(){
		for(int i=0;i<4;i++){
			//2 2 2 2,4 4 4 4,2 2 4 4などのパターン
			if(set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
 			   number.box[0][i]==number.box[1][i] && number.box[2][i]==number.box[3][i] &&
			   number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				if(left==1){
				number.box[0][i]=number.box[0][i]*2;
				number.box[1][i]=number.box[2][i]*2;
				number.box[2][i]=0;
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=0;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[0][i]=number.box[0][i];
				score.box[1][i]=number.box[1][i];
				}
				if(right==1){
				number.box[3][i]=number.box[3][i]*2;
				number.box[2][i]=number.box[1][i]*2;
				number.box[1][i]=0;
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=0;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[3][i]=number.box[3][i];
				score.box[2][i]=number.box[2][i];
				}
				score_total();
			continue;
			}
			//2 4 4 2
			if(set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
				number.box[1][i]==number.box[2][i] && number.box[0][i]==number.box[3][i] &&
				number.box[0][i]!=number.box[1][i] && number.box[0][i]!=number.box[2][i] &&
				number.box[3][i]!=number.box[2][i] && number.box[3][i]!=number.box[1][i] &&
				number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				if(left==1){
				number.box[1][i]=number.box[1][i]*2;
				number.box[2][i]=number.box[3][i];
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=1;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[1][i]=number.box[1][i];
				}
				if(right==1){
				number.box[2][i]=number.box[2][i]*2;
				number.box[1][i]=number.box[0][i];
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=1;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[2][i]=number.box[2][i];
				}
				score_total();
			continue;
			}
			//2 4 4 8,8 4 4 2
			if(set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
				number.box[1][i]==number.box[2][i] && number.box[0][i]!=number.box[3][i] &&
				number.box[0][i]!=number.box[1][i] && number.box[0][i]!=number.box[2][i] &&
				number.box[3][i]!=number.box[2][i] && number.box[3][i]!=number.box[1][i] &&
				number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				if(left==1){
				number.box[1][i]=number.box[1][i]*2;
				number.box[2][i]=number.box[3][i];
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=1;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[1][i]=number.box[1][i];
				}
				if(right==1){
				number.box[2][i]=number.box[2][i]*2;
				number.box[1][i]=number.box[0][i];
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=1;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[2][i]=number.box[2][i];
				}
				score_total();
			continue;
			}
			//2 2 4 2,2 4 2 2
			if(left==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
				number.box[0][i]==number.box[1][i] && number.box[1][i]==number.box[3][i] && 
				number.box[0][i]==number.box[3][i] && number.box[0][i]!=number.box[2][i] && 
				number.box[1][i]!=number.box[2][i] && number.box[3][i]!=number.box[2][i] && 
				number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){ 
				//if(left==1){
				number.box[0][i]=number.box[0][i]*2;
				number.box[1][i]=number.box[2][i];
				number.box[2][i]=number.box[3][i];
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=1;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[0][i]=number.box[0][i];
				//}
				score_total();
			continue;
			}
			if(right==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
				number.box[3][i]==number.box[2][i] && number.box[0][i]==number.box[2][i] && 
				number.box[0][i]==number.box[3][i] && number.box[3][i]!=number.box[1][i] && 
				number.box[2][i]!=number.box[1][i] && number.box[0][i]!=number.box[1][i] && 
				number.box[0][i]>=2 && number.box[1][i]>= 2&& number.box[2][i]>=2 && number.box[3][i]>=2){
				//if(right==1){
				number.box[3][i]=number.box[3][i]*2;
				number.box[2][i]=number.box[1][i];
				number.box[1][i]=number.box[0][i];
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=1;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[3][i]=number.box[3][i];
				//}
				score_total();
			continue;
			}
			//2 4 2 2,2 2 4 2
			if(left==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
				number.box[0][i]==number.box[2][i] && number.box[0][i]==number.box[3][i] &&
				number.box[2][i]==number.box[3][i] && number.box[1][i]!=number.box[0][i] &&
				number.box[1][i]!=number.box[2][i] && number.box[1][i]!=number.box[3][i] &&
				number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				//if(left==1){
				number.box[2][i]=number.box[2][i]*2;
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=1;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[2][i]=number.box[2][i];
				//}
				score_total();
			continue;
			}
			if(right==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
				number.box[0][i]==number.box[1][i] && number.box[0][i]==number.box[3][i] &&
				number.box[1][i]==number.box[3][i] && number.box[2][i]!=number.box[0][i] &&
				number.box[2][i]!=number.box[1][i] && number.box[2][i]!=number.box[3][i] &&
				number.box[0][i]>=2 && number.box[1][i]>= 2&& number.box[2][i]>=2 && number.box[3][i]>=2){
				//if(right==1){
				number.box[1][i]=number.box[1][i]*2;
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=1;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[1][i]=number.box[1][i];
				//}
				score_total();
			continue;
			}
			//2 2 2 4,4 2 2 2
			if(left==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
				number.box[0][i]==number.box[1][i] && number.box[1][i]==number.box[2][i] &&
				number.box[0][i]==number.box[2][i] && number.box[3][i]!=number.box[0][i] &&
				number.box[3][i]!=number.box[1][i] && number.box[3][i]!=number.box[2][i] &&
				number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				if(left==1){
				number.box[0][i]=number.box[0][i]*2;
				number.box[1][i]=number.box[2][i];
				number.box[2][i]=number.box[3][i];
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=1;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[0][i]=number.box[0][i];
				}
				score_total();
			continue;
			}
			if(right==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
				number.box[3][i]==number.box[2][i] && number.box[2][i]==number.box[1][i] &&
				number.box[1][i]==number.box[3][i] && number.box[0][i]!=number.box[3][i] &&
				number.box[0][i]!=number.box[2][i] && number.box[0][i]!=number.box[1][i] &&
				number.box[0][i]>=2 && number.box[1][i]>= 2&& number.box[2][i]>=2 && number.box[3][i]>=2){
				if(right==1){
				number.box[3][i]=number.box[3][i]*2;
				number.box[2][i]=number.box[1][i];
				number.box[1][i]=number.box[0][i];
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=1;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[3][i]=number.box[3][i];
				}
				score_total();
			continue;
			}
			//4 2 2 2,2 2 2 4
				if(left==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[1][i]==number.box[2][i] && number.box[2][i]==number.box[3][i] &&
					number.box[1][i]==number.box[3][i] && number.box[0][i]!=number.box[1][i] &&
					number.box[0][i]!=number.box[2][i] && number.box[0][i]!=number.box[3][i] &&
					number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				if(left==1){
				number.box[1][i]=number.box[1][i]*2;
				number.box[2][i]=number.box[3][i];
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=1;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[1][i]=number.box[1][i];
				}
				score_total();
			continue;
			}
				if(right==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[2][i]==number.box[1][i] && number.box[1][i]==number.box[0][i] &&
					number.box[0][i]==number.box[2][i] && number.box[3][i]!=number.box[0][i] &&
					number.box[3][i]!=number.box[1][i] && number.box[3][i]!=number.box[2][i] &&
					number.box[0][i]>=2 && number.box[1][i]>= 2&& number.box[2][i]>=2 && number.box[3][i]>=2){
				if(right==1){
				number.box[2][i]=number.box[2][i]*2;
				number.box[1][i]=number.box[0][i];
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=1;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[2][i]=number.box[2][i];
				}
				score_total();
			continue;
			}
			//8 4 2 2,2 2 4 8
				if(left==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[0][i]!=number.box[1][i] && number.box[1][i]!=number.box[2][i] &&
					number.box[0][i]!=number.box[2][i] && number.box[0][i]!=number.box[3][i] &&
					number.box[1][i]!=number.box[3][i] && number.box[2][i]==number.box[3][i] &&
					number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				//if(left==1){
				number.box[2][i]=number.box[2][i]*2;
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=1;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[2][i]=number.box[2][i];
				//}
				score_total();
			continue;
			}
				if(right==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[3][i]!=number.box[2][i] && number.box[2][i]!=number.box[1][i] &&
					number.box[0][i]!=number.box[2][i] && number.box[0][i]!=number.box[3][i] &&
					number.box[1][i]!=number.box[3][i] && number.box[0][i]==number.box[1][i] &&
					number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				//if(right==1){
				number.box[1][i]=number.box[1][i]*2;
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=1;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[1][i]=number.box[1][i];
				//}
				score_total();
			continue;
			}
				//2 2 4 8,8 4 2 2
				if(left==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[0][i]==number.box[1][i] && number.box[1][i]!=number.box[2][i] &&
					number.box[1][i]!=number.box[3][i] && number.box[0][i]!=number.box[2][i] &&
					number.box[0][i]!=number.box[3][i] && number.box[2][i]!=number.box[3][i] &&
					number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				//if(left==1){
				number.box[0][i]=number.box[0][i]*2;
				number.box[1][i]=number.box[2][i];
				number.box[2][i]=number.box[3][i];
				number.box[3][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=1;
				set.box[3][i]=0;
				add_leftx=1;
				score.box[0][i]=number.box[0][i];
				//}
				score_total();
			continue;
			}
				if(right==1 && set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[3][i]==number.box[2][i] && number.box[3][i]!=number.box[0][i] &&
					number.box[3][i]!=number.box[1][i] && number.box[2][i]!=number.box[1][i] &&
					number.box[2][i]!=number.box[0][i] && number.box[0][i]!=number.box[1][i] &&
					number.box[0][i]>=2 && number.box[1][i]>=2 && number.box[2][i]>=2 && number.box[3][i]>=2){
				//if(right==1){
				number.box[3][i]=number.box[3][i]*2;
				number.box[2][i]=number.box[1][i];
				number.box[1][i]=number.box[0][i];
				number.box[0][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=1;
				set.box[0][i]=0;
				add_rightx=1;
				score.box[3][i]=number.box[3][i];
				//}
				score_total();
			continue;
			}
				//2 2 2
				if(set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==0 &&
					number.box[0][i]==number.box[1][i] && number.box[1][i]==number.box[2][i] &&
					number.box[0][i]==number.box[2][i] && number.box[0][i]>=2 && number.box[1][i]>=2 &&
					number.box[2][i]>=2 && number.box[3][i]==0){
				if(left==1){
				number.box[0][i]=number.box[0][i]*2;
				number.box[2][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=0;
				add_leftx=1;
				score.box[0][i]=number.box[0][i];
				}
				score_total();
			continue;
			}
				if(set.box[0][i]==0 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[3][i]==number.box[2][i] && number.box[2][i]==number.box[1][i] &&
					number.box[0][i]==number.box[2][i] && number.box[1][i]>=2 && number.box[2][i]>= 2 &&
					number.box[3][i]>=2 && number.box[0][i]==0){
				if(right==1){
				number.box[3][i]=number.box[3][i]*2;
				number.box[1][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=0;
				add_rightx=1;
				score.box[3][i]=number.box[3][i];
				}
				score_total();
			continue;
			}
				//2 2 4,4 2 2
				if(set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==0 &&
					number.box[0][i]==number.box[1][i] && number.box[1][i]!=number.box[2][i] &&
					number.box[0][i]!=number.box[2][i] && number.box[0][i]>=2 && number.box[1][i]>=2 &&
					number.box[2][i]>=2 && number.box[3][i]==0){
				if(left==1){
				number.box[0][i]=number.box[0][i]*2;
				number.box[1][i]=number.box[2][i];
				number.box[2][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=0;
				add_leftx=1;
				score.box[0][i]=number.box[0][i];
				}
				score_total();
			continue;
			}
				if(set.box[0][i]==0 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[3][i]==number.box[2][i] && number.box[2][i]!=number.box[0][i] &&
					number.box[1][i]!=number.box[0][i] && number.box[1][i]>=2 && number.box[2][i]>= 2 &&
					number.box[3][i]>=2 && number.box[0][i]==0){
				if(right==1){
				number.box[3][i]=number.box[3][i]*2;
				number.box[2][i]=number.box[1][i];
				number.box[1][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=0;
				add_rightx=1;
				score.box[3][i]=number.box[3][i];
				}
				score_total();
			continue;
			}
				//4 2 2,2 2 4
				if(set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==0 &&
					number.box[1][i]==number.box[2][i] && number.box[0][i]!=number.box[1][i] &&
					number.box[0][i]!=number.box[2][i] && number.box[0][i]>=2 && number.box[1][i]>=2 &&
					number.box[2][i]>=2 && number.box[3][i]==0){
				if(left==1){
				number.box[1][i]=number.box[1][i]*2;
				number.box[2][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=1;
				set.box[2][i]=0;
				add_leftx=1;
				score.box[1][i]=number.box[1][i];
				}
				score_total();
			continue;
			}
				if(set.box[0][i]==0 && set.box[1][i]==1 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[2][i]==number.box[1][i] && number.box[2][i]!=number.box[3][i] &&
					number.box[1][i]!=number.box[3][i] && number.box[1][i]>=2 && number.box[2][i]>= 2 &&
					number.box[3][i]>=2 && number.box[0][i]==0){
				if(right==1){
				number.box[2][i]=number.box[2][i]*2;
				number.box[1][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=1;
				set.box[1][i]=0;
				add_rightx=1;
				score.box[2][i]=number.box[2][i];
				}
				score_total();
			continue;
			}
				//2 2,4 4
				if(set.box[0][i]==1 && set.box[1][i]==1 && set.box[2][i]==0 && set.box[3][i]==0 &&
					number.box[0][i]==number.box[1][i] && number.box[0][i]>=2 && number.box[1][i]>=2 &&
					number.box[2][i]==0 && number.box[3][i]==0){
				if(left==1){
				number.box[0][i]=number.box[0][i]*2;
				number.box[1][i]=0;
				set.box[0][i]=1;
				set.box[1][i]=0;
				add_leftx=1;
				score.box[0][i]=number.box[0][i];
				}
				score_total();
			continue;
			}
				if(set.box[0][i]==0 && set.box[1][i]==0 && set.box[2][i]==1 && set.box[3][i]==1 &&
					number.box[2][i]==number.box[3][i] && number.box[2][i]>=2 && number.box[3][i]>=2 &&
					number.box[1][i]==0 && number.box[0][i]==0){
				if(right==1){
				number.box[3][i]=number.box[3][i]*2;
				number.box[2][i]=0;
				set.box[3][i]=1;
				set.box[2][i]=0;
				add_rightx=1;
				score.box[3][i]=number.box[3][i];
				}
				score_total();
			continue;
			}
	}

	if(add_leftx==0)
		left_addset();
	if(add_rightx==0)
		right_addset();
}

void vertical_numberset(){
		for(int i=0;i<4;i++){
			//2 2 2 2,4 4 4 4,2 2 4 4などのパターン
			if(set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
 			   number.box[i][0]==number.box[i][1] && number.box[i][2]==number.box[i][3] &&
			   number.box[i][0]>=2 && number.box[i][1]>=2 && number.box[i][2]>=2 && number.box[i][3]>=2){
				if(up==1){
				number.box[i][0]=number.box[i][0]*2;
				number.box[i][1]=number.box[i][2]*2;
				number.box[i][2]=0;
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=0;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][0]=number.box[i][0];
				score.box[i][1]=number.box[i][1];
				}
				if(down==1){
				number.box[i][3]=number.box[i][3]*2;
				number.box[i][2]=number.box[i][1]*2;
				number.box[i][1]=0;
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=0;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][3]=number.box[i][3];
				score.box[i][2]=number.box[i][2];
				}
				score_total();
			continue;
			}
			//2 4 4 2
			if(set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
				number.box[i][1]==number.box[i][2] && number.box[i][0]==number.box[i][3] &&
				number.box[i][0]!=number.box[i][1] && number.box[i][0]!=number.box[i][2] &&
				number.box[i][3]!=number.box[i][2] && number.box[i][3]!=number.box[i][1] &&
				number.box[i][0]>=2 && number.box[i][1]>=2 && number.box[i][2]>=2 && number.box[i][3]>=2){
				if(up==1){
				number.box[i][1]=number.box[i][1]*2;
				number.box[i][2]=number.box[i][3];
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=1;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][1]=number.box[i][1];
				}
				if(down==1){
				number.box[i][2]=number.box[i][2]*2;
				number.box[i][1]=number.box[i][0];
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=1;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][2]=number.box[i][2];
				}
				score_total();
			continue;
			}
			//2 4 4 8,8 4 4 2
			if(set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
				number.box[i][1]==number.box[i][2] && number.box[i][0]!=number.box[i][3] &&
				number.box[i][0]!=number.box[i][1] && number.box[i][0]!=number.box[i][2] &&
				number.box[i][3]!=number.box[i][2] && number.box[i][3]!=number.box[i][1] &&
				number.box[i][0]>=2 && number.box[i][1]>=2 && number.box[i][2]>=2 && number.box[i][3]>=2){
				if(up==1){
				number.box[i][1]=number.box[i][1]*2;
				number.box[i][2]=number.box[i][3];
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=1;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][1]=number.box[i][1];
				}
				if(down==1){
				number.box[i][2]=number.box[i][2]*2;
				number.box[i][1]=number.box[i][0];
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=1;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][2]=number.box[i][2];
				}
				score_total();
			continue;
			}
			//2 2 4 2,2 4 2 2
			if(up==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
				number.box[i][0]==number.box[i][1] && number.box[i][1]==number.box[i][3] && 
				number.box[i][0]==number.box[i][3] && number.box[i][0]!=number.box[i][2] && 
				number.box[i][1]!=number.box[i][2] && number.box[i][3]!=number.box[i][2] && 
				number.box[i][0]>=2 && number.box[i][1]>=2 && number.box[i][2]>=2 && number.box[i][3]>=2){ 
				//if(up==1){
				number.box[i][0]=number.box[i][0]*2;
				number.box[i][1]=number.box[i][2];
				number.box[i][2]=number.box[i][3];
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=1;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][0]=number.box[i][0];
				//}
				score_total();
			continue;
			}
			if(down==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
				number.box[i][3]==number.box[i][2] && number.box[i][0]==number.box[i][2] && 
				number.box[i][0]==number.box[i][3] && number.box[i][3]!=number.box[i][1] && 
				number.box[i][2]!=number.box[i][1] && number.box[i][0]!=number.box[i][1] && 
				number.box[i][0]>=2 && number.box[i][1]>= 2 && number.box[i][2]>=2 && number.box[i][3]>=2){
				//if(down==1){
				number.box[i][3]=number.box[i][3]*2;
				number.box[i][2]=number.box[i][1];
				number.box[i][1]=number.box[i][0];
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=1;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][3]=number.box[i][3];
				//}
				score_total();
			continue;
			}
			//2 4 2 2,2 2 4 2
			if(up==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
				number.box[i][0]==number.box[i][2] && number.box[i][0]==number.box[i][3] &&
				number.box[i][2]==number.box[i][3] && number.box[i][1]!=number.box[i][0] &&
				number.box[i][1]!=number.box[i][2] && number.box[i][1]!=number.box[i][3] &&
				number.box[i][0]>=2 && number.box[i][1]>=2 && number.box[i][2]>=2 && number.box[i][3]>=2){
				//if(up==1){
				number.box[i][2]=number.box[i][2]*2;
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=1;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][2]=number.box[i][2];
				//}
				score_total();
			continue;
			}
			if(down==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
				number.box[i][0]==number.box[i][1] && number.box[i][0]==number.box[i][3] &&
				number.box[i][1]==number.box[i][3] && number.box[i][2]!=number.box[i][0] &&
				number.box[i][2]!=number.box[i][1] && number.box[i][2]!=number.box[i][3] &&
				number.box[i][0]>=2 && number.box[i][1]>=2 && number.box[i][2]>=2 && number.box[i][3]>=2){
				//if(down==1){
				number.box[i][1]=number.box[i][1]*2;
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=1;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][1]=number.box[i][1];
				//}
				score_total();
			continue;
			}
			//2 2 2 4,4 2 2 2
			if(up==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
				number.box[i][0]==number.box[i][1] && number.box[i][1]==number.box[i][2] &&
				number.box[i][0]==number.box[i][2] && number.box[i][3]!=number.box[i][0] &&
				number.box[i][3]!=number.box[i][1] && number.box[i][3]!=number.box[i][2] &&
				number.box[i][0]>=2 && number.box[i][1]>=2 && number.box[i][2]>=2 && number.box[i][3]>=2){
				if(up==1){
				number.box[i][0]=number.box[i][0]*2;
				number.box[i][1]=number.box[i][2];
				number.box[i][2]=number.box[i][3];
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=1;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][0]=number.box[i][0];
				}
				score_total();
			continue;
			}
			if(down==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
				number.box[i][3]==number.box[i][2] && number.box[i][2]==number.box[i][1] &&
				number.box[i][1]==number.box[i][3] && number.box[i][0]!=number.box[i][3] &&
				number.box[i][0]!=number.box[i][2] && number.box[i][0]!=number.box[i][1] &&
				number.box[i][0]>=2 && number.box[i][1]>= 2&& number.box[i][2]>=2 && number.box[i][3]>=2){
				if(down==1){
				number.box[i][3]=number.box[i][3]*2;
				number.box[i][2]=number.box[i][1];
				number.box[i][1]=number.box[i][0];
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=1;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][3]=number.box[i][3];
				}
				score_total();
			continue;
			}
			//4 2 2 2,2 2 2 4
				if(up==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][1]==number.box[i][2] && number.box[i][2]==number.box[i][3] &&
					number.box[i][1]==number.box[i][3] && number.box[i][0]!=number.box[i][1] &&
					number.box[i][0]!=number.box[i][2] && number.box[i][0]!=number.box[i][3] &&
					number.box[i][0]>=2 && number.box[i][1]>= 2&& number.box[i][2]>=2 && number.box[i][3]>=2){
				if(up==1){
				number.box[i][1]=number.box[i][1]*2;
				number.box[i][2]=number.box[i][3];
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=1;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][1]=number.box[i][1];
				}
				score_total();
			continue;
			}
				if(down==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][2]==number.box[i][1] && number.box[i][1]==number.box[i][0] &&
					number.box[i][0]==number.box[i][2] && number.box[i][3]!=number.box[i][0] &&
					number.box[i][3]!=number.box[i][1] && number.box[i][3]!=number.box[i][2] &&
					number.box[i][0]>=2 && number.box[i][1]>= 2&& number.box[i][2]>=2 && number.box[i][3]>=2){
				if(down==1){
				number.box[i][2]=number.box[i][2]*2;
				number.box[i][1]=number.box[i][0];
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=1;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][2]=number.box[i][2];
				}
				score_total();
			continue;
			}
			//8 4 2 2,2 2 4 8
				if(up==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][0]!=number.box[i][1] && number.box[i][1]!=number.box[i][2] &&
					number.box[i][0]!=number.box[i][2] && number.box[i][0]!=number.box[i][3] &&
					number.box[i][1]!=number.box[i][3] && number.box[i][2]==number.box[i][3] &&
					number.box[i][0]>=2 && number.box[i][1]>= 2&& number.box[i][2]>=2 && number.box[i][3]>=2){
				//if(up==1){
				number.box[i][2]=number.box[i][2]*2;
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=1;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][2]=number.box[i][2];
				//}
				score_total();
			continue;
			}
				if(down==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][3]!=number.box[i][2] && number.box[i][2]!=number.box[i][1] &&
					number.box[i][0]!=number.box[i][2] && number.box[i][0]!=number.box[i][3] &&
					number.box[i][1]!=number.box[i][3] && number.box[i][0]==number.box[i][1] &&
					number.box[i][0]>=2 && number.box[i][1]>= 2&& number.box[i][2]>=2 && number.box[i][3]>=2){
				//if(down==1){
				number.box[i][1]=number.box[i][1]*2;
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=1;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][1]=number.box[i][1];
				//}
				score_total();
			continue;
			}
				//2 2 4 8,8 4 2 2
				if(up==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][0]==number.box[i][1] && number.box[i][1]!=number.box[i][2] &&
					number.box[i][1]!=number.box[i][3] && number.box[i][0]!=number.box[i][2] &&
					number.box[i][0]!=number.box[i][3] && number.box[i][2]!=number.box[i][3] &&
					number.box[i][0]>=2 && number.box[i][1]>= 2&& number.box[i][2]>=2 && number.box[i][3]>=2){
				//if(up==1){
				number.box[i][0]=number.box[i][0]*2;
				number.box[i][1]=number.box[i][2];
				number.box[i][2]=number.box[i][3];
				number.box[i][3]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=1;
				set.box[i][3]=0;
				add_upx=1;
				score.box[i][0]=number.box[i][0];
				//}
				score_total();
			continue;
			}
				if(down==1 && set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][3]==number.box[i][2] && number.box[i][3]!=number.box[i][0] &&
					number.box[i][3]!=number.box[i][1] && number.box[i][2]!=number.box[i][1] &&
					number.box[i][2]!=number.box[i][0] && number.box[i][0]!=number.box[i][1] &&
					number.box[i][0]>=2 && number.box[i][1]>= 2&& number.box[i][2]>=2 && number.box[i][3]>=2){
				//if(down==1){
				number.box[i][3]=number.box[i][3]*2;
				number.box[i][2]=number.box[i][1];
				number.box[i][1]=number.box[i][0];
				number.box[i][0]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=1;
				set.box[i][0]=0;
				add_downx=1;
				score.box[i][3]=number.box[i][3];
				//}
				score_total();
			continue;
			}
				//2 2 2
				if(set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==0 &&
					number.box[i][0]==number.box[i][1] && number.box[i][1]==number.box[i][2] &&
					number.box[i][0]==number.box[i][2] && number.box[i][0]>=2 && number.box[i][1]>=2 &&
					number.box[i][2]>=2 && number.box[i][3]==0){
				if(up==1){
				number.box[i][0]=number.box[i][0]*2;
				number.box[i][2]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=0;
				add_upx=1;
				score.box[i][0]=number.box[i][0];
				}
				score_total();
			continue;
			}
				if(set.box[i][0]==0 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][3]==number.box[i][2] && number.box[i][2]==number.box[i][1] &&
					number.box[i][0]==number.box[i][2] && number.box[i][0]==0 && number.box[i][1]>=2 &&
					number.box[i][2]>=2 && number.box[i][3]>=2){
				if(down==1){
				number.box[i][3]=number.box[i][3]*2;
				number.box[i][1]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=0;
				add_downx=1;
				score.box[i][3]=number.box[i][3];
				}
				score_total();
			continue;
			}
				//2 2 4,4 2 2
				if(set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==0 &&
					number.box[i][0]==number.box[i][1] && number.box[i][1]!=number.box[i][2] &&
					number.box[i][0]!=number.box[i][2] && number.box[i][0]>=2 && number.box[i][1]>=2 &&
					number.box[i][2]>=2 && number.box[i][3]==0){
				if(up==1){
				number.box[i][0]=number.box[i][0]*2;
				number.box[i][1]=number.box[i][2];
				number.box[i][2]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=0;
				add_upx=1;
				score.box[i][0]=number.box[i][0];
				}
				score_total();
			continue;
			}
				if(set.box[i][0]==0 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][3]==number.box[i][2] && number.box[i][2]!=number.box[i][0] &&
					number.box[i][1]!=number.box[i][0] && number.box[i][0]==0 && number.box[i][1]>=2 &&
					number.box[i][2]>=2 && number.box[i][3]>=2){
				if(down==1){
				number.box[i][3]=number.box[i][3]*2;
				number.box[i][2]=number.box[i][1];
				number.box[i][1]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=0;
				add_downx=1;
				score.box[i][3]=number.box[i][3];
				}
				score_total();
			continue;
			}
				//4 2 2,2 2 4
				if(set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==0 &&
					number.box[i][1]==number.box[i][2] && number.box[i][0]!=number.box[i][1] &&
					number.box[i][0]!=number.box[i][2] && number.box[i][0]>=2 && number.box[i][1]>=2 &&
					number.box[i][2]>=2 && number.box[i][3]==0){
				if(up==1){
				number.box[i][1]=number.box[i][1]*2;
				number.box[i][2]=0;
				set.box[i][0]=1;
				set.box[i][1]=1;
				set.box[i][2]=0;
				add_upx=1;
				score.box[i][1]=number.box[i][1];
				}
				score_total();
			continue;
			}
				if(set.box[i][0]==0 && set.box[i][1]==1 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][2]==number.box[i][1] && number.box[i][2]!=number.box[i][3] &&
					number.box[i][1]!=number.box[i][3] && number.box[i][0]==0 && number.box[i][1]>=2 &&
					number.box[i][2]>=2 && number.box[i][3]>=2){
				if(down==1){
				number.box[i][2]=number.box[i][2]*2;
				number.box[i][1]=0;
				set.box[i][3]=1;
				set.box[i][2]=1;
				set.box[i][1]=0;
				add_downx=1;
				score.box[i][2]=number.box[i][2];
				}
				score_total();
			continue;
			}
				//2 2,4 4
				if(set.box[i][0]==1 && set.box[i][1]==1 && set.box[i][2]==0 && set.box[i][3]==0 &&
					number.box[i][0]==number.box[i][1] && number.box[i][0]>=2 && number.box[i][1]>=2 &&
					number.box[i][2]==0 && number.box[i][3]==0){
				if(up==1){
				number.box[i][0]=number.box[i][0]*2;
				number.box[i][1]=0;
				set.box[i][0]=1;
				set.box[i][1]=0;
				add_upx=1;
				score.box[i][0]=number.box[i][0];
				}
				score_total();
			continue;
			}
				if(set.box[i][0]==0 && set.box[i][1]==0 && set.box[i][2]==1 && set.box[i][3]==1 &&
					number.box[i][2]==number.box[i][3] && number.box[i][2]>=2 && number.box[i][3]>=2 &&
					number.box[i][1]==0 && number.box[i][0]==0){
				if(down==1){
				number.box[i][3]=number.box[i][3]*2;
				number.box[i][2]=0;
				set.box[i][3]=1;
				set.box[i][2]=0;
				add_downx=1;
				score.box[i][3]=number.box[i][3];
				}
				score_total();
			continue;
			}
	}

	if(add_upx==0)
		up_addset();
	if(add_downx==0)
		down_addset();
}