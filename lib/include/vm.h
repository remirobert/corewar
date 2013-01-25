/*
** main.h for main.h in /home/bridou_n//corewar
**
** Made by nicolas bridoux
** Login   <bridou_n@epitech.net>
**
** Started on  Wed Jan 16 17:58:40 2013 nicolas bridoux
** Last update Fri Jan 25 11:36:26 2013 remi robert
*/

#ifndef VM_H_
# define VM_H_

# include <stdio.h>
# include <stdlib.h>
# include "op.h"

# define READ 4096

typedef struct	s_options
{
  int		options;
  int		dump_nbr;
  int		prog_nbr;
  int		load_address;
}		t_options;

typedef struct	s_vm
{
  char		*mem;
}		t_vm;

typedef struct	s_param_mem
{
  int		nb_octet;
  int		indice;
}		t_param_mem;

/*
** open_file.c
*/
int	open_file_champion(char *path, header_t *header);
char	*read_file(const int fd, int *nb_carac);
char	*return_buf_mem(char *file, int *size);

/*
** check_header.c
*/
header_t	*check_header(const int fd, header_t *header);

#endif /* LIB_H_ */
