/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.


int maxPoints(int** points, int pointsSize, int* pointsColSize){
    if(pointsSize < 3) return pointsSize;
    int max = 0;
    for(int i = 0; i < pointsSize; i++){
        int same = 1;
        int vertical = 0;
        int curMax = 0;
        for(int j = i + 1; j < pointsSize; j++){
            if(points[i][0] == points[j][0] && points[i][1] == points[j][1]){
                same++;
            }else if(points[i][0] == points[j][0]){
                vertical++;
            }else{
                int a = points[i][1] - points[j][1];
                int b = points[i][0] - points[j][0];
                int gcd = getGcd(a, b);
                a /= gcd;
                b /= gcd;
                if(map[a] == NULL){
                    map[a] = (int*)malloc(sizeof(int) * 10000);
                    memset(map[a], 0, sizeof(int) * 10000);
                }
                map[a][b]++;
                if(map[a][b] > curMax) curMax = map[a][b];
            }
        }
        if(vertical > curMax) curMax = vertical;
        curMax += same;
        if(curMax > max) max = curMax;
    }
    return max;
    


}

    