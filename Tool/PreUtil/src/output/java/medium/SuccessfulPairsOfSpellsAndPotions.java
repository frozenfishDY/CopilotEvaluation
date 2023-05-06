/**https://leetcode.com/problems/successful-pairs-of-spells-and-potions/ */
//You are given two positive integer arrays spells and potions, of length n and m respectively, where spells[i] represents the strength of the ith spell and potions[j] represents the strength of the jth potion.
//You are also given an integer success. A spell and potion pair is considered successful if the product of their strengths is at least success.
//Return an integer array pairs of length n where pairs[i] is the number of potions that will form a successful pair with the ith spell.


class SuccessfulPairsOfSpellsAndPotions {
    public int[] successfulPairs(int[] spells, int[] potions, long success) {
        int[] count = new int[100000];
        for (int spell : spells) {
            count[spell]++;
        }
        int[] result = new int[spells.length];
        for (int i = 0; i < potions.length; i++) {
            for (int j = 1; j * j <= potions[i]; j++) {
                if (potions[i] % j == 0) {
                    if (j * j == potions[i]) {
                        result[i] += count[j];
                    } else {
                        result[i] += count[j] + count[potions[i] / j];
                    }
                }
            }
        }
        return result;
        
    }
}
     
    