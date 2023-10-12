/**https://leetcode.com/problems/path-with-minimum-effort/ */
//You are a hiker preparing for an upcoming hike. You are given heights, a 2D array of size rows x columns, where heights[row][col] represents the height of cell (row, col). You are situated in the top-left cell, (0, 0), and you hope to travel to the bottom-right cell, (rows-1, columns-1) (i.e., 0-indexed). You can move up, down, left, or right, and you wish to find a route that requires the minimum effort._x000D_
//_x000D_
//A route's effort is the maximum absolute difference in heights between two consecutive cells of the route._x000D_
//_x000D_
//Return the minimum effort required to travel from the top-left cell to the bottom-right cell._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: heights = [[1,2,2],[3,8,2],[5,3,5]]_x000D_
//Output: 2_x000D_
//Explanation: The route of [1,3,5,3,5] has a maximum absolute difference of 2 in consecutive cells._x000D_
//This is better than the route of [1,2,2,2,5], where the maximum absolute difference is 3._x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: heights = [[1,2,3],[3,8,4],[5,3,5]]_x000D_
//Output: 1_x000D_
//Explanation: The route of [1,2,3,4,5] has a maximum absolute difference of 1 in consecutive cells, which is better than route [1,3,5,3,5]._x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//Input: heights = [[1,2,1,1,1],[1,2,1,2,1],[1,2,1,2,1],[1,2,1,2,1],[1,1,1,2,1]]_x000D_
//Output: 0_x000D_
//Explanation: This route does not require any effort._x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	rows == heights.length_x000D_
//	columns == heights[i].length_x000D_
//	1 <= rows, columns <= 100_x000D_
//	1 <= heights[i][j] <= 106_x000D_
int minimumEffortPath(int** heights, int heightsSize, int* heightsColSize){
int i = 0;
    int j = 0;
    int k = 0;
    int l = 0;
    int m = 0;
    int n = 0;
    int len = strlen(s);
    int min = 0;
    int tmp = 0;
    int count = 0;
    int flag = 0;
    int *visited = (int*)malloc(sizeof(int) * len);
    memset(visited, 0, sizeof(int) * len);
    char *str = (char*)malloc(sizeof(char) * len + 1);
    strcpy(str, s);
    char *str2 = (char*)malloc(sizeof(char) * len + 1);
    strcpy(str2, s);
    for(i = 0; i < len; i++)
    {
        min = i;
        for(j = i + 1; j < len; j++)
        {
            if(str[j] < str[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            tmp = str[i];
            str[i] = str[min];
            str[min] = tmp;
        }
    }
    for(i = 0; i < len; i++)
    {
        min = i;
        for(j = i + 1; j < len; j++)
        {
            if(str2[j] < str2[min])
            {
                min = j;
            }
        }
        if(min != i)
        {
            tmp = str2[i];
            str2[i] = str2[min];
            str2[min] = tmp;
        }
    }
    for(i = 0; i < len; i++)
    {
        if(str[i] != str2[i])
        {
            return false;
        }
    }
    return true;
}