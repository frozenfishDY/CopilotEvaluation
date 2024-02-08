/**https://leetcode.com/problems/find-latest-group-of-size-m/ */
//Given an array arr that represents a permutation of numbers from 1 to n.
//You have a binary string of size n that initially has all its bits set to zero. At each step i (assuming both the binary string and arr are 1-indexed) from 1 to n, the bit at position arr[i] is set to 1.
//You are also given an integer m. Find the latest step at which there exists a group of ones of length m. A group of ones is a contiguous substring of 1's such that it cannot be extended in either direction.
//Return the latest step at which there exists a group of ones of length exactly m. If no such group exists, return -1.


class FindLatestGroupOfSizeM {
    public int findLatestStep(int[] arr, int m) {
        int n = arr.length;
        int[] dp = new int[n + 2];
        int[] count = new int[n + 1];
        int res = -1;
        for(int i = 0; i < n; i++){
            int index = arr[i];
            int left = dp[index - 1];
            int right = dp[index + 1];
            dp[index - left] = dp[index + right] = left + right + 1;
            count[left]--;
            count[right]--;
            count[left + right + 1]++;
            if(count[m] > 0){
                res = i + 1;
            }
        }
        return res;
        
    }
}
     
    