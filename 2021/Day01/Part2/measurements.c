#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>


int		ft_strlen(char *str)
{
	int	res;

	if (!str)
		return (0);
	res = 0;
	while (str[res] != '\0')
	{
		res++;
	}
	return (res);
}

int		check_eol(char *tmp)
{
	int	i;

	i = 0;
	if (tmp == NULL)
		return (0);
	while (tmp[i])
	{
		if (tmp[i] == '\n')
			return (1);
		i++;
	}
	return (0);
}

char	*get_line(char *tmp)
{
	char	*dest;
	int		i_n;
	int		i_d;

	i_n = 0;
	i_d = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i_n] != '\n' && tmp[i_n])
		i_n++;
	if (!(dest = malloc(sizeof(char) * (i_n + 1))))
		return (NULL);
	while (i_n--)
	{
		dest[i_d] = tmp[i_d];
		i_d++;
	}
	dest[i_d] = '\0';
	return (dest);
}

char	*get_after_eol(char *tmp)
{
	char	*dest;
	int		i_t;
	int		i_d;

	i_t = 0;
	i_d = 0;
	if (!tmp)
		return (NULL);
	while (tmp[i_t] && tmp[i_t] != '\n')
		i_t++;
	if (tmp[i_t] == '\0' || tmp[i_t + 1] == '\0')
	{
		free(tmp);
		return (NULL);
	}
	while (tmp[i_t + i_d])
		i_d++;
	if (!(dest = malloc(sizeof(char) * i_d)))
		return (NULL);
	i_d = -1;
	while (tmp[(i_t + 1) + ++i_d])
		dest[i_d] = tmp[(i_t + 1) + i_d];
	dest[i_d] = '\0';
	free(tmp);
	return (dest);
}

char	*ftft_strjoin(char *tmp, int tmp_sz, char *buffer, int bytes_read)
{
	char	*dest;
	int		i_d;
	int		i_s;

	i_d = 0;
	i_s = 0;
	if (tmp == NULL && bytes_read == 0)
		return (NULL);
	if (!(dest = malloc(sizeof(char) * (tmp_sz + bytes_read + 1))))
		return (NULL);
	while (0 < tmp_sz--)
		dest[i_d++] = tmp[i_s++];
	i_s = 0;
	while (0 < bytes_read--)
		dest[i_d++] = buffer[i_s++];
	dest[i_d] = '\0';
	free(tmp);
	return (dest);
}


static int	return_zero(char *tmp)
{
	free(tmp);
	return (0);
}

int			get_next_line(int fd, char **line)
{
	static char	*tmp;
	char		*buffer;
	int			bytes_read;

	if (fd < 0 || !line || BUFFER_SIZE <= 0)
		return (-1);
	if (!(buffer = malloc(sizeof(char) * (BUFFER_SIZE + 1))))
		return (-1);
	bytes_read = 42;
	while (bytes_read != 0 && check_eol(tmp) != 1)
	{
		if ((bytes_read = read(fd, buffer, BUFFER_SIZE)) == -1)
		{
			free(buffer);
			return (-1);
		}
		tmp = ftft_strjoin(tmp, ft_strlen(tmp), buffer, bytes_read);
	}
	free(buffer);
	*line = get_line(tmp);
	tmp = get_after_eol(tmp);
	if (bytes_read == 0)
		return (return_zero(tmp));
	return (1);
}




int main(int ac, char **av)
{
	char	*val_1 = NULL;
	char	*val_2 = NULL;
	int		res_val_1;
	int		res_val_2;

	size_t	n = 0;
	ssize_t	res_gl = 0;

	char	**tab;

	int		master_res = 0;
	for (int i = 0; res_gl != -1; i++) {
		res_gl = get_next_line(1, &tab[i]);
		printf("tab[i] = %s\n", tab[i]);
	}

}
