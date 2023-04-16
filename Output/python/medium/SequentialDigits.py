#https://leetcode.com/problems/sequential-digits/
#An integer has sequential digits if and only if each digit in the number is one more than the previous digit.
#Return a sorted list of all the integers in the range [low, high] inclusive that have sequential digits.


class Solution(object):
    def sequentialDigits(self, low, high):
        """
        :type low: int
        :type high: int
        :rtype: List[int]
        """
        res = []
        for i in range(1,10):
            num = i
            while num <= high and num < 10**9:
                if num >= low:
                    res.append(num)
                num = num*10 + (num%10+1)
        return sorted(res)
        

    