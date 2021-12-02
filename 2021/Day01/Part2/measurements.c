#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

int	sum_three(char **tab, int i)
{
	int	res = 0;
	res = atoi(tab[i]) + atoi(tab[i + 1]) + atoi(tab[i + 2]);
	return (res);
}

int main(int ac, char **av)
{
	char	*val_1 = NULL;
	char	*val_2 = NULL;
	int		res_val_1;
	int		res_val_2;

	size_t	n = 0;
	ssize_t	res_gl = 0;

	char	**tab = NULL;
	int		master_res = 0;
	tab = calloc(2000, sizeof(char *) * 2000);
	for (int i = 0; i < 2000; i++)
		tab[i] = calloc(1, sizeof(char) * 10);
	for (int i = 0; res_gl != -1; i++) {
		res_gl = getline(&tab[i], &n, stdin);
	}
	res_val_1 = sum_three(tab, 0);
	for (int i = 1; i < 2000 - 3; i++) {
		res_val_2 = sum_three(tab, i);
		if (res_val_1 < res_val_2)
			master_res++;
		res_val_1 = res_val_2;
	}
	printf("ers_master = %d\n", master_res);
}
