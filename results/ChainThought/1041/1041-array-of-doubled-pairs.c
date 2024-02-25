/**https://leetcode.com/problems/array-of-doubled-pairs/ */
//Given an integer array of even length arr, return true if it is possible to reorder arr such that arr[2 * i + 1] = 2 * arr[2 * i] for every 0 <= i < len(arr) / 2, or false otherwise.


bool canReorderDoubled(int* arr, int arrSize){
    int* count = (int*)malloc(sizeof(int) * 20001);
    for(int i = 0; i < 20001; i++){
        count[i] = 0;
    }
    for(int i = 0; i < arrSize; i++){
        count[arr[i] + 10000]++;
    }
    for(int i = 0; i < 10001; i++){
        if(count[i] > count[2 * i]){
            return false;
        }
        count[2 * i] -= count[i];
    }
    return true;

}

    