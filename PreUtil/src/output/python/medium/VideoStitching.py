#https://leetcode.com/problems/video-stitching/
#You are given a series of video clips from a sporting event that lasted time seconds. These video clips can be overlapping with each other and have varying lengths.
#Each video clip is described by an array clips where clips[i] = [starti, endi] indicates that the ith clip started at starti and ended at endi.
#We can cut these clips into segments freely.
#For example, a clip [0, 7] can be cut into segments [0, 1] + [1, 3] + [3, 7].
#Return the minimum number of clips needed so that we can cut the clips into segments that cover the entire sporting event [0, time]. If the task is impossible, return -1.


class Solution(object):
    def videoStitching(self, clips, time):
        """
        :type clips: List[List[int]]
        :type time: int
        :rtype: int
        """                                                          
        clips.sort()
        res, pre, cur = 0, 0, 0
        for i, clip in enumerate(clips):
            if clip[0] > pre:
                res += 1
                pre = cur
            cur = max(cur, clip[1])
            if cur >= time:
                return res+1
        return -1

        

    