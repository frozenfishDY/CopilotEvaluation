/**https://leetcode.com/problems/make-number-of-distinct-characters-equal/ */
//You are given two 0-indexed strings word1 and word2.
//A move consists of choosing two indices i and j such that 0 <= i < word1.length and 0 <= j < word2.length and swapping word1[i] with word2[j].
//Return true if it is possible to get the number of distinct characters in word1 and word2 to be equal with exactly one move. Return false otherwise.


class MakeNumberOfDistinctCharactersEqual {
    public boolean isItPossible(String word1, String word2) {
        int[] count1 = new int[26];
        int[] count2 = new int[26];
        for(char c : word1.toCharArray()){
            count1[c - 'a']++;
        }
        for(char c : word2.toCharArray()){
            count2[c - 'a']++;
        }
        int diff = 0;
        for(int i = 0; i < 26; i++){
            if(count1[i] > 0 && count2[i] > 0){
                diff++;
            }
        }
        int sum1 = 0;
        int sum2 = 0;
        for(int i = 0; i < 26; i++){
            sum1 += count1[i];
            sum2 += count2[i];
        }
        if(sum1 == sum2){
            return diff < 26;
        }
        if(sum1 > sum2){
            return (sum1 - sum2) % 2 == 0 && diff < 25;
        }
        return (sum2 - sum1) % 2 == 0 && diff < 25;
        
        
        
    }
}

    