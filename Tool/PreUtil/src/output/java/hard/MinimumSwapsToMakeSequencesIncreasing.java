/**https://leetcode.com/problems/minimum-swaps-to-make-sequences-increasing/ */
//You are given two integer arrays of the same length nums1 and nums2. In one operation, you are allowed to swap nums1[i] with nums2[i].
//For example, if nums1 = [1,2,3,8], and nums2 = [5,6,7,4], you can swap the element at i = 3 to obtain nums1 = [1,2,3,4] and nums2 = [5,6,7,8].
//Return the minimum number of needed operations to make nums1 and nums2 strictly increasing. The test cases are generated so that the given input always makes it possible.
//An array arr is strictly increasing if and only if arr[0] < arr[1] < arr[2] < ... < arr[arr.length - 1].


class MinimumSwapsToMakeSequencesIncreasing {
    public int minSwap(int[] nums1, int[] nums2) {
        int n = nums1.length;
        int[] swap = new int[n];
        int[] noswap = new int[n];
        Arrays.fill(swap, Integer.MAX_VALUE);
        Arrays.fill(noswap, Integer.MAX_VALUE);
        swap[0] = 1;
        noswap[0] = 0;
        for(int i=1;i<n;i++){
            if(nums1[i]>nums1[i-1] && nums2[i]>nums2[i-1]){
                noswap[i] = noswap[i-1];
                swap[i] = swap[i-1]+1;
            }
            if(nums1[i]>nums2[i-1] && nums2[i]>nums1[i-1]){
                noswap[i] = Math.min(noswap[i], swap[i-1]);
                swap[i] = Math.min(swap[i], noswap[i-1]+1);
            }
        }
        return Math.min(swap[n-1], noswap[n-1]);
        
    }
}
     
    