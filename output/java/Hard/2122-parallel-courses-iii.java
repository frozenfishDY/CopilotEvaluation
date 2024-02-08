/**https://leetcode.com/problems/parallel-courses-iii/ */
//You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.
//You must find the minimum number of months needed to complete all the courses following these rules:
//You may start taking a course at any time if the prerequisites are met.
//Any number of courses can be taken at the same time.
//Return the minimum number of months needed to complete all the courses.
//Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).


class ParallelCoursesIii {
    public int minimumTime(int n, int[][] relations, int[] time) {
        int[] pre = new int[n];
        int[] dp = new int[n];
        int[] indegree = new int[n];
        for(int[] r : relations){
            pre[r[1] - 1] |= 1 << (r[0] - 1);
            indegree[r[1] - 1]++;
        }
        int res = 0;
        Queue<Integer> q = new LinkedList<>();
        for(int i = 0; i < n; i++){
            if(indegree[i] == 0){
                q.offer(i);
                dp[i] = time[i];
            }
        }
        while(!q.isEmpty()){
            int cur = q.poll();
            res = Math.max(res, dp[cur]);
            for(int i = 0; i < n; i++){
                if((pre[i] & (1 << cur)) != 0){
                    dp[i] = Math.max(dp[i], dp[cur] + time[i]);
                    if(--indegree[i] == 0){
                        q.offer(i);
                    }
                }
            }
        }
        return res;
        
    }
}
     
    