/**https://leetcode.com/problems/friends-of-appropriate-ages/ */
//There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.
//A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:
//age[y] <= 0.5 * age[x] + 7
//age[y] > age[x]
//age[y] > 100 && age[x] < 100
//Otherwise, x will send a friend request to y.
//Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.
//Return the total number of friend requests made.


int numFriendRequests(int* ages, int agesSize){
    int* hash = (int*)malloc(sizeof(int) * 121);
    for(int i = 0; i < agesSize; i++){
        hash[ages[i]]++;
    }
    int count = 0;
    for(int i = 0; i < agesSize; i++){
        for(int j = 1; j <= 120; j++){
            if(hash[j] == 0){
                continue;
            }
            if(j <= 0.5 * ages[i] + 7){
                continue;
            }
            if(j > ages[i]){
                continue;
            }
            if(j > 100 && ages[i] < 100){
                continue;
            }
            count += hash[j];
            if(j == ages[i]){
                count--;
            }
        }
    }
    return count;

}

    