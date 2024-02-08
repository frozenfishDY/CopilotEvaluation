/**https://leetcode.com/problems/number-of-boomerangs/ */
//You are given n points in the plane that are all distinct, where points[i] = [xi, yi]. A boomerang is a tuple of points (i, j, k) such that the distance between i and j equals the distance between i and k (the order of the tuple matters).
//Return the number of boomerangs.


class NumberOfBoomerangs {
    public int numberOfBoomerangs(int[][] points) {
        int n = points.length;
        int res = 0;
        for(int i = 0; i < n; i++){
            Map<Integer, Integer> map = new HashMap<>();
            for(int j = 0; j < n; j++){
                if(i == j){
                    continue;
                }
                int dist = (points[i][0] - points[j][0]) * (points[i][0] - points[j][0]) + (points[i][1] - points[j][1]) * (points[i][1] - points[j][1]);
                map.put(dist, map.getOrDefault(dist, 0) + 1);
            }
            for(int val : map.values()){
                res += val * (val - 1);
            }
        }
        return res;
        
    }
}

    