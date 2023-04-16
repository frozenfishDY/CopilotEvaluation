/**https://leetcode.com/problems/get-the-maximum-score/ */
//You are given two sorted arrays of distinct integers nums1 and nums2.
//A valid path is defined as follows:
//Choose array nums1 or nums2 to traverse (from index-0).
//Traverse the current array from left to right.
//If you are reading any value that is present in nums1 and nums2 you are allowed to change your path to the other array. (Only one repeated value is considered in the valid path).
//The score is defined as the sum of uniques values in a valid path.
//Return the maximum score you can obtain of all possible valid paths. Since the answer may be too large, return it modulo 10^9 + 7.


class GetTheMaximumScore {
    public int maxSum(int[] nums1, int[] nums2) {
        int i = 0;
        int j = 0;
        int sum1 = 0;
        int sum2 = 0;
        int mod = 1000000007;
        while(i < nums1.length || j < nums2.length){
            if(i < nums1.length && (j == nums2.length || nums1[i] < nums2[j])){
                sum1 += nums1[i++];
            }else if(j < nums2.length && (i == nums1.length || nums1[i] > nums2[j])){
                sum2 += nums2[j++];
            }else{
                sum1 = sum2 = Math.max(sum1, sum2) + nums1[i];
                i++;
                j++;
            }
        }
        return (int)(Math.max(sum1, sum2) % mod);
        
    }
}
     
    