/*
** live.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:28:00 2013 guillaume fillon
** Last update Wed Mar 27 09:25:02 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		live_champion(t_vm *vm, int live)
{
  t_proc	*pcourant;

  if (vm->proc == NULL)
    return ;
  pcourant = vm->proc;
  while (pcourant != NULL)
    {
      if (/* pcourant->reg[0] == live || */ pcourant->nb_proc == live)
	{
	  printf("%sLe champion : %d est en vie !%s\n", VERT, live, REZ);
	  vm->old_live = pcourant->nb_proc;
	  pcourant->live = 1;
	}
      pcourant = pcourant->next;
    }
}

void	op_live(t_vm *vm, t_proc **lproc)
{
  int	live;

  vm->nb_live = vm->nb_live + 1;
  printf("[%d][%d]live ", (*lproc)->reg[0], (*lproc)->nb_proc);
  //printf("mem = [%X] ", vm->mem[(*lproc)->pc]);
  //printf("Pc : [%d] {%X}{%X}{%X}{%X}  ", (*lproc)->pc, (*lproc)->cmd[0],  (*lproc)->cmd[1],  (*lproc)->cmd[2],  (*lproc)->cmd[3]);
  live = ((((*lproc)->cmd[0]) << 24) | (((*lproc)->cmd[1]) << 16) |
	  (((*lproc)->cmd[2]) << 8) | ((*lproc)->cmd[3])) & 0xFFFFFFFF;
  printf("champion live : %d \n", live);
  live_champion(vm, live);
  (*lproc)->pc += 5;
}
