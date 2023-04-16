#https://leetcode.com/problems/palindrome-partitioning-ii/
#Given a string s, partition s such that every substring of the partition is a palindrome.
#Return the minimum cuts needed for a palindrome partitioning of s.


class Solution(object):
    def minCut(self, s):
        """
        :type s: str
        :rtype: int
        """
        # initialize the 2D array of distances
        distances = [[0 for j in range(len(s) + 1)] for i in range(len(s) + 1)]
        # iterate over the rows of the 2D array of distances
        for i in range(len(s) + 1):
            # iterate over the columns of the 2D array of distances
            for j in range(len(s) + 1):
                # if the current row is 0
                if i == 0:
                    # set the current cell to the current column
                    distances[i][j] = j
                # if the current column is 0
                elif j == 0:
                    # set the current cell to the current row
                    distances[i][j] = i
                # if the current row is not 0 and the current column is not 0
                else:
                    # if the current character in s is equal to the current character in s
                    if s[i - 1] == s[j - 1]:
                        # set the current cell to the cell above and to the left
                        distances[i][j] = distances[i - 1][j - 1]
                    # if the current character in s is not equal to the current character in s
                    else:
                        # set the current cell to the minimum of the cell above, the cell to the left, and the cell above and to the left plus 1
                        distances[i][j] = min(distances[i - 1][j], distances[i][j - 1], distances[i - 1][j - 1]) + 1
        # return the bottom right cell of the 2D array of distances
        return distances[len(s)][len(s)]
        
        
    