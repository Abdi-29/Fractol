char	*ft_whitespaces(char *s)
{
	while (*s == ' ' || *s == '\t' || *s == '\n' || \
			*s == '\v' || *s == '\f' || *s == '\r')
		s++;
	return (s);
}
