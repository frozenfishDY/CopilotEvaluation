/**https://leetcode.com/problems/non-overlapping-intervals/ */
//Given an array of intervals intervals where intervals[i] = [starti, endi], return the minimum number of intervals you need to remove to make the rest of the intervals non-overlapping.


class NonOverlappingIntervals {
    public int eraseOverlapIntervals(int[][] intervals) {
        int n = intervals.length;
        if(n == 0){
            return 0;
        }
        Arrays.sort(intervals, (a, b) -> a[1] - b[1]);
        int res = 1;
        int end = intervals[0][1];
        for(int i = 1; i < n; i++){
            if(intervals[i][0] >= end){
                res++;
                end = intervals[i][1];
            }
        }
        return n - res;
        
    }
}

    