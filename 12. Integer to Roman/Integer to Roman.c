char* intToRoman(int num) {
    // Define an array of strings for each digit
    char* thousands[] = {"", "M", "MM", "MMM"};
    char* hundreds[] = {"", "C", "CC", "CCC", "CD", "D", "DC", "DCC", "DCCC", "CM"};
    char* tens[] = {"", "X", "XX", "XXX", "XL", "L", "LX", "LXX", "LXXX", "XC"};
    char* ones[] = {"", "I", "II", "III", "IV", "V", "VI", "VII", "VIII", "IX"};

    // Allocate memory for the result string
    char* result = (char*)malloc(sizeof(char) * 16);
    // Initialize the result string as empty
    result[0] = '\0';

    // Append the roman numerals for each digit
    strcat(result, thousands[num / 1000]);
    strcat(result, hundreds[(num % 1000) / 100]);
    strcat(result, tens[(num % 100) / 10]);
    strcat(result, ones[num % 10]);

    // Return the result string
    return result;
}