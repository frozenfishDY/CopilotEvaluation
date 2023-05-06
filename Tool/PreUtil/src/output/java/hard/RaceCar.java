/**https://leetcode.com/problems/race-car/ */
//Your car starts at position 0 and speed +1 on an infinite number line. Your car can go into negative positions. Your car drives automatically according to a sequence of instructions 'A' (accelerate) and 'R' (reverse):
//When you get an instruction 'A', your car does the following:
//position += speed
//speed *= 2
//When you get an instruction 'R', your car does the following:
//If your speed is positive then speed = -1
//otherwise speed = 1
//Your position stays the same.
//For example, after commands "AAR", your car goes to positions 0 --> 1 --> 3 --> 3, and your speed goes to 1 --> 2 --> 4 --> -1.
//Given a target position target, return the length of the shortest sequence of instructions to get there.


class RaceCar {
    public int racecar(int target) {
        Queue<int[]> queue = new LinkedList<>();
        queue.offer(new int[]{0, 1});
        Set<String> visited = new HashSet<>();
        visited.add("0,1");
        int step = 0;
        while (!queue.isEmpty()) {
            int size = queue.size();
            for (int i = 0; i < size; i++) {
                int[] cur = queue.poll();
                int pos = cur[0];
                int speed = cur[1];
                if (pos == target) {
                    return step;
                }
                int[] next = new int[]{pos + speed, speed * 2};
                String key = next[0] + "," + next[1];
                if (next[0] > 0 && next[0] < 2 * target && !visited.contains(key)) {
                    queue.offer(next);
                    visited.add(key);
                }
                next = new int[]{pos, speed > 0 ? -1 : 1};
                key = next[0] + "," + next[1];
                if (!visited.contains(key)) {
                    queue.offer(next);
                    visited.add(key);
                }
            }
            step++;
        }
        return -1;
        
    }
}
     
    