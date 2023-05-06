/**https://leetcode.com/problems/minimum-possible-integer-after-at-most-k-adjacent-swaps-on-digits/ */
//You are given a string num representing the digits of a very large integer and an integer k. You are allowed to swap any two adjacent digits of the integer at most k times.
//Return the minimum integer you can obtain also as a string.


class MinimumPossibleIntegerAfterAtMostKAdjacentSwapsOnDigits {
    public String minInteger(String num, int k) {
        int n = num.length();
        int[] pos = new int[10];
        for (int i = 0; i < n; i++) {
            pos[num.charAt(i) - '0'] = i;
        }
        char[] res = new char[n];
        for (int i = 0; i < n; i++) {
            for (int d = 0; d < 10; d++) {
                if (pos[d] < i) {
                    continue;
                }
                int diff = pos[d] - i;
                if (diff <= k) {
                    res[i] = (char) (d + '0');
                    k -= diff;
                    pos[d] = -1;
                    break;
                }
            }
        }
        return new String(res);
        
    }
}
     
    