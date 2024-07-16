int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    int* result = (int*)malloc(matrixSize * (*matrixColSize) * sizeof(int));
    *returnSize = 0;
    int left = 0, right = *matrixColSize - 1, top = 0, bottom = matrixSize - 1;
    while (*returnSize < matrixSize * (*matrixColSize)) {
        for (int i = left; i <= right && *returnSize < matrixSize * (*matrixColSize); i++) {
            result[(*returnSize)++] = matrix[top][i];
        }
        top++;
        for (int i = top; i <= bottom && *returnSize < matrixSize * (*matrixColSize); i++) {
            result[(*returnSize)++] = matrix[i][right];
        }
        right--;
        for (int i = right; i >= left && *returnSize < matrixSize * (*matrixColSize); i--) {
            result[(*returnSize)++] = matrix[bottom][i];
        }
        bottom--;
        for (int i = bottom; i >= top && *returnSize < matrixSize * (*matrixColSize); i--) {
            result[(*returnSize)++] = matrix[i][left];
        }
        left++;
    }
    return result;
}