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

int	add_pos(s_santa *log, s_santa pos)
{
	static int len;
	log[len].N = pos.N;
	log[len].S = pos.S;
	log[len].E = pos.E;
	log[len].W = pos.W;
	len++;
	return len;
}

void	check_pos(s_santa *log, int len_log, s_santa ongoing)
{
	int check = 0;
	for (int i = 0; i < len_log; i++)
	{
		if (log[i].N == ongoing.N)
			check++;
		if (log[i].S == ongoing.S)
			check++;
		if (log[i].E == ongoing.E)
			check++;
		if (log[i].W == ongoing.W)
			check++;
		if (check == 4) {
			printf("N = %d\nS = %d\nE = %d\nW = %d\n", ongoing.N, ongoing.S, ongoing.E, ongoing.W);
		}
		check = 0;
	}
}

int main(int ac, char **av)
{
	s_santa	santa;
	s_santa *log;
	size_t	n = 0;
	ssize_t	gl_res;
	char	*buffer;
	int		i_b = 0;
	int	len_log = 0;
	santa.N = 0;
	santa.S = 0;
	santa.E = 0;
	santa.W = 0;
	santa.d = 1;
	buffer = (char *)calloc(900, sizeof(char));
	log = (s_santa *)calloc(200, sizeof(s_santa));
	gl_res = getline(&buffer, &n, stdin);
	len_log	= add_pos(log, santa);
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
		check_pos(log, len_log, santa);
		len_log	= add_pos(log, santa);
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
//	printf("%d\n", res);
}
