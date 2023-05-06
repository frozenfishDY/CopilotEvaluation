/**https://leetcode.com/problems/minimum-falling-path-sum-ii/ */
//Given an n x n integer matrix grid, return the minimum sum of a falling path with non-zero shifts.
//A falling path with non-zero shifts is a choice of exactly one element from each row of grid such that no two elements chosen in adjacent rows are in the same column.


int minFallingPathSum(int** grid, int gridSize, int* gridColSize){
    int i,j;
    int* arr = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr[i] = 0;
    }
    int* arr2 = (int*)malloc(sizeof(int)*gridSize);
    for(i=0;i<gridSize;i++){
        arr2[i] = 0;
    }
    int* arr3 = (int*)malloc(sizeof(int)*gridColSize[0]);
    for(i=0;i<gridColSize[0];i++){
        arr3[i] = 0;
    }
    int* arr4 = (int*)malloc(sizeof(int)*gridColSize[0]);
    for(i=0;i<gridColSize[0];i++){
        arr4[i] = 0;
    }
    int ans = 0;
    int flag = 0;
    while(flag==0){
        flag = 1;
        for(i=0;i<gridSize;i++){
            if(arr[i]<gridColSize[0]){
                flag = 0;
                break;
            }
        }
        if(flag==1){
            break;
        }
        for(i=0;i<gridSize;i++){
            if(arr[i]<gridColSize[0]){
                arr[i]++;
                arr2[i]++;
                break;
            }
        }
        for(i=0;i<gridColSize[0];i++){
            if(arr3[i]<gridSize){
                arr3[i]++;
                arr4[i]++;
                break;
            }
        }
        ans++;
    }
    return ans;

}

    