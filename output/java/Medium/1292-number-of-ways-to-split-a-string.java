/**https://leetcode.com/problems/number-of-ways-to-split-a-string/ */
//Given a binary string s, you can split s into 3 non-empty strings s1, s2, and s3 where s1 + s2 + s3 = s.
//Return the number of ways s can be split such that the number of ones is the same in s1, s2, and s3. Since the answer may be too large, return it modulo 109 + 7.


class NumberOfWaysToSplitAString {
    public int numWays(String s) {
        int mod = 1000000007;
        int count = 0;
        for(char c : s.toCharArray()){
            if(c == '1'){
                count++;
            }
        }
        if(count % 3 != 0){
            return 0;
        }
        if(count == 0){
            return (int)(((long)(s.length() - 1) * (long)(s.length() - 2) / 2) % mod);
        }
        int target = count / 3;
        int[] left = new int[s.length()];
        int[] right = new int[s.length()];
        int leftCount = 0;
        int rightCount = 0;
        for(int i = 0; i < s.length(); i++){
            if(s.charAt(i) == '1'){
                leftCount++;
            }
            left[i] = leftCount;
        }
        for(int i = s.length() - 1; i >= 0; i--){
            if(s.charAt(i) == '1'){
                rightCount++;
            }
            right[i] = rightCount;
        }
        int leftIndex = 0;
        int rightIndex = 0;
        for(int i = 0; i < s.length(); i++){
            if(left[i] == target){
                leftIndex = i;
                break;
            }
        }
        for(int i = s.length() - 1; i >= 0; i--){
            if(right[i] == target){
                rightIndex = i;
                break;
            }
        }
        int leftCount2 = 0;
        int rightCount2 = 0;
        for(int i = leftIndex + 1; i < s.length(); i++){
            if(s.charAt(i) == '1'){
                leftCount2++;
            }
            if(leftCount2 == target){
                leftIndex = i;
                break;
            }
        }
        for(int i = rightIndex - 1; i >= 0; i--){
            if(s.charAt(i) == '1'){
                rightCount2++;
            }
            if(rightCount2 == target){
                rightIndex = i;
                break;
            }
        }
        return (int)(((long)(leftIndex - leftCount + 1) * (long)(s.length() - rightIndex)) % mod);
        
    }
}
     
    