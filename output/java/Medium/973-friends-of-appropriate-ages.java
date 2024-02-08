/**https://leetcode.com/problems/friends-of-appropriate-ages/ */
//There are n persons on a social media website. You are given an integer array ages where ages[i] is the age of the ith person.
//A Person x will not send a friend request to a person y (x != y) if any of the following conditions is true:
//age[y] <= 0.5 * age[x] + 7
//age[y] > age[x]
//age[y] > 100 && age[x] < 100
//Otherwise, x will send a friend request to y.
//Note that if x sends a request to y, y will not necessarily send a request to x. Also, a person will not send a friend request to themself.
//Return the total number of friend requests made.


class FriendsOfAppropriateAges {
    public int numFriendRequests(int[] ages) {
        int n = ages.length;
        int[] cnt = new int[121];
        for(int i = 0; i < n; i++){
            cnt[ages[i]]++;
        }
        int res = 0;
        for(int i = 15; i <= 120; i++){
            int sum = 0;
            for(int j = 1; j <= i; j++){
                if(j > 0.5 * i + 7){
                    sum += cnt[j];
                }
            }
            res += cnt[i] * (sum - 1);
        }
        return res;
        
    }
}

    