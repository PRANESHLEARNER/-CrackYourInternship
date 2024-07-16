int strStr(char* haystack, char* needle) {
    int m = strlen(haystack), n = strlen(needle);
    if (n == 0) return 0;

    for (int i = 0; i <= m - n; i++) {
        int j;
        for (j = 0; j < n; j++) {
            if (haystack[i + j] != needle[j]) break;
        }
        if (j == n) return i;
    }

    return -1;
}