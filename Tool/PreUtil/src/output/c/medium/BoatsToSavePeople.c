/**https://leetcode.com/problems/boats-to-save-people/ */
//You are given an array people where people[i] is the weight of the ith person, and an infinite number of boats where each boat can carry a maximum weight of limit. Each boat carries at most two people at the same time, provided the sum of the weight of those people is at most limit.
//Return the minimum number of boats to carry every given person.


int numRescueBoats(int* people, int peopleSize, int limit){
    int* hash = (int*)malloc(sizeof(int) * peopleSize);
    for(int i = 0; i < peopleSize; i++){
        hash[i] = 0;
    }
    int result = 0;
    for(int i = 0; i < peopleSize; i++){
        if(hash[i] == 0){
            int max = -1;
            int maxIndex = -1;
            for(int j = 0; j < peopleSize; j++){
                if(hash[j] == 0 && people[j] > max && people[j] <= limit - people[i]){
                    max = people[j];
                    maxIndex = j;
                }
            }
            if(maxIndex == -1){
                result++;
            }else{
                hash[maxIndex] = 1;
                hash[i] = 1;
            }
        }
    }
    return result;

}

    