/**https://leetcode.com/problems/card-flipping-game/ */
//You are given two 0-indexed integer arrays fronts and backs of length n, where the ith card has the positive integer fronts[i] printed on the front and backs[i] printed on the back. Initially, each card is placed on a table such that the front number is facing up and the other is facing down. You may flip over any number of cards (possibly zero).
//After flipping the cards, an integer is considered good if it is facing down on some card and not facing up on any card.
//Return the minimum possible good integer after flipping the cards. If there are no good integers, return 0.


int flipgame(int* fronts, int frontsSize, int* backs, int backsSize){
    int* hash = (int*)malloc(sizeof(int) * 2001);
    for(int i = 0; i < frontsSize; i++){
        if(fronts[i] == backs[i]){
            hash[fronts[i]] = 1;
        }
    }
    for(int i = 0; i < frontsSize; i++){
        if(hash[fronts[i]] == 0){
            return fronts[i];
        }
        if(hash[backs[i]] == 0){
            return backs[i];
        }
    }
    return 0;

}

    