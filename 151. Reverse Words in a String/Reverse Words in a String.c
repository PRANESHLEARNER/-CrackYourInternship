char* reverseWords(char* s) {
    int len = strlen(s);
    char* result = (char*)malloc((len + 1) * sizeof(char));
    int i = len - 1, j = len;
    int index = 0;
    while (i >= 0) {
        if (s[i] == ' ') {
            j = i;
        } else if (i == 0 || s[i - 1] == ' ') {
            if (index != 0) {
                result[index++] = ' ';
            }
            strncpy(result + index, s + i, j - i);
            index += j - i;
        }
        i--;
    }
    result[index] = '\0';
    return result;
}