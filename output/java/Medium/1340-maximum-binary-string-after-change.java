/**https://leetcode.com/problems/maximum-binary-string-after-change/ */
//You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:
//Operation 1: If the number contains the substring "00", you can replace it with "10".
//For example, "00010" -> "10010"
//Operation 2: If the number contains the substring "10", you can replace it with "01".
//For example, "00010" -> "00001"
//Return the maximum binary string you can obtain after any number of operations. Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.


class MaximumBinaryStringAfterChange {
    public String maximumBinaryString(String binary) {
        int n = binary.length();
        int[] pre = new int[n + 1];
        for(int i = 1; i <= n; i++){
            pre[i] = pre[i - 1] + (binary.charAt(i - 1) - '0');
        }
        int[] dp = new int[n + 1];
        int res = 0;
        int[] last = new int[2];
        Arrays.fill(last, -1);
        for(int i = 1; i <= n; i++){
            dp[i] = dp[i - 1];
            if(last[binary.charAt(i - 1) - '0'] != -1){
                dp[i] = Math.max(dp[i], dp[last[binary.charAt(i - 1) - '0']] + pre[i] - pre[last[binary.charAt(i - 1) - '0'] + 1]);
            }
            last[binary.charAt(i - 1) - '0'] = i - 1;
            res = Math.max(res, dp[i]);
        }
        StringBuilder sb = new StringBuilder();
        for(int i = 0; i < n - res; i++){
            sb.append('1');
        }
        for(int i = 0; i < res; i++){
            sb.append('0');
        }
        return sb.toString();
        
    }
}
     
    