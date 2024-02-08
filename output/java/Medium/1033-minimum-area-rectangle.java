/**https://leetcode.com/problems/minimum-area-rectangle/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of a rectangle formed from these points, with sides parallel to the X and Y axes. If there is not any such rectangle, return 0.


class MinimumAreaRectangle {
    public int minAreaRect(int[][] points) {
        int n = points.length;
        Map<Integer, Set<Integer>> map = new HashMap<>();
        for(int[] p : points){
            map.putIfAbsent(p[0], new HashSet<>());
            map.get(p[0]).add(p[1]);
        }
        int res = Integer.MAX_VALUE;
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int[] p1 = points[i];
                int[] p2 = points[j];
                if(p1[0] == p2[0] || p1[1] == p2[1]){
                    continue;
                }
                if(map.get(p1[0]).contains(p2[1]) && map.get(p2[0]).contains(p1[1])){
                    res = Math.min(res, Math.abs(p1[0] - p2[0]) * Math.abs(p1[1] - p2[1]));
                }
            }
        }
        return res == Integer.MAX_VALUE ? 0 : res;
        
        
        
    }
}

    