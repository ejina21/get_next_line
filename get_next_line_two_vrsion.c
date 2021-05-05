#include "get_next_line.h"

int	anti_leak(char **str, char *str2)
{
	char	*tmp;

	tmp = *str;
	*str = ft_strjoin(*str, str2);
	if (!*str)
		return (-1);
	free(tmp);
	return (0);
}

int	point_n(char **line, char **ostatok, char *p_n, char check)
{
	char	*tmp;

	*p_n = 0;
	if (check)
	{
		*line = ft_strdup(*ostatok);
		if (!line)
			return (0);
	}
	else
	{
		if (anti_leak(line, *ostatok) == -1)
			return (0);
	}
	tmp = *ostatok;
	*ostatok = ft_strdup(++p_n);
	if (!*ostatok)
		return (0);
	free(tmp);
	return (1);
}

int	check_ost(char **line, char **ostatok)
{
	char	*p_n;

	if (*ostatok)
	{
		p_n = ft_strchr(*ostatok, '\n');
		if (p_n && point_n(line, ostatok, p_n, 1))
			return (0);
		else if (p_n)
			return (-1);
		else
		{
			*line = (char *)malloc(1);
			if (!*line)
				return (-1);
			*line[0] = 0;
		}
	}
	else
	{
		*line = (char *)malloc(1);
		if (!*line)
			return (-1);
		*line[0] = 0;
	}
	return (1);
}

int	gnl(char **ostatok, char *buf, char **line, int i)
{
	char	*p_n;

	if (*ostatok && anti_leak(ostatok, buf) == -1)
		return (-1);
	else if (!*ostatok)
	{
		*ostatok = ft_strdup(buf);
		if (!*ostatok)
			return (-1);
	}
	p_n = ft_strchr(*ostatok, '\n');
	if (p_n && point_n(line, ostatok, p_n, 0))
		return (1);
	else if (p_n)
		return (-1);
	if (i < BUFFER_SIZE)
	{
		if (anti_leak(line, *ostatok) == -1)
			return (-1);
		free(*ostatok);
		*ostatok = 0;
		return (0);
	}
	return (2);
}

int	get_next_line(int fd, char **line)
{
	char		buf[BUFFER_SIZE + 1];
	static char	*ostatok = 0;
	int			i;
	int			g;

	if (fd == -1 || fd > 255 || !line)
		return (-1);
	*line = 0;
	i = check_ost(line, &ostatok);
	if (i == -1)
		return (-1);
	while (i)
	{
		i = read(fd, buf, BUFFER_SIZE);
		if (i < 0)
			return (-1);
		buf[i] = 0;
		g = gnl(&ostatok, buf, line, i);
		if (g != 2)
			return (g);
	}
	return (1);
}
