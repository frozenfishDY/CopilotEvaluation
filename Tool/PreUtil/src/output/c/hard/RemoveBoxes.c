/**https://leetcode.com/problems/remove-boxes/ */
//You are given several boxes with different colors represented by different positive numbers.
//You may experience several rounds to remove boxes until there is no box left. Each time you can choose some continuous boxes with the same color (i.e., composed of k boxes, k >= 1), remove them and get k * k points.
//Return the maximum points you can get.


int removeBoxes(int* boxes, int boxesSize){
    int* queue = (int*)malloc(sizeof(int) * boxesSize);
    int head = 0, tail = 0;
    for(int i = 0; i < boxesSize; i++){
        while(head < tail && boxes[queue[tail - 1]] < boxes[i]) tail--;
        queue[tail++] = i;
        if(i - queue[head] >= k) head++;
        if(i >= k - 1) result[i - k + 1] = boxes[queue[head]];
    }
    return boxesSize - k + 1;

}

    