/**https://leetcode.com/problems/reveal-cards-in-increasing-order/ */
//You are given an integer array deck. There is a deck of cards where every card has a unique integer. The integer on the ith card is deck[i].
//You can order the deck in any order you want. Initially, all the cards start face down (unrevealed) in one deck.
//You will do the following steps repeatedly until all cards are revealed:
//Take the top card of the deck, reveal it, and take it out of the deck.
//If there are still cards in the deck then put the next top card of the deck at the bottom of the deck.
//If there are still unrevealed cards, go back to step 1. Otherwise, stop.
//Return an ordering of the deck that would reveal the cards in increasing order.
//Note that the first entry in the answer is considered to be the top of the deck.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* deckRevealedIncreasing(int* deck, int deckSize, int* returnSize){
    int* result = (int*)malloc(sizeof(int) * deckSize);
    *returnSize = deckSize;
    int* temp = (int*)malloc(sizeof(int) * deckSize);
    for(int i = 0; i < deckSize; i++){
        temp[i] = i;
    }
    qsort(temp, deckSize, sizeof(int), cmp);
    int* index = (int*)malloc(sizeof(int) * deckSize);
    for(int i = 0; i < deckSize; i++){
        index[i] = i;
    }
    int length = deckSize;
    int indexLength = deckSize;
    int indexIndex = 0;
    while(length > 0){
        result[index[indexIndex]] = deck[temp[deckSize - length]];
        indexIndex++;
        if(indexIndex == indexLength){
            indexIndex = 0;
        }
        index[indexIndex] = index[indexIndex + 1];
        indexIndex++;
        if(indexIndex == indexLength){
            indexIndex = 0;
        }
        indexLength--;
        length--;
    }
    free(temp);
    free(index);
    return result;

}

    