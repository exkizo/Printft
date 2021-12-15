#include "libft/libft.h"

int main() {
  void *ptr = "hello";
  unsigned long long num = (unsigned long long)ptr;
  char *str = " hello 0 -1200 -300 1000 12c 12C % x07fffcad8c1c0";
  int i = ft_strlen(str);
  
  printf("%d\n", i);
  return 0;
}