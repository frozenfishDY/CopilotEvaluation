#https://leetcode.com/problems/construct-k-palindrome-strings/
#Given a string s and an integer k, return true if you can use all the characters in s to construct k palindrome strings or false otherwise.


class Solution(object):
    def canConstruct(self, s, k):
        """
        :type s: str
        :type k: int
        :rtype: bool
        """     
        # 1. Get the count of each character in the string
        # 2. Get the count of odd characters
        # 3. If the number of odd characters is greater than k, then return false
        # 4. If the number of odd characters is less than k, then return true
        # 5. If the number of odd characters is equal to k, then return true
        count = {}
        for c in s:
            if c in count:
                count[c] += 1
            else:
                count[c] = 1
        odd_count = 0
        for c in count:
            if count[c] % 2 == 1:
                odd_count += 1
        if odd_count > k:
            return False
        elif odd_count < k:
            return True
        else:
            return True
        

    