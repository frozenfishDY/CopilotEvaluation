/**https://leetcode.com/problems/orderly-queue/ */
//You are given a string s and an integer k. You can choose one of the first k letters of s and append it at the end of the string..
//Return the lexicographically smallest string you could have after applying the mentioned step any number of moves.


class OrderlyQueue {
    public String orderlyQueue(String s, int k) {
        if (k == 1) {
            String res = s;
            for (int i = 0; i < s.length(); i++) {
                String temp = s.substring(i) + s.substring(0, i);
                if (temp.compareTo(res) < 0) {
                    res = temp;
                }
            }
            return res;
        } else {
            char[] arr = s.toCharArray();
            Arrays.sort(arr);
            return new String(arr);
        }
        
    }
}
     
    