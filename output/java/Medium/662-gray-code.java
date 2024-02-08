/**https://leetcode.com/problems/gray-code/ */
//An n-bit gray code sequence is a sequence of 2n integers where:
//Every integer is in the inclusive range [0, 2n - 1],
//The first integer is 0,
//An integer appears no more than once in the sequence,
//The binary representation of every pair of adjacent integers differs by exactly one bit, and
//The binary representation of the first and last integers differs by exactly one bit.
//Given an integer n, return any valid n-bit gray code sequence.


class GrayCode {
    public List<Integer> grayCode(int n) {
        List<Integer> res = new ArrayList<>();
        res.add(0);
        for(int i = 0; i < n; i++){
            int size = res.size();
            for(int j = size - 1; j >= 0; j--){
                res.add(res.get(j) | 1 << i);
            }
        }
        return res;
        
        
    }
}

    