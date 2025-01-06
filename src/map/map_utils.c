#include "so_long.h"

size_t	dim2_len(void **tab)
{
	size_t	len;

	len = 0;
	while (tab[len] != NULL)
		len++;
	return (len);
}

void	dim2_cpy(void **dest, void **src)
{
	while (*src != NULL)
		*dest++ = *src++;
	*dest = NULL;
}
