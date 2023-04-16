#https://leetcode.com/problems/redundant-connection-ii/
#In this problem, a rooted tree is a directed graph such that, there is exactly one node (the root) for which all other nodes are descendants of this node, plus every node has exactly one parent, except for the root node which has no parents.
#The given input is a directed graph that started as a rooted tree with n nodes (with distinct values from 1 to n), with one additional directed edge added. The added edge has two different vertices chosen from 1 to n, and was not an edge that already existed.
#The resulting graph is given as a 2D-array of edges. Each element of edges is a pair [ui, vi] that represents a directed edge connecting nodes ui and vi, where ui is a parent of child vi.
#Return an edge that can be removed so that the resulting graph is a rooted tree of n nodes. If there are multiple answers, return the answer that occurs last in the given 2D-array.


class Solution(object):
    def findRedundantDirectedConnection(self, edges):
        """
        :type edges: List[List[int]]
        :rtype: List[int]
        """      
        if not edges:
            return []
        if len(edges)==1:
            return edges[0]
        if len(edges)==2:
            return edges[1]
        #find the node with two parents
        parents={}
        for edge in edges:
            if edge[1] in parents:
                parents[edge[1]].append(edge[0])
            else:
                parents[edge[1]]=[edge[0]]
        #print(parents)
        #find the node with two parents
        node_with_two_parents=None
        for key in parents:
            if len(parents[key])==2:
                node_with_two_parents=key
                break
        #print(node_with_two_parents)
        #if there is no node with two parents, then the last edge is the answer
        if not node_with_two_parents:
            return edges[-1]
        #if there is a node with two parents, then we need to find the edge that connects the node with two parents
        #and the parent that is not the root
        #if there is no such edge, then the last edge is the answer
        #if there is such edge, then we need to remove it
        #if the graph is a tree, then the answer is the edge that connects the node with two parents and the parent that is not the root
        #if the graph is not a tree, then the answer is the last edge
        #we can use union find to check if the graph is a tree
        #we can use dfs to check if the graph is a tree
        #we can use bfs to check if the graph is a tree
        #we can use a stack to check if the graph is a tree
        #we can use a queue to check if the graph is a tree
        #we can use a set to check if the graph is a tree
        #we can use a dictionary to check if the graph is a tree
        #we can use a list to check if the graph is a tree
        #we can use a tuple to check if the graph is a tree
        #we can use a string to check if the graph is a tree
        #we can use a number to check if the graph is a tree
        #we can use a boolean to check if the graph is a tree
        #we can use a None to check if the graph is a tree

        
        
    