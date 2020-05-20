#include <stdlib.h>
#include <stdio.h>
#include "sandpiles.h"


/**
 * sandpiles_sum - add sand matrices
 *@grid1: first greed
 *@grid2: second greed
 * Return: Always 0 (Success)
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int a = 0;

	for (int x = 0; x <= 3; x++)
	{
		for (int y = 0; y <= 3; y++)
		{
			grid1[x][y] += grid2[x][y];
			if (grid1[x][y] <= 4)
			{
				a = 1;
			}
		}
	}
		if (a == 1)
		{
			recursion(grid1);
			print_grid(grid1);

		}
}

/**
 * recursion - reorganize sand
 *@grid: - first grid
 * Return: Always 0 (Success)
 */

void recursion(int grid[3][3])
{
	for (int x = 0; x <= 3; x++)
	{
		for (int y = 0; y <= 3; y++)
		{
			int num = grid[x][y];

			if (num >= 4)
			{
				grid[x][y] -= 4;
				if (x + 1 <= 3)
					grid[x + 1][y]++;
				if (x - 1 >= 0)
					grid[x - 1][y]++;
				if (y + 1 <= 3)
					grid[x][y + 1]++;
				if (y - 1 >= 0)
					grid[x][y - 1]++;
			}
		}
	}
}

/**
 * print_grid - creates a binary tree node
 *@grid: grid to be print
 * Return: Always 0 (Success)
 */

static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}
