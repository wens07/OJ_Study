# no_1.py
# Author: wengqiang
# Date Last Modified: 16:14 2016/9/12
#
# Changelog:
#  
#     
#
# Usage:
#    
#     

#!/usr/bin/env python
# coding=utf-8


class Solution(object):
    def twoSum(self, nums, target):
        """
        :type nums: List[int]
        :type target: int
        :rtype: List[int]
        """
        dict = {}
        for i in range(nums):
            if (target - nums[i]) in dict:
                return [i, dict[target - nums[i]]]
            else:
                dict[nums[i]] = i


