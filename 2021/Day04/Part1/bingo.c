#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int	count_grill(char **master_tab)
{
	int	res = 0;

	for (int i = 1; i < 601; i++) {
		while (isdigit(master_tab[i][0]) == 0)
			i++;
		if (isdigit(master_tab[i][1]))
			res++;
		while (isdigit(master_tab[i][1]))
			i++;
	}
	return res;
}

int	get_number_of_random(char *line)
{
	int	res = 0;
	int	index = 0;

	while (index < strlen(line))
	{
		if (isdigit(line[index]))
			res++;
		while (isdigit(line[index]))
			index++;
		if (isdigit(line[index]) == 0)
			index++;
	}
	return res;
}

void	get_random_num(int *random_num, char *first_line, int len_random_num) {
	int	index_num = 0;
	if (random_num == NULL) {
		printf("calloc failed with random_num\n");
	}
	for (int i = 0; index_num < len_random_num; i++)
	{
		while (isdigit(first_line[i]) == 0)
			i++;
		random_num[index_num] = atoi(&first_line[i]);
		index_num++;
		while(isdigit(first_line[i])) {
			if (i < strlen(first_line)) {
				i++;
			}
		}
	}
}

void	init_bingo_valide(int bingo_valide[100][5][5])
{
	for (int grill = 0; grill < 100; grill++)
	{
		for (int y = 0; y < 5; y++)
		{
			for (int x = 0; x < 5; x++) {
				bingo_valide[grill][y][x] = 0;
			}
		}
	}
}

void	init_bingo_grill(int bingo_grill[100][5][5], char **input_master) {
	int	grill = 0;
	int	y_grill = 0;
	int	x_grill = 0;
	int	line = 2;
	int	x_line = 0;
	for (; grill < 100; grill++) {
		for (y_grill = 0; y_grill < 5; y_grill++) {
			while (isdigit(input_master[line][x_line]) == 0)
				x_line++;
			//1
			bingo_grill[grill][y_grill][x_grill] = atoi(&input_master[line][x_line]);
			x_grill++;
			while (isdigit(input_master[line][x_line]))
				x_line++;
			while (isdigit(input_master[line][x_line]) == 0)
				x_line++;
			//2
			bingo_grill[grill][y_grill][x_grill] = atoi(&input_master[line][x_line]);
			x_grill++;
			while (isdigit(input_master[line][x_line]))
				x_line++;
			while (isdigit(input_master[line][x_line]) == 0)
				x_line++;
			//3
			bingo_grill[grill][y_grill][x_grill] = atoi(&input_master[line][x_line]);
			x_grill++;
			while (isdigit(input_master[line][x_line]))
				x_line++;
			while (isdigit(input_master[line][x_line]) == 0)
				x_line++;
			//4
			bingo_grill[grill][y_grill][x_grill] = atoi(&input_master[line][x_line]);
			x_grill++;
			while (isdigit(input_master[line][x_line]))
				x_line++;
			while (isdigit(input_master[line][x_line]) == 0)
				x_line++;
			//5
			bingo_grill[grill][y_grill][x_grill] = atoi(&input_master[line][x_line]);
			x_grill = 0;
			x_line = 0;
			line++;
		}
		x_grill = 0;
		x_line = 0;
		while (strlen(input_master[line]) == 0)
			line++;
	}
}


int main(int ac, char **av)
{
	int		random_num[100];
	int		len_random_num = 100;
	int		number_of_grill = 100;
	int		bingo_grill[100][5][5];
	int		bingo_valide[100][5][5];
	char	**input_master;
	
	size_t n = 0;
	ssize_t res_gl = 1;
	//calloc and protection of input_master
	input_master = (char**)calloc(602, sizeof(char*));
	if (input_master == NULL) {
		printf("input_master failed to calloc\n");
		return 0;
	}
	//calloc and protection of all input_master[i]
	for (int i = 0; i < 602; i++) {
		input_master[i] = (char*)calloc(300, sizeof(char));
		if (input_master[i] == NULL) {
			printf("failed to calloc input_master[%d]\n", i);
			return 0;
		}
	}
	//getline of the first line of the input and put it in input_master[0]
	if (getline(&input_master[0], &n, stdin) == -1)
	{
		printf("failed to getline\n");
		return 0;
	}
	//putinf the len of random_num
	for (int i = 1; i < 601; i++) {
		if (getline(&input_master[i], &n, stdin) == -1) {
			printf("error on getline on line [%d]", i);
			return 0;
		}
	}
	len_random_num = get_number_of_random(input_master[0]);
	get_random_num(random_num, input_master[0], len_random_num);
	init_bingo_valide(bingo_valide);
	init_bingo_grill(bingo_grill, input_master);
	for (int i = 0; i < 5; i++)
		printf("%d ", bingo_grill[1][0][i]);
	printf("\n");
	for (int i = 0; i < 5; i++)
		printf("%d ", bingo_grill[1][1][i]);
	/*
	for (int grill = 0; grill < 3; grill++) {
		for (int y = 0; y < 5; y++) {
			for (int x = 0; x < 5; x++) {
				printf("%d ", bingo_grill[grill][y][x]);
			}
			printf("\n");
		}
		printf("\n");
	}
	*/
}
