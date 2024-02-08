/**https://leetcode.com/problems/maximum-performance-of-a-team/ */
//You are given two integers n and k and two integer arrays speed and efficiency both of length n. There are n engineers numbered from 1 to n. speed[i] and efficiency[i] represent the speed and efficiency of the ith engineer respectively.
//Choose at most k different engineers out of the n engineers to form a team with the maximum performance.
//The performance of a team is the sum of their engineers' speeds multiplied by the minimum efficiency among their engineers.
//Return the maximum performance of this team. Since the answer can be a huge number, return it modulo 109 + 7.


int maxPerformance(int n, int* speed, int speedSize, int* efficiency, int efficiencySize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*n);
    for(i=0;i<n;i++){
        arr[i] = 1;
    }
    for(i=1;i<n;i++){
        for(j=0;j<i;j++){
            arr[i] = (arr[i] * (2*(i-j)+1)) % 1000000007;
        }
    }
    int sum = 0;
    for(i=0;i<n;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    