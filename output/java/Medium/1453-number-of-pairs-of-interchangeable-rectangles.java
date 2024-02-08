/**https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/ */
//You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.
//Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).
//Return the number of pairs of interchangeable rectangles in rectangles.


class NumberOfPairsOfInterchangeableRectangles {
    public long interchangeableRectangles(int[][] rectangles) {
        Map<Double, Integer> map = new HashMap<>();
        for(int[] rectangle : rectangles){
            double ratio = (double)rectangle[0] / rectangle[1];
            map.put(ratio, map.getOrDefault(ratio, 0) + 1);
        }
        long count = 0;
        for(int value : map.values()){
            count += (long)value * (value - 1) / 2;
        }
        return count;
        
    }
}
     
    