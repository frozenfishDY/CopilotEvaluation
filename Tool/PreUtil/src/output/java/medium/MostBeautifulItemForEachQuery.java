/**https://leetcode.com/problems/most-beautiful-item-for-each-query/ */
//You are given a 2D integer array items where items[i] = [pricei, beautyi] denotes the price and beauty of an item respectively.
//You are also given a 0-indexed integer array queries. For each queries[j], you want to determine the maximum beauty of an item whose price is less than or equal to queries[j]. If no such item exists, then the answer to this query is 0.
//Return an array answer of the same length as queries where answer[j] is the answer to the jth query.


class MostBeautifulItemForEachQuery {
    public int[] maximumBeauty(int[][] items, int[] queries) {
        int[] ans = new int[queries.length];
        int[] beauty = new int[100001];
        for(int i = 0; i < items.length; i++){
            beauty[items[i][0]] = Math.max(beauty[items[i][0]], items[i][1]);
        }
        for(int i = 1; i < beauty.length; i++){
            beauty[i] = Math.max(beauty[i], beauty[i - 1]);
        }
        for(int i = 0; i < queries.length; i++){
            ans[i] = beauty[queries[i]];
        }
        return ans;
        
    }
}
     
    