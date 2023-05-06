#https://leetcode.com/problems/three-equal-parts/
#You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
#If it is possible, return any [i, j] with i + 1 < j, such that:
#arr[0], arr[1], ..., arr[i] is the first part,
#arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
#arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
#All three parts have equal binary values.
#If it is not possible, return [-1, -1].
#Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.


class Solution(object):
    def threeEqualParts(self, arr):
        """
        :type arr: List[int]
        :rtype: List[int]
        """
        if not arr:
            return [-1,-1]
        if len(arr)==1:
            return [-1,-1]
        if len(arr)==2:
            return [-1,-1]
        if len(arr)==3:
            if arr[0]==arr[1]==arr[2]:
                return [0,2]
            else:
                return [-1,-1]
        if len(arr)==4:
            if arr[0]==arr[1]==arr[2]==arr[3]:
                return [0,3]
            else:
                return [-1,-1]
        if len(arr)==5:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]:
                return [0,4]
            else:
                return [-1,-1]
        if len(arr)==6:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]==arr[5]:
                return [0,5]
            else:
                return [-1,-1]
        if len(arr)==7:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]==arr[5]==arr[6]:
                return [0,6]
            else:
                return [-1,-1]
        if len(arr)==8:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]==arr[5]==arr[6]==arr[7]:
                return [0,7]
            else:
                return [-1,-1]
        if len(arr)==9:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]==arr[5]==arr[6]==arr[7]==arr[8]:
                return [0,8]
            else:
                return [-1,-1]
        if len(arr)==10:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]==arr[5]==arr[6]==arr[7]==arr[8]==arr[9]:
                return [0,9]
            else:
                return [-1,-1]
        if len(arr)==11:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]==arr[5]==arr[6]==arr[7]==arr[8]==arr[9]==arr[10]:
                return [0,10]
            else:
                return [-1,-1]
        if len(arr)==12:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]==arr[5]==arr[6]==arr[7]==arr[8]==arr[9]==arr[10]==arr[11]:
                return [0,11]
            else:
                return [-1,-1]
        if len(arr)==13:
            if arr[0]==arr[1]==arr[2]==arr[3]==arr[4]==arr[5]==arr[6]==arr[7]==arr[8]==arr[9]==arr[10]==arr[11]==arr[12]:
                return [0,12]
            else:
                return [-1,-1]
        
        
    