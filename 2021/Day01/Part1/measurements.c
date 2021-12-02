#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int ac, char **av)
{
	char	*val_1 = NULL;
	char	*val_2 = NULL;
	int		res_val_1;
	int		res_val_2;
	size_t	n = 0;
	ssize_t	res_gl = 0;
	int		master_res = 0;
	res_gl = getline(&val_1, &n, stdin);
	res_val_1 = atoi(val_1);
	while (res_gl != -1)
	{
		res_gl = getline(&val_2, &n, stdin);
		res_val_2 = atoi(val_2);
		if (res_val_2 > res_val_1)
			master_res++;
		res_val_1 = res_val_2;
	}
	printf("master_res = %d\n",master_res);
}
