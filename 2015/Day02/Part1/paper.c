#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(int ac, char **av)
{
	int	l = 0;
	int	w = 0;
	int	h = 0;
	int	s1 = 0;
	int	s2 = 0;
	int	s3 = 0;
	int	min;
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
		s1 = 2 * l * w;
		s2 = 2 * w * h;
		s3 = 2 * h * l;
		min = s1 / 2;
		if (min > s2 / 2)
			min = s2 / 2;
		if (min > s3 / 2)
			min = s3 / 2;
		total_res += (s1 + s2 +s3 + min);
	}
	printf("%d\n", total_res);
}
