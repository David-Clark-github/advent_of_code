#include <stdio.h>
#include <stdlib.h>


int	put_digit(char **tab, int *remains, int index_lenght, char search) {
	int	res_loop = 0;
	for (int depth = 0; depth < 1000; depth++)
	{
		if (tab[depth][index_lenght] != search && remains[depth] == 0) {
			res_loop++;
			remains[depth] = 1;
		}
	}
	return res_loop;
}

int	ft_total_remains(int *remains)
{
	int	res = 0;
	for (int i = 0; i < 1000; i++)
	{
		if (remains[i] == 0)
			res++;
	}
	return res;
}

int	binaire_to_digit(char *str)
{
	int	binaire = 1;
	int	res = 0;
	for (int i = 11; i >= 0; i--) {
		if (str[i] == '1') {
			res += binaire;
		}
		binaire *= 2;
	}
	return res;
}

int main(int ac, char **av)
{
	ssize_t	res_gl;
	size_t	n;

	char	**tab;
	int		tab_depth = 1000;
	int		tab_length = 12;
	int		*remains;
	int		zero = 0;
	int		one = 0;
	int		index_lenght = 0;
	int		total_rem = 1000;
	int		Oxy_res = 0;
	int		CO2_res = 0;

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

	while (total_rem > 1) {
		//calcul all 0 or 1 in a certain index
		for (int depth = 0; depth < 1000; depth++) {
			if (tab[depth][index_lenght] == '0' && remains[depth] == 0) {
				zero++;
			}
			if (tab[depth][index_lenght] == '1' && remains[depth] == 0) {
				one++;
			}
		}
		if (one > zero) {
			put_digit(tab, remains, index_lenght, '1');
		} else if (one == zero) {
			put_digit(tab, remains, index_lenght, '1');
		} else {
			put_digit(tab, remains, index_lenght, '0');
		}
		total_rem = ft_total_remains(remains);
		index_lenght++;
	}
	for (int i = 0; i < 1000; i++) {
		if (remains[i] == 0)
			Oxy_res = binaire_to_digit(tab[i]);
	}
	for (int i = 0; i < 1000; i++)
		remains[i] = 0;
	total_rem = 0;
	zero = 0;
	one = 0;
	while (total_rem > 1) {
		//calcul all 0 or 1 in a certain index
		for (int depth = 0; depth < 1000; depth++) {
			if (tab[depth][index_lenght] == '0' && remains[depth] == 0) {
				zero++;
			}
			if (tab[depth][index_lenght] == '1' && remains[depth] == 0) {
				one++;
			}
		}
		if (one < zero) {
			put_digit(tab, remains, index_lenght, '1');
		} else if (one == zero) {
			put_digit(tab, remains, index_lenght, '0');
		} else {
			put_digit(tab, remains, index_lenght, '0');
		}
		total_rem = ft_total_remains(remains);
		index_lenght++;
	}
	for ( int i = 0; i < 1000; i++)
		if (remains[i] == 0)
			CO2_res = binaire_to_digit(tab[i]);
	printf("master_res = %d\n", CO2_res * Oxy_res);
	for (int i = 0; i < 1000; i++)
		free(tab[i]);
	free(tab);
}
