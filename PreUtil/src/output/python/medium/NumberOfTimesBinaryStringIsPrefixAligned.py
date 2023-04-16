#https://leetcode.com/problems/number-of-times-binary-string-is-prefix-aligned/
#You have a 1-indexed binary string of length n where all the bits are 0 initially. We will flip all the bits of this binary string (i.e., change them from 0 to 1) one by one. You are given a 1-indexed integer array flips where flips[i] indicates that the bit at index i will be flipped in the ith step.
#A binary string is prefix-aligned if, after the ith step, all the bits in the inclusive range [1, i] are ones and all the other bits are zeros.
#Return the number of times the binary string is prefix-aligned during the flipping process.


class Solution(object):
    def numTimesAllBlue(self, flips):
        """
        :type flips: List[int]
        :rtype: int
        """       
        # 1. Find the max number in the list
        # 2. If max number is equal to the length of the list, then return 1
        # 3. If max number is greater than the length of the list, then return 2
        # 4. If max number is less than the length of the list, then return 0
        max_num = max(flips)
        if max_num == len(flips):
            return 1
        elif max_num > len(flips):
            return 2
        else:
            return 0

        

    