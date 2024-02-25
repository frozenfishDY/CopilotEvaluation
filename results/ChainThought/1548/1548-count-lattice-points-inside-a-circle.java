/**https://leetcode.com/problems/count-lattice-points-inside-a-circle/ */
//Given a 2D integer array circles where circles[i] = [xi, yi, ri] represents the center (xi, yi) and radius ri of the ith circle drawn on a grid, return the number of lattice points that are present inside at least one circle.
//Note:
//A lattice point is a point with integer coordinates.
//Points that lie on the circumference of a circle are also considered to be inside it.


class CountLatticePointsInsideACircle {
    public int countLatticePoints(int[][] circles) {
        int count = 0;
        for(int i = 0; i < circles.length; i++){
            int x = circles[i][0];
            int y = circles[i][1];
            int r = circles[i][2];
            for(int j = x - r; j <= x + r; j++){
                for(int k = y - r; k <= y + r; k++){
                    if(Math.pow(j - x, 2) + Math.pow(k - y, 2) <= Math.pow(r, 2)){
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
}
     
    