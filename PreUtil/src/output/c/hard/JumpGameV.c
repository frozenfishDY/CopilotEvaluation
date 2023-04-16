/**https://leetcode.com/problems/jump-game-v/ */
//Given an array of integers arr and an integer d. In one step you can jump from index i to index:
//i + x where: i + x < arr.length and 0 < x <= d.
//i - x where: i - x >= 0 and 0 < x <= d.
//In addition, you can only jump from index i to index j if arr[i] > arr[j] and arr[i] > arr[k] for all indices k between i and j (More formally min(i, j) < k < max(i, j)).
//You can choose any index of the array and start jumping. Return the maximum number of indices you can visit.
//Notice that you can not jump outside of the array at any time.


int maxJumps(int* arr, int arrSize, int d){
    int i,j,k;
    int* arr2 = (int*)malloc(sizeof(int)*arrSize);
    for(i=0;i<arrSize;i++){
        arr2[i] = 1;
    }
    for(i=0;i<arrSize;i++){
        for(j=i+1;j<arrSize;j++){
            if(arr[j]>arr[i]){
                arr2[i]++;
            }
            else{
                break;
            }
        }
        for(j=i-1;j>=0;j--){
            if(arr[j]>arr[i]){
                arr2[i]++;
            }
            else{
                break;
            }
        }
    }
    int max = 0;
    for(i=0;i<arrSize;i++){
        if(arr2[i]>max){
            max = arr2[i];
        }
    }
    return max;

}

    