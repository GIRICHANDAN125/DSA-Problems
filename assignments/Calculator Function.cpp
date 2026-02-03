double calculator(double a, double b, char op) {
    if (op == '+') return a + b;
    else if (op == '-') return a - b;
    else if (op == '*') return a * b;
    else if (op == '/') {
        if (b == 0) return 0;
        return a / b;
    }
    return 0;
}
