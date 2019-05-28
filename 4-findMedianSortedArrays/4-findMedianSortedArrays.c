#include <stdio.h>
double findMedianSortedArrays(int *nums1, int nums1Size, int *nums2, int nums2Size)
{
    if (nums1Size > nums2Size)
        return findMedianSortedArrays(nums2, nums2Size, nums1, nums1Size);
    int imin = 0, imax = nums1Size;
    int mid = (nums1Size + nums2Size + 1) / 2;
    int odd = (nums1Size + nums2Size) % 2;
    while (imin <= imax)
    {
        int i = (imin + imax) / 2;
        int j = mid - 1;
        if (i < imax && nums2[j - 1] > nums1[i])
            imin = i + 1;
        else if (i > imin && nums1[i - 1] > nums2[j])
            imax = i - 1;
        else
        {
            int leftMax;
            if (i == 0)
                leftMax = nums2[j - 1];
            else if (j == 0)
                leftMax = nums1[i - 1];
            else
                leftMax = nums1[i - 1] > nums2[j - 1] ? nums1[i - 1] : nums2[j - 1];

            if (odd)
                return leftMax;

            int rightMin;
            if (i == nums1Size)
                rightMin = nums2[j];
            else if (j == nums2Size)
                rightMin = nums1[i];
            else
                rightMin = (nums1[i] > nums2[j]) ? nums2[j] : nums1[i];
            return (leftMax + rightMin) / 2;
        }
    }
}

int main(void)
{
    int nums1[2] = {1, 3};
    int nums2[3] = {2, 4, 5};
    findMedianSortedArrays(nums1, 2, nums2, 3);
    return 0;
}