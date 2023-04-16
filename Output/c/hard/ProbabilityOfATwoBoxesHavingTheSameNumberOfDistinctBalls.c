/**https://leetcode.com/problems/probability-of-a-two-boxes-having-the-same-number-of-distinct-balls/ */
//Given 2n balls of k distinct colors. You will be given an integer array balls of size k where balls[i] is the number of balls of color i.
//All the balls will be shuffled uniformly at random, then we will distribute the first n balls to the first box and the remaining n balls to the other box (Please read the explanation of the second example carefully).
//Please note that the two boxes are considered different. For example, if we have two balls of colors a and b, and two boxes [] and (), then the distribution [a] (b) is considered different than the distribution [b] (a) (Please read the explanation of the first example carefully).
//Return the probability that the two boxes have the same number of distinct balls. Answers within 10-5 of the actual value will be accepted as correct.


double getProbability(int* balls, int ballsSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*ballsSize);
    for(i=0;i<ballsSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<ballsSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<ballsSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    