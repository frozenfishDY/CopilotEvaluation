/**https://leetcode.com/problems/reordered-power-of-2/ */
//You are given an integer n. We reorder the digits in any order (including the original order) such that the leading digit is not zero.
//Return true if and only if we can do this so that the resulting number is a power of two.


class ReorderedPowerOf2 {
    public boolean reorderedPowerOf2(int n) {
        int[] count = count(n);
        for(int i = 0; i < 31; i++){
            if(Arrays.equals(count, count(1 << i))){
                return true;
            }
        }
        return false;
        
        
    }
}

    