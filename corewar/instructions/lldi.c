#include "lib.h"
#include "vm.h"

void		op_lldi(t_vm *vm, t_proc **lproc)
{
  int	param1;
  int	param2;
  int	indice;

  indice = 2;
  debug(vm, lproc, -1);
  param1 = get_adress_ldi(vm, lproc, 6, &indice);
  param2 = get_adress_ldi(vm, lproc, 4, &indice);
  if (param1 < 0)
    param1 = MEM_SIZE - param1;
  param1 = vm->mem[((*lproc)->pc + (param1 % IDX_MOD)) % MEM_SIZE];
  param1 = param1 + param2;
  if (((*lproc)->cmd[indice + 1] - 1) % REG_NUMBER < 0)
    (*lproc)->cmd[indice + 1] = 1;
  if (param1 < 0)
    param1 = MEM_SIZE - param1;
  if (vm->option[0].debug != -1)
    print_debug(param1, "value : ", 0);
  (*lproc)->reg[((*lproc)->cmd[indice + 1] - 1) %
		REG_NUMBER] = vm->mem[(((*lproc)->pc + param1) %
				       IDX_MOD) % MEM_SIZE];
  set_carry(lproc, param1);
  (*lproc)->pc += interval_memory((*lproc)->cmd, (*lproc)->code, 0, 0);
}
