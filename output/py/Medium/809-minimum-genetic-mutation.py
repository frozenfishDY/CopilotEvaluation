#https://leetcode.com/problems/minimum-genetic-mutation/
#A gene string can be represented by an 8-character long string, with choices from 'A', 'C', 'G', and 'T'.
#Suppose we need to investigate a mutation from a gene string startGene to a gene string endGene where one mutation is defined as one single character changed in the gene string.
#For example, "AACCGGTT" --> "AACCGGTA" is one mutation.
#There is also a gene bank bank that records all the valid gene mutations. A gene must be in bank to make it a valid gene string.
#Given the two gene strings startGene and endGene and the gene bank bank, return the minimum number of mutations needed to mutate from startGene to endGene. If there is no such a mutation, return -1.
#Note that the starting point is assumed to be valid, so it might not be included in the bank.


class Solution(object):
    def minMutation(self, startGene, endGene, bank):
        """
        :type startGene: str
        :type endGene: str
        :type bank: List[str]
        :rtype: int
        """      
        if endGene not in bank:
            return -1
        bank = set(bank)
        queue = collections.deque([(startGene, 0)])
        while queue:
            gene, step = queue.popleft()
            if gene == endGene:
                return step
            for i in range(8):
                for c in 'ACGT':
                    new_gene = gene[:i] + c + gene[i+1:]
                    if new_gene in bank:
                        bank.remove(new_gene)
                        queue.append((new_gene, step + 1))
        return -1

        

    