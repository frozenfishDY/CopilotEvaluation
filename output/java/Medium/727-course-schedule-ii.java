/**https://leetcode.com/problems/course-schedule-ii/ */
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


class CourseScheduleIi {
    public int[] findOrder(int numCourses, int[][] prerequisites) {
        int[] indegree = new int[numCourses];
        for(int[] pre : prerequisites){
            indegree[pre[0]]++;
        }
        Queue<Integer> queue = new LinkedList<>();
        for(int i = 0; i < numCourses; i++){
            if(indegree[i] == 0){
                queue.offer(i);
            }
        }
        int[] res = new int[numCourses];
        int index = 0;
        while(!queue.isEmpty()){
            int course = queue.poll();
            res[index++] = course;
            for(int[] pre : prerequisites){
                if(pre[1] == course){
                    indegree[pre[0]]--;
                    if(indegree[pre[0]] == 0){
                        queue.offer(pre[0]);
                    }
                }
            }
        }
        return index == numCourses ? res : new int[0];
        
    }
}

    