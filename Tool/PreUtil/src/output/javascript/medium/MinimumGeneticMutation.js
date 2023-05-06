/**https://leetcode.com/problems/minimum-genetic-mutation/ */
//A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
//Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
//For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
//There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
//Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
//Note that the starting point is assumed to be valid, so it might not be included in the bank.


/**
 * @param {string} startGene
 * @param {string} endGene
 * @param {string[]} bank
 * @return {number}
 */
var minMutation = function(startGene, endGene, bank) {
    let queue = [startGene];
    let visited = new Set();
    let count = 0;
    while(queue.length > 0){
        let size = queue.length;
        for(let i = 0; i < size; i++){
            let gene = queue.shift();
            if(gene == endGene){
                return count;
            }
            for(let j = 0; j < bank.length; j++){
                if(!visited.has(j) && isValid(gene, bank[j])){
                    visited.add(j);
                    queue.push(bank[j]);
                }
            }
        }
        count++;
    }
    return -1;
    
    
    
};

    