int maxArea(int *height, int heightSize)
{
  int i = 0, j = heightSize - 1;
  int max = 0;
  int temp;
  for (; i < j;)
  {
    temp = (j - i) * (height[i] > height[j] ? height[j] : height[i]);
    max = temp > max ? temp : max;
    if (height[i] <= height[j])
      i++;
    else
      j--;
  }
  return max;
}