#https://leetcode.com/problems/minimum-number-of-frogs-croaking/
#You are given the string croakOfFrogs, which represents a combination of the string "croak" from different frogs, that is, multiple frogs can croak at the same time, so multiple "croak" are mixed.
#Return the minimum number of different frogs to finish all the croaks in the given string.
#A valid "croak" means a frog is printing five letters 'c', 'r', 'o', 'a', and 'k' sequentially. The frogs have to print all five letters to finish a croak. If the given string is not a combination of a valid "croak" return -1.


class Solution(object):
    def minNumberOfFrogs(self, croakOfFrogs):
        """
        :type croakOfFrogs: str
        :rtype: int
        """   
        # 1. Get the count of each character in the string
        # 2. If the count of c is not equal to the count of k, then return -1
        # 3. If the count of r is not equal to the count of o, then return -1
        # 4. If the count of a is not equal to the count of k, then return -1
        # 5. If the count of c is greater than the count of r, then return -1
        # 6. If the count of r is greater than the count of a, then return -1
        # 7. If the count of a is greater than the count of k, then return -1
        # 8. Return the count of c
        count = {}
        for c in croakOfFrogs:
            if c in count:
                count[c] += 1
            else:
                count[c] = 1
        if count["c"] != count["k"]:
            return -1
        if count["r"] != count["o"]:
            return -1
        if count["a"] != count["k"]:
            return -1
        if count["c"] > count["r"]:
            return -1
        if count["r"] > count["a"]:
            return -1
        if count["a"] > count["k"]:
            return -1
        return count["c"]

        

    