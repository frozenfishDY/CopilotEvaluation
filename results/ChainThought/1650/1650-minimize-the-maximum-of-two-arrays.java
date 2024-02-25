/**https://leetcode.com/problems/minimize-the-maximum-of-two-arrays/ */
//We have two arrays arr1 and arr2 which are initially empty. You need to add positive integers to them such that they satisfy all the following conditions:
//arr1 contains uniqueCnt1 distinct positive integers, each of which is not divisible by divisor1.
//arr2 contains uniqueCnt2 distinct positive integers, each of which is not divisible by divisor2.
//No integer is present in both arr1 and arr2.
//Given divisor1, divisor2, uniqueCnt1, and uniqueCnt2, return the minimum possible maximum integer that can be present in either array.


class MinimizeTheMaximumOfTwoArrays {
    public int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        int l = 1;
        int r = 1000000000;
        while(l < r){
            int mid = l + (r - l) / 2;
            if(check(mid, divisor1, divisor2, uniqueCnt1, uniqueCnt2)){
                r = mid;
            }else{
                l = mid + 1;
            }
        }
        return l;
        
        
    }
}

    