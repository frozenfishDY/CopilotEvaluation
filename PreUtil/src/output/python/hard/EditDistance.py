#https://leetcode.com/problems/edit-distance/
#Given two strings word1 and word2, return the minimum number of operations required to convert word1 to word2.
#You have the following three operations permitted on a word:
#Insert a character
#Delete a character
#Replace a character


class Solution(object):
    def minDistance(self, word1, word2):
        """
        :type word1: str
        :type word2: str
        :rtype: int
        """
        # initialize the 2D array of distances
        distances = [[0 for j in range(len(word2) + 1)] for i in range(len(word1) + 1)]
        # iterate over the rows of the 2D array of distances
        for i in range(len(word1) + 1):
            # iterate over the columns of the 2D array of distances
            for j in range(len(word2) + 1):
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
                    # if the current character in word1 is equal to the current character in word2
                    if word1[i - 1] == word2[j - 1]:
                        # set the current cell to the cell above and to the left
                        distances[i][j] = distances[i - 1][j - 1]
                    # if the current character in word1 is not equal to the current character in word2
                    else:
                        # set the current cell to the minimum of the cell above, the cell to the left, and the cell above and to the left plus 1
                        distances[i][j] = min(distances[i - 1][j], distances[i][j - 1], distances[i - 1][j - 1]) + 1
        # return the bottom right cell of the 2D array of distances
        return distances[len(word1)][len(word2)]
        
        
    