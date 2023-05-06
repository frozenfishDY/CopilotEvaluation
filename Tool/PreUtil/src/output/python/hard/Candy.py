#https://leetcode.com/problems/candy/
#There are n children standing in a line. Each child is assigned a rating value given in the integer array ratings.
#You are giving candies to these children subjected to the following requirements:
#Each child must have at least one candy.
#Children with a higher rating get more candies than their neighbors.
#Return the minimum number of candies you need to have to distribute the candies to the children.


class Solution(object):
    def candy(self, ratings):
        """
        :type ratings: List[int]
        :rtype: int
        """
        # initialize the candies
        candies = [1] * len(ratings)
        # iterate over the ratings
        for i in range(1, len(ratings)):
            # if the current rating is greater than the previous rating
            if ratings[i] > ratings[i - 1]:
                # set the current candies to the previous candies plus one
                candies[i] = candies[i - 1] + 1
        # iterate over the ratings in reverse
        for i in range(len(ratings) - 2, -1, -1):
            # if the current rating is greater than the next rating
            if ratings[i] > ratings[i + 1]:
                # set the current candies to the maximum of the current candies and the next candies plus one
                candies[i] = max(candies[i], candies[i + 1] + 1)
        # return the sum of the candies
        return sum(candies)
        
        
    