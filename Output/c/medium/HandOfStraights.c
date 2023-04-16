/**https://leetcode.com/problems/hand-of-straights/ */
//Alice has some number of cards and she wants to rearrange the cards into groups so that each group is of size groupSize, and consists of groupSize consecutive cards.
//Given an integer array hand where hand[i] is the value written on the ith card and an integer groupSize, return true if she can rearrange the cards, or false otherwise.


bool isNStraightHand(int* hand, int handSize, int groupSize){
    if(handSize % groupSize != 0){
        return false;
    }
    int* hash = (int*)malloc(sizeof(int) * 10001);
    for(int i = 0; i < 10001; i++){
        hash[i] = 0;
    }
    for(int i = 0; i < handSize; i++){
        hash[hand[i]]++;
    }
    for(int i = 0; i < 10001; i++){
        if(hash[i] != 0){
            for(int j = 1; j < groupSize; j++){
                if(hash[i + j] < hash[i]){
                    return false;
                }
                hash[i + j] -= hash[i];
            }
        }
    }
    return true;

}

    