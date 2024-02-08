#https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/
#You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.
#Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).
#Return the number of pairs of interchangeable rectangles in rectangles.


class Solution(object):
    def interchangeableRectangles(self, rectangles):
        """
        :type rectangles: List[List[int]]
        :rtype: int
        """
        from collections import Counter
        cnt = Counter()
        for w, h in rectangles:
            cnt[w / float(h)] += 1
        return sum(v * (v - 1) / 2 for v in cnt.values())
        

    