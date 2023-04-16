/**https://leetcode.com/problems/maximize-distance-to-closest-person/ */
//You are given an array representing a row of seats where seats[i] = 1 represents a person sitting in the ith seat, and seats[i] = 0 represents that the ith seat is empty (0-indexed).
//There is at least one empty seat, and at least one person sitting.
//Alex wants to sit in the seat such that the distance between him and the closest person to him is maximized. 
//Return that maximum distance to the closest person.


class MaximizeDistanceToClosestPerson {
    public int maxDistToClosest(int[] seats) {
        int n = seats.length;
        int[] left = new int[n];
        int[] right = new int[n];
        int i = 0;
        int j = 0;
        while(i < n){
            if(seats[i] == 1){
                left[i] = 0;
            }else{
                left[i] = i > 0 ? left[i - 1] + 1 : Integer.MAX_VALUE;
            }
            i++;
        }
        i = n - 1;
        while(i >= 0){
            if(seats[i] == 1){
                right[i] = 0;
            }else{
                right[i] = i < n - 1 ? right[i + 1] + 1 : Integer.MAX_VALUE;
            }
            i--;
        }
        int res = 0;
        for(i = 0; i < n; i++){
            if(seats[i] == 0){
                res = Math.max(res, Math.min(left[i], right[i]));
            }
        }
        return res;
        
    }
}

    