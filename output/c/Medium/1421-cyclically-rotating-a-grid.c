/**https://leetcode.com/problems/cyclically-rotating-a-grid/ */
//You are given an m x n integer matrix grid​​​, where m and n are both even integers, and an integer k._x000D_
//_x000D_
//The matrix is composed of several layers, which is shown in the below image, where each color is its own layer:_x000D_
//_x000D_
//_x000D_
//_x000D_
//A cyclic rotation of the matrix is done by cyclically rotating each layer in the matrix. To cyclically rotate a layer once, each element in the layer will take the place of the adjacent element in the counter-clockwise direction. An example rotation is shown below:_x000D_
//_x000D_
//Return the matrix after applying k cyclic rotations to it._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//Input: grid = [[40,10],[30,20]], k = 1_x000D_
//Output: [[10,20],[40,30]]_x000D_
//Explanation: The figures above represent the grid at every state._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//  _x000D_
//_x000D_
//_x000D_
//Input: grid = [[1,2,3,4],[5,6,7,8],[9,10,11,12],[13,14,15,16]], k = 2_x000D_
//Output: [[3,4,8,12],[2,11,10,16],[1,7,6,15],[5,9,13,14]]_x000D_
//Explanation: The figures above represent the grid at every state._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	m == grid.length_x000D_
//	n == grid[i].length_x000D_
//	2 <= m, n <= 50_x000D_
//	Both m and n are even integers._x000D_
//	1 <= grid[i][j] <= 5000_x000D_
//	1 <= k <= 109_x000D_
/**_x000D_
 * Return an array of arrays of size *returnSize._x000D_
 * The sizes of the arrays are returned as *returnColumnSizes array._x000D_
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free()._x000D_
 */
int** rotateGrid(int** grid, int gridSize, int* gridColSize, int k, int* returnSize, int** returnColumnSizes){
int i,j;
    int m=gridSize;
    int n=*gridColSize;
    int **res=(int **)malloc(sizeof(int *)*m);
    for(i=0;i<m;i++){
        res[i]=(int *)malloc(sizeof(int)*n);
    }
    int temp;
    int temp_i,temp_j;
    int count;
    for(count=0;count<k;count++){
        temp_i=m-1;
        temp_j=n-1;
        for(i=0;i<m/2 && i<n/2;i++,temp_i--,temp_j--){
            temp=grid[i][i];
            for(j=i+1;j<=temp_j;j++){
                grid[i][j-1]=grid[i][j];
            }
            for(j=i+1;j<=temp_i;j++){
                grid[j-1][temp_j]=grid[j][temp_j];
            }
            for(j=temp_j-1;j>=i;j--){
                grid[temp_i][j+1]=grid[temp_i][j];
            }
            for(j=temp_i-1;j>=i+1;j--){
                grid[j+1][i]=grid[j][i];
            }
            grid[i+1][i]=temp;
        }
    }
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            res[i][j]=grid[i][j];
        }
    }
    *returnSize=m;
    *returnColumnSizes=(int *)malloc(sizeof(int)*m);
    for(i=0;i<m;i++){
        (*returnColumnSizes)[i]=n;
    }
    return res;
}