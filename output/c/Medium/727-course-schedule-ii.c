/**https://leetcode.com/problems/course-schedule-ii/ */
//There are a total of numCourses courses you have to take, labeled from 0 to numCourses - 1. You are given an array prerequisites where prerequisites[i] = [ai, bi] indicates that you must take course bi first if you want to take course ai.
//For example, the pair [0, 1], indicates that to take course 0 you have to first take course 1.
//Return the ordering of courses you should take to finish all courses. If there are many valid answers, return any of them. If it is impossible to finish all courses, return an empty array.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findOrder(int numCourses, int** prerequisites, int prerequisitesSize, int* prerequisitesColSize, int* returnSize){
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
    int* res = (int*)malloc(sizeof(int) * numCourses);
    while(front != rear){
        int course = queue[front++];
        res[count++] = course;
        for(int i = 0; i < prerequisitesSize; i++){
            if(prerequisites[i][1] == course){
                inDegree[prerequisites[i][0]]--;
                if(inDegree[prerequisites[i][0]] == 0){
                    queue[rear++] = prerequisites[i][0];
                }
            }
        }
    }
    if(count == numCourses){
        *returnSize = count;
        return res;
    }
    *returnSize = 0;
    return NULL;

}

    