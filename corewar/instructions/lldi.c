/*
** lldi.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:27:49 2013 guillaume fillon
** Last update Tue Mar 26 13:46:34 2013 remi
*/

#include "lib.h"
#include "vm.h"

void		op_lldi(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	s;
  int	read;
  int	indice;

  printf("[%d][%d]lldi ", (*lproc)->reg[0], (*lproc)->nb_proc);
  indice = 0;
  param1 = return_param_op(lproc, &indice, vm, 6);
  param2 = return_param_op(lproc, &indice, vm, 4);
  s = ((vm->mem[((int)((*lproc)->pc + (param1))) % MEM_SIZE] << 8) |
       (vm->mem[((int)((*lproc)->pc + (param1)) + 1)
		% MEM_SIZE] << 8)) + param2;
  read = ((vm->mem[(s % MEM_SIZE) & 0xFF] << 24) | (vm->mem[s % MEM_SIZE + 1] << 16) |
	  (vm->mem[(s % MEM_SIZE + 2) & 0xFF] << 8) |
	  (vm->mem[(s % MEM_SIZE + 3) & 0xFF]));
  set_carry(lproc, read);
  printf("[%d]\n", read);
  (*lproc)->reg[(int)((*lproc)->cmd[indice] - 1)] = read;
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
