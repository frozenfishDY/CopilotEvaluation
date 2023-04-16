/**https://leetcode.com/problems/koko-eating-bananas/ */
//Koko loves to eat bananas. There are n piles of bananas, the ith pile has piles[i] bananas. The guards have gone and will come back in h hours.
//Koko can decide her bananas-per-hour eating speed of k. Each hour, she chooses some pile of bananas and eats k bananas from that pile. If the pile has less than k bananas, she eats all of them instead and will not eat any more bananas during this hour.
//Koko likes to eat slowly but still wants to finish eating all the bananas before the guards return.
//Return the minimum integer k such that she can eat all the bananas within h hours.


int minEatingSpeed(int* piles, int pilesSize, int h){
    int left = 1;
    int right = 1000000000;
    while(left < right){
        int mid = left + (right - left) / 2;
        int count = 0;
        for(int i = 0; i < pilesSize; i++){
            count += piles[i] / mid;
            if(piles[i] % mid != 0){
                count++;
            }
        }
        if(count > h){
            left = mid + 1;
        }else{
            right = mid;
        }
    }
    return left;

}

    