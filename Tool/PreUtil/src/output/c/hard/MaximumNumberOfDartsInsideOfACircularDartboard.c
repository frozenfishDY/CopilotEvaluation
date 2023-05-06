/**https://leetcode.com/problems/maximum-number-of-darts-inside-of-a-circular-dartboard/ */
//Alice is throwing n darts on a very large wall. You are given an array darts where darts[i] = [xi, yi] is the position of the ith dart that Alice threw on the wall.
//Bob knows the positions of the n darts on the wall. He wants to place a dartboard of radius r on the wall so that the maximum number of darts that Alice throws lies on the dartboard.
//Given the integer r, return the maximum number of darts that can lie on the dartboard.


int numPoints(int** darts, int dartsSize, int* dartsColSize, int r){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*dartsSize);
    for(i=0;i<dartsSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<dartsSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<dartsSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    