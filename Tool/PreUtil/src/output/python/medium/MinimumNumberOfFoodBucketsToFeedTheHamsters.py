#https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/
#You are given a 0-indexed string hamsters where hamsters[i] is either:
#'H' indicating that there is a hamster at index i, or
#'.' indicating that index i is empty.
#You will add some number of food buckets at the empty indices in order to feed the hamsters. A hamster can be fed if there is at least one food bucket to its left or to its right. More formally, a hamster at index i can be fed if you place a food bucket at index i - 1 and/or at index i + 1.
#Return the minimum number of food buckets you should place at empty indices to feed all the hamsters or -1 if it is impossible to feed all of them.


class Solution(object):
    def minimumBuckets(self, hamsters):
        """
        :type hamsters: str
        :rtype: int
        """       
        hamsters=hamsters.replace('.','')
        if len(hamsters)==0:
            return 0
        if len(hamsters)==1:
            return 1
        if len(hamsters)==2:
            return 2
        return -1
       
        

    