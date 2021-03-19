#include "cub3d.h"

char			*ft_strfjoin(char *s1, char *s2)
{
	char	*ret;
	int		i;
	int		y;
	int		len;

	i = 0;
	y = 0;
	if (!s1)
		len = ft_strlen(s2);
	else
		len = ft_strlen(s1) + ft_strlen(s2);
	if (!(ret = malloc(sizeof(char) * (len + 1))))
		return (0);
	if (s1)
		while (s1[i])
		{
			ret[i] = s1[i];
			i++;
		}
	if (s2)
		while (s2[y])
			ret[i++] = s2[y++];
	free(s1);
	ret[i] = '\0';
	return (ret);
}
