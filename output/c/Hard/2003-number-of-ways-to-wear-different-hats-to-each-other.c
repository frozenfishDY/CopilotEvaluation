/**https://leetcode.com/problems/number-of-ways-to-wear-different-hats-to-each-other/ */
//There are n people and 40 types of hats labeled from 1 to 40.
//Given a 2D integer array hats, where hats[i] is a list of all hats preferred by the ith person.
//Return the number of ways that the n people wear different hats to each other.
//Since the answer may be too large, return it modulo 10^9 + 7.


int numberWays(int** hats, int hatsSize, int* hatsColSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*hatsSize);
    for(i=0;i<hatsSize;i++){
        arr[i] = 1;
    }
    for(i=1;i<hatsSize;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<hatsSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    