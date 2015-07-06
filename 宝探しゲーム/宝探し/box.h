GLOBAL int i, j, k, l,flag;

GLOBAL int boxopen[6];//	箱の中身のフラグ（かんたん） 0ならyesbox、1～5ならnobox
GLOBAL int boxopenN[3][3];//箱の中身のフラグ（ふつう）  1ならyesbox、0ならnobox
GLOBAL int boxopenH[4][4];//箱の中身のフラグ（むずかしい）  1ならyesbox、0ならnobox

GLOBAL int boxstore1;//箱の状態(かんたん用)　配列にすれば良かっ(ry
GLOBAL int boxstore2;
GLOBAL int boxstore3;
GLOBAL int boxstore4;
GLOBAL int boxstore5;
GLOBAL int boxstore6;
GLOBAL int boxstoreN[3][3]; //箱の状態(ふつう用)
GLOBAL int boxstoreH[4][4];	//箱の状態(むずかしい用)

GLOBAL int boxKeystore[6];//    Keyが押されたかどうか判定フラグ（かんたん用）
GLOBAL int boxKeystoreN[3][3];//Keyが押されたかどうか判定フラグ（ふつう用）
GLOBAL int boxKeystoreH[4][4];//Keyが押されたかどうか判定フラグ（むずかしい用）

GLOBAL char *infor;
GLOBAL int boxcount;//何回箱を開いたかカウント
GLOBAL int boxflag;//宝箱は見つかったよ！等　下に出たら他の箱を開けなくするためのフラグ
GLOBAL int yes;//yesboxを見つけたときにyes=1にして宝箱は見つかったよ！と表示
GLOBAL int hit;//何回yesboxを開けたか
GLOBAL int gamecount;//10回ゲームしたときの何回か
GLOBAL int ote;//おてつきの回数

GLOBAL int musicstop;//1回だけ箱開けるときの効果音鳴らすためのフラグ