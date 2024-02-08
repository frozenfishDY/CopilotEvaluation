/**https://leetcode.com/problems/count-pairs-of-similar-strings/ */
//You are given a 0-indexed string array words.
//Two strings are similar if they consist of the same characters.
//For example, "abca" and "cba" are similar since both consist of characters 'a', 'b', and 'c'.
//However, "abacba" and "bcfd" are not similar since they do not consist of the same characters.
//Return the number of pairs (i, j) such that 0 <= i < j <= word.length - 1 and the two strings words[i] and words[j] are similar.


class CountPairsOfSimilarStrings {
    public int similarPairs(String[] words) {
        int count = 0;
        for(int i = 0; i < words.length; i++){
            for(int j = i + 1; j < words.length; j++){
                if(isSimilar(words[i], words[j])){
                    count++;
                }
            }
        }
        return count; 
    }
}

    