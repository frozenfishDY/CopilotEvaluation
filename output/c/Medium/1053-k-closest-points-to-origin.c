/**https://leetcode.com/problems/k-closest-points-to-origin/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
//The distance between two points on the X-Y plane is the Euclidean distance (i.e., ��(x1 - x2)2 + (y1 - y2)2).
//You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int** kClosest(int** points, int pointsSize, int* pointsColSize, int k, int* returnSize, int** returnColumnSizes){
    int** result = (int**)malloc(sizeof(int*) * k);
    *returnSize = 0;
    *returnColumnSizes = (int*)malloc(sizeof(int) * k);
    for(int i = 0; i < k; i++){
        (*returnColumnSizes)[i] = 2;
    }
    int* distances = (int*)malloc(sizeof(int) * pointsSize);
    for(int i = 0; i < pointsSize; i++){
        distances[i] = points[i][0] * points[i][0] + points[i][1] * points[i][1];
    }
    for(int i = 0; i < pointsSize; i++){
        for(int j = i + 1; j < pointsSize; j++){
            if(distances[i] > distances[j]){
                int temp = distances[i];
                distances[i] = distances[j];
                distances[j] = temp;
                int* temp2 = points[i];
                points[i] = points[j];
                points[j] = temp2;
            }
        }
    }
    for(int i = 0; i < k; i++){
        result[i] = points[i];
        (*returnSize)++;
    }
    free(distances);
    return result;

}

    