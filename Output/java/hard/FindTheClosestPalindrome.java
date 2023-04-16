/**https://leetcode.com/problems/find-the-closest-palindrome/ */
//Given a string n representing an integer, return the closest integer (not including itself), which is a palindrome. If there is a tie, return the smaller one.
//The closest is defined as the absolute difference minimized between two integers.


class FindTheClosestPalindrome {
    public String nearestPalindromic(String n) {
        int len = n.length();
        long num = Long.parseLong(n);
        long minDiff = Long.MAX_VALUE;
        long minNum = 0;
        long left = Long.parseLong(n.substring(0, (len + 1) / 2));
        for (long i = -1; i <= 1; i++) {
            long cur = left + i;
            String curStr = Long.toString(cur);
            String curRev = new StringBuilder(curStr).reverse().toString();
            String curPal = curStr + curRev.substring(curRev.length() - len % 2);
            long curPalNum = Long.parseLong(curPal);
            if (curPalNum == num) {
                continue;
            }
            long diff = Math.abs(curPalNum - num);
            if (diff < minDiff) {
                minDiff = diff;
                minNum = curPalNum;
            } else if (diff == minDiff) {
                minNum = Math.min(minNum, curPalNum);
            }
        }
        return Long.toString(minNum);
        
    }
}
     
    