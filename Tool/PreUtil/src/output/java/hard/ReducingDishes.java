/**https://leetcode.com/problems/reducing-dishes/ */
//A chef has collected data on the satisfaction level of his n dishes. Chef can cook any dish in 1 unit of time.
//Like-time coefficient of a dish is defined as the time taken to cook that dish including previous dishes multiplied by its satisfaction level i.e. time[i] * satisfaction[i].
//Return the maximum sum of like-time coefficient that the chef can obtain after dishes preparation.
//Dishes can be prepared in any order and the chef can discard some dishes to get this maximum value.


class ReducingDishes {
    public int maxSatisfaction(int[] satisfaction) {
        Arrays.sort(satisfaction);
        int n = satisfaction.length;
        int[] prefix = new int[n + 1];
        for(int i = 1; i <= n; i++){
            prefix[i] = prefix[i - 1] + satisfaction[i - 1];
        }
        int res = 0;
        int sum = 0;
        for(int i = n - 1; i >= 0; i--){
            sum += satisfaction[i];
            res = Math.max(res, sum + prefix[i]);
        }
        return res;
        
    }
}
     
    