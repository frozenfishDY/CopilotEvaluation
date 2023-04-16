/**https://leetcode.com/problems/count-collisions-on-a-road/ */
//There are n cars on an infinitely long road. The cars are numbered from 0 to n - 1 from left to right and each car is present at a unique point.
//You are given a 0-indexed string directions of length n. directions[i] can be either 'L', 'R', or 'S' denoting whether the ith car is moving towards the left, towards the right, or staying at its current point respectively. Each moving car has the same speed.
//The number of collisions can be calculated as follows:
//When two cars moving in opposite directions collide with each other, the number of collisions increases by 2.
//When a moving car collides with a stationary car, the number of collisions increases by 1.
//After a collision, the cars involved can no longer move and will stay at the point where they collided. Other than that, cars cannot change their state or direction of motion.
//Return the total number of collisions that will happen on the road.


class CountCollisionsOnARoad {
    public int countCollisions(String directions) {
        int res = 0;
        int n = directions.length();
        int[] left = new int[n];
        int[] right = new int[n];
        for(int i = 0; i < n; i++){
            if(directions.charAt(i) == 'L'){
                left[i] = 1;
            }else if(directions.charAt(i) == 'R'){
                right[i] = 1;
            }
        }
        for(int i = 0; i < n; i++){
            if(left[i] == 1){
                for(int j = i + 1; j < n; j++){
                    if(right[j] == 1){
                        res += 2;
                        left[i] = 0;
                        right[j] = 0;
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(left[i] == 1){
                for(int j = i + 1; j < n; j++){
                    if(left[j] == 1){
                        res += 1;
                        left[i] = 0;
                        left[j] = 0;
                        break;
                    }
                }
            }
        }
        for(int i = 0; i < n; i++){
            if(right[i] == 1){
                for(int j = i + 1; j < n; j++){
                    if(right[j] == 1){
                        res += 1;
                        right[i] = 0;
                        right[j] = 0;
                        break;
                    }
                }
            }
        }
        return res;
        
    }
}
     
    