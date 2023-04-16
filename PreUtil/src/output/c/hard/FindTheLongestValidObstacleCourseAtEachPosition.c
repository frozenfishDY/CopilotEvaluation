/**https://leetcode.com/problems/find-the-longest-valid-obstacle-course-at-each-position/ */
//You want to build some obstacle courses. You are given a 0-indexed integer array obstacles of length n, where obstacles[i] describes the height of the ith obstacle.
//For every index i between 0 and n - 1 (inclusive), find the length of the longest obstacle course in obstacles such that:
//You choose any number of obstacles between 0 and i inclusive.
//You must include the ith obstacle in the course.
//You must put the chosen obstacles in the same order as they appear in obstacles.
//Every obstacle (except the first) is taller than or the same height as the obstacle immediately before it.
//Return an array ans of length n, where ans[i] is the length of the longest obstacle course for index i as described above.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* longestObstacleCourseAtEachPosition(int* obstacles, int obstaclesSize, int* returnSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr4[i] = 0;
    }
    int* arr5 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr5[i] = 0;
    }
    int* arr6 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr6[i] = 0;
    }
    int* arr7 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr7[i] = 0;
    }
    int* arr8 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr8[i] = 0;
    }
    int* arr9 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr9[i] = 0;
    }
    int* arr10 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr10[i] = 0;
    }
    int* arr11 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr11[i] = 0;
    }
    int* arr12 = (int*)malloc(sizeof(int)*obstaclesSize);
    for(i=0;i<obstaclesSize;i++){
        arr12[i] = 0;
    }
    int* arr13 = (int*)malloc(sizeof(int)*obstacles

}

    