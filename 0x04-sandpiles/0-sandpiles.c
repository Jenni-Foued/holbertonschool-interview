#include "sandpiles.h"

/**
 * print_grid - Print 3x3 grid
 * @grid: 3x3 grid
 *
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

/**
 * check_stability - verify if sandpile is stable or not
 *
 * @grid: grid(sandpile) to verify
 * Return: 1 if stable else 0
 */
int check_stability(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			if (grid[i][j] > 3)
				return (0);
	return (1);
}

/**
 * sandpiles_sum -  computes the sum of two sandpiles
 *
 * @grid1: first sandpile
 * @grid2: second sandpile
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j;
	int isStable;

	for (i = 0; i < 3; i++)
		for (j = 0; j < 3; j++)
			grid1[i][j] = grid1[i][j] + grid2[i][j];

	isStable = check_stability(grid1);
	while (isStable == 0)
	{
		printf("=\n");
		print_grid(grid1);
		for (i = 0; i < 3; i++)
		{
			for (j = 0; j < 3; j++)
			{
				if (grid1[i][j] > 3)
				{
					grid1[i][j] -= 4;

					if (j - 1 >= 0)
						grid1[i][j - 1]++;
					if (i - 1 >= 0)
						grid1[i - 1][j]++;
					if (i + 1 < 3)
						grid1[i + 1][j]++;
					if (j + 1 < 3)
						grid1[i][j + 1]++;
				}
			}
		}
		isStable = check_stability(grid1);
	}
}
