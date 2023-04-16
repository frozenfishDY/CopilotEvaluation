/**https://leetcode.com/problems/super-washing-machines/ */
//You have n super washing machines on a line. Initially, each washing machine has some dresses or is empty.
//For each move, you could choose any m (1 <= m <= n) washing machines, and pass one dress of each washing machine to one of its adjacent washing machines at the same time.
//Given an integer array machines representing the number of dresses in each washing machine from left to right on the line, return the minimum number of moves to make all the washing machines have the same number of dresses. If it is not possible to do it, return -1.


class SuperWashingMachines {
    public int findMinMoves(int[] machines) {
        int n = machines.length;
        int sum = 0;
        for (int machine : machines) {
            sum += machine;
        }
        if (sum % n != 0) {
            return -1;
        }
        int avg = sum / n;
        int[] left = new int[n];
        int[] right = new int[n];
        left[0] = machines[0] - avg;
        right[n - 1] = machines[n - 1] - avg;
        for (int i = 1; i < n; i++) {
            left[i] = left[i - 1] + machines[i] - avg;
            int j = n - i - 1;
            right[j] = right[j + 1] + machines[j] - avg;
        }
        int ans = 0;
        for (int i = 0; i < n; i++) {
            int l = i > 0 ? left[i - 1] : 0;
            int r = i < n - 1 ? right[i + 1] : 0;
            int a = Math.abs(left[i]);
            int b = Math.abs(right[i]);
            if (l < 0 && r < 0) {
                ans = Math.max(ans, a + b - Math.min(a, b));
            } else {
                ans = Math.max(ans, Math.max(a, b));
            }
        }
        return ans;
        
    }
}
     
    