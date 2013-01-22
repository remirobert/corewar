/*
** open_file.c for iopen_file in /home/robert_r//Corewar/Corewar/vm
**
** Made by remi robert
** Login   <robert_r@epitech.net>
**
** Started on  Mon Jan 21 18:34:30 2013 remi robert
** Last update Tue Jan 22 12:15:42 2013 remi robert
*/

#include <sys/stat.h>
#include <fcntl.h>
#include "lib.h"
#include "vm.h"

char	*read_file(const int fd, int *nb_carac)
{
  int	size_read;
  char	buff[2];
  char	*file;

  *nb_carac = 0;
  size_read = 1;
  file = NULL;
  buff[1] = '\0';
  while ((size_read = read(fd, buff, 1)) != 0)
    {
      if (size_read == -1)
	my_error("Error read file\n", 1);
      if ((file = realloc(file, *nb_carac + size_read)) == NULL)
	my_error("Error malloc\n", 1);
      file[*nb_carac] = buff[0];
      *nb_carac = *nb_carac + size_read;
    }
  return (file);
}

t_champion	*open_file(char *path, t_champion *champion)
{
  char		*file;
  int		fd;

  champion->nb_carac = 0;
  fd = open(path, O_RDONLY);
  if (fd == -1)
    my_error("File not found\n", 1);
  champion->file = read_file(fd, &(champion->nb_carac));
  my_putstr("File ok \n");
  check_magic_code(champion->file, champion->nb_carac);
  champion->name = extract_name(champion->file, champion->nb_carac);
  printf("%s\n", champion->name);
  print_file(champion->file, champion->nb_carac);
  return (champion);
}