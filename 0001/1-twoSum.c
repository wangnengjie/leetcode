//solution1
int *twoSum(int *nums, int numsSize, int target)
{
  int flag = 0;
  int *result = (int *)malloc(2 * (sizeof(int)));
  for (int i = 0; i < numsSize - 1; i++)
  {
    for (int j = i + 1; j < numsSize; j++)
    {
      if (nums[i] + nums[j] == target)
      {
        result[0] = i;
        result[1] = j;
        flag = 1;
        break;
      }
    }
    if (flag)
      break;
  }
  return result;
}