bool isValid(char* s) {
    int n = strlen(s);
    if (n % 2 == 1) return false;

    int stack[n];
    int top = -1;

    for (int i = 0; i < n; i++) {
        if (s[i] == '(' || s[i] == '{' || s[i] == '[') {
            stack[++top] = s[i];
        } else {
            if (top == -1) return false;
            if (s[i] == ')' && stack[top--] != '(') return false;
            if (s[i] == '}' && stack[top--] != '{') return false;
            if (s[i] == ']' && stack[top--] != '[') return false;
        }
    }

    return top == -1;
}