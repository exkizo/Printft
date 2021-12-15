#include "libft.h"

void put_hex(unsigned long long nbr)
{
  if (nbr >= 16)
  {
    put_hex(nbr / 16);
    put_hex(nbr % 16);
  }
  else
  {
    if (nbr <= 9)
      ft_putchar_fd((nbr + '0'), 1);
    else
      ft_putchar_fd((nbr - 10 +  'a'), 1);
  } 
}