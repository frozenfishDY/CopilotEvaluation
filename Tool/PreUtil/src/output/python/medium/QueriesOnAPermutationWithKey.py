#https://leetcode.com/problems/queries-on-a-permutation-with-key/
#Given the array queries of positive integers between 1 and m, you have to process all queries[i] (from i=0 to i=queries.length-1) according to the following rules:
#In the beginning, you have the permutation P=[1,2,3,...,m].
#For the current i, find the position of queries[i] in the permutation P (indexing from 0) and then move this at the beginning of the permutation P. Notice that the position of queries[i] in P is the result for queries[i].
#Return an array containing the result for the given queries.


class Solution(object):
    def processQueries(self, queries, m):
        """
        :type queries: List[int]
        :type m: int
        :rtype: List[int]
        """    
        
        # 1. Create the permutation array
        # 2. Loop through the queries
        # 3. For each query, get the index of the query in the permutation array
        # 4. Remove the query from the permutation array
        # 5. Insert the query at the beginning of the permutation array
        # 6. Add the index to the result
        # 7. Return the result
        permutation = [i for i in range(1, m + 1)]
        result = []
        for query in queries:
            index = permutation.index(query)
            permutation.remove(query)
            permutation.insert(0, query)
            result.append(index)
        return result

        

    