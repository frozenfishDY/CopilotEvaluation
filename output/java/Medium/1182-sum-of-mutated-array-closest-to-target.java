/**https://leetcode.com/problems/sum-of-mutated-array-closest-to-target/ */
//Given an integer array arr and a target value target, return the integer value such that when we change all the integers larger than value in the given array to be equal to value, the sum of the array gets as close as possible (in absolute difference) to target.
//In case of a tie, return the minimum such integer.
//Notice that the answer is not neccesarilly a number from arr.


class SumOfMutatedArrayClosestToTarget {
    public int findBestValue(int[] arr, int target) {
        int n = arr.length;
        int[] prefix = new int[n + 1];
        for(int i = 0; i < n; i++){
            prefix[i + 1] = prefix[i] + arr[i];
        }
        int l = 0;
        int r = 100000;
        int res = 0;
        int min = Integer.MAX_VALUE;
        while(l <= r){
            int mid = l + (r - l) / 2;
            int index = Arrays.binarySearch(arr, mid);
            if(index < 0){
                index = -index - 1;
            }
            int sum = prefix[index] + (n - index) * mid;
            if(sum <= target){
                if(target - sum < min){
                    min = target - sum;
                    res = mid;
                }
                l = mid + 1;
            }else{
                if(sum - target < min){
                    min = sum - target;
                    res = mid;
                }
                r = mid - 1;
            }
        }
        return res;
        
        
        
    }
}

    