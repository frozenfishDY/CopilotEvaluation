/**https://leetcode.com/problems/minimum-time-to-remove-all-cars-containing-illegal-goods/ */
//You are given a 0-indexed binary string s which represents a sequence of train cars. s[i] = '0' denotes that the ith car does not contain illegal goods and s[i] = '1' denotes that the ith car does contain illegal goods.
//As the train conductor, you would like to get rid of all the cars containing illegal goods. You can do any of the following three operations any number of times:
//Remove a train car from the left end (i.e., remove s[0]) which takes 1 unit of time.
//Remove a train car from the right end (i.e., remove s[s.length - 1]) which takes 1 unit of time.
//Remove a train car from anywhere in the sequence which takes 2 units of time.
//Return the minimum time to remove all the cars containing illegal goods.
//Note that an empty sequence of cars is considered to have no cars containing illegal goods.


class MinimumTimeToRemoveAllCarsContainingIllegalGoods {
    public int minimumTime(String s) {
        int n = s.length();
        int left = 0;
        int right = n - 1;
        int res = 0;
        while (left <= right) {
            if (s.charAt(left) == '1' && s.charAt(right) == '1') {
                res += 2;
                left++;
                right--;
            } else if (s.charAt(left) == '1') {
                res++;
                left++;
            } else if (s.charAt(right) == '1') {
                res++;
                right--;
            } else {
                left++;
                right--;
            }
        }
        return res;
        
    }
}
     
    