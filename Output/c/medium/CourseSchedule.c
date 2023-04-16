/**https://leetcode.com/problems/course-schedule/ */
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return true if you can finish all courses. Otherwise, return false.


bool canFinish(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize){
    int* inDegree = (int*)malloc(sizeof(int) * numCourses);
    memset(inDegree, 0, sizeof(int) * numCourses);
    for(int i = 0; i < prerequisitesSize; i++){
        inDegree[prerequisites[i][0]]++;
    }
    int count = 0;
    int* queue = (int*)malloc(sizeof(int) * numCourses);
    int front = 0;
    int rear = 0;
    for(int i = 0; i < numCourses; i++){
        if(inDegree[i] == 0){
            queue[rear++] = i;
        }
    }
    while(front != rear){
        int course = queue[front++];
        count++;
        for(int i = 0; i < prerequisitesSize; i++){
            if(prerequisites[i][1] == course){
                inDegree[prerequisites[i][0]]--;
                if(inDegree[prerequisites[i][0]] == 0){
                    queue[rear++] = prerequisites[i][0];
                }
            }
        }
    }
    return count == numCourses;

}

    