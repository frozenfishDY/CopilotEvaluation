#https://leetcode.com/problems/shortest-path-to-get-all-keys/
#You are given an m x n grid grid where:
#'.' is an empty cell.
#'#' is a wall.
#'@' is the starting point.
#Lowercase letters represent keys.
#Uppercase letters represent locks.
#You start at the starting point and one move consists of walking one space in one of the four cardinal directions. You cannot walk outside the grid, or walk into a wall.
#If you walk over a key, you can pick it up and you cannot walk over a lock unless you have its corresponding key.
#For some 1 <= k <= 6, there is exactly one lowercase and one uppercase letter of the first k letters of the English alphabet in the grid. This means that there is exactly one key for each lock, and one lock for each key; and also that the letters used to represent the keys and locks were chosen in the same order as the English alphabet.
#Return the lowest number of moves to acquire all keys. If it is impossible, return -1.


class Solution(object):
    def shortestPathAllKeys(self, grid):
        """
        :type grid: List[str]
        :rtype: int
        """      
        if not grid or not grid[0]:
            return -1
        m, n = len(grid), len(grid[0])
        start = None
        keys = set()
        for i in range(m):
            for j in range(n):
                if grid[i][j] == '@':
                    start = (i, j)
                elif grid[i][j] in string.ascii_lowercase:
                    keys.add(grid[i][j])
        q = collections.deque([(start, 0, set())])
        visited = set()
        while q:
            (x, y), step, cur_keys = q.popleft()
            if (x, y, tuple(sorted(cur_keys))) in visited:
                continue
            visited.add((x, y, tuple(sorted(cur_keys))))
            if len(cur_keys) == len(keys):
                return step
            for dx, dy in [(0, 1), (0, -1), (1, 0), (-1, 0)]:
                nx, ny = x + dx, y + dy
                if 0 <= nx < m and 0 <= ny < n and grid[nx][ny] != '#':
                    if grid[nx][ny] in string.ascii_lowercase:
                        q.append(((nx, ny), step + 1, cur_keys | set([grid[nx][ny]])))
                    elif grid[nx][ny] in string.ascii_uppercase:
                        if grid[nx][ny].lower() in cur_keys:
                            q.append(((nx, ny), step + 1, cur_keys))
                    else:
                        q.append(((nx, ny), step + 1, cur_keys))
        return -1

        
        
    