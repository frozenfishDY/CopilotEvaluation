/**https://leetcode.com/problems/3sum-with-multiplicity/ */
//Given an integer array arr, and an integer target, return the number of tuples i, j, k such that i < j < k and arr[i] + arr[j] + arr[k] == target.
//As the answer can be very large, return it modulo 10^9 + 7.


class ThreeSumWithMultiplicity {
    public int threeSumMulti(int[] arr, int target) {
        int n = arr.length;
        int mod = 1000000007;
        long res = 0;
        for(int i = 0; i < n; i++){
            int[] cnt = new int[101];
            for(int j = i + 1; j < n; j++){
                int t = target - arr[i] - arr[j];
                if(t >= 0 && t <= 100){
                    res += cnt[t];
                    res %= mod;
                }
                cnt[arr[j]]++;
            }
        }
        return (int)res;
        
    }
}

    