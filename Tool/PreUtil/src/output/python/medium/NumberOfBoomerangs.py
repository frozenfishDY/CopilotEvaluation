#https://leetcode.com/problems/number-of-boomerangs/
#You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
#Return the number of boomerangs.


class Solution(object):
    def numberOfBoomerangs(self, points):
        """
        :type points: List[List[int]]
        :rtype: int
        """
        res = 0
        for i in range(len(points)):
            d = {}
            for j in range(len(points)):
                if i == j:
                    continue
                dist = (points[i][0] - points[j][0]) ** 2 + (points[i][1] - points[j][1]) ** 2
                d[dist] = d.get(dist, 0) + 1
            for k in d:
                res += d[k] * (d[k] - 1)
        return res
        

    