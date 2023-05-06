/**https://leetcode.com/problems/find-longest-awesome-substring/ */
//You are given a string s. An awesome substring is a non-empty substring of s such that we can make any number of swaps in order to make it a palindrome.
//Return the length of the maximum length awesome substring of s.


class FindLongestAwesomeSubstring {
    public int longestAwesome(String s) {
        int[] seen = new int[1024];
        Arrays.fill(seen, -1);
        int res = 0;
        int mask = 0;
        seen[0] = 0;
        for(int i = 0; i < s.length(); i++){
            int c = s.charAt(i) - '0';
            mask ^= 1 << c;
            if(seen[mask] >= 0){
                res = Math.max(res, i + 1 - seen[mask]);
            }else{
                seen[mask] = i + 1;
            }
            for(int j = 0; j < 10; j++){
                int newMask = mask ^ (1 << j);
                if(seen[newMask] >= 0){
                    res = Math.max(res, i + 1 - seen[newMask]);
                }
            }
        }
        return res;
        
    }
}
     
    