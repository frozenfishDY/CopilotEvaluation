/**https://leetcode.com/problems/three-equal-parts/ */
//You are given an array arr which consists of only zeros and ones, divide the array into three non-empty parts such that all of these parts represent the same binary value.
//If it is possible, return any [i, j] with i + 1 < j, such that:
//arr[0], arr[1], ..., arr[i] is the first part,
//arr[i + 1], arr[i + 2], ..., arr[j - 1] is the second part, and
//arr[j], arr[j + 1], ..., arr[arr.length - 1] is the third part.
//All three parts have equal binary values.
//If it is not possible, return [-1, -1].
//Note that the entire part is used when considering what binary value it represents. For example, [1,1,0] represents 6 in decimal, not 3. Also, leading zeros are allowed, so [0,1,1] and [1,1] represent the same value.


class ThreeEqualParts {
    public int[] threeEqualParts(int[] arr) {
        int n = arr.length;
        int[] res = new int[]{-1, -1};
        int count = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 1) {
                count++;
            }
        }
        if (count == 0) {
            return new int[]{0, n - 1};
        }
        if (count % 3 != 0) {
            return res;
        }
        int k = count / 3;
        int i = 0;
        while (arr[i] == 0) {
            i++;
        }
        int j = i;
        while (k > 0) {
            if (arr[j] == 1) {
                k--;
            }
            j++;
        }
        int p1 = i;
        int p2 = j;
        while (arr[p1] == 0) {
            p1++;
        }
        while (arr[p2] == 0) {
            p2++;
        }
        while (p2 < n) {
            if (arr[p1] != arr[p2]) {
                return res;
            }
            p1++;
            p2++;
        }
        return new int[]{i + j - 1, j + p2 - 1};
        
    }
}
     
    