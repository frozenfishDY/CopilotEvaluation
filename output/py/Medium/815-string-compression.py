#https://leetcode.com/problems/string-compression/
#Given an array of characters chars, compress it using the following algorithm:
#Begin with an empty string s. For each group of consecutive repeating characters in chars:
#	If the group's length is 1, append the character to s.
#	Otherwise, append the character followed by the group's length.
#The compressed string s should not be returned separately, but instead, be stored in the input character array chars. Note that group lengths that are 10 or longer will be split into multiple characters in chars.
#After you are done modifying the input array, return the new length of the array.
#You must write an algorithm that uses only constant extra space.
# 
#Example 1:
#Input: chars = ["a","a","b","b","c","c","c"]
#Output: Return 6, and the first 6 characters of the input array should be: ["a","2","b","2","c","3"]
#Explanation: The groups are "aa", "bb", and "ccc". This compresses to "a2b2c3".
#Example 2:
#Input: chars = ["a"]
#Output: Return 1, and the first character of the input array should be: ["a"]
#Explanation: The only group is "a", which remains uncompressed since it's a single character.
#Example 3:
#Input: chars = ["a","b","b","b","b","b","b","b","b","b","b","b","b"]
#Output: Return 4, and the first 4 characters of the input array should be: ["a","b","1","2"].
#Explanation: The groups are "a" and "bbbbbbbbbbbb". This compresses to "ab12".
# 
#Constraints:
#	1 <= chars.length <= 2000
#	chars[i] is a lowercase English letter, uppercase English letter, digit, or symbol.
class Solution(object):
    def compress(self, chars):
        """
        :type chars: List[str]
        :rtype: int
        """
        #Solution
        #1. Initialize the index of the result to 0
        #2. Iterate through every character in chars
        #3. For each character, count the number of consecutive same characters
        #4. If the count is greater than 1, add the character and count to the result
        #5. Return the length of the result
        #
        #Example:
        #chars = ["a","a","b","b","c","c","c"]
        #ret: ["a","2","b","2","c","3"]
        #
        #Time complexity: O(n)
        #Space complexity: O(1)

        retIndex = 0
        for i in range(len(chars)):
            count = 1
            while i < len(chars) - 1 and chars[i] == chars[i + 1]:
                count += 1
                i += 1

            chars[retIndex] = chars[i]
            retIndex += 1
            if count > 1:
                countStr = str(count)
                for j in range(len(countStr)):
                    chars[retIndex] = countStr[j]
                    retIndex += 1

        return retIndex