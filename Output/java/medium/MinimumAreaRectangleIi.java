/**https://leetcode.com/problems/minimum-area-rectangle-ii/ */
//You are given an array of points in the X-Y plane points where points[i] = [xi, yi].
//Return the minimum area of any rectangle formed from these points, with sides not necessarily parallel to the X and Y axes. If there is not any such rectangle, return 0.
//Answers within 10-5 of the actual answer will be accepted.


class MinimumAreaRectangleIi {
    public double minAreaFreeRect(int[][] points) {
        int n = points.length;
        Map<String, List<int[]>> map = new HashMap<>();
        for(int i = 0; i < n; i++){
            for(int j = i + 1; j < n; j++){
                int[] p1 = points[i];
                int[] p2 = points[j];
                int x = p1[0] + p2[0];
                int y = p1[1] + p2[1];
                int d = (p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1]);
                String key = x + "," + y + "," + d;
                map.putIfAbsent(key, new ArrayList<>());
                map.get(key).add(new int[]{i, j});
            }
        }
        double res = Double.MAX_VALUE;
        for(String key : map.keySet()){
            List<int[]> list = map.get(key);
            int m = list.size();
            for(int i = 0; i < m; i++){
                for(int j = i + 1; j < m; j++){
                    int[] p1 = points[list.get(i)[0]];
                    int[] p2 = points[list.get(i)[1]];
                    int[] p3 = points[list.get(j)[0]];
                    int[] p4 = points[list.get(j)[1]];
                    double area = Math.sqrt((p1[0] - p2[0]) * (p1[0] - p2[0]) + (p1[1] - p2[1]) * (p1[1] - p2[1])) * Math.sqrt((p1[0] - p3[0]) * (p1[0] - p3[0]) + (p1[1] - p3[1]) * (p1[1] - p3[1]));
                    res = Math.min(res, area);
                }
            }
        }
        return res == Double.MAX_VALUE ? 0 : res;
        
        
        
    }
}

    