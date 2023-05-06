/**https://leetcode.com/problems/capacity-to-ship-packages-within-d-days/ */
//A conveyor belt has packages that must be shipped from one port to another within days days.
//The ith package on the conveyor belt has a weight of weights[i]. Each day, we load the ship with packages on the conveyor belt (in the order given by weights). We may not load more weight than the maximum weight capacity of the ship.
//Return the least weight capacity of the ship that will result in all the packages on the conveyor belt being shipped within days days.


class CapacityToShipPackagesWithinDDays {
    public int shipWithinDays(int[] weights, int days) {
        int n = weights.length;
        int l = 0;
        int r = 0;
        for(int i = 0; i < n; i++){
            l = Math.max(l, weights[i]);
            r += weights[i];
        }
        while(l < r){
            int mid = l + (r - l) / 2;
            int cur = 0;
            int cnt = 1;
            for(int i = 0; i < n; i++){
                if(cur + weights[i] > mid){
                    cnt++;
                    cur = 0;
                }
                cur += weights[i];
            }
            if(cnt > days){
                l = mid + 1;
            }else{
                r = mid;
            }
        }
        return l;
        
    }
}

    