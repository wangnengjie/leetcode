#include <string.h>

char *longestCommonPrefix(char **strs, int strsSize)
{
  if (strsSize == 0)
  {
    char *result = (char *)malloc(sizeof(char));
    result[0] = '\0';
    return result;
  }
  if (strsSize == 1)
    return *strs;
  int len = 0;
  for (int i = 0; i < strlen(strs[0]) - 1; i++)
  {
    if (strs[0][i] == strs[1][i] && strs[0][i] != '\0')
      len++;
    else
      break;
  }
  for (int i = 1; i < strsSize - 1; i++)
  {
    if(len>strlen(strs[i+1]))
      len = strlen(strs[i + 1]);
    for (int j = len - 1; j >= 0; j--)
    {
      if (strs[i][j] != strs[i + 1][j])
        len = j;
    }
    if (len == 0)
      break;
  }
  char *result = (char *)malloc((len + 1) * sizeof(char));
  strncpy(result, strs[0], len);
  result[len] = '\0';
  return result;
}