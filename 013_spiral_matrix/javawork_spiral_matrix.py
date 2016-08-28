def initVisited(w,h):
    visited = []
    for i in range(w):
        l = []
        for j in range(h):
            l.append(False)
        visited.append(l)
    return visited

def spiralOrder(matrix):
    h = len(matrix)
    if h == 0:
        return []
    if h <= 1:
        return matrix[0]
    w = len(matrix[0])
    i = 0; j = 0; d = 0
    result = []
    mask = [[1,0],[0,1],[-1,0],[0,-1]]
    visited = initVisited(w,h)
    for idx in range(w*h):
        result.append(matrix[j][i])
        visited[i][j] = True
        if d == 0 and i+1 >= w:
            d = (d+1)%4
        elif d == 1 and j+1 >= h:
            d = (d+1)%4
        elif d == 2 and i <= 0:
            d = (d+1)%4
        elif d == 3 and j <= 0:
            d = (d+1)%4
        if visited[i+mask[d][0]][j+mask[d][1]]:
            d = (d+1)%4
        i += mask[d][0]
        j += mask[d][1]
    return result

matrix = [[1,2,3],[4,5,6],[7,8,9]]
#matrix = [[1,2,3,4],[5,6,7,8],[9,10,11,12]]
#matrix = [[1,2,3]]
#matrix = [[1],[2]]
#matrix = []

print spiralOrder(matrix)