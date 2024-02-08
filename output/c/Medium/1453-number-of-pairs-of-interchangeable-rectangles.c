/**https://leetcode.com/problems/number-of-pairs-of-interchangeable-rectangles/ */
//You are given n rectangles represented by a 0-indexed 2D integer array rectangles, where rectangles[i] = [widthi, heighti] denotes the width and height of the ith rectangle.
//Two rectangles i and j (i < j) are considered interchangeable if they have the same width-to-height ratio. More formally, two rectangles are interchangeable if widthi/heighti == widthj/heightj (using decimal division, not integer division).
//Return the number of pairs of interchangeable rectangles in rectangles.


long long interchangeableRectangles(int** rectangles, int rectanglesSize, int* rectanglesColSize){
    int i, j;
    int count = 0;
    int mod = 1000000007;
    for(i = 0; i < rectanglesSize; i++){
        for(j = i + 1; j < rectanglesSize; j++){
            if((double)rectangles[i][0] / rectangles[i][1] == (double)rectangles[j][0] / rectangles[j][1]){
                count++;
            }
        }
    }
    return count % mod;

}

    