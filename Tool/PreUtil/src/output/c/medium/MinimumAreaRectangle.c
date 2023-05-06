/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.


int minAreaRect(int** points, int pointsSize, int* pointsColSize){
    int result = 0;
    for(int i = 0; i < pointsSize; i++){
        for(int j = i + 1; j < pointsSize; j++){
            if(points[i][0] == points[j][0] || points[i][1] == points[j][1]){
                continue;
            }
            int x1 = points[i][0];
            int y1 = points[i][1];
            int x2 = points[j][0];
            int y2 = points[j][1];
            int x3 = x1;
            int y3 = y2;
            int x4 = x2;
            int y4 = y1;
            int found = 0;
            for(int k = 0; k < pointsSize; k++){
                if(points[k][0] == x3 && points[k][1] == y3){
                    found++;
                }
                if(points[k][0] == x4 && points[k][1] == y4){
                    found++;
                }
            }
            if(found == 2){
                int area = abs(x1 - x2) * abs(y1 - y2);
                if(result == 0 || area < result){
                    result = area;
                }
            }
        }
    }
    return result;

}

    