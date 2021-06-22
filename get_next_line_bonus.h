#ifndef GET_NEXT_LINE_BONUS_H
# define GET_NEXT_LINE_BONUS_H

# include <stddef.h>

int		get_next_line(int fd, char **line);
char	*ft_strchr(char *s, int c);
char	*ft_strjoin(char *s1, char *s2);
int		len_c(char *str, char c);
char	*cutstr(char *s, unsigned int begin, size_t length, int on);
#endif
