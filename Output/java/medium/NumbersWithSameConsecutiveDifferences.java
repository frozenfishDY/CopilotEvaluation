/**https://leetcode.com/problems/numbers-with-same-consecutive-differences/ */
//Given two integers n and k, return an array of all the integers of length n where the difference between every two consecutive digits is k. You may return the answer in any order.
//Note that the integers should not have leading zeros. Integers as 02 and 043 are not allowed.


class NumbersWithSameConsecutiveDifferences {
    public int[] numsSameConsecDiff(int n, int k) {
        List<Integer> res = new ArrayList<>();
        for(int i = 1; i <= 9; i++){
            dfs(res, i, n, k);
        }
        if(n == 1){
            res.add(0);
        }
        return res.stream().mapToInt(i -> i).toArray();
        
        
    }
}

    