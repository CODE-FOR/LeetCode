class Solution(object):
    def exist(self, board, word):
        """
        :type board: List[List[str]]
        :type word: str
        :rtype: bool
        """
        visited = [[False for __ in range(len(board[0]))] for _ in range(len(board))]
        bitmask = 0
        bitmask_set = set()
        line_len = len(board)
        row_len = len(board[0])
        def find(board, word, pos_in_word, x, y, bitmask):
            if pos_in_word == len(word):
                return True
            if (bitmask, x, y) in bitmask_set:
                return False
            bitmask_set.add((bitmask, x, y))
            if x - 1 >= 0 and not visited[x - 1][y] and board[x - 1][y] == word[pos_in_word]:
                visited[x][y] = True
                res = find(board, word, pos_in_word + 1, x - 1, y, bitmask | (1 << ((x - 1) * row_len + y)))
                if res:
                    return True
                visited[x][y] = False
            if x + 1 < line_len and not visited[x + 1][y] and board[x + 1][y] == word[pos_in_word]:
                visited[x][y] = True
                res = find(board, word, pos_in_word + 1, x + 1, y, bitmask | (1 << ((x + 1) * row_len + y)))
                if res:
                    return True
                visited[x][y] = False
            if y - 1 >= 0 and not visited[x][y - 1] and board[x][y - 1] == word[pos_in_word]:
                visited[x][y] = True
                res = find(board, word, pos_in_word + 1, x, y - 1, bitmask | (1 << (x * row_len + y - 1)))
                if res:
                    return True
                visited[x][y] = False
            if y + 1 < row_len and not visited[x][y + 1] and board[x][y + 1] == word[pos_in_word]:
                visited[x][y] = True
                res = find(board, word, pos_in_word + 1, x, y + 1, bitmask | (1 << (x * row_len + y + 1)))
                if res:
                    return True
                visited[x][y] = False
            return False

        for x in range(len(board)):
            for y in range(len(board[0])):
                if board[x][y] == word[0]:
                    bitmask |= (1 << (x * len(board[0]) + y))
                    res = find(board, word, 1, x, y, bitmask)
                    if res:
                        return True
                    bitmask = 0
        return False