#include <stdio.h>
#include <string.h>
#include <stdlib.h>

typedef struct s_santa {
	int	x;
	int	y;
	int	d;
}				t_santa;

int	check_pos(t_santa log_santa[10000], t_santa santa, size_t log_len)
{
	for (size_t i = 0; i < log_len; i++)
	{
		if (santa.x == log_santa[i].x && santa.y == log_santa[i].y) {
			return (1);
		}
	}
	return (0);
}

size_t	add_pos(t_santa log_santa[10000], t_santa santa, size_t log_len)
{
	log_santa[log_len].x = santa.x;
	log_santa[log_len].y = santa.y;
	return (log_len + 1);
}

void	print_santa(t_santa *santa)
{
	printf("x = %d\n", santa->x);
	printf("y = %d\n", santa->y);
}

int main(int ac, char **av)
{
	t_santa	santa;
	t_santa	log_santa[10000];
	t_santa	robot;
	t_santa	log_robot[10000];
	size_t	res = 0;
	size_t	log_len_s = 0;
	size_t	log_len_r = 0;
	size_t	gl_res;
	size_t	n = 0;
	santa.x = 0;
	santa.y = 0;
	robot.x = 0;
	robot.y = 0;
	char	*buffer;
	buffer = calloc(10000, sizeof(char));
	gl_res = getline(&buffer, &n, stdin);
	if (gl_res == -1) {
		printf("getline failed");
		return 1;
	}
	log_len_s = add_pos(log_santa, santa, log_len_s);
	log_len_r = add_pos(log_robot, robot, log_len_r);
	res++;
	for (int i = 0; buffer[i]; i++) {
		if (i % 2 == 0) {
			if (buffer[i] == '^') {
				santa.y++;
			}
			if (buffer[i] == '>') {
				santa.x++;
			}
			if (buffer[i] == 'v') {
				santa.y--;
			}
			if (buffer[i] == '<') {
				santa.x--;
			}
			if (check_pos(log_santa, santa, log_len_s) == 0 &&
				check_pos(log_robot, santa, log_len_r) == 0) {
				res++;
				log_len_s = add_pos(log_santa, santa, log_len_s);
				log_len_r = add_pos(log_robot, santa, log_len_r);
			}
		} else {
			if (buffer[i] == '^') {
				robot.y++;
			}
			if (buffer[i] == '>') {
				robot.x++;
			}
			if (buffer[i] == 'v') {
				robot.y--;
			}
			if (buffer[i] == '<') {
				robot.x--;
			}
			if (check_pos(log_robot, robot, log_len_r) == 0 && 
				check_pos(log_santa, robot, log_len_s) == 0) {
				res++;
				log_len_r = add_pos(log_robot, robot, log_len_r);
				log_len_s = add_pos(log_santa, robot, log_len_s);
			}
		}
	}
	printf("%ld\n", res);
	return 1;
}
