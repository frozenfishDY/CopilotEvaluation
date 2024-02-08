/**https://leetcode.com/problems/minimum-number-of-days-to-make-m-bouquets/ */
//You are given an integer array bloomDay, an integer m and an integer k.
//You want to make m bouquets. To make a bouquet, you need to use k adjacent flowers from the garden.
//The garden consists of n flowers, the ith flower will bloom in the bloomDay[i] and then can be used in exactly one bouquet.
//Return the minimum number of days you need to wait to be able to make m bouquets from the garden. If it is impossible to make m bouquets return -1.


class MinimumNumberOfDaysToMakeMBouquets {
    public int minDays(int[] bloomDay, int m, int k) {
        if(m * k > bloomDay.length){
            return -1;
        }
        int low = 1;
        int high = 1000000000;
        while(low < high){
            int mid = low + (high - low) / 2;
            if(canMake(bloomDay, m, k, mid)){
                high = mid;
            }
            else{
                low = mid + 1;
            }
        }
        return low;
        
    }
}

    