/**https://leetcode.com/problems/successful-pairs-of-spells-and-potions/ */
//You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
//You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
//Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.


/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
int* successfulPairs(int* spells, int spellsSize, int* potions, int potionsSize, long long success, int* returnSize){
    int i, j, k, count = 0, temp = 0;
    int* pairs = (int*)malloc(sizeof(int) * spellsSize);
    for(i = 0; i < spellsSize; i++){
        count = 0;
        for(j = 0; j < potionsSize; j++){
            if((long long)spells[i] * potions[j] >= success){
                count++;
            }
        }
        pairs[i] = count;
    }
    *returnSize = spellsSize;
    return pairs;


}

    