/**https://leetcode.com/problems/combinations/ */
//Given two integers n and k, return all possible combinations of k numbers chosen from the range [1, n].
//You may return the answer in any order.


class Combinations {
    public List<List<Integer>> combine(int n, int k) {
        List<List<Integer>> res = new ArrayList<>();
        if(n == 0 || k == 0){
            return res;
        }
        helper(n, k, 1, new ArrayList<>(), res);
        return res;
        
        
        
    }
}

    