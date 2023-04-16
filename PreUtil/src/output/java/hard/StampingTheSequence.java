/**https://leetcode.com/problems/stamping-the-sequence/ */
//You are given two strings stamp and target. Initially, there is a string s of length target.length with all s[i] == '?'.
//In one turn, you can place stamp over s and replace every letter in the s with the corresponding letter from stamp.
//For example, if stamp = "abc" and target = "abcba", then s is "?????" initially. In one turn you can:
//place stamp at index 0 of s to obtain "abc??",
//place stamp at index 1 of s to obtain "?abc?", or
//place stamp at index 2 of s to obtain "??abc".
//Note that stamp must be fully contained in the boundaries of s in order to stamp (i.e., you cannot place stamp at index 3 of s).
//We want to convert s to target using at most 10 * target.length turns.
//Return an array of the index of the left-most letter being stamped at each turn. If we cannot obtain target from s within 10 * target.length turns, return an empty array.


class StampingTheSequence {
    public int[] movesToStamp(String stamp, String target) {
        int n = target.length();
        int m = stamp.length();
        char[] t = target.toCharArray();
        char[] s = stamp.toCharArray();
        boolean[] done = new boolean[n];
        List<Integer> res = new ArrayList<>();
        int count = 0;
        while (count < n) {
            boolean found = false;
            for (int i = 0; i <= n - m; i++) {
                if (!done[i] && canReplace(t, s, i)) {
                    found = true;
                    done[i] = true;
                    count += replace(t, i, m);
                    res.add(i);
                }
            }
            if (!found) {
                return new int[0];
            }
        }
        Collections.reverse(res);
        int[] ans = new int[res.size()];
        for (int i = 0; i < res.size(); i++) {
            ans[i] = res.get(i);
        }
        return ans;
        
        
    }
}
     
    