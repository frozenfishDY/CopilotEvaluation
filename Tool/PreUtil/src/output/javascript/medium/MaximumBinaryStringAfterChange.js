/**https://leetcode.com/problems/maximum-binary-string-after-change/ */
//You are given a binary string binary consisting of only 0's or 1's. You can apply each of the following operations any number of times:
//Operation 1: If the number contains the substring "00", you can replace it with "10".
//For example, "00010" -> "10010"
//Operation 2: If the number contains the substring "10", you can replace it with "01".
//For example, "00010" -> "00001"
//Return the maximum binary string you can obtain after any number of operations. Binary string x is greater than binary string y if x's decimal representation is greater than y's decimal representation.


/**
 * @param {string} binary
 * @return {string}
 */
var maximumBinaryString = function(binary) {
    let n = binary.length;
    let count = 0;
    let first = 0;
    for (let i = 0; i < n; i++) {
        if (binary[i] == '0') {
            count++;
        } else if (count > 0) {
            first = i;
            break;
        }
    }
    return '1'.repeat(first) + '0'.repeat(count - 1) + '1'.repeat(n - first - count + 1);
    
};

    