class Solution:
    def numIslands(self, grid: List[List[str]]) -> int:
        if not grid:
            return 0
        
        rows, cols = len(grid), len(grid[0])
        island_count = 0

        def sink_island(row, col):
            if row < 0 or col < 0 or row >= rows or col >= cols or grid[row][col] == "0":
                return
            
            grid[row][col] = "0"

            sink_island(row, col - 1)
            sink_island(row, col + 1)
            sink_island(row- 1, col)
            sink_island(row + 1, col)

        
        for r in range(rows):
            for c in range(cols):
                if grid[r][c] == "1":
                    island_count += 1
                    sink_island(r, c)
                
            
        return island_count
