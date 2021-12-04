#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int	count_grill(int **master_tab)
{
	
}

int	get_number_of_random(char *line)
{
	int	res = 0;
	int	index = 0;

	while (line[index] != 0)
	{
		if (isdigit(line[index]))
			res++;
		while (isdigit(line[index]) != 0)
			index++;
		if (isdigit(line[index]) == 0)
			index++;
	}
	return res;
}

int main(int ac, char **av)
{
	int		*random_num;
	int		len_random_num;
	int		number_of_grill;
	int		***bingo_grill;
	int		***bingo_valide;
	char	*first_line;
	char	**input_master;
	
	size_t n = 0;
	//calloc and protection of input_master
	input_master = (char**)calloc(601, sizeof(char*));
	if (input_master == NULL) {
		printf("input_master failed to calloc\n");
		return 0;
	}

	//calloc and protection of all input_master[i]
	for (int i = 0; i < 601; i++) {
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

	//allocate the number of number of random number into random_num
	random_num = (int*)calloc(get_number_of_random(input_master[0]), sizeof(int));
	if (random_num == NULL) {
		printf("calloc failed with random_num\n");
		return 0;
	}
	
	//putinf the len of random_num
	len_random_num = get_number_of_random(input_master[0]);



}
