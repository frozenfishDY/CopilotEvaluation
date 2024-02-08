/**https://leetcode.com/problems/car-fleet/ */
//There are n cars going to the same destination along a one-lane road. The destination is target miles away.
//You are given two integer array position and speed, both of length n, where position[i] is the position of the ith car and speed[i] is the speed of the ith car (in miles per hour).
//A car can never pass another car ahead of it, but it can catch up to it and drive bumper to bumper at the same speed. The faster car will slow down to match the slower car's speed. The distance between these two cars is ignored (i.e., they are assumed to have the same position).
//A car fleet is some non-empty set of cars driving at the same position and same speed. Note that a single car is also a car fleet.
//If a car catches up to a car fleet right at the destination point, it will still be considered as one car fleet.
//Return the number of car fleets that will arrive at the destination.


class CarFleet {
    public int carFleet(int target, int[] position, int[] speed) {
        int n = position.length;
        int[][] cars = new int[n][2];
        int i = 0;
        for(i = 0; i < n; i++){
            cars[i][0] = position[i];
            cars[i][1] = speed[i];
        }
        Arrays.sort(cars, (a, b) -> a[0] - b[0]);
        int res = 0;
        double time = 0;
        for(i = n - 1; i >= 0; i--){
            if((double)(target - cars[i][0]) / cars[i][1] > time){
                res++;
                time = (double)(target - cars[i][0]) / cars[i][1];
            }
        }
        return res;
        
    }
}

    