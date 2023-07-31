def shortest_path_grid(grid, start, goal):
    '''
    Function that returns the length of the shortest path in a grid
    that HAS obstacles represented by 1s. The length is simply the number
    of cells on the path including the 'start' and the 'goal'

    :param grid: list of lists (represents a square grid where 0 represents free space and 1s obstacles)
    :param start: tuple of start index
    :param goal: tuple of goal index
    :return: length of path
    (row, column)
    '''

    n = len(grid)

    # use BFS to find shortest path
    visited = []    
    queue = [start]
    reached_goal = False
    dist_from_start = {start: 0}

    while len(queue) != 0: # while queue not empty
        node = queue.pop(0) # pop from start of queue
        visited.append(node) # marking node as visited
        
              
        # add adjacent indexes to the queue
        r = node[0]
        c = node[1]

        if r + 1 < n and (r+1, c) not in queue and (r+1, c) not in visited: # not already in queue, not visited, and valid grid index
            if grid[r+1][c] != 1: # no obstacle in the way
                #print(1)
                queue.append((r + 1, c))
                dist_from_start[(r + 1, c)] = dist_from_start[node] + 1
                
        if r - 1 >= 0 and (r-1, c) not in queue and (r-1, c) not in visited:
            if grid[r-1][c] != 1:
                #print(2)
                queue.append((r - 1, c))
                dist_from_start[(r - 1, c)] = dist_from_start[node] + 1
                
        if c + 1 < n and (r, c+1) not in queue and (r, c+1) not in visited:
            if grid[r][c+1] != 1:
                #print(3)
                queue.append((r, c + 1))
                dist_from_start[(r, c + 1)] = dist_from_start[node] + 1
                
        if c - 1 >= 0 and (r, c-1) not in queue and (r, c-1) not in visited:
            if grid[r][c-1] != 1:
                #print(4)
                queue.append((r, c - 1))
                dist_from_start[(r, c - 1)] = dist_from_start[node] + 1

        if goal in queue: # reached goal
            reached_goal = True
            dist_from_start[goal] = dist_from_start[node] + 1
            break

    if reached_goal == False:
        return -1
    
    return dist_from_start[goal]+1 
    

if __name__ == "__main__":

    grid = [[0,0,0],
            [1,1,0],
            [1,1,0]]
    start, goal = (0,1), (2,2)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == 4

    grid = [[0,1],
            [1,0]]
    start, goal = (0, 0), (1,1)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == -1
    '''
    grid = [[0,0,0],
            [0,1,1],
            [0,0,0]]
    start, goal = (0, 1), (2,2)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == 6
    '''

