/**https://leetcode.com/problems/find-all-groups-of-farmland/ */
//You are given a 0-indexed m x n binary matrix land where a 0 represents a hectare of forested land and a 1 represents a hectare of farmland.
//To keep the land organized, there are designated rectangular areas of hectares that consist entirely of farmland. These rectangular areas are called groups. No two groups are adjacent, meaning farmland in one group is not four-directionally adjacent to another farmland in a different group.
//land can be represented by a coordinate system where the top left corner of land is (0, 0) and the bottom right corner of land is (m-1, n-1). Find the coordinates of the top left and bottom right corner of each group of farmland. A group of farmland with a top left corner at (r1, c1) and a bottom right corner at (r2, c2) is represented by the 4-length array [r1, c1, r2, c2].
//Return a 2D array containing the 4-length arrays described above for each group of farmland in land. If there are no groups of farmland, return an empty array. You may return the answer in any order.
// 
//Example 1:
//Input: land = [[1,0,0],[0,1,1],[0,1,1]]
//Output: [[0,0,0,0],[1,1,2,2]]
//Explanation:
//The first group has a top left corner at land[0][0] and a bottom right corner at land[0][0].
//The second group has a top left corner at land[1][1] and a bottom right corner at land[2][2].
//Example 2:
//Input: land = [[1,1],[1,1]]
//Output: [[0,0,1,1]]
//Explanation:
//The first group has a top left corner at land[0][0] and a bottom right corner at land[1][1].
//Example 3:
//Input: land = [[0]]
//Output: []
//Explanation:
//There are no groups of farmland.
// 
//Constraints:
//	m == land.length
//	n == land[i].length
//	1 <= m, n <= 300
//	land consists of only 0's and 1's.
//	Groups of farmland are rectangular in shape.
/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** findFarmland(int** land, int landSize, int* landColSize, int* returnSize, int** returnColumnSizes){
int i,j;
    int m=landSize;
    int n=*landColSize;
    int **res=(int **)malloc(sizeof(int *)*m*n);
    int index=0;
    int flag=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(land[i][j]==1){
                int temp_i=i;
                int temp_j=j;
                while(temp_i<m && land[temp_i][j]==1){
                    temp_i++;
                }
                while(temp_j<n && land[i][temp_j]==1){
                    temp_j++;
                }
                res[index]=(int *)malloc(sizeof(int)*4);
                res[index][0]=i;
                res[index][1]=j;
                res[index][2]=temp_i-1;
                res[index][3]=temp_j-1;
                index++;
                flag=1;
                for(int k=i;k<temp_i;k++){
                    for(int l=j;l<temp_j;l++){
                        land[k][l]=0;
                    }
                }
            }
        }
    }
    if(flag==0){
        *returnSize=0;
        return res;
    }
    *returnSize=index;
    *returnColumnSizes=(int *)malloc(sizeof(int)*index);
    for(i=0;i<index;i++){
        (*returnColumnSizes)[i]=4;
    }
    return res;

=======
Suggestion 2

int i,j,k;
    int m=landSize;
    int n=*landColSize;
    int len=m*n;
    int **res=(int **)malloc(sizeof(int *)*len);
    *returnColumnSizes=(int *)malloc(sizeof(int)*len);
    int index=0;
    for(i=0;i<m;i++){
        for(j=0;j<n;j++){
            if(land[i][j]==1){
                int flag=0;
                for(k=i;k<m;k++){
                    if(land[k][j]==0){
                        break;
                    }
                    for(int l=j;l<n;l++){
                        if(land[k][l]==0){
                            flag=1;
                            break;
                        }
                    }
                    if(flag==1){
                        break;
                    }
                }
                res[index]=(int *)malloc(sizeof(int)*4);
                res[index][0]=i;
                res[index][1]=j;
                res[index][2]=k-1;
                res[index][3]=j;
                (*returnColumnSizes)[index]=4;
                index++;
            }
        }
    }
    *returnSize=index;
    return res;

}