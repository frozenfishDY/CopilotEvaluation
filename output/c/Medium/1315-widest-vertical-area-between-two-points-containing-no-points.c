/**https://leetcode.com/problems/widest-vertical-area-between-two-points-containing-no-points/ */
//Given n points on a 2D plane where points[i] = [xi, yi], Return the widest vertical area between two points such that no points are inside the area.
//A vertical area is an area of fixed-width extending infinitely along the y-axis (i.e., infinite height). The widest vertical area is the one with the maximum width.
//Note that points on the edge of a vertical area are not considered included in the area.
// 
//Example 1:
//​
//Input: points = [[8,7],[9,9],[7,4],[9,7]]
//Output: 1
//Explanation: Both the red and the blue area are optimal.
//Example 2:
//Input: points = [[3,1],[9,0],[1,0],[1,4],[5,3],[8,8]]
//Output: 3
// 
//Constraints:
//	n == points.length
//	2 <= n <= 105
//	points[i].length == 2
//	0 <= xi, yi <= 109
int maxWidthOfVerticalArea(int** points, int pointsSize, int* pointsColSize){
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
        for(j = 0; j < len; j++)
        {
            if(str[i] == str2[j] && visited[j] == 0)
            {
                visited[j] = 1;
                count++;
                break;
            }
        }
    }
    return count;

=======
Suggestion 2

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
        if(visited[i] == 0)
        {
            tmp = 0;
            j = i;
            while(visited[j] == 0)
            {
                visited[j] = 1;
                tmp++;
                j = (j + b) % len;
            }
            if(tmp < len)
            {
                for(k = 0; k < 10; k++)
                {
                    for(l = 0; l < tmp; l++)
                    {
                        str[(i + l * a) % len] += 1;
                        if(str[(i + l * a) % len] > '9')
                        {
                            str[(i + l * a) % len] = '0';
                        }
                    }
                    if(strcmp(result, str) > 0)
                    {
                        strcpy(result, str);
                    }
                }
            }
        }
    }
    return result;
}