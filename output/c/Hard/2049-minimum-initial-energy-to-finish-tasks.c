/**https://leetcode.com/problems/minimum-initial-energy-to-finish-tasks/ */
//You are given an array tasks where tasks[i] = [actuali, minimumi]:
//actuali is the actual amount of energy you spend to finish the ith task.
//minimumi is the minimum amount of energy you require to begin the ith task.
//For example, if the task is [10, 12] and your current energy is 11, you cannot start this task. However, if your current energy is 13, you can complete this task, and your energy will be 3 after finishing it.
//You can finish the tasks in any order you like.
//Return the minimum initial amount of energy you will need to finish all the tasks.


int minimumEffort(int** tasks, int tasksSize, int* tasksColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*tasksSize);
    for(i=0;i<tasksSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<tasksSize;i++){
        arr[i] = arr[i-1] + 1;
        if(i%2==0){
            arr[i] = (arr[i] < arr[i/2] + 1) ? arr[i] : arr[i/2] + 1;
        }
        if(i%3==0){
            arr[i] = (arr[i] < arr[i/3] + 1) ? arr[i] : arr[i/3] + 1;
        }
    }
    return arr[tasksSize-1];

}

    