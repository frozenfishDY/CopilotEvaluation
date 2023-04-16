/**https://leetcode.com/problems/count-vowel-strings-in-ranges/ */
//You are given a 0-indexed array of strings words and a 2D array of integers queries.
//Each query queries[i] = [li, ri] asks us to find the number of strings present in the range li to ri (both inclusive) of words that start and end with a vowel.
//Return an array ans of size queries.length, where ans[i] is the answer to the ith query.
//Note that the vowel letters are 'a', 'e', 'i', 'o', and 'u'.


class CountVowelStringsInRanges {
    public int[] vowelStrings(String[] words, int[][] queries) {
        int[] res = new int[queries.length];
        int[][] dp = new int[words.length + 1][5];
        for(int i = 1; i <= words.length; i++){
            for(int j = 0; j < 5; j++){
                dp[i][j] = dp[i - 1][j];
            }
            char c = words[i - 1].charAt(0);
            if(c == 'a'){
                dp[i][0]++;
            }else if(c == 'e'){
                dp[i][1]++;
            }else if(c == 'i'){
                dp[i][2]++;
            }else if(c == 'o'){
                dp[i][3]++;
            }else if(c == 'u'){
                dp[i][4]++;
            }
        }
        for(int i = 0; i < queries.length; i++){
            int[] q = queries[i];
            int[] start = dp[q[0]];
            int[] end = dp[q[1] + 1];
            res[i] = end[0] - start[0] + end[1] - start[1] + end[2] - start[2] + end[3] - start[3] + end[4] - start[4];
        }
        return res;
        
        
    }
}

    