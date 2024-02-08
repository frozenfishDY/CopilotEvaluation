/**https://leetcode.com/problems/max-value-of-equation/ */
//You are given an array points containing the coordinates of points on a 2D plane, sorted by the x-values, where points[i] = [xi, yi] such that xi < xj for all 1 <= i < j <= points.length. You are also given an integer k.
//Return the maximum value of the equation yi + yj + |xi - xj| where |xi - xj| <= k and 1 <= i < j <= points.length.
//It is guaranteed that there exists at least one pair of points that satisfy the constraint |xi - xj| <= k.


int findMaxValueOfEquation(int** points, int pointsSize, int* pointsColSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*pointsSize);
    for(i=0;i<pointsSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<pointsSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<pointsSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    