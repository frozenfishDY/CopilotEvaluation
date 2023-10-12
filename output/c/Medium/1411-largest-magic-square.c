/**https://leetcode.com/problems/largest-magic-square/ */
//A k x k magic square is a k x k grid filled with integers such that every row sum, every column sum, and both diagonal sums are all equal. The integers in the magic square do not have to be distinct. Every 1 x 1 grid is trivially a magic square.
//Given an m x n integer grid, return the size (i.e., the side length k) of the largest magic square that can be found within this grid.
// 
//Example 1:
//Input: grid = [[7,1,4,5,6],[2,5,1,6,4],[1,5,4,3,2],[1,2,7,3,4]]
//Output: 3
//Explanation: The largest magic square has a size of 3.
//Every row sum, column sum, and diagonal sum of this magic square is equal to 12.
//- Row sums: 5+1+6 = 5+4+3 = 2+7+3 = 12
//- Column sums: 5+5+2 = 1+4+7 = 6+3+3 = 12
//- Diagonal sums: 5+4+3 = 6+4+2 = 12
//Example 2:
//Input: grid = [[5,1,3,1],[9,3,3,1],[1,3,3,8]]
//Output: 2
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 106
int largestMagicSquare(int** grid, int gridSize, int* gridColSize){
int i,j,k;
    int m=gridSize;
    int n=*gridColSize;
    int len=m*n;
    int *arr=(int *)malloc(sizeof(int)*len);
    int *res=(int *)malloc(sizeof(int)*3);
    int index=0;
    int flag=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            arr[index]=grid[i][j];
            index++;
            if(i>0 && j>0){
                flag=1;
                for(k=1;k<=i && k<=j;k++){
                    arr[index]+=grid[i-k][j-k]+grid[i-k][j+k]+grid[i+k][j-k]+grid[i+k][j+k];
                }
                index++;
            }
        }
    }
    if(flag==0){
        res[0]=arr[0];
        *returnSize=1;
        return res;
    }
    int temp;
    for(i=0;i<len;i++){
        for(j=i+1;j<len;j++){
            if(arr[i]<arr[j]){
                temp=arr[i];
                arr[i]=arr[j];
                arr[j]=temp;
            }
        }
    }
    res[0]=arr[0];
    index=1;
    for(i=1;i<len;i++){
        if(arr[i]!=arr[i-1]){
            res[index]=arr[i];
            index++;
            if(index==3){
                *returnSize=3;
                return res;
            }
        }
    }
    *returnSize=index;
    return res;
}