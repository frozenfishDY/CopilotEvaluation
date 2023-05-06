/**https://leetcode.com/problems/number-of-good-ways-to-split-a-string/ */
//You are given a string s.
//A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.
//Return the number of good splits you can make in s.


class NumberOfGoodWaysToSplitAString {
    public int numSplits(String s) {
        int[] left = new int[26];
        int[] right = new int[26];
        int leftCount = 0;
        int rightCount = 0;
        for(char c : s.toCharArray()){
            if(right[c - 'a'] == 0){
                rightCount++;
            }
            right[c - 'a']++;
        }
        int count = 0;
        for(char c : s.toCharArray()){
            if(left[c - 'a'] == 0){
                leftCount++;
            }
            left[c - 'a']++;
            right[c - 'a']--;
            if(right[c - 'a'] == 0){
                rightCount--;
            }
            if(leftCount == rightCount){
                count++;
            }
        }
        return count;
        
    }
}

    