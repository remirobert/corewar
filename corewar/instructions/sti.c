/*
** sti.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:30:00 2013 guillaume fillon
** Last update Tue Mar 12 19:23:55 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"
/* Est censé marcher ... */
/* 3 min plus tard ... Oui ça marche !!*/

void		op_sti(t_vm *vm, t_proc **lproc)
{
  int		interval[2];

  printf("%sSTI%s\n", F_CYAN, REZ);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
  if ((((*lproc)->cmd[0] >> 4) & 0x03) == 1)
    {
      interval[0] = ((*lproc)->cmd[2] << 8) + (*lproc)->cmd[3];
      printf("REGISTRE = %d\n", interval[0]);
    }
  else
    printf("DIRECTE\n");
  if ((((*lproc)->cmd[0] >> 2) & 0x03) == 1)
    {
      printf("REGISTRE\n");
    }
  else
    printf("DIRECTE\n");
}
