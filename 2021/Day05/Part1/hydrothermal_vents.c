/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hydrothermal_vents.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dclark <dclark@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/01/05 14:48:33 by dclark            #+#    #+#             */
/*   Updated: 2022/01/05 16:54:25 by dclark           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

char	**input_tab;

void	print_data(int vents[500][4], int iter)
{
	printf("[%3d] [%3d]\n", vents[iter][0], vents[iter][1]);
	printf("[%3d] [%3d]\n\n", vents[iter][2], vents[iter][3]);
}

void	paint_into_grid(int grid[1000][1000], int vents[500][4], int iter)
{
	int i = 0;
	if (vents[iter][0] == vents[iter][2])
	{
		if (vents[iter][1] < vents[iter][3])
			for (i = vents[iter][1]; i <= vents[iter][3]; i++)
				grid[vents[iter][0]][i] += 1;
		else if (vents[iter][1] > vents[iter][3])
			for (i = vents[iter][1]; i >= vents[iter][3]; i--)
				grid[vents[iter][0]][i] += 1;
	}
	else if (vents[iter][1] == vents[iter][3])
	{
		if (vents[iter][0] < vents[iter][2])
			for (i = vents[iter][0]; i <= vents[iter][2]; i++)
				grid[i][vents[iter][1]] += 1;
		else if (vents[iter][0] > vents[iter][2])
			for (i = vents[iter][0]; i >= vents[iter][2]; i--)
				grid[i][vents[iter][1]] += 1;
	}
}

void	exctract_data(char *line_vents, int vents[500][4], int iter_vents)
{
	int	i = 0;
	vents[iter_vents][0] = atoi(&line_vents[i]);
	while (isdigit(line_vents[i]))
		i++;
	if (line_vents[i] == ',')
		i++;
	vents[iter_vents][1] = atoi(&line_vents[i]);
	while (isdigit(line_vents[i]))
		i++;
	while (isdigit(line_vents[i]) == 0)
		i++;
	vents[iter_vents][2] = atoi(&line_vents[i]);
	while (isdigit(line_vents[i]))
		i++;
	if (line_vents[i] == ',')
		i++;
	vents[iter_vents][3] = atoi(&line_vents[i]);
}

int	check_line(int vents[500][4], int iter)
{
	if (vents[iter][0] == vents[iter][2])
		return (1);
	if (vents[iter][1] == vents[iter][3])
		return (1);
	return (0);
}

int main(int ac, char **av)
{
	int	grid[1000][1000];
	int	vents[500][4];
	int res = 0;
	int	input_len = 0;

	for (int x = 0; x < 1000; x++)
		for (int y = 0; y < 1000; y++)
			grid[x][y] = 0;
	size_t	n = 0;
	input_tab = (char **)calloc(500, sizeof(char *));
	while (getline(&input_tab[input_len], &n, stdin) != -1)
		input_len++;
	for (int i = 0; i < input_len; i++)
		exctract_data(input_tab[i], vents, i);
	for (int i = 0; i < input_len; i++) {
		if (check_line(vents, i)) {
			paint_into_grid(grid, vents, i);
		}
	}
	for (int x = 0; x < 1000; x++)
		for (int y = 0; y < 1000; y++)
			if (grid[x][y] > 1)
				res++;
	printf("%d\n", res);
}
