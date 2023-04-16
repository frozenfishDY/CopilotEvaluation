/**https://leetcode.com/problems/beautiful-array/ */
//An array nums of length n is beautiful if:
//nums is a permutation of the integers in the range [1, n].
//For every 0 <= i < j < n, there is no index k with i < k < j where 2 * nums[k] == nums[i] + nums[j].
//Given the integer n, return any beautiful array nums of length n. There will be at least one valid answer for the given n.


class BeautifulArray {
    public int[] beautifulArray(int n) {
        List<Integer> res = new ArrayList<>();
        res.add(1);
        while(res.size() < n){
            List<Integer> tmp = new ArrayList<>();
            for(int i : res){
                if(i * 2 - 1 <= n){
                    tmp.add(i * 2 - 1);
                }
            }
            for(int i : res){
                if(i * 2 <= n){
                    tmp.add(i * 2);
                }
            }
            res = tmp;
        }
        return res.stream().mapToInt(i -> i).toArray();
        
        
    }
}

    