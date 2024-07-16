/**
 * Note: The returned array must be malloced, assume caller calls free().
 */
void backtrack(char** ans, char* cur, int open, int close, int max, int* returnSize){
    if(strlen(cur) == max * 2){
        ans[*returnSize] = malloc(sizeof(char) * 2 * max + 1);
        strcpy(ans[*returnSize], cur);
        (*returnSize)++;
        return;
    }

    if(open < max){
        strcat(cur, "(");
        backtrack(ans, cur, open + 1, close, max, returnSize);
        cur[strlen(cur) - 1] = '\0';
    }
    if(close < open){
        strcat(cur, ")");
        backtrack(ans, cur, open, close + 1, max, returnSize);
        cur[strlen(cur) - 1] = '\0';
    }
}

char** generateParenthesis(int n, int* returnSize){
    char** result = (char**)malloc(sizeof(char*) * 17000);
    *returnSize = 0;
    char* current = (char*)calloc(2 * n + 1, sizeof(char));
    backtrack(result, current, 0, 0, n, returnSize);
    free(current);
    return result;
}