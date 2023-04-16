#https://leetcode.com/problems/fruit-into-baskets/
#You are visiting a farm that has a single row of fruit trees arranged from left to right. The trees are represented by an integer array fruits where fruits[i] is the type of fruit the ith tree produces.
#You want to collect as much fruit as possible. However, the owner has some strict rules that you must follow:
#You only have two baskets, and each basket can only hold a single type of fruit. There is no limit on the amount of fruit each basket can hold.
#Starting from any tree of your choice, you must pick exactly one fruit from every tree (including the start tree) while moving to the right. The picked fruits must fit in one of your baskets.
#Once you reach a tree with fruit that cannot fit in your baskets, you must stop.
#Given the integer array fruits, return the maximum number of fruits you can pick.


class Solution(object):
    def totalFruit(self, fruits):
        """
        :type fruits: List[int]
        :rtype: int
        """       
        res = 0
        i = 0
        j = 0
        count = {}
        while j < len(fruits):
            count[fruits[j]] = count.get(fruits[j], 0) + 1
            while len(count) > 2:
                count[fruits[i]] -= 1
                if count[fruits[i]] == 0:
                    del count[fruits[i]]
                i += 1
            res = max(res, j - i + 1)
            j += 1
        return res

        

    