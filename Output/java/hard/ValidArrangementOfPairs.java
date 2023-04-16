/**https://leetcode.com/problems/valid-arrangement-of-pairs/ */
//You are given a 0-indexed 2D integer array pairs where pairs[i] = [starti, endi]. An arrangement of pairs is valid if for every index i where 1 <= i < pairs.length, we have endi-1 == starti.
//Return any valid arrangement of pairs.
//Note: The inputs will be generated such that there exists a valid arrangement of pairs.


class ValidArrangementOfPairs {
    public int[][] validArrangement(int[][] pairs) {
        Arrays.sort(pairs, (a, b) -> a[0] - b[0]);
        int[][] res = new int[pairs.length][2];
        res[0] = pairs[0];
        for (int i = 1; i < pairs.length; i++) {
            if (pairs[i][0] == res[i - 1][1]) {
                res[i] = pairs[i];
            } else {
                res[i] = pairs[i - 1];
                res[i - 1] = pairs[i];
            }
        }
        return res;
        
    }
}
     
    