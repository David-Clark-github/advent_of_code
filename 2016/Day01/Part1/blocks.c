#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/*
	dir:
	1 = N
	2 = E
	3 = S
	4 = W
*/
	
typedef struct santa_direction {
	int	N;
	int	S;
	int	E;
	int	W;
	int	d;
}				s_santa;

int main(int ac, char **av)
{
	s_santa	santa;
	size_t	n = 0;
	ssize_t	gl_res;
	char	*buffer;
	int		i_b = 0;
	santa.N = 0;
	santa.S = 0;
	santa.E = 0;
	santa.W = 0;
	santa.d = 1;
	buffer = (char *)calloc(900, sizeof(char));
	gl_res = getline(&buffer, &n, stdin);
	while (buffer[i_b]) {
		if (buffer[i_b] == 'R' || buffer[i_b] == 'L') {
			if (buffer[i_b] == 'R') {
				santa.d++;
				if (santa.d > 4)
					santa.d = 1;
			} else {
				santa.d--;
				if (santa.d < 1)
					santa.d = 4;
			}
		}
		i_b++;
		if (santa.d == 1) {
			santa.N += atoi(&buffer[i_b]);
			santa.S -= atoi(&buffer[i_b]);
		} else if (santa.d == 2) {
			santa.E += atoi(&buffer[i_b]);
			santa.W -= atoi(&buffer[i_b]);
		} else if (santa.d == 3) {
			santa.S += atoi(&buffer[i_b]);
			santa.N -= atoi(&buffer[i_b]);
		} else if (santa.d == 4) {
			santa.W += atoi(&buffer[i_b]);
			santa.E -= atoi(&buffer[i_b]);
		}
		while (isdigit(buffer[i_b]))
			i_b++;
		while (buffer[i_b] && isalpha(buffer[i_b]) == 0)
		{
			i_b++;
		}
	}
	int	res;
	if (santa.N > 0)
		res += santa.N;
	if (santa.S > 0)
		res += santa.S;
	if (santa.E > 0)
		res += santa.E;
	if (santa.W > 0)
		res += santa.W;
	printf("%d\n", res);
}
