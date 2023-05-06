/**https://leetcode.com/problems/maximum-candies-you-can-get-from-boxes/ */
//You have n boxes labeled from 0 to n - 1. You are given four arrays: status, candies, keys, and containedBoxes where:
//status[i] is 1 if the ith box is open and 0 if the ith box is closed,
//candies[i] is the number of candies in the ith box,
//keys[i] is a list of the labels of the boxes you can open after opening the ith box.
//containedBoxes[i] is a list of the boxes you found inside the ith box.
//You are given an integer array initialBoxes that contains the labels of the boxes you initially have. You can take all the candies in any open box and you can use the keys in it to open new boxes and you also can use the boxes you find in it.
//Return the maximum number of candies you can get following the rules above.


int maxCandies(int* status, int statusSize, int* candies, int candiesSize, int** keys, int keysSize, int* keysColSize, int** containedBoxes, int containedBoxesSize, int* containedBoxesColSize, int* initialBoxes, int initialBoxesSize){
    int i,j;
    int* visited = (int*)malloc(sizeof(int)*statusSize);
    for(i=0;i<statusSize;i++){
        visited[i] = 0;
    }
    int* queue = (int*)malloc(sizeof(int)*statusSize);
    int front = 0;
    int rear = 0;
    for(i=0;i<initialBoxesSize;i++){
        queue[rear] = initialBoxes[i];
        rear++;
    }
    int count = 0;
    while(front != rear){
        int box = queue[front];
        front++;
        if(visited[box] == 1){
            continue;
        }
        visited[box] = 1;
        if(status[box] == 1){
            count += candies[box];
            for(i=0;i<keysColSize[box];i++){
                status[keys[box][i]] = 1;
            }
            for(i=0;i<containedBoxesColSize[box];i++){
                queue[rear] = containedBoxes[box][i];
                rear++;
            }
        }
        else{
            queue[rear] = box;
            rear++;
        }
    }
    return count;

}

    