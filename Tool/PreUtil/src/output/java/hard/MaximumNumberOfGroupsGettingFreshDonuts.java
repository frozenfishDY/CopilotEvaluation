/**https://leetcode.com/problems/maximum-number-of-groups-getting-fresh-donuts/ */
//There is a donuts shop that bakes donuts in batches of batchSize. They have a rule where they must serve all of the donuts of a batch before serving any donuts of the next batch. You are given an integer batchSize and an integer array groups, where groups[i] denotes that there is a group of groups[i] customers that will visit the shop. Each customer will get exactly one donut.
//When a group visits the shop, all customers of the group must be served before serving any of the following groups. A group will be happy if they all get fresh donuts. That is, the first customer of the group does not receive a donut that was left over from the previous group.
//You can freely rearrange the ordering of the groups. Return the maximum possible number of happy groups after rearranging the groups.


class MaximumNumberOfGroupsGettingFreshDonuts {
    public int maxHappyGroups(int batchSize, int[] groups) {
        int n = groups.length;
        int[] count = new int[batchSize];
        int res = 0;
        for(int i = 0; i < n; i++){
            if(groups[i] % batchSize == 0){
                res++;
            }else{
                count[groups[i] % batchSize]++;
            }
        }
        int[] dp = new int[batchSize];
        for(int i = 1; i < batchSize; i++){
            dp[i] = count[i];
        }
        for(int i = 1; i < batchSize; i++){
            for(int j = 1; j < batchSize; j++){
                if(i + j < batchSize){
                    dp[i + j] = Math.max(dp[i + j], dp[i] + count[j]);
                }else{
                    dp[(i + j) % batchSize] = Math.max(dp[(i + j) % batchSize], dp[i] + count[j] + 1);
                }
            }
        }
        return res + dp[0];
        
    }
}
     
    