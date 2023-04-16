/**https://leetcode.com/problems/jump-game-iii/ */
//Given an array of non-negative integers arr, you are initially positioned at start index of the array. When you are at index i, you can jump to i + arr[i] or i - arr[i], check if you can reach to any index with value 0.
//Notice that you can not jump outside of the array at any time.


bool canReach(int* arr, int arrSize, int start){
    int* visited = (int*)malloc(sizeof(int) * arrSize);
    memset(visited, 0, sizeof(int) * arrSize);
    int* queue = (int*)malloc(sizeof(int) * arrSize);
    int left = 0;
    int right = 0;
    queue[right++] = start;
    while(left < right){
        int index = queue[left++];
        if(arr[index] == 0){
            return true;
        }
        if(index + arr[index] < arrSize && visited[index + arr[index]] == 0){
            queue[right++] = index + arr[index];
            visited[index + arr[index]] = 1;
        }
        if(index - arr[index] >= 0 && visited[index - arr[index]] == 0){
            queue[right++] = index - arr[index];
            visited[index - arr[index]] = 1;
        }
    }
    return false;

}

    