class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:            
        res = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        help(0, board,res, n)
        return res
def in_range(r, c,n):
            return 0 <= r < n and 0 <= c < n
        
def validate(r, c, board,n):
    for i in range(c):
        if board[r][i] == 'Q':
            return False

    for i in range(1, c + 1):
        if not in_range(r - i, c - i, n):
            break
        if board[r - i][c - i] == 'Q':
            return False

    for i in range(1, c + 1):
        if not in_range(r + i, c - i, n):
            break
        if board[r + i][c - i] == 'Q':
            return False
    return True

def help(col, board,res, n):
    if col == n:
        res.append([''.join(line) for line in board])
        return

    for row in range(n):
        if validate(row, col, board,n):
            board[row][col] = 'Q'
            help(col + 1, board,res,n)
            board[row][col] = '.'
