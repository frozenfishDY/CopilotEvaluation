/**https://leetcode.com/problems/minimum-number-of-food-buckets-to-feed-the-hamsters/ */
//You are given a 0-indexed string hamsters where hamsters[i] is either:
//'H' indicating that there is a hamster at index i, or
//'.' indicating that index i is empty.
//You will add some number of food buckets at the empty indices in order to feed the hamsters. A hamster can be fed if there is at least one food bucket to its left or to its right. More formally, a hamster at index i can be fed if you place a food bucket at index i - 1 and/or at index i + 1.
//Return the minimum number of food buckets you should place at empty indices to feed all the hamsters or -1 if it is impossible to feed all of them.


class MinimumNumberOfFoodBucketsToFeedTheHamsters {
    public int minimumBuckets(String hamsters) {
        int count = 0;
        int n = hamsters.length();
        for(int i = 0; i < n; i++){
            if(hamsters.charAt(i) == 'H'){
                if(i == 0){
                    if(hamsters.charAt(i + 1) == '.'){
                        count++;
                    }
                }else if(i == n - 1){
                    if(hamsters.charAt(i - 1) == '.'){
                        count++;
                    }
                }else{
                    if(hamsters.charAt(i - 1) == '.' && hamsters.charAt(i + 1) == '.'){
                        count++;
                    }
                }
            }
        }
        return count;
        
    }
}
     
    