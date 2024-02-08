#https://leetcode.com/problems/longest-happy-string/
#A string s is called happy if it satisfies the following conditions:
#s only contains the letters 'a', 'b', and 'c'.
#s does not contain any of "aaa", "bbb", or "ccc" as a substring.
#s contains at most a occurrences of the letter 'a'.
#s contains at most b occurrences of the letter 'b'.
#s contains at most c occurrences of the letter 'c'.
#Given three integers a, b, and c, return the longest possible happy string. If there are multiple longest happy strings, return any of them. If there is no such string, return the empty string "".
#A substring is a contiguous sequence of characters within a string.


class Solution(object):
    def longestDiverseString(self, a, b, c):
        """
        :type a: int
        :type b: int
        :type c: int
        :rtype: str
        """    
        # 1. Create a dictionary of characters and their counts
        # 2. Create a result string
        # 3. Loop until all the characters are exhausted
        # 4. Get the character with the highest count
        # 5. If the character with the highest count is the same as the last character in the result string, then get the next highest character
        # 6. Add the character with the highest count to the result string
        # 7. Decrement the count of the character with the highest count
        # 8. Return the result string
        count = {}
        if a > 0:
            count["a"] = a
        if b > 0:
            count["b"] = b
        if c > 0:
            count["c"] = c
        result = ""
        while len(count) > 0:
            max_char = ""
            max_count = 0
            for c in count:
                if count[c] > max_count:
                    max_count = count[c]
                    max_char = c
            if max_char == result[-1:]:
                max_char = ""
                max_count = 0
                for c in count:
                    if c != result[-1:] and count[c] > max_count:
                        max_count = count[c]
                        max_char = c
            if max_char != "":
                result += max_char
                count[max_char] -= 1
                if count[max_char] == 0:
                    del count[max_char]
        return result

        

    