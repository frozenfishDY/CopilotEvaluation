#https://leetcode.com/problems/minimum-number-of-people-to-teach/
#On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
#You are given an integer n, an array languages, and an array friendships where:
#There are n languages numbered 1 through n,
#languages[i] is the set of languages the ith user knows, and
#friendships[i] = [ui,vi] denotes a friendship between the users ui and vi.
#You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.
#Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.


class Solution(object):
    def minimumTeachings(self, n, languages, friendships):
        """
        :type n: int
        :type languages: List[List[int]]
        :type friendships: List[List[int]]
        :rtype: int
        """                                                                                               
        # 1. Get the languages that each user knows
        # 2. Get the languages that each friendship needs
        # 3. Get the number of users that need to be taught each language
        # 4. Return the minimum number of users that need to be taught a language
        users = self.get_users(languages)
        needs = self.get_needs(users, friendships)
        counts = self.get_counts(needs)
        return self.get_min(counts)                 



        

    