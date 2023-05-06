/**https://leetcode.com/problems/jump-game-iv/ */
//Given an array of integers arr, you are initially positioned at the first index of the array.
//In one step you can jump from index i to index:
//i + 1 where: i + 1 < arr.length.
//i - 1 where: i - 1 >= 0.
//j where: arr[i] == arr[j] and i != j.
//Return the minimum number of steps to reach the last index of the array.
//Notice that you can not jump outside of the array at any time.


int minJumps(int* arr, int arrSize){
    int i,j,k;
    int* arr2 = (int*)malloc(sizeof(int)*arrSize);
    for(i=0;i<arrSize;i++){
        arr2[i] = 0;
    }
    for(i=0;i<arrSize;i++){
        for(j=i+1;j<arrSize;j++){
            if(arr[j]==arr[i]){
                arr2[i]++;
            }
            else{
                break;
            }
        }
        for(j=i-1;j>=0;j--){
            if(arr[j]==arr[i]){
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

    