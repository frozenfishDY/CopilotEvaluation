/**https://leetcode.com/problems/subdomain-visit-count/ */
//A website domain "discuss.leetcode.com" consists of various subdomains. At the top level, we have "com", at the next level, we have "leetcode.com" and at the lowest level, "discuss.leetcode.com". When we visit a domain like "discuss.leetcode.com", we will also visit the parent domains "leetcode.com" and "com" implicitly.
//A count-paired domain is a domain that has one of the two formats "rep d1.d2.d3" or "rep d1.d2" where rep is the number of visits to the domain and d1.d2.d3 is the domain itself.
//For example, "9001 discuss.leetcode.com" is a count-paired domain that indicates that discuss.leetcode.com was visited 9001 times.
//Given an array of count-paired domains cpdomains, return an array of the count-paired domains of each subdomain in the input. You may return the answer in any order.


/**
 * @param {string[]} cpdomains
 * @return {string[]}
 */
var subdomainVisits = function(cpdomains) {
    let result = [];
    let map = new Map();
    for(let i = 0; i < cpdomains.length; i++){
        let [count, domain] = cpdomains[i].split(" ");
        let subdomains = domain.split(".");
        let temp = "";
        for(let j = subdomains.length - 1; j >= 0; j--){
            temp = subdomains[j] + (j < subdomains.length - 1 ? "." : "") + temp;
            if(map.has(temp)){
                map.set(temp, map.get(temp) + parseInt(count));
            }else{
                map.set(temp, parseInt(count));
            }
        }
    }
    for(let [key, value] of map){
        result.push(value + " " + key);
    }
    return result;
    
};

    