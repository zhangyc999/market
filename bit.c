#include <stdio.h>

int main()
{
  int bit_find(int x, int i);
  printf("%d\n", bit_find(6, 0));
}

int bit_find_loop(int n)
{
  int i;
  for (i = 0; i < 32; i++)
    if ((1 << i) & n)
      return i;
}

int bit_find(int x, int i)
{
  if (i >= sizeof(x) * 8) {
    printf("bit_find: find none !!!\n");
    return -1;
  }
  if ((1 << i) & x)
    return i;
  return bit_find(x, i+1);
}

int bit_find_num(int x, int i, int n)
{
  int ret = bit_find(x, i);
  if (!n)
    return ret;
  return bit_find_num(x, ret, n - 1);
}
