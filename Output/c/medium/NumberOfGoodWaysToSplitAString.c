/**https://leetcode.com/problems/number-of-good-ways-to-split-a-string/ */
//You are given a string s.
//A split is called good if you can split s into two non-empty strings sleft and sright where their concatenation is equal to s (i.e., sleft + sright = s) and the number of distinct letters in sleft and sright is the same.
//Return the number of good splits you can make in s.


int numSplits(char * s){
    int count = 0;
    int left[26] = {0};
    int right[26] = {0};
    int leftCount = 0;
    int rightCount = 0;
    int len = strlen(s);
    for(int i = 0; i < len; i++){
        if(right[s[i] - 'a'] == 0){
            rightCount++;
        }
        right[s[i] - 'a']++;
    }
    for(int i = 0; i < len; i++){
        if(left[s[i] - 'a'] == 0){
            leftCount++;
        }
        left[s[i] - 'a']++;
        right[s[i] - 'a']--;
        if(right[s[i] - 'a'] == 0){
            rightCount--;
        }
        if(leftCount == rightCount){
            count++;
        }
    }
    return count;

}

    