/**https://leetcode.com/problems/minimum-consecutive-cards-to-pick-up/ */
//ou are given an integer array cards where cards[i] represents the value of the ith card. A pair of cards are matching if the cards have the same value.
//Return the minimum number of consecutive cards you have to pick up to have a pair of matching cards among the picked cards. If it is impossible to have matching cards, return -1.


int minimumCardPickup(int* cards, int cardsSize){
    int i, j, k, count = 0, min = 0;
    for(i = 0; i < cardsSize; i++){
        for(j = i+1; j < cardsSize; j++){
            if(cards[i] == cards[j]){
                count = j - i;
                if(min == 0){
                    min = count;
                }
                else if(count < min){
                    min = count;
                }
            }
        }
    }
    if(min == 0){
        return -1;
    }
    return min;

}

    