/**https://leetcode.com/problems/find-right-interval/ */
//You are given an array of intervals, where intervals[i] = [starti, endi] and each starti is unique.
//The right interval for an interval i is an interval j such that startj >= endi and startj is minimized. Note that i may equal j.
//Return an array of right interval indices for each interval i. If no right interval exists for interval i, then put -1 at index i.


class FindRightInterval {
    public int[] findRightInterval(int[][] intervals) {
        int n = intervals.length;
        int[] res = new int[n];
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for(int i = 0; i < n; i++){
            map.put(intervals[i][0], i);
        }
        for(int i = 0; i < n; i++){
            Map.Entry<Integer, Integer> entry = map.ceilingEntry(intervals[i][1]);
            res[i] = entry == null ? -1 : entry.getValue();
        }
        return res;
        
        
    }
}

    