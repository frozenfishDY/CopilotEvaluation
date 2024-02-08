/**https://leetcode.com/problems/minimum-rounds-to-complete-all-tasks/ */
//You are given a 0-indexed integer array tasks, where tasks[i] represents the difficulty level of a task. In each round, you can complete either 2 or 3 tasks of the same difficulty level.
//Return the minimum rounds required to complete all the tasks, or -1 if it is not possible to complete all the tasks.


class MinimumRoundsToCompleteAllTasks {
    public int minimumRounds(int[] tasks) {
        int[] count = new int[11];
        for(int i = 0; i < tasks.length; i++){
            count[tasks[i]]++;
        }
        int res = 0;
        for(int i = 1; i < 11; i++){
            if(count[i] > 0){
                res += count[i] / 3;
                count[i] %= 3;
                if(count[i] > 0){
                    res++;
                    count[i] = 3 - count[i];
                }
            }
            if(count[i] > 0){
                count[i + 1] += count[i];
            }
        }
        return res;
        
    }
}
     
    