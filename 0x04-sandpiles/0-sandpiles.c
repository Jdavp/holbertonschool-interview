#include <stdlib.h>
#include <stdio.h>

#include "sandpiles.h"

void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int a = 0;
    for (int x = 0; x <= 3; x++) {
        for (int y = 0; y <= 3; y++) {
		grid1[x][y] += grid2[x][y];
		if (grid1[x][y] <= 4){
	        a = 1;
		}
        }
    }
    if (a == 1){
	    recursion(grid1);
    }
}

void recursion(int grid1[3][3]) {
	for (int x = 0; x <= 3; x++) {
		for (int y = 0; y <= 3; y++) {
			int num = grid1[x][y];
			if (num >= 4) {
				grid1[x][y] -= 4;
				if (x + 1 <=3) grid1[x + 1][y]++;
				if (x - 1 >= 0) grid1[x - 1][y]++;
				if (y + 1 <= 3) grid1[x][y + 1]++;
				if (y - 1 >= 0) grid1[x][y - 1]++;
			}
		}
	}
}
