/**https://leetcode.com/problems/verbal-arithmetic-puzzle/ */
//Given an equation, represented by words on the left side and the result on the right side.
//You need to check if the equation is solvable under the following rules:
//Each character is decoded as one digit (0 - 9).
//No two characters can map to the same digit.
//Each words[i] and result are decoded as one number without leading zeros.
//Sum of numbers on the left side (words) will equal to the number on the right side (result).
//Return true if the equation is solvable, otherwise return false.


class VerbalArithmeticPuzzle {
    public boolean isSolvable(String[] words, String result) {
        int[] count = new int[26];
        for (String word : words) {
            for (char c : word.toCharArray()) {
                count[c - 'A']++;
            }
        }
        for (char c : result.toCharArray()) {
            count[c - 'A']++;
        }
        int maxLen = 0;
        for (int i = 0; i < 26; i++) {
            if (count[i] > 0) {
                maxLen++;
            }
        }
        if (maxLen > 10) {
            return false;
        }
        int[] map = new int[26];
        Arrays.fill(map, -1);
        return dfs(words, result, 0, 0, 0, map);
        
    }
}
     
    