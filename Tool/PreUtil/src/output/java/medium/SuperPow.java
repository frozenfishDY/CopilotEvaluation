/**https://leetcode.com/problems/super-pow/ */
//Your task is to calculate ab mod 1337 where a is a positive integer and b is an extremely large positive integer given in the form of an array.


class SuperPow {
    public int superPow(int a, int[] b) {
        int res = 1;
        for(int i = 0; i < b.length; i++){
            res = pow(res, 10) * pow(a, b[i]) % 1337;
        }
        return res;
        
        
    }
}

    