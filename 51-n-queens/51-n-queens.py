class Solution:
    def solveNQueens(self, n: int) -> List[List[str]]:
        def in_range(r, c):
            return 0 <= r < n and 0 <= c < n
        
        def validate(r, c, board):
            for i in range(c):
                if board[r][i] == 'Q':
                    return False
            
            for i in range(1, c + 1):
                if not in_range(r - i, c - i):
                    break
                if board[r - i][c - i] == 'Q':
                    return False
            
            for i in range(1, c + 1):
                if not in_range(r + i, c - i):
                    break
                if board[r + i][c - i] == 'Q':
                    return False
            return True
        
        def help(col, board):
            if col == n:
                res.append([''.join(line) for line in board])
                return
            
            for row in range(n):
                if validate(row, col, board):
                    board[row][col] = 'Q'
                    help(col + 1, board)
                    board[row][col] = '.'
                    
        res = []
        board = [['.' for _ in range(n)] for _ in range(n)]
        help(0, board)
        return res
        