/**https://leetcode.com/problems/simplified-fractions/ */
//Given an integer n, return a list of all simplified fractions between 0 and 1 (exclusive) such that the denominator is less-than-or-equal-to n. You can return the answer in any order.


class SimplifiedFractions {
    public List<String> simplifiedFractions(int n) {
        List<String> list = new ArrayList<>();
        for(int i = 1; i < n; i++){
            for(int j = i + 1; j <= n; j++){
                if(gcd(i, j) == 1){
                    list.add(i + "/" + j);
                }
            }
        }
        return list;
        
        
    }
}

    