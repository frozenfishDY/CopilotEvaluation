/**https://leetcode.com/problems/get-biggest-three-rhombus-sums-in-a-grid/ */
//You are given an m x n integer matrix grid​​​.
//A rhombus sum is the sum of the elements that form the border of a regular rhombus shape in grid​​​. The rhombus must have the shape of a square rotated 45 degrees with each of the corners centered in a grid cell. Below is an image of four valid rhombus shapes with the corresponding colored cells that should be included in each rhombus sum:
//Note that the rhombus can have an area of 0, which is depicted by the purple rhombus in the bottom right corner.
//Return the biggest three distinct rhombus sums in the grid in descending order. If there are less than three distinct values, return all of them.
// 
//Example 1:
//Input: grid = [[3,4,5,1,3],[3,3,4,2,3],[20,30,200,40,10],[1,5,5,4,1],[4,3,2,2,5]]
//Output: [228,216,211]
//Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
//- Blue: 20 + 3 + 200 + 5 = 228
//- Red: 200 + 2 + 10 + 4 = 216
//- Green: 5 + 200 + 4 + 2 = 211
//Example 2:
//Input: grid = [[1,2,3],[4,5,6],[7,8,9]]
//Output: [20,9,8]
//Explanation: The rhombus shapes for the three biggest distinct rhombus sums are depicted above.
//- Blue: 4 + 2 + 6 + 8 = 20
//- Red: 9 (area 0 rhombus in the bottom right corner)
//- Green: 8 (area 0 rhombus in the bottom middle)
//Example 3:
//Input: grid = [[7,7,7]]
//Output: [7]
//Explanation: All three possible rhombus sums are the same, so return [7].
// 
//Constraints:
//	m == grid.length
//	n == grid[i].length
//	1 <= m, n <= 50
//	1 <= grid[i][j] <= 105
/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* getBiggestThree(int** grid, int gridSize, int* gridColSize, int* returnSize){
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
        if(arr[i-1]!=arr[i]){
            res[index]=arr[i];
            index++;
            if(index==3){
                break;
            }
        }
    }
    *returnSize=index;
    return res;
}