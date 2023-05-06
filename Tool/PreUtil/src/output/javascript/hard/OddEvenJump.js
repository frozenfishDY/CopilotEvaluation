/**https://leetcode.com/problems/odd-even-jump/ */
//You are given an integer array arr. From some starting index, you can make a series of jumps. The (1st, 3rd, 5th, ...) jumps in the series are called odd-numbered jumps, and the (2nd, 4th, 6th, ...) jumps in the series are called even-numbered jumps. Note that the jumps are numbered, not the indices.
//You may jump forward from index i to index j (with i < j) in the following way:
//During odd-numbered jumps (i.e., jumps 1, 3, 5, ...), you jump to the index j such that arr[i] <= arr[j] and arr[j] is the smallest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
//During even-numbered jumps (i.e., jumps 2, 4, 6, ...), you jump to the index j such that arr[i] >= arr[j] and arr[j] is the largest possible value. If there are multiple such indices j, you can only jump to the smallest such index j.
//It may be the case that for some index i, there are no legal jumps.
//A starting index is good if, starting from that index, you can reach the end of the array (index arr.length - 1) by jumping some number of times (possibly 0 or more than once).
//Return the number of good starting indices.


/**
 * @param {number[]} arr
 * @return {number}
 */
var oddEvenJumps = function(arr) {
    let n = arr.length;
    let odd = new Array(n).fill(false);
    let even = new Array(n).fill(false);
    odd[n - 1] = true;
    even[n - 1] = true;
    let map = new Map();
    map.set(arr[n - 1], n - 1);
    let ans = 1;
    for(let i = n - 2; i >= 0; i--){
        let next = map.get(arr[i]);
        if(next != undefined){
            odd[i] = even[next];
            even[i] = odd[next];
        }else{
            let next = map.get(Math.min(...map.keys().filter(x => x > arr[i])));
            if(next != undefined){
                odd[i] = even[next];
            }
            next = map.get(Math.max(...map.keys().filter(x => x < arr[i])));
            if(next != undefined){
                even[i] = odd[next];
            }
        }
        if(odd[i]){
            ans++;
        }
        map.set(arr[i], i);
    }
    return ans;
    
};

    