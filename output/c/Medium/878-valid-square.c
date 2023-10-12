/**https://leetcode.com/problems/valid-square/ */
//Given the coordinates of four points in 2D space p1, p2, p3 and p4, return true if the four points construct a square.
//The coordinate of a point pi is represented as [xi, yi]. The input is not given in any order.
//A valid square has four equal sides with positive length and four equal angles (90-degree angles).
// 
//Example 1:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,1]
//Output: true
//Example 2:
//Input: p1 = [0,0], p2 = [1,1], p3 = [1,0], p4 = [0,12]
//Output: false
//Example 3:
//Input: p1 = [1,0], p2 = [-1,0], p3 = [0,1], p4 = [0,-1]
//Output: true
// 
//Constraints:
//	p1.length == p2.length == p3.length == p4.length == 2
//	-104 <= xi, yi <= 104
bool validSquare(int* p1, int p1Size, int* p2, int p2Size, int* p3, int p3Size, int* p4, int p4Size){ 
 int* p[4] = {p1, p2, p3, p4};
    int dis[6] = {0};
    int index = 0;
    for(int i = 0; i < 4; i++) {
        for(int j = i + 1; j < 4; j++) {
            dis[index++] = (p[i][0] - p[j][0]) * (p[i][0] - p[j][0]) + (p[i][1] - p[j][1]) * (p[i][1] - p[j][1]);
        }
    }
    int max = 0;
    int min = 2147483647;
    int count = 0;
    for(int i = 0; i < 6; i++) {
        if(dis[i] > max) max = dis[i];
        if(dis[i] < min) min = dis[i];
    }
    for(int i = 0; i < 6; i++) {
        if(dis[i] == max) count++;
    }
    if(count == 2 && dis[5] == dis[4]) return true;
    return false;
}