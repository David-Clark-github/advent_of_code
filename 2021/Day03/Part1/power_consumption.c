#include <stdio.h>
#include <stdlib.h>


int main(int ac, char **av)
{
	ssize_t	res_gl;
	size_t	n;

	char	**tab;
	char	*gamma;
	char	*epsilon;
	int		one = 0;
	int		zero = 0;
	int		gamma_res = 0;
	int		epsilon_res = 0;

	gamma = (char*)calloc(20, sizeof(char));
	epsilon = (char*)calloc(20, sizeof(char));
	tab = calloc(1000, sizeof(char*));
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
	for (int index = 0; index < 12; index++) {
		for (int depth = 0; depth < 1000; depth++) {
			if (tab[depth][index] == '1') {
				one++;
			} else {
				zero++;
			}
		}
		if (zero > one) {
			gamma[index] = '0';
			epsilon[index] = '1';
		} else {
			gamma[index] = '1';
			epsilon[index] = '0';
		}
		zero = 0;
		one = 0;
	}
	int	binaire = 1;
	for (int index = 11; index >= 0; index--) {
		if (gamma[index] == '1')
			gamma_res += binaire;
		if (epsilon[index] == '1')
			epsilon_res += binaire;
		binaire *= 2;
	}
	printf("%d\n", gamma_res * epsilon_res);
	for (int i = 0; i < 1000; i++)
		free(tab[i]);
	free(tab);
	free(gamma);
	free(epsilon);
}
