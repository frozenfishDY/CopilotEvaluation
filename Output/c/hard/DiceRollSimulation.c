/**https://leetcode.com/problems/dice-roll-simulation/ */
//A die simulator generates a random number from 1 to 6 for each roll. You introduced a constraint to the generator such that it cannot roll the number i more than rollMax[i] (1-indexed) consecutive times.
//Given an array of integers rollMax and an integer n, return the number of distinct sequences that can be obtained with exact n rolls. Since the answer may be too large, return it modulo 109 + 7.
//Two sequences are considered different if at least one element differs from each other


int dieSimulator(int n, int* rollMax, int rollMaxSize){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*6);
    for(i=0;i<6;i++){
        arr[i] = 1;
    }
    int* arr2 = (int*)malloc(sizeof(int)*6);
    for(i=0;i<6;i++){
        arr2[i] = 0;
    }
    for(i=1;i<n;i++){
        arr2[0] = (arr[1] + arr[2] + arr[3] + arr[4] + arr[5])%1000000007;
        arr2[1] = (arr[0] + arr[2] + arr[3] + arr[4] + arr[5])%1000000007;
        arr2[2] = (arr[0] + arr[1] + arr[3] + arr[4] + arr[5])%1000000007;
        arr2[3] = (arr[0] + arr[1] + arr[2] + arr[4] + arr[5])%1000000007;
        arr2[4] = (arr[0] + arr[1] + arr[2] + arr[3] + arr[5])%1000000007;
        arr2[5] = (arr[0] + arr[1] + arr[2] + arr[3] + arr[4])%1000000007;
        for(j=0;j<6;j++){
            arr[j] = arr2[j];
        }
    }
    int ans = 0;
    for(i=0;i<6;i++){
        ans = (ans + arr[i])%1000000007;
    }
    return ans;

}

    