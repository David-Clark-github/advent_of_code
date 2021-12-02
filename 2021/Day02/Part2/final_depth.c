#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int		depth = 0;
	int		position = 0;
	int		aim = 0;
	size_t	n = 0;

	char	*line = NULL;
	while (getline(&line, &n, stdin) != -1)
	{
		if (line[0] == 'u') {
			aim -= atoi(&line[2]);
		}
		if (line[0] == 'd') {
			aim += atoi(&line[2]);
		}
		if (line[0] == 'f') {
			position += atoi(&line[2]);
			depth += (aim * atoi(&line[2]));
		}
	}
	printf("result = %d\n", depth * position);
}
