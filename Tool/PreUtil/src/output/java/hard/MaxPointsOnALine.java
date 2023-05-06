/**https://leetcode.com/problems/max-points-on-a-line/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane, return the maximum number of points that lie on the same straight line.


class MaxPointsOnALine {
    public int maxPoints(int[][] points) {
        int n = points.length;
        if (n < 3) {
            return n;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            Map<String, Integer> map = new HashMap<>();
            int same = 0;
            int max = 0;
            for (int j = i + 1; j < n; j++) {
                int x = points[j][0] - points[i][0];
                int y = points[j][1] - points[i][1];
                if (x == 0 && y == 0) {
                    same++;
                    continue;
                }
                int gcd = gcd(x, y);
                x /= gcd;
                y /= gcd;
                String key = x + "," + y;
                map.put(key, map.getOrDefault(key, 0) + 1);
                max = Math.max(max, map.get(key));
            }
            ans = Math.max(ans, max + same + 1);
        }
        return ans;
        
        
    }
}
     
    