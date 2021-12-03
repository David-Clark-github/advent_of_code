#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
	ssize_t	res_gl;
	size_t	n;

	char	**tab;
	int		*remains;
	int		total_rem = 1000;
	int		gamma_res = 0;
	int		epsilon_res = 0;

	tab = calloc(1000, sizeof(char*));
	remains = calloc(1000, sizeof(int));
	if (tab == NULL) {
		printf("calloc first tab failed\n");
		return 1;
	}
	for (int i = 0; i < 1000; i++) {
		tab[i] = calloc(20, sizeof(char));
		if (tab[i] == NULL) {
			printf("calloc second tab [%d] failed\n", i);
			return 2;
		}
	}
	for (int i = 0; i < 1000; i++) {
		res_gl = getline(&tab[i], &n, stdin);
		if (res_gl == -1) {
			printf("getline failed on line [%d]\n", i);
			return 3;
		}
	}
	for (; total_rem > 1;)
	{
		
	}
	for (int i = 0; i < 1000; i++)
		free(tab[i]);
	free(tab);
}
