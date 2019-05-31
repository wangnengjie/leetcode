#include <stdbool.h>
#include <limits.h>
bool isPalindrome(int x)
{
  if (x < 0)
    return false;
  int i, j, k = 10, q = 1;
  int m = INT_MAX / 10;
  while (k < x && k < m)
    k *= 10;
  if (k > x)
    k /= 10;
  while (q < k)
  {
    i = (x / k) % 10;
    j = (x / q) % 10;
    if (i != j)
      return false;
    k /= 10;
    q *= 10;
  }
  return true;
}