/**https://leetcode.com/problems/car-fleet-ii/ */
//There are n cars traveling at different speeds in the same direction along a one-lane road. You are given an array cars of length n, where cars[i] = [positioni, speedi] represents:
//positioni is the distance between the ith car and the beginning of the road in meters. It is guaranteed that positioni < positioni+1.
//speedi is the initial speed of the ith car in meters per second.
//For simplicity, cars can be considered as points moving along the number line. Two cars collide when they occupy the same position. Once a car collides with another car, they unite and form a single car fleet. The cars in the formed fleet will have the same position and the same speed, which is the initial speed of the slowest car in the fleet.
//Return an array answer, where answer[i] is the time, in seconds, at which the ith car collides with the next car, or -1 if the car does not collide with the next car. Answers within 10-5 of the actual answers are accepted.


class CarFleetIi {
    public double[] getCollisionTimes(int[][] cars) {
        int n = cars.length;
        double[] res = new double[n];
        Arrays.fill(res, -1);
        Stack<Integer> stack = new Stack<>();
        for(int i = n - 1; i >= 0; i--){
            int[] car = cars[i];
            int pos = car[0];
            int speed = car[1];
            while(!stack.isEmpty()){
                int[] top = cars[stack.peek()];
                int topPos = top[0];
                int topSpeed = top[1];
                if(speed <= topSpeed || (res[stack.peek()] > 0 && (double)(topPos - pos) / (speed - topSpeed) >= res[stack.peek()])){
                    stack.pop();
                }else{
                    break;
                }
            }
            if(!stack.isEmpty()){
                int[] top = cars[stack.peek()];
                int topPos = top[0];
                int topSpeed = top[1];
                res[i] = (double)(topPos - pos) / (speed - topSpeed);
            }
            stack.push(i);
        }
        return res;
        
    }
}
     
    