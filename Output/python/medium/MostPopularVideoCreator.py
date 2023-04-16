#https://leetcode.com/problems/most-popular-video-creator/
#You are given two string arrays creators and ids, and an integer array views, all of length n. The ith video on a platform was created by creator[i], has an id of ids[i], and has views[i] views.
#The popularity of a creator is the sum of the number of views on all of the creator's videos. Find the creator with the highest popularity and the id of their most viewed video.
#If multiple creators have the highest popularity, find all of them.
#If multiple videos have the highest view count for a creator, find the lexicographically smallest id.
#Return a 2D array of strings answer where answer[i] = [creatori, idi] means that creatori has the highest popularity and idi is the id of their most popular video. The answer can be returned in any order.


class Solution(object):
    def mostPopularCreator(self, creators, ids, views):
        """
        :type creators: List[str]
        :type ids: List[str]
        :type views: List[int]
        :rtype: List[List[str]]
        """       
        from collections import defaultdict
        popularity = defaultdict(int)
        max_popularity = 0
        for creator, video_id, view in zip(creators, ids, views):
            popularity[creator] += view
            max_popularity = max(max_popularity, popularity[creator])
        result = []
        for creator, view in popularity.items():
            if view == max_popularity:
                result.append([creator, video_id])
        return result
        

    