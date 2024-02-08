/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.


double minAreaFreeRect(int** points, int pointsSize, int* pointsColSize){
    double result = 0;
    for(int i = 0; i < pointsSize; i++){
        for(int j = i + 1; j < pointsSize; j++){
            for(int k = j + 1; k < pointsSize; k++){
                for(int l = k + 1; l < pointsSize; l++){
                    int x1 = points[i][0];
                    int y1 = points[i][1];
                    int x2 = points[j][0];
                    int y2 = points[j][1];
                    int x3 = points[k][0];
                    int y3 = points[k][1];
                    int x4 = points[l][0];
                    int y4 = points[l][1];
                    if((x1 - x2) * (x1 - x3) + (y1 - y2) * (y1 - y3) == 0){
                        double area = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) * sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2));
                        if(result == 0 || area < result){
                            result = area;
                        }
                    }
                    if((x1 - x2) * (x1 - x4) + (y1 - y2) * (y1 - y4) == 0){
                        double area = sqrt(pow(x1 - x2, 2) + pow(y1 - y2, 2)) * sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
                        if(result == 0 || area < result){
                            result = area;
                        }
                    }
                    if((x1 - x3) * (x1 - x4) + (y1 - y3) * (y1 - y4) == 0){
                        double area = sqrt(pow(x1 - x3, 2) + pow(y1 - y3, 2)) * sqrt(pow(x1 - x4, 2) + pow(y1 - y4, 2));
                        if(result == 0 || area < result){
                            result = area;
                        }
                    }
                    if((x2 - x3) * (x2 - x4) + (y2 - y3) * (y - y4) == 0){
                        double area = sqrt(pow(x2 - x3, 2) + pow(y2 - y3, 2)) * sqrt(pow(x2 - x4, 2) + pow(y2 - y4, 2));
                        if(result == 0 || area < result){
                            result = area;
                        }
                    } 
                    

}

    