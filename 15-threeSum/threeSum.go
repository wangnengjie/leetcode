package threeSum

import "sort"

func threeSum(nums []int) [][]int {
	var result [][]int
	sort.Ints(nums)
	lastIndex := len(nums) - 1
	if lastIndex < 2 {
		return result
	}
	if nums[0] > 0 || nums[lastIndex] < 0 {
		return result
	}
	for i := 0; i < lastIndex; i++ { // len(nums)-2
		if nums[i] > 0 {
			break
		}
		first, last := i+1, lastIndex
		for first < last {
			if t := nums[i] + nums[first] + nums[last]; t == 0 {
				result = append(result, []int{nums[i], nums[first], nums[last]})
				for first < last && nums[last] == nums[last-1] {
					last--
				}
				for first < last && nums[first] == nums[first+1] {
					first++
				}
				last--
				first++
			} else if t > 0 {
				for first < last && nums[last] == nums[last-1] {
					last--
				}
				last--
			} else {
				for first < last && nums[first] == nums[first+1] {
					first++
				}
				first++
			}
		}
		for i < lastIndex && nums[i] == nums[i+1] {
			i++
		}
	}
	return result
}
