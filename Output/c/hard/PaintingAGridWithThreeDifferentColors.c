/**https://leetcode.com/problems/painting-a-grid-with-three-different-colors/ */
//You are given two integers m and n. Consider an m x n grid where each cell is initially white. You can paint each cell red, green, or blue. All cells must be painted.
//Return the number of ways to color the grid with no two adjacent cells having the same color. Since the answer can be very large, return it modulo 109 + 7.


int colorTheGrid(int m, int n){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 0;
    }
    arr[0] = 3;
    for(i=1;i<m;i++){
        for(j=n-1;j>0;j--){
            arr[j] = (arr[j] + arr[j-1])%1000000007;
        }
        arr[0] = 0;
    }
    return arr[n-1];

}

    