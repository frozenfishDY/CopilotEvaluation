/**https://leetcode.com/problems/maximum-points-you-can-obtain-from-cards/ */
//There are several cards arranged in a row, and each card has an associated number of points. The points are given in the integer array cardPoints.
//In one step, you can take one card from the beginning or from the end of the row. You have to take exactly k cards.
//Your score is the sum of the points of the cards you have taken.
//Given the integer array cardPoints and the integer k, return the maximum score you can obtain.


int maxScore(int* cardPoints, int cardPointsSize, int k){
    int i, j, k, l, m, n, sum = 0, max = 0;
    for(i = 0; i < k; i++){
        sum += cardPoints[i];
    }
    max = sum;
    for(i = k - 1, j = cardPointsSize - 1; i >= 0; i--, j--){
        sum -= cardPoints[i];
        sum += cardPoints[j];
        if(sum > max){
            max = sum;
        }
    }
    return max;

}

    