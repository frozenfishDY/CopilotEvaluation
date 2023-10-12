/**https://leetcode.com/problems/x-of-a-kind-in-a-deck-of-cards/ */
//You are given an integer array deck where deck[i] represents the number written on the ith card.
//Partition the cards into one or more groups such that:
//	Each group has exactly x cards where x > 1, and
//	All the cards in one group have the same integer written on them.
//Return true if such partition is possible, or false otherwise.
// 
//Example 1:
//Input: deck = [1,2,3,4,4,3,2,1]
//Output: true
//Explanation: Possible partition [1,1],[2,2],[3,3],[4,4].
//Example 2:
//Input: deck = [1,1,1,2,2,2,3,3]
//Output: false
//Explanation: No possible partition.
// 
//Constraints:
//	1 <= deck.length <= 104
//	0 <= deck[i] < 104
bool hasGroupsSizeX(int* deck, int deckSize){
int count[10000] = {0};
    int min = deckSize;
    for(int i = 0; i < deckSize; i++){
        count[deck[i]]++;
    }
    for(int i = 0; i < 10000; i++){
        if(count[i] > 0 && count[i] < min){
            min = count[i];
        }
    }
    for(int i = 2; i <= min; i++){
        int j = 0;
        for(; j < 10000; j++){
            if(count[j] % i != 0){
                break;
            }
        }
        if(j == 10000){
            return true;
        }
    }
    return false;
}