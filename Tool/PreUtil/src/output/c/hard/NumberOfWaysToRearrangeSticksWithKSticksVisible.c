/**https://leetcode.com/problems/number-of-ways-to-rearrange-sticks-with-k-sticks-visible/ */
//There are n uniquely-sized sticks whose lengths are integers from 1 to n. You want to arrange the sticks such that exactly k sticks are visible from the left. A stick is visible from the left if there are no longer sticks to the left of it.
//For example, if the sticks are arranged [1,3,2,5,4], then the sticks with lengths 1, 3, and 5 are visible from the left.
//Given n and k, return the number of such arrangements. Since the answer may be large, return it modulo 10^9 + 7.


int rearrangeSticks(int n, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*k);
    for(i=0;i<k;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<n;i++){
        for(j=k-1;j>0;j--){
            arr[j] = (arr[j] + arr[j-1])%1000000007;
        }
        arr[0] = 0;
    }
    return arr[k-1];

}

    