#include "philo_bonus.h"

size_t	ft_strlen(const char *str)
{
	size_t	size;

	size = 0;
	while (str[size])
		size++;
	return (size);
}

int	ft_strncmp(const char *str1, const char *str2, size_t size)
{
	unsigned int	i;

	if (size == 0)
		return (0);
	i = 0;
	while (str1[i] && str2[i] && i < (size - 1))
	{
		if ((unsigned char)str1[i] != (unsigned char)str2[i])
			return ((unsigned char)str1[i] - (unsigned char)str2[i]);
		i++;
	}
	return ((unsigned char)str1[i] - (unsigned char)str2[i]);
}

void	*ft_calloc(size_t count, size_t size)
{
	char	*str;

	str = malloc(size * count);
	if (!str)
		return (NULL);
	ft_bzero(str, (size * count));
	return (str);
}

void	ft_bzero(void *ptr, size_t size)
{
	unsigned int	i;
	unsigned char	*str;

	i = 0;
	str = (unsigned char *)ptr;
	while (i < size)
	{
		str[i] = '\0';
		i++;
	}
}
