/**https://leetcode.com/problems/kth-smallest-instructions/ */
//Bob is standing at cell (0, 0), and he wants to reach destination: (row, column). He can only travel right and down. You are going to help Bob by providing instructions for him to reach destination.
//The instructions are represented as a string, where each character is either:
//'H', meaning move horizontally (go right), or
//'V', meaning move vertically (go down).
//Multiple instructions will lead Bob to destination. For example, if destination is (2, 3), both "HHHVV" and "HVHVH" are valid instructions.
//However, Bob is very picky. Bob has a lucky number k, and he wants the kth lexicographically smallest instructions that will lead him to destination. k is 1-indexed.
//Given an integer array destination and an integer k, return the kth lexicographically smallest instructions that will take Bob to destination.


char * kthSmallestPath(int* destination, int destinationSize, int k){
    int i,j,k;
    int* arr = (int*)malloc(sizeof(int)*destinationSize);
    for(i=0;i<destinationSize;i++){
        arr[i] = 0;
    }
    arr[0] = 1;
    for(i=1;i<destinationSize;i++){
        arr[i] = arr[i-1] * i;
    }
    int sum = 0;
    for(i=0;i<destinationSize;i++){
        sum = (sum + arr[i]) % 1000000007;
    }
    return sum;

}

    