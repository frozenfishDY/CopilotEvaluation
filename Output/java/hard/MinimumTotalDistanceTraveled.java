/**https://leetcode.com/problems/minimum-total-distance-traveled/ */
//There are some robots and factories on the X-axis. You are given an integer array robot where robot[i] is the position of the ith robot. You are also given a 2D integer array factory where factory[j] = [positionj, limitj] indicates that positionj is the position of the jth factory and that the jth factory can repair at most limitj robots.
//The positions of each robot are unique. The positions of each factory are also unique. Note that a robot can be in the same position as a factory initially.
//All the robots are initially broken; they keep moving in one direction. The direction could be the negative or the positive direction of the X-axis. When a robot reaches a factory that did not reach its limit, the factory repairs the robot, and it stops moving.
//At any moment, you can set the initial direction of moving for some robot. Your target is to minimize the total distance traveled by all the robots.
//Return the minimum total distance traveled by all the robots. The test cases are generated such that all the robots can be repaired.
//Note that
//All robots move at the same speed.
//If two robots move in the same direction, they will never collide.
//If two robots move in opposite directions and they meet at some point, they do not collide. They cross each other.
//If a robot passes by a factory that reached its limits, it crosses it as if it does not exist.
//If the robot moved from a position x to a position y, the distance it moved is |y - x|.


class MinimumTotalDistanceTraveled {
    public long minimumTotalDistance(List<Integer> robot, int[][] factory) {
        int n = robot.size();
        int m = factory.length;
        long[] dist = new long[n];
        long res = Long.MAX_VALUE;
        for (int i = 0; i < m; i++) {
            int pos = factory[i][0];
            int limit = factory[i][1];
            for (int j = 0; j < n; j++) {
                dist[j] += Math.abs(robot.get(j) - pos);
            }
            Arrays.sort(dist);
            long sum = 0;
            for (int j = 0; j < limit; j++) {
                sum += dist[j];
            }
            res = Math.min(res, sum);
        }
        return res;
        
    }
}
     
    