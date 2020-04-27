//
// Created by August on 4/27/20.
//

#ifndef LEETCODE_SEARCHROTATEDSORTARRAY_H
#define LEETCODE_SEARCHROTATEDSORTARRAY_H

/**
 * 33. 搜索旋转排序数组
 * https://leetcode-cn.com/problems/search-in-rotated-sorted-array/
 */

#include <vector>

using namespace std;

class Solution {
public:
    int search(vector<int>& nums, int target) {
        return search(nums, target, 0, nums.size() - 1);
    }

    int search(vector<int>& nums, int target, int begin, int end) {
        if (begin > end) return -1;
        int mid = (begin + end) / 2;
        if (nums[mid] == target) {
            return mid;
        } else if (nums[mid] < nums[end]) {
            if (target > nums[mid] && target <= nums[end]) {
                return search(nums, target, mid + 1, end);
            } else {
                return search(nums, target, begin, mid - 1);
            }
        } else {
            if (target >= nums[begin] && target < nums[mid]) {
                return search(nums, target, begin, mid - 1);
            } else
                return search(nums, target, mid + 1, end);
        }
    }
};

#endif //LEETCODE_SEARCHROTATEDSORTARRAY_H
