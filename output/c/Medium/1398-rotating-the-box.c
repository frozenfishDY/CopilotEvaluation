/**https://leetcode.com/problems/rotating-the-box/ */
//You are given an m x n matrix of characters box representing a side-view of a box. Each cell of the box is one of the following:_x000D_
//_x000D_
//_x000D_
//	A stone '#'_x000D_
//	A stationary obstacle '*'_x000D_
//	Empty '.'_x000D_
//_x000D_
//_x000D_
//The box is rotated 90 degrees clockwise, causing some of the stones to fall due to gravity. Each stone falls down until it lands on an obstacle, another stone, or the bottom of the box. Gravity does not affect the obstacles' positions, and the inertia from the box's rotation does not affect the stones' horizontal positions._x000D_
//_x000D_
//It is guaranteed that each stone in box rests on an obstacle, another stone, or the bottom of the box._x000D_
//_x000D_
//Return an n x m matrix representing the box after the rotation described above._x000D_
//_x000D_
// _x000D_
//Example 1:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: box = [["#",".","#"]]_x000D_
//Output: [["."],_x000D_
//         ["#"],_x000D_
//         ["#"]]_x000D_
//_x000D_
//_x000D_
//Example 2:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: box = [["#",".","*","."],_x000D_
//              ["#","#","*","."]]_x000D_
//Output: [["#","."],_x000D_
//         ["#","#"],_x000D_
//         ["*","*"],_x000D_
//         [".","."]]_x000D_
//_x000D_
//_x000D_
//Example 3:_x000D_
//_x000D_
//_x000D_
//_x000D_
//_x000D_
//Input: box = [["#","#","*",".","*","."],_x000D_
//              ["#","#","#","*",".","."],_x000D_
//              ["#","#","#",".","#","."]]_x000D_
//Output: [[".","#","#"],_x000D_
//         [".","#","#"],_x000D_
//         ["#","#","*"],_x000D_
//         ["#","*","."],_x000D_
//         ["#",".","*"],_x000D_
//         ["#",".","."]]_x000D_
//_x000D_
//_x000D_
// _x000D_
//Constraints:_x000D_
//_x000D_
//_x000D_
//	m == box.length_x000D_
//	n == box[i].length_x000D_
//	1 <= m, n <= 500_x000D_
//	box[i][j] is either '#', '*', or '.'._x000D_


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
char** rotateTheBox(char** box, int boxSize, int* boxColSize, int* returnSize, int** returnColumnSizes){
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
        if(str[i] != str2[i])
        {
            count++;
            visited[i] = 1;
        }
    }
    if(count == 0)
    {
        return 0;
    }
}