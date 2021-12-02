#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>

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
	for (int i = 0; res_gl != -1; i++) {
		res_gl = getline(&tab[i], &n, stdin);
	}
}
