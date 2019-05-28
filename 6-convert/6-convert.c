#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
char *convert(char *s, int numRows)
{
  int length = strlen(s);
  char *result = (char *)malloc((length + 1) * sizeof(char));
  int step = numRows == 1 ? 1 : 2 * (numRows - 1);
  int p = 0;
  for (int j = 0; j < numRows; j++)
  {
    for (int i = 0; i < length + step; i += step)
    {
      if (j == 0 || j == numRows - 1)
      {
        if (i + j < length)
          result[p++] = s[i + j];
      }
      else
      {
        if (i + j < length && i + step - j < length)
        {
          result[p++] = s[i + j];
          result[p++] = s[i + step - j];
        }
        else if (i + j < length && i + step - j >= length)
          result[p++] = s[i + j];
      }
    }
  }
  result[length] = '\0';
  return result;
}

int main(void)
{
  char *s = "LEETCODEISHIRING";
  char *r = convert(s, 3);
  printf("%s", r);
  return 0;
}