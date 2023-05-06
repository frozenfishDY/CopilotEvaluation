/**https://leetcode.com/problems/find-original-array-from-doubled-array/ */
//An integer array original is transformed into a doubled array changed by appending twice the value of every element in original, and then randomly shuffling the resulting array.
//Given an array changed, return original if changed is a doubled array. If changed is not a doubled array, return an empty array. The elements in original may be returned in any order.


class FindOriginalArrayFromDoubledArray {
    public int[] findOriginalArray(int[] changed) {
        int n = changed.length;
        if(n % 2 == 1){
            return new int[0];
        }
        Arrays.sort(changed);
        int[] res = new int[n / 2];
        int count = 0;
        for(int i = 0; i < n; i += 2){
            if(changed[i] != changed[i + 1] || changed[i] % 2 == 1){
                return new int[0];
            }
            res[count++] = changed[i] / 2;
        }
        return res;
        
    }
}
     
    