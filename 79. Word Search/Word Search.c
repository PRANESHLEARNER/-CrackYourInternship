#include <stdbool.h>

bool search(char** board, int boardSize, int* boardColSize, int i, int j, char* word, int index) {
    if (word[index] == '\0') return true; // End of word reached successfully
    if (i < 0 || i >= boardSize || j < 0 || j >= boardColSize[i] || board[i][j] != word[index]) return false; // Out of bounds or not a match

    char temp = board[i][j]; // Save the character
    board[i][j] = '*'; // Mark as visited

    // Explore all adjacent cells
    if (search(board, boardSize, boardColSize, i + 1, j, word, index + 1) ||
        search(board, boardSize, boardColSize, i - 1, j, word, index + 1) ||
        search(board, boardSize, boardColSize, i, j + 1, word, index + 1) ||
        search(board, boardSize, boardColSize, i, j - 1, word, index + 1)) {
        return true;
    }

    board[i][j] = temp; // Restore the character
    return false;
}

bool exist(char** board, int boardSize, int* boardColSize, char* word) {
    for (int i = 0; i < boardSize; i++) {
        for (int j = 0; j < boardColSize[i]; j++) {
            if (search(board, boardSize, boardColSize, i, j, word, 0)) {
                return true; // Start the search from each cell
            }
        }
    }
    return false;
}