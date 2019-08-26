#include <limits.h>
int reverse(int x)
{
  int result = 0;
  int t;
  int m = INT_MAX / 10, n = INT_MIN / 10;
  while (x != 0)
  {
    t = x % 10;
    x /= 10;
    if (result > m || (result == m && t > 7))
      return 0;
    if (result < n || (result == n && t < -8))
      return 0;
    result = result * 10 + t;
  }
  return result;
}