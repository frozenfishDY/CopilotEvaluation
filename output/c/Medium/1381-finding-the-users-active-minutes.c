/**https://leetcode.com/problems/finding-the-users-active-minutes/ */
//You are given the logs for users' actions on LeetCode, and an integer k. The logs are represented by a 2D integer array logs where each logs[i] = [IDi, timei] indicates that the user with IDi performed an action at the minute timei.
//Multiple users can perform actions simultaneously, and a single user can perform multiple actions in the same minute.
//The user active minutes (UAM) for a given user is defined as the number of unique minutes in which the user performed an action on LeetCode. A minute can only be counted once, even if multiple actions occur during it.
//You are to calculate a 1-indexed array answer of size k such that, for each j (1 <= j <= k), answer[j] is the number of users whose UAM equals j.
//Return the array answer as described above.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* findingUsersActiveMinutes(int** logs, int logsSize, int* logsColSize, int k, int* returnSize){
    int* arr = malloc(k * sizeof(int));
    int i, j;
    int count = 0;
    for(i = 0; i < k; i++){
        arr[i] = 0;
    }
    for(i = 0; i < logsSize; i++){
        for(j = i + 1; j < logsSize; j++){
            if(logs[i][0] == logs[j][0] && logs[i][1] == logs[j][1]){
                logs[j][0] = -1;
                logs[j][1] = -1;
            }
        }
    }
    for(i = 0; i < logsSize; i++){
        if(logs[i][0] != -1){
            count++;
        }
    }
    int* arr1 = malloc(count * sizeof(int));
    int* arr2 = malloc(count * sizeof(int));
    int index = 0;
    for(i = 0; i < logsSize; i++){
        if(logs[i][0] != -1){
            arr1[index] = logs[i][0];
            arr2[index] = logs[i][1];
            index++;
        }
    }
    for(i = 0; i < count; i++){
        for(j = i + 1; j < count; j++){
            if(arr1[i] == arr1[j]){
                arr2[i] = -1;
            }
        }
    }
    for(i = 0; i < count; i++){
        if(arr2[i] != -1){
            arr[count - 1]++;
        }
    }
    *returnSize = k;
    return arr;

}

    