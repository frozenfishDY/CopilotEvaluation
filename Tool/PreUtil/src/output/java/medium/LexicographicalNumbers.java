/**https://leetcode.com/problems/lexicographical-numbers/ */
//Given an integer n, return all the numbers in the range [1, n] sorted in lexicographical order.
//You must write an algorithm that runs in O(n) time and uses O(1) extra space. 


class LexicographicalNumbers {
    public List<Integer> lexicalOrder(int n) {
        List<Integer> res = new ArrayList<>();
        int cur = 1;
        for(int i = 1; i <= n; i++){
            res.add(cur);
            if(cur * 10 <= n){
                cur *= 10;
            }else if(cur % 10 != 9 && cur + 1 <= n){
                cur++;
            }else{
                while((cur / 10) % 10 == 9){
                    cur /= 10;
                }
                cur = cur / 10 + 1;
            }
        }
        return res;
        
    }
}

    