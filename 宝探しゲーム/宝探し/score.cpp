#include "GV.h"

void Score(){
	if (boxcount == 1)
		score.total += 20; score.boxcount = 0;
	if (boxcount == 2)
		score.total += 10; score.boxcount = 0;
	if (boxcount == 3)
		score.total += 5; score.boxcount = 0;
	if (boxcount >= 4)
		score.total += 0; score.boxcount = 0;
}