/**https://leetcode.com/problems/parallel-courses-ii/ */
//You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given an array relations where relations[i] = [prevCoursei, nextCoursei], representing a prerequisite relationship between course prevCoursei and course nextCoursei: course prevCoursei has to be taken before course nextCoursei. Also, you are given the integer k.
//In one semester, you can take at most k courses as long as you have taken all the prerequisites in the previous semesters for the courses you are taking.
//Return the minimum number of semesters needed to take all courses. The testcases will be generated such that it is possible to take every course.


class ParallelCoursesIi {
    public int minNumberOfSemesters(int n, int[][] relations, int k) {
        int[] pre = new int[n];
        for (int[] r : relations) {
            pre[r[1] - 1] |= 1 << (r[0] - 1);
        }
        int[] dp = new int[1 << n];
        Arrays.fill(dp, n);
        dp[0] = 0;
        for (int i = 0; i < 1 << n; i++) {
            int canTake = 0;
            for (int j = 0; j < n; j++) {
                if ((i & pre[j]) == pre[j]) {
                    canTake |= 1 << j;
                }
            }
            canTake &= ~i;
            for (int j = canTake; j > 0; j = (j - 1) & canTake) {
                if (Integer.bitCount(j) <= k) {
                    dp[i | j] = Math.min(dp[i | j], dp[i] + 1);
                }
            }
        }
        return dp[(1 << n) - 1];
        
    }
}
     
    