char *convert(char *s, int numRows)
{
  if (numRows == 1)
    return s;
  int length = strlen(s);
  char *result = (char *)malloc((length + 1) * sizeof(char));
  int step = 2 * (numRows - 1);
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