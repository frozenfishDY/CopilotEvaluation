/**https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/ */
//You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.
//Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.


int minimumRounds(int* tasks, int tasksSize){
    int i, j;
    int count = 0;
    int arr[100000] = {0};
    for(i = 0; i < tasksSize; i++){
        arr[tasks[i]]++;
    }
    for(i = 0; i < 100000; i++){
        if(arr[i] > 0){
            if(arr[i] % 2 == 0){
                count += arr[i] / 2;
            }
            else{
                count += arr[i] / 2 + 1;
            }
        }
    }
    return count;

}

    