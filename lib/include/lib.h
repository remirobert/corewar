/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Sun Jan 27 00:55:19 2013 guillaume fillon
*/

#ifndef LIB_H_
# define LIB_H_

# define DEBUG

# include <stdio.h>
# include <stdlib.h>
# include <unistd.h>

void	my_putchar(char c);
void	my_putstr(char *str);
void	my_put_nbr(int nb);
void	my_error(char *str, int nb);
int	my_strlen(char *str);
int	my_strcmp(char *s1, char *s2);
void	my_strcpy(char *dest, char *src);
int	my_strncmp(char *s1, char *s2, int n);
char	*my_strdup(char *str);
void	init_reg(int *buf, int cid);

#endif /* LIB_H_ */
