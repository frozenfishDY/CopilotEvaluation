/**https://leetcode.com/problems/minimum-number-of-people-to-teach/ */
//On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
//You are given an integer n, an array languages, and an array friendships where:
//There are n languages numbered 1 through n,
//languages[i] is the set of languages the ith user knows, and
//friendships[i] = [ui,vi] denotes a friendship between the users ui and vi.
//You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.
//Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.


class MinimumNumberOfPeopleToTeach {
    public int minimumTeachings(int n, int[][] languages, int[][] friendships) {
        int m = languages.length;
        int[] count = new int[n + 1];
        for(int i = 0; i < m; i++){
            for(int j = 0; j < languages[i].length; j++){
                count[languages[i][j]]++;
            }
        }
        int max = 0;
        for(int i = 1; i <= n; i++){
            max = Math.max(max, count[i]);
        }
        int ans = m - max;
        for(int i = 0; i < friendships.length; i++){
            int[] a = languages[friendships[i][0] - 1];
            int[] b = languages[friendships[i][1] - 1];
            int[] temp = new int[n + 1];
            for(int j = 0; j < a.length; j++){
                temp[a[j]]++;
            }
            for(int j = 0; j < b.length; j++){
                temp[b[j]]++;
            }
            max = 0;
            for(int j = 1; j <= n; j++){
                max = Math.max(max, temp[j]);
            }
            ans = Math.min(ans, m - max);
        }
        return ans;
        
    }
}
     
    