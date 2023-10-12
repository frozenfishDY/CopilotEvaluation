#https://leetcode.com/problems/reconstruct-original-digits-from-english/
#Given a string s containing an out-of-order English representation of digits 0-9, return the digits in ascending order.
# 
#Example 1:
#Input: s = "owoztneoer"
#Output: "012"
#Example 2:
#Input: s = "fviefuro"
#Output: "45"
# 
#Constraints:
#	1 <= s.length <= 105
#	s[i] is one of the characters ["e","g","f","i","h","o","n","s","r","u","t","w","v","x","z"].
#	s is guaranteed to be valid.
class Solution(object):
    def originalDigits(self, s):
        """
        :type s: str
        :rtype: str
        """
        #Solution
        #1. Count the number of each character in s
        #2. For each digit, count the number of its unique character in s
        #3. Return the result
        #
        #Example:
        #s = "owoztneoer"
        #count: {'r': 1, 'e': 3, 'n': 1, 'z': 1, 'o': 2, 't': 1, 'w': 1}
        #ret: [0, 1, 2, 3, 4, 5, 6, 7, 8, 9]
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        count = collections.Counter(s)
        ret = []
        ret.append(count['z'])
        ret.append(count['o'] - count['z'] - count['w'] - count['u'])
        ret.append(count['w'])
        ret.append(count['h'] - count['g'])
        ret.append(count['u'])
        ret.append(count['f'] - count['u'])
        ret.append(count['x'])
        ret.append(count['s'] - count['x'])
        ret.append(count['g'])
        ret.append(count['i'] - count['x'] - count['g'] - count['f'] + count['u'])

        return ''.join(str(digit) * count for digit, count in enumerate(ret))
