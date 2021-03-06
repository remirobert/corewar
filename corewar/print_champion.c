#include "vm.h"
#include "lib.h"

void		print_champ_data(header_t hdr)
{
  my_putstr("\n\n");
  my_putstr(hdr.prog_name);
  my_putstr(" ");
  my_putstr(BLEU);
  my_putstr(INTENSITE);
  my_putstr(" (");
  my_putstr(hdr.comment);
  my_putstr(")");
  my_putstr(REZ);
  my_putstr(" a gagné !\n");
}

void			print_champion(int count, t_vm *vm)
{
  static SDL_Color	color = {0, 255, 0};
  TTF_Font		*font288;
  SDL_Surface		*surface;
  SDL_Rect		pos;

  font288 = TTF_OpenFont("game_over.ttf", 288);
  print_champ_data(vm->header[count % 4]);
  surface = TTF_RenderText_Blended(font288,
				   vm->header[count % 4].prog_name, color);
  pos.x = (WIDTH / 2) - (surface->w / 2);
  pos.y = (HEIGHT / 2) - (surface->h / 2);
  SDL_BlitSurface(surface, NULL, vm->sdl->screen, &pos);
  SDL_FreeSurface(surface);
  surface = TTF_RenderText_Blended(font288, "WON !", color);
  pos.x = (WIDTH / 2) - (surface->w / 2);
  pos.y = (HEIGHT / 2) - (surface->h / 6) + 50;
  SDL_BlitSurface(surface, NULL, vm->sdl->screen, &pos);
  SDL_FreeSurface(surface);
  TTF_CloseFont(font288);
  SDL_Flip(vm->sdl->screen);
}
