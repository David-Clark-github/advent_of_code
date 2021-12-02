#include <stdio.h>
#include <stdlib.h>

int main(int ac, char **av)
{
	int		depth = 0;
	int		position = 0;
	size_t	n = 0;

	char	*line = NULL;
	while (getline(&line, &n, stdin) != -1)
	{
		if (line[0] == 'u') {
			depth -= atoi(&line[2]);
		}
		if (line[0] == 'd') {
			depth += atoi(&line[2]);
		}
		if (line[0] == 'f') {
			position += atoi(&line[2]);
		}
	}
	printf("result = %d\n", depth * position);
}
