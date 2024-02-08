/**https://leetcode.com/problems/construct-target-array-with-multiple-sums/ */
//You are given an array target of n integers. From a starting array arr consisting of n 1's, you may perform the following procedure :
//let x be the sum of all elements currently in your array.
//choose index i, such that 0 <= i < n and set the value of arr at index i to x.
//You may repeat this procedure as many times as needed.
//Return true if it is possible to construct the target array from arr, otherwise, return false.


bool isPossible(int* target, int targetSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*targetSize);
    for(i=0;i<targetSize;i++){
        arr[i] = 1;
    }
    int sum = 0;
    for(i=0;i<targetSize;i++){
        sum += target[i];
    }
    int max = 0;
    int maxIndex = 0;
    for(i=0;i<targetSize;i++){
        if(target[i]>max){
            max = target[i];
            maxIndex = i;
        }
    }
    while(sum>targetSize){
        sum -= max;
        if(sum==1){
            return true;
        }
        max = max - sum;
        if(max<=0){
            return false;
        }
        sum += max;
    }
    return false;

}

    