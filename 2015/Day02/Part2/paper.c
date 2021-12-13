#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int ac, char **av)
{
	int	l = 0;
	int	w = 0;
	int	h = 0;
	int	min1 = 0;
	int	choise_min1 = 0; // 1 = l / 2 = w / 3 = h
	int	min2 = 0;
	char	*buffer;
	int		i_buf = 0;
	size_t	n = 0;
	ssize_t res;
	int	total_res = 0;

	//allocate memory in buffer in 0 -- no need to add '\0' at the end :) --
	buffer = (char *)calloc(10, sizeof(char));
	while (getline(&buffer, &n, stdin) != -1) {
		i_buf = 0;
		l = atoi(&buffer[i_buf]);
		while (isdigit(buffer[i_buf]))
			i_buf++;
		i_buf++;
		w = atoi(&buffer[i_buf]);
		while (isdigit(buffer[i_buf]))
			i_buf++;
		i_buf++;
		h = atoi(&buffer[i_buf]);
		min1 = l;
		choise_min1 = 1;
		if (min1 > w) {
			choise_min1 = 2;
			min1 = w;
		}
		if (min1 > h) {
			choise_min1 = 3;
			min1 = h;
		}
		if (choise_min1 != 1)
			min2 = l;
		else
			min2 = w;
		if (min2 > w && choise_min1 != 2)
			min2 = w;
		if (min2 > h && choise_min1 != 3)
			min2 = h;
		total_res += ((min1 * 2) + (min2 * 2) + (l*h*w));
	}
	printf("%d\n", total_res);
}
