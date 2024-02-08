/**https://leetcode.com/problems/maximum-number-of-visible-points/ */
//You are given an array points, an integer angle, and your location, where location = [posx, posy] and points[i] = [xi, yi] both denote integral coordinates on the X-Y plane.
//Initially, you are facing directly east from your position. You cannot move from your position, but you can rotate. In other words, posx and posy cannot be changed. Your field of view in degrees is represented by angle, determining how wide you can see from any given view direction. Let d be the amount in degrees that you rotate counterclockwise. Then, your field of view is the inclusive range of angles [d - angle/2, d + angle/2].


class MaximumNumberOfVisiblePoints {
    public int visiblePoints(List<List<Integer>> points, int angle, List<Integer> location) {
        List<Double> angles = new ArrayList<>();
        int extra = 0;
        for (List<Integer> point : points) {
            int x = point.get(0) - location.get(0);
            int y = point.get(1) - location.get(1);
            if (x == 0 && y == 0) {
                extra++;
                continue;
            }
            angles.add(Math.atan2(y, x) * 180 / Math.PI);
        }
        Collections.sort(angles);
        int n = angles.size();
        for (int i = 0; i < n; i++) {
            angles.add(angles.get(i) + 360);
        }
        int ans = 0;
        int i = 0;
        for (int j = 0; j < angles.size(); j++) {
            while (angles.get(j) - angles.get(i) > angle) {
                i++;
            }
            ans = Math.max(ans, j - i + 1);
        }
        return ans + extra;
        
    }
}
     
    