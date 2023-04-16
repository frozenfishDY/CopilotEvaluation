#https://leetcode.com/problems/count-number-of-teams/
#There are n soldiers standing in a line. Each soldier is assigned a unique rating value.
#You have to form a team of 3 soldiers amongst them under the following rules:
#Choose 3 soldiers with index (i, j, k) with rating (rating[i], rating[j], rating[k]).
#A team is valid if: (rating[i] < rating[j] < rating[k]) or (rating[i] > rating[j] > rating[k]) where (0 <= i < j < k < n).
#Return the number of teams you can form given the conditions. (soldiers can be part of multiple teams).


class Solution(object):
    def numTeams(self, rating):
        """
        :type rating: List[int]
        :rtype: int
        """
        # 1. Create a variable to hold the number of teams
        # 2. Loop through the rating list
        # 3. Loop through the rating list
        # 4. Loop through the rating list
        # 5. If the rating at the first index is less than the rating at the second index and the rating at the second index is less than the rating at the third index, then add 1 to the number of teams
        # 6. If the rating at the first index is greater than the rating at the second index and the rating at the second index is greater than the rating at the third index, then add 1 to the number of teams
        # 7. Return the number of teams
        teams = 0
        for i in range(len(rating)):
            for j in range(len(rating)):
                for k in range(len(rating)):
                    if rating[i] < rating[j] < rating[k]:
                        teams += 1
                    if rating[i] > rating[j] > rating[k]:
                        teams += 1
        return teams
        

    