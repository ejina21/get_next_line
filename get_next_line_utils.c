#include <stdlib.h>

int	ft_strlen(char *s)
{
	int	i;

	i = 0;
	while (s[i])
		i++;
	return (i);
}

char	*ft_strjoin(char *s1, char *s2)
{
	char	*p;
	int		i;

	if (!s2 || !s1)
		return (0);
	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!p)
		return (p);
	i = 0;
	while (*s1)
	{
		p[i] = *s1;
		i++;
		s1++;
	}
	while (*s2)
	{
		p[i] = *s2;
		i++;
		s2++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strdup(char *s1)
{
	char	*p;
	int		i;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + 1));
	if (!p)
		return (p);
	i = 0;
	while (*s1)
	{
		p[i] = *s1;
		i++;
		s1++;
	}
	p[i] = 0;
	return (p);
}

char	*ft_strchr(char *s, char c)
{
	while (*s)
	{
		if (*s == c)
			return (s);
		s++;
	}
	return (0);
}

char	*ft_substr(char *s, unsigned int start, unsigned int len)
{
	char			*p;
	unsigned int	i;
	unsigned int	l;

	if (!s)
		return (0);
	l = ft_strlen(s);
	if (len > l)
		len = l;
	if (l <= start)
	{
		p = (char *)malloc(1);
		p[0] = 0;
		return (p);
	}
	p = (char *)malloc(len + 1);
	if (!p)
		return (p);
	i = -1;
	while (++i < len)
		p[i] = s[start + i];
	p[i] = 0;
	return (p);
}
