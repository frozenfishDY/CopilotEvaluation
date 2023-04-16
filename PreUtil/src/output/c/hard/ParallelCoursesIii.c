/**https://leetcode.com/problems/parallel-courses-iii/ */
//You are given an integer n, which indicates that there are n courses labeled from 1 to n. You are also given a 2D integer array relations where relations[j] = [prevCoursej, nextCoursej] denotes that course prevCoursej has to be completed before course nextCoursej (prerequisite relationship). Furthermore, you are given a 0-indexed integer array time where time[i] denotes how many months it takes to complete the (i+1)th course.
//You must find the minimum number of months needed to complete all the courses following these rules:
//You may start taking a course at any time if the prerequisites are met.
//Any number of courses can be taken at the same time.
//Return the minimum number of months needed to complete all the courses.
//Note: The test cases are generated such that it is possible to complete every course (i.e., the graph is a directed acyclic graph).


int minimumTime(int n, int** relations, int relationsSize, int* relationsColSize, int* time, int timeSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<n;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[n-1];


}

    