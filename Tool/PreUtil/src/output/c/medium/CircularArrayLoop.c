/**https://leetcode.com/problems/circular-array-loop/ */
//You are playing a game involving a circular array of non-zero integers nums. Each nums[i] denotes the number of indices forward/backward you must move if you are located at index i:
//If nums[i] is positive, move nums[i] steps forward, and
//If nums[i] is negative, move nums[i] steps backward.
//Since the array is circular, you may assume that moving forward from the last element puts you on the first element, and moving backwards from the first element puts you on the last element.
//A cycle in the array consists of a sequence of indices seq of length k where:
//Following the movement rules above results in the repeating index sequence seq[0] -> seq[1] -> ... -> seq[k - 1] -> seq[0] -> ...
//Every nums[seq[j]] is either all positive or all negative.
//k > 1
//Return true if there is a cycle in nums, or false otherwise.


bool circularArrayLoop(int* nums, int numsSize){
    int* visited = (int*)malloc(sizeof(int) * numsSize);
    for(int i = 0; i < numsSize; i++){
        visited[i] = 0;
    }
    for(int i = 0; i < numsSize; i++){
        if(visited[i] == 0){
            int* path = (int*)malloc(sizeof(int) * numsSize);
            int pathSize = 0;
            int num = nums[i];
            int index = i;
            while(visited[index] == 0){
                visited[index] = 1;
                path[pathSize++] = index;
                index = (index + num) % numsSize;
                if(index < 0){
                    index += numsSize;
                }
                num = nums[index];
                if(num == 0){
                    break;
                }
                if(num > 0 && nums[i] < 0){
                    break;
                }
                if(num < 0 && nums[i] > 0){
                    break;
                }
            }
            if(pathSize > 1 && index == path[0]){
                return true;
            }
        }
    }
    return false;

}

    