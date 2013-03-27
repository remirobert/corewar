/*
** sti.c for Corewar in /home/fillon_g/projets/groups/corewar/corewar/instructions
**
** Made by guillaume fillon
** Login   <fillon_g@epitech.net>
**
** Started on  Mon Jan 28 20:30:00 2013 guillaume fillon
** Last update Wed Mar 27 11:27:19 2013 remi
*/

#include "lib.h"
#include "vm.h"
#include "couleur.h"

void		load_reg(t_vm *vm, t_proc **lproc, char *reg, int *i)
{
  int		adress;

  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 1)
    {
      reg[0] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) % REG_NUMBER] >> 24) & 0xFF;
      reg[1] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) % REG_NUMBER] >> 16) & 0xFF;
      reg[2] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) % REG_NUMBER] >> 8) & 0xFF;
      reg[3] = ((*lproc)->reg[((int)(*lproc)->cmd[1] - 1) % REG_NUMBER]) & 0xFF;
    *i = 2;
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 2)
    {
      adress = (((*lproc)->reg[((int)((*lproc)->cmd[1] - 1) % REG_NUMBER)] >> 24) & 0xFF) |
      (((*lproc)->reg[((int)((*lproc)->cmd[2] - 1) % REG_NUMBER)] >> 16) & 0xFF) |
      (((*lproc)->reg[((int)((*lproc)->cmd[3] - 1) % REG_NUMBER)] >> 8) & 0xFF) |
      (((*lproc)->reg[((int)((*lproc)->cmd[4] - 1) % REG_NUMBER)]) & 0xFF);
      if (adress < 0)
	adress = MEM_SIZE - adress;
      reg[0] = (vm->mem[adress % MEM_SIZE] >> 24) & 0xFF;
      reg[1] = (vm->mem[adress % MEM_SIZE] >> 16) & 0xFF;
      reg[2] = (vm->mem[adress % MEM_SIZE] >> 8) & 0xFF;
      reg[3] = (vm->mem[adress % MEM_SIZE]) & 0xFF;
      *i = 5;
    }
  if ((((*lproc)->cmd[0] >> 6) & 0x03) == 3)
    {
      adress = (((*lproc)->reg[((int)((*lproc)->cmd[1] - 1) % REG_NUMBER)] >> 8) & 0xFF) |
	(((*lproc)->reg[((int)((*lproc)->cmd[2] - 1) % REG_NUMBER)]) & 0xFF);
      reg[0] = (adress << 24) & 0xFF;
      reg[1] = (adress << 16) & 0xFF;
      reg[2] = (adress << 8) & 0xFF;
      reg[3] = (adress) & 0xFF;
      *i = 3;
    }
}

int		calc_offset(t_proc **lproc, int *i, int param)
{
  int		offset;

  offset = 0;
  if (((((*lproc)->cmd[0] & 0xFF) >> param) & 0x03) == 1)
    {
      offset = (*lproc)->reg[(int)(((*lproc)->cmd[*i] - 1) & 0xFF) % REG_NUMBER];
      ++(*i);
    }
  else if (((((*lproc)->cmd[0] & 0xFF) >> param) & 0x3) == 2 ||
	   ((((*lproc)->cmd[0] & 0xFF) >> param) & 0x3) == 3)
    {
      offset = ((((*lproc)->cmd[*i] & 0xFF) << 8)) + ((((*lproc)->cmd[*i + 1]) & 0xFF));
      *i += 2;
    }
  printf("offset : {%d}  ", offset);
  return (offset);
}

/*
** STI BUGE NE FONCTIONNE PAS !!!!
*/

void		op_sti(t_vm *vm, t_proc **lproc)
{
  int		i;
  char		reg[4];
  int		offset;

  offset = 0;
  i = 2;
  load_reg(vm, lproc, reg, &i);
  printf("[%d][%d]sti ", (*lproc)->reg[0], (*lproc)->nb_proc);
  offset += calc_offset(lproc, &i, 4);
  fflush(stdout);
  offset += calc_offset(lproc, &i, 2);
  fflush(stdout);
  if (offset < 0)
    offset = (MEM_SIZE) + offset;
  printf("@(%d)\n", offset);
  //printf("REG = {%d}=> %d  ", (*lproc)->reg[(int)(*lproc)->cmd[1]], (int)(*lproc)->cmd[1]);
  printf("copy : [%d][%d][%d][%d] \n", reg[0], reg[1], reg[2], reg[3]);
  vm->mem[((*lproc)->pc + offset) % MEM_SIZE] = reg[0];
  vm->mem[((*lproc)->pc + (offset + 1)) % MEM_SIZE] = reg[1];
  vm->mem[((*lproc)->pc + (offset + 2)) % MEM_SIZE] = reg[2];
  vm->mem[((*lproc)->pc + (offset + 3)) % MEM_SIZE] = reg[3];
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
