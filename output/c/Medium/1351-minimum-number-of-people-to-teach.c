/**https://leetcode.com/problems/minimum-number-of-people-to-teach/ */
//On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
//You are given an integer n, an array languages, and an array friendships where:
//There are n languages numbered 1 through n,
//languages[i] is the set of languages the ith user knows, and
//friendships[i] = [ui,vi] denotes a friendship between the users ui and vi.
//You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.
//Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.


int minimumTeachings(int n, int** languages, int languagesSize, int* languagesColSize, int** friendships, int friendshipsSize, int* friendshipsColSize){
    int* lang = (int*)calloc(n+1, sizeof(int));
    int* langCount = (int*)calloc(n+1, sizeof(int));
    int* langFriend = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount2 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount3 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount4 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount5 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount6 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount7 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount8 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount9 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount10 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount11 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount12 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount13 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount14 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount15 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount16 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount17 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount18 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount19 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount20 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount21 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount22 = (int*)calloc(n+1, sizeof(int));
    int* langFriendCount23 = (int*)calloc(n+1, sizeof(int));
 


}

    