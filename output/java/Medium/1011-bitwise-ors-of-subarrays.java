/**https://leetcode.com/problems/bitwise-ors-of-subarrays/ */
//Given an integer array arr, return the number of distinct bitwise ORs of all the non-empty subarrays of arr.
//The bitwise OR of a subarray is the bitwise OR of each integer in the subarray. The bitwise OR of a subarray of one integer is that integer.
//A subarray is a contiguous non-empty sequence of elements within an array.


class BitwiseOrsOfSubarrays {
    public int subarrayBitwiseORs(int[] arr) {
        Set<Integer> res = new HashSet<>();
        Set<Integer> cur = new HashSet<>();
        for(int i = 0; i < arr.length; i++){
            Set<Integer> next = new HashSet<>();
            next.add(arr[i]);
            for(int j : cur){
                next.add(j | arr[i]);
            }
            res.addAll(next);
            cur = next;
        }
        return res.size();
        
        
    }
}

    