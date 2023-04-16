#https://leetcode.com/problems/set-mismatch/
#You have a set of integers s, which originally contains all the numbers from 1 to n. Unfortunately, due to some error, one of the numbers in s got duplicated to another number in the set, which results in repetition of one number and loss of another number.
#You are given an integer array nums representing the data status of this set after the error.
#Find the number that occurs twice and the number that is missing and return them in the form of an array.


class Solution(object):
    def findErrorNums(self, nums):
        """
        :type nums: List[int]
        :rtype: List[int]
        """  
        n=len(nums)
        sum1=n*(n+1)/2
        sum2=0
        sum3=0
        for i in nums:
            sum2+=i
            sum3+=i*i
        sum2=sum2-sum1
        sum3=sum3-sum1*sum1/n
        return [(sum2+sum3/sum2)/2,(sum2+sum3/sum2)/2-sum2]
        

    