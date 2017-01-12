#include "header.h"
#include <stdio.h>
int		fft_is_delimeter(char c);
char	*fft_strcpy(char *dest, char *src);
int		fft_advance(char **str);
void	fft_advance_whitespace(char **str);
char	**ft_split_whitespaces(char *str);

int		fft_is_delimeter(char c)
{
	return (c == ' ' || c == '\0' || c == '	' || c == '\n');
}

char	*fft_strcpy(char *dest, char *src)
{
	int i;

	i = 0;
	while (!fft_is_delimeter(src[i]))
	{
		dest[i] = src[i];
		++i;
	}
	dest[i] = src[i];
	return (dest);
}

int		fft_advance(char **str)
{
	while (!fft_is_delimeter(**str))
		++(*str);
	return (1);
}

void	fft_advance_whitespace(char **str)
{
	while (**str && fft_is_delimeter(**str))
		++(*str);
}

char	**ft_split_whitespaces(char *str)
{
	char	**tab;
	char	*ptr;
	static int words = 0;

	ptr = str;
	while (*ptr != '\0')
	{
		fft_advance_whitespace(&ptr);
		words += fft_advance(&ptr);
		fft_advance_whitespace(&ptr);
	}
	tab = (char**)malloc(sizeof(tab) * words + 1);
	words = 0;
	while (*str)
	{
		fft_advance_whitespace(&str);
		ptr = str;
		fft_advance(&str);
		tab[words] = (char*)malloc(sizeof(char) * (str - ptr) + 1);
		fft_strcpy(tab[words], ptr);
		tab[words++][str - ptr] = '\0';
		fft_advance_whitespace(&str);
	}
    tab[words] = NULL;
	return (tab);
}
