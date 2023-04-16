/**https://leetcode.com/problems/number-of-boomerangs/ */
//You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//Return the number of boomerangs.


int numberOfBoomerangs(int** points, int pointsSize, int* pointsColSize){
    int result = 0;
    for(int i = 0; i < pointsSize; i++){
        int* distance = (int*)malloc(sizeof(int) * pointsSize);
        for(int j = 0; j < pointsSize; j++){
            distance[j] = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
        }
        for(int j = 0; j < pointsSize; j++){
            int count = 0;
            for(int k = 0; k < pointsSize; k++){
                if(distance[j] == distance[k]){
                    count++;
                }
            }
            result += count * (count - 1);
        }
    }
    return result;

}

    