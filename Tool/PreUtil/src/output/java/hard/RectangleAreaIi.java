/**https://leetcode.com/problems/rectangle-area-ii/ */
//You are given a 2D array of axis-aligned rectangles. Each rectangle[i] = [xi1, yi1, xi2, yi2] denotes the ith rectangle where (xi1, yi1) are the coordinates of the bottom-left corner, and (xi2, yi2) are the coordinates of the top-right corner.
//Calculate the total area covered by all rectangles in the plane. Any area covered by two or more rectangles should only be counted once.
//Return the total area. Since the answer may be too large, return it modulo 10^9 + 7.


class RectangleAreaIi {
    public int rectangleArea(int[][] rectangles) {
        int n = rectangles.length;
        int[][] events = new int[2 * n][];
        int t = 0;
        for (int[] rec : rectangles) {
            events[t++] = new int[]{rec[1], rec[0], rec[2], 1};
            events[t++] = new int[]{rec[3], rec[0], rec[2], -1};
        }
        Arrays.sort(events, (a, b) -> a[0] - b[0]);
        long res = 0;
        long prevY = -1;
        long curY = -1;
        long curXSum = 0;
        TreeMap<Integer, Integer> map = new TreeMap<>();
        for (int[] event : events) {
            curY = event[0];
            int x1 = event[1], x2 = event[2], sig = event[3];
            res += (curY - prevY) * curXSum;
            res %= 1000000007;
            curXSum = 0;
            prevY = curY;
            map.put(x1, map.getOrDefault(x1, 0) + sig);
            if (sig == 1) {
                map.put(x2, map.getOrDefault(x2, 0) - 1);
            }
            int count = 0;
            for (int x : map.keySet()) {
                count += map.get(x);
                if (count > 0) {
                    curXSum += x - (map.lowerKey(x) == null ? 0 : map.lowerKey(x));
                    curXSum %= 1000000007;
                }
            }
        }
        return (int) res;
        
    }
}
     
    