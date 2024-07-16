/**
 * Return an array of arrays of size *returnSize.
 * The sizes of the arrays are returned as *returnColumnSizes array.
 * Note: Both returned array and *columnSizes array must be malloced, assume caller calls free().
 */
int cmp(const void* a, const void* b) {
    return *(char*)a - *(char*)b;
}


char*** groupAnagrams(char** strs, int strsSize, int* returnSize, int** returnColumnSizes){
    char*** res = (char***)malloc(sizeof(char**) * strsSize);
    *returnColumnSizes = (int*)malloc(sizeof(int) * strsSize);
    char** keys = (char**)malloc(sizeof(char*) * strsSize);
    int* keyLengths = (int*)malloc(sizeof(int) * strsSize);
    int size = 0;
    
    for (int i = 0; i < strsSize; i++) {
        char* key = strdup(strs[i]);
        int length = strlen(key);
        qsort(key, length, sizeof(char), cmp);
        
        int j = 0;
        while (j < size && strcmp(keys[j], key) != 0) {
            j++;
        }
        
        if (j == size) {
            keys[size] = key;
            keyLengths[size] = 1;
            res[size] = (char**)malloc(sizeof(char*));
            res[size][0] = strs[i];
            size++;
        } else {
            keyLengths[j]++;
            res[j] = (char**)realloc(res[j], sizeof(char*) * keyLengths[j]);
            res[j][keyLengths[j] - 1] = strs[i];
            free(key);
        }
    }
    
    free(keys);
    *returnSize = size;
    memcpy(*returnColumnSizes, keyLengths, sizeof(int) * size);
    free(keyLengths);
    return res;
}