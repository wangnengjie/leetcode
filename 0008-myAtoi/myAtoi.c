#include <limits.h>
int myAtoi(char *str)
{
  int i;
  for (i = 0; str[i] != '\0'; i++)
  {
    if (str[i] == ' ')
      continue;
    else if (str[i] == '-' || str[i] == '+' || (str[i] <= '9' && str[i] >= '0'))
      break;
    else
      return 0;
  }
  int m = INT_MAX / 10, n = INT_MIN / 10;
  int result = 0;
  int t = 0;
  if (str[i] == '-')
  {
    i++;
    for (; str[i] <= '9' && str[i] >= '0'; i++)
    {
      t = str[i] - '0';
      if (result < n || (result == n && t > 8))
        return INT_MIN;
      result = result * 10 - t;
    }
  }
  else
  {
    if (str[i] == '+')
      i++;
    for (; str[i] <= '9' && str[i] >= '0'; i++)
    {
      t = str[i] - '0';
      if (result > m || (result == m && t > 7))
        return INT_MAX;
      result = result * 10 + t;
    }
  }
  return result;
}