#include "GV.h"

/*配置
	DrawRotaGraph( 170, 90, 0.7,  0.0, Two, TRUE );[0][0]
	DrawRotaGraph( 170, 190, 0.7,  0.0, Two, TRUE );[0][1]
	DrawRotaGraph( 170, 290, 0.7,  0.0, Two, TRUE );[0][2]
	DrawRotaGraph( 170, 390, 0.7,  0.0, Two, TRUE );[0][3]
	DrawRotaGraph( 270, 90, 0.7,  0.0, Two, TRUE );[1][0]
	DrawRotaGraph( 270, 190, 0.7,  0.0, Two, TRUE );[1][1]
	DrawRotaGraph( 270, 290, 0.7,  0.0, Two, TRUE );[1][2]
	DrawRotaGraph( 270, 390, 0.7,  0.0, Two, TRUE );[1][3]
	DrawRotaGraph( 370, 90, 0.7,  0.0, Two, TRUE );[2][0]
	DrawRotaGraph( 370, 190, 0.7,  0.0, Two, TRUE );[2][1]
	DrawRotaGraph( 370, 290, 0.7,  0.0, Two, TRUE );[2][2]
	DrawRotaGraph( 370, 390, 0.7,  0.0, Two, TRUE );[2][3]
	DrawRotaGraph( 470, 90, 0.7,  0.0, Two, TRUE );[3][0]
	DrawRotaGraph( 470, 190, 0.7,  0.0, Two, TRUE );[3][1]
	DrawRotaGraph( 470, 290, 0.7,  0.0, Two, TRUE );[3][2]
	DrawRotaGraph( 470, 390, 0.7,  0.0, Two, TRUE );[3][3]
*/

//set終了後マスの配置
void set_graph(){
	
 for(int i=0;i<=3;i++){
	 int l=100*i;
	for(int j=0;j<=3;j++){
		int k=100*j;
		if(number.box[j][i]==2){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Two, TRUE );
		continue;
		}
		if(number.box[j][i]==4){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Four, TRUE );
		continue;
		}
		if(number.box[j][i]==8){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Eight, TRUE );
		continue;
		}
		if(number.box[j][i]==16){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Sixteen, TRUE );
		continue;
		}
		if(number.box[j][i]==32){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Thirtytwo, TRUE );
		continue;
		}
		if(number.box[j][i]==64){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Sixtyfour, TRUE );
		continue;
		}
		if(number.box[j][i]==128){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Onehundred_twentyeight, TRUE );
		continue;
		}
		if(number.box[j][i]==256){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Twohundred_fiftysix, TRUE );
		continue;
		}
		if(number.box[j][i]==512){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Fivehundred_twelve, TRUE );
		continue;
		}
		if(number.box[j][i]==1024){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Thousand_twentyfour, TRUE );
		continue;
		}
		if(number.box[j][i]==2048){
		DrawRotaGraph( 170+k, 90+l, 0.7,  0.0, Two_thousand_fortyeight, TRUE );
		continue;
		}
		}
	}
}

void first_graph(){
	if(first==0 || first==1 ){
	first_set();
	first++;
	}
	set_graph();

  if(Key[ KEY_INPUT_LEFT ]==1 || Key[ KEY_INPUT_RIGHT ]==1 || Key[ KEY_INPUT_UP ]==1 || Key[ KEY_INPUT_DOWN ]==1){
	  add=0;
	if(Key[ KEY_INPUT_LEFT ]==1){
		left_set();
		if(add==1)
		left=0;
		else{ 
		add=0;
		left=0;
		}
	}
	if(Key[ KEY_INPUT_RIGHT ]==1){
		right_set();
		if(add==1)
		right=0;
		else{ 
		add=0;
		right=0;
		}
	}
	if(Key[ KEY_INPUT_UP ]==1){
		up_set();
		if(add==1)
		up=0;
		else{ 
		add=0;
		up=0;
		}
	}
	if(Key[ KEY_INPUT_DOWN ]==1){
		down_set();
		if(add==1)
		down=0;
		else{ 
		add=0;
		down=0;
		}
	}
  }

	if(add==0){
	first_set();
	add++;
	}

	//初期化　デバッグ用
	if(Key[ KEY_INPUT_SPACE ]==1 || Key[ KEY_INPUT_RETURN ]==1){
		int i=0,j=0;
 for(i=0;i<=3;i++){
	for(j=0;j<=3;j++){
		if(set.box[i][j] == 1){
			set.box[i][j]=0;
			number.box[i][j]=0;
				}
			}
		}
 ini();
	}
	//スコア
	DrawFormatString( 555, 380, GetColor(0,0,0), "スコア");
	DrawFormatString( 570, 400, GetColor(0,0,0), "%d",score.total);

	//マス格納デバッグ（マスに入っているかの判定）
	DrawFormatString( 0, 0, GetColor(0,0,0), "%d %d %d %d",set.box[0][0],set.box[1][0],set.box[2][0],set.box[3][0]);
	DrawFormatString( 0, 15, GetColor(0,0,0), "%d %d %d %d",set.box[0][1],set.box[1][1],set.box[2][1],set.box[3][1]);
	DrawFormatString( 0, 30, GetColor(0,0,0), "%d %d %d %d",set.box[0][2],set.box[1][2],set.box[2][2],set.box[3][2]);
	DrawFormatString( 0, 45, GetColor(0,0,0), "%d %d %d %d",set.box[0][3],set.box[1][3],set.box[2][3],set.box[3][3]);

	//マス格納デバッグ（数字）
	DrawFormatString( 0, 100, GetColor(0,0,0), "%d %d %d %d",number.box[0][0],number.box[1][0],number.box[2][0],number.box[3][0]);
	DrawFormatString( 0, 115, GetColor(0,0,0), "%d %d %d %d",number.box[0][1],number.box[1][1],number.box[2][1],number.box[3][1]);
	DrawFormatString( 0, 130, GetColor(0,0,0), "%d %d %d %d",number.box[0][2],number.box[1][2],number.box[2][2],number.box[3][2]);
	DrawFormatString( 0, 145, GetColor(0,0,0), "%d %d %d %d",number.box[0][3],number.box[1][3],number.box[2][3],number.box[3][3]);
}

void main_graph(){
	GetMouseInput();
	GetMousePoint( &pointer.x, &pointer.y ); 
	DrawRotaGraph( 320, 240, 1.0,  0.0, main, FALSE );
	DrawFormatString( 50, 450, Green, "座標[%d,%d]", pointer.x, pointer.y); 
	first_graph();
	/*デバッグ用
	if(Key[ KEY_INPUT_SPACE ]==1 || Key[ KEY_INPUT_RETURN ]==1){
		int i=0,j=0;
 for(i=0;i<=3;i++){
	for(j=0;j<=3;j++){
		if(set.box[i][j] == 1){
			set.box[i][j]=0;
				}
			}
		}
 ini();
	}
	*/
}

void back_graph(){
	GetMouseInput();
	GetMousePoint( &pointer.x, &pointer.y ); 
	DrawRotaGraph( 0, 0, 3.0,  0.0, white, TRUE );
	DrawFormatString( 0, 0, GetColor(0,0,0), "2015 Space/Enterでスタート！");
	DrawFormatString( 50, 450, Green, "座標[%d,%d]", pointer.x, pointer.y);
}