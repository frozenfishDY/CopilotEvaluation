/**https://leetcode.com/problems/k-closest-points-to-origin/ */
//Given an array of points where points[i] = [xi, yi] represents a point on the X-Y plane and an integer k, return the k closest points to the origin (0, 0).
//The distance between two points on the X-Y plane is the Euclidean distance (i.e., ��(x1 - x2)2 + (y1 - y2)2).
//You may return the answer in any order. The answer is guaranteed to be unique (except for the order that it is in).


class KClosestPointsToOrigin {
    public int[][] kClosest(int[][] points, int k) {
        PriorityQueue<int[]> pq = new PriorityQueue<>((a, b) -> b[0] - a[0]);
        for(int[] p : points){
            int dist = p[0] * p[0] + p[1] * p[1];
            pq.add(new int[]{dist, p[0], p[1]});
            if(pq.size() > k){
                pq.poll();
            }
        }
        int[][] res = new int[k][2];
        for(int i = 0; i < k; i++){
            int[] p = pq.poll();
            res[i][0] = p[1];
            res[i][1] = p[2];
        }
        return res;
        
        
    }
}

    