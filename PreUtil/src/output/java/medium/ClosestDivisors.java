/**https://leetcode.com/problems/closest-divisors/ */
//Given an integer num, find the closest two integers in absolute difference whose product equals num + 1 or num + 2.
//Return the two integers in any order.


class ClosestDivisors {
    public int[] closestDivisors(int num) {
        int[] res = new int[2];
        int min = Integer.MAX_VALUE;
        for(int i = 1; i * i <= num + 2; i++){
            if((num + 1) % i == 0){
                int j = (num + 1) / i;
                if(Math.abs(i - j) < min){
                    min = Math.abs(i - j);
                    res[0] = i;
                    res[1] = j;
                }
            }
            if((num + 2) % i == 0){
                int j = (num + 2) / i;
                if(Math.abs(i - j) < min){
                    min = Math.abs(i - j);
                    res[0] = i;
                    res[1] = j;
                }
            }
        }
        return res;
        
    }
}

    