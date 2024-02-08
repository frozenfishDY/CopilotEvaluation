/**https://leetcode.com/problems/partition-string-into-substrings-with-values-at-most-k/ */
//You are given a string s consisting of digits from 1 to 9 and an integer k.
//A partition of a string s is called good if:
//Each digit of s is part of exactly one substring.
//The value of each substring is less than or equal to k.
//Return the minimum number of substrings in a good partition of s. If no good partition of s exists, return -1.
//Note that:
//The value of a string is its result when interpreted as an integer. For example, the value of "123" is 123 and the value of "1" is 1.
//A substring is a contiguous sequence of characters within a string.


class PartitionStringIntoSubstringsWithValuesAtMostK {
    public int minimumPartition(String s, int k) {
        int n = s.length();
        int[] cnt = new int[10];
        for(int i = 0; i < n; i++){
            cnt[s.charAt(i) - '0']++;
        }
        int res = 0;
        for(int i = 1; i <= 9; i++){
            if(cnt[i] > 0){
                res++;
                cnt[i]--;
                int j = i;
                while(j <= 9 && cnt[j] > 0){
                    cnt[j]--;
                    j++;
                }
                if(j > k){
                    return -1;
                }
            }
        }
        return res;
        
        
        
    }
}

    