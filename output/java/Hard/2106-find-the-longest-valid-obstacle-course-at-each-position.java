/**https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/ */
//You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.
//For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:
//You choose any number of obstacles between 0 and i inclusive.
//You must include the ith obstacle in the course.
//You must put the chosen obstacles in the same order as they appear in obstacles.
//Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
//Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.


class FindTheLongestValidObstacleCourseAtEachPosition {
    public int[] longestObstacleCourseAtEachPosition(int[] obstacles) {
        int n = obstacles.length;
        int[] ans = new int[n];
        int[] dp = new int[n];
        int len = 0;
        for(int i = 0; i < n; i++){
            int idx = Arrays.binarySearch(dp, 0, len, obstacles[i]);
            if(idx < 0){
                idx = -(idx + 1);
            }
            dp[idx] = obstacles[i];
            if(idx == len){
                len++;
            }
            ans[i] = idx + 1;
        }
        return ans;
        
    }
}
     
    