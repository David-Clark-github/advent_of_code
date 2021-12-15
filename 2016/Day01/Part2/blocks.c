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
	int	x;
	int	y;
	int	d;
}				s_santa;

int	add_pos(s_santa *log, s_santa pos)
{
	static int len;
	log[len].x = pos.x;
	log[len].y = pos.y;
	len++;
	return len;
}

int	check_pos(s_santa *log, int len_log, s_santa ongoing)
{
	int check = 0;
	int	res_x = 0;
	int	res_y = 0;
	for (int i = 0; i < len_log; i++)
	{
		if (log[i].x == ongoing.x)
			check++;
		if (log[i].y == ongoing.y)
			check++;
		if (check == 2) {
			if (ongoing.x < 0)
				res_x = ongoing.x * -1;
			else 
				res_x = ongoing.x;
			if (ongoing.y < 0)
				res_y = ongoing.y * -1;
			else 
				res_y = ongoing.y;
			return (res_x + res_y);
		}
		check = 0;
	}
	return -1;
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
	int	res;
	santa.x = 0;
	santa.y = 0;
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
		if (santa.d == 1 && res == -1) {
			for (int i = atoi(&buffer[i_b]); i && res == -1; i--)
			{
				santa.y += 1;
				if ((res = check_pos(log, len_log, santa)) != -1)
					printf("%d\n", res);
				len_log = add_pos(log, santa);
			}
		} else if (santa.d == 2 && res == -1) {
			for (int i = atoi(&buffer[i_b]); i && res == -1; i--)
			{
				santa.x += 1;
				if ((res = check_pos(log, len_log, santa)) != -1)
					printf("%d\n", res);
				len_log = add_pos(log, santa);
			}
		} else if (santa.d == 3 && res == -1) {
			for (int i = atoi(&buffer[i_b]); i && res == -1; i--)
			{
				santa.y -= 1;
				if ((res = check_pos(log, len_log, santa)) != -1)
					printf("%d\n", res);
				len_log = add_pos(log, santa);
			}
		} else if (santa.d == 4 && res == -1) {
			for (int i = atoi(&buffer[i_b]); i && res == -1; i--)
			{
				santa.x -= 1;
				if ((res = check_pos(log, len_log, santa)) != -1)
					printf("%d\n", res);
				len_log = add_pos(log, santa);
			}
		}
		while (isdigit(buffer[i_b]))
			i_b++;
		while (buffer[i_b] && isalpha(buffer[i_b]) == 0)
		{
			i_b++;
		}
	}
	//	printf("%d\n", res);
}
