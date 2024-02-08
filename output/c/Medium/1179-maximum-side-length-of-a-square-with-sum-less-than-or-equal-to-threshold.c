/**https://leetcode.com/problems/maximum-side-length-of-a-square-with-sum-less-than-or-equal-to-threshold/ */
//Given a m x n matrix mat and an integer threshold, return the maximum side-length of a square with a sum less than or equal to threshold or return 0 if there is no such square.


int maxSideLength(int** mat, int matSize, int* matColSize, int threshold){
    int result = 0;
    int** sum = (int**)malloc(sizeof(int*) * matSize);
    for(int i = 0; i < matSize; i++){
        sum[i] = (int*)malloc(sizeof(int) * matColSize[i]);
        sum[i][0] = mat[i][0];
        for(int j = 1; j < matColSize[i]; j++){
            sum[i][j] = sum[i][j - 1] + mat[i][j];
        }
    }
    for(int i = 0; i < matSize; i++){
        for(int j = 0; j < matColSize[i]; j++){
            int temp = 0;
            int k = 0;
            while(i + k < matSize && j + k < matColSize[i]){
                temp += sum[i + k][j + k];
                if(j > 0){
                    temp -= sum[i + k][j - 1];
                }
                if(temp <= threshold){
                    if(k + 1 > result){
                        result = k + 1;
                    }
                }else{
                    break;
                }
                k++;
            }
        }
    }
    return result;

}

    