#https://leetcode.com/problems/number-of-music-playlists/
#Your music player contains n different songs. You want to listen to goal songs (not necessarily different) during your trip. To avoid boredom, you will create a playlist so that:
#Every song is played at least once.
#A song can only be played again only if k other songs have been played.
#Given n, goal, and k, return the number of possible playlists that you can create. Since the answer can be very large, return it modulo 10^9 + 7.


class Solution(object):
    def numMusicPlaylists(self, n, goal, k):
        """
        :type n: int
        :type goal: int
        :type k: int
        :rtype: int
        """
        if n==goal:
            return 1
        if n==1:
            return 1
        if goal==1:
            return 1
        if goal==2:
            return 2
        if k==0:
            return 1
        if k==1:
            return 1
        result = 0
        for i in range(n):
            if i==0:
                result+=self.numMusicPlaylists(n,goal-1,k)
            else:
                result+=self.numMusicPlaylists(n,goal-1,k)
        return result%(10**9+7)
        
        
    