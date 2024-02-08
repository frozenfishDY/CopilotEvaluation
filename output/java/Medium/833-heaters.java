/**https://leetcode.com/problems/heaters/ */
//Winter is coming! During the contest, your first job is to design a standard heater with a fixed warm radius to warm all the houses.
//Every house can be warmed, as long as the house is within the heater's warm radius range. 
//Given the positions of houses and heaters on a horizontal line, return the minimum radius standard of heaters so that those heaters could cover all houses.
//Notice that all the heaters follow your radius standard, and the warm radius will the same.


class Heaters {
    public int findRadius(int[] houses, int[] heaters) {
        Arrays.sort(heaters);
        int res = 0;
        for(int i = 0; i < houses.length; i++){
            int left = 0;
            int right = heaters.length - 1;
            while(left < right){
                int mid = left + (right - left) / 2;
                if(heaters[mid] < houses[i]){
                    left = mid + 1;
                }else{
                    right = mid;
                }
            }
            int dist1 = Math.abs(heaters[left] - houses[i]);
            int dist2 = Integer.MAX_VALUE;
            if(left > 0){
                dist2 = Math.abs(heaters[left - 1] - houses[i]);
            }
            res = Math.max(res, Math.min(dist1, dist2));
        }
        return res;
        
    }
}

    