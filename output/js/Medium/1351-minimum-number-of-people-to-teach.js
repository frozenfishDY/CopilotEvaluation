/**https://leetcode.com/problems/minimum-number-of-people-to-teach/ */
//On a social network consisting of m users and some friendships between users, two users can communicate with each other if they know a common language.
//You are given an integer n, an array languages, and an array friendships where:
//There are n languages numbered 1 through n,
//languages[i] is the set of languages the ith user knows, and
//friendships[i] = [ui,vi] denotes a friendship between the users ui and vi.
//You can choose one language and teach it to some users so that all friends can communicate with each other. Return the minimum number of users you need to teach.
//Note that friendships are not transitive, meaning if x is a friend of y and y is a friend of z, this doesn't guarantee that x is a friend of z.


/**
 * @param {number} n
 * @param {number[][]} languages
 * @param {number[][]} friendships
 * @return {number}
 */
var minimumTeachings = function(n, languages, friendships) {
    let map = new Map();
    let set = new Set();
    let count = 0;
    for(let i = 0; i < languages.length; i++){
        for(let j = 0; j < languages[i].length; j++){
            if(map.has(languages[i][j])){
                map.get(languages[i][j]).push(i);
            }else{
                map.set(languages[i][j], [i]);
            }
        }
    }
    for(let i = 0; i < friendships.length; i++){
        let [u, v] = friendships[i];
        let flag = false;
        for(let j = 0; j < languages[u-1].length; j++){
            if(map.get(languages[u-1][j]).includes(v-1)){
                flag = true;
                break;
            }
        }
        if(!flag){
            set.add(u);
            set.add(v);
        }
    }
    return set.size;
    
};

    