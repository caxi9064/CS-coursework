def shortest_path_grid(grid, start, goal):
    '''
    Function that returns the length of the shortest path in a grid
    that has no obstacles. The length is simply the number of cells
    on the path including the 'start' and the 'goal'

    :param grid: list of lists (represents a square grid)
    :param start: tuple of start index
    :param goal: tuple of goal index
    :return: length of path
    '''
    n = len(grid)

    for index in range(1): # make sure start and stop are valid in the grid
        if start[index] < 0 or goal[index] < 0:
            return
        if start[index] >= n or goal[index] >= n:
            return
            
    # find the difference between start and stop position for both x and y index
    difference = abs(goal[0]-start[0]) + abs(goal[1]-start[1]) 
    return difference+1 # start position (0,0) not counted so add 1


if __name__ == "__main__":
    grid = [[0,0,0],
            [0,0,0],
            [0,0,0]]
    start, goal = (2,1), (0,0)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == 4

    grid = [[0,0,0],
            [0,0,0],
            [0,0,0]]
    start, goal = (2,2), (0,0)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == 5

    grid = [[0,0,0],
            [0,0,0],
            [0,0,0]]
    start, goal = (0,2), (0,0)
    print(shortest_path_grid(grid, start, goal))
    assert shortest_path_grid(grid, start, goal) == 3

