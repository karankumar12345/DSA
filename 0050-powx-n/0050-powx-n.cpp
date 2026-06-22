class Solution {
public:
    double power(double x, long long n) {
        // Base case
        if (n == 0) return 1.0;

        // Even power
        if (n % 2 == 0) {
            return power(x * x, n / 2);
        }

        // Odd power
        return x * power(x, n - 1);
    }

    double myPow(double x, int n) {
        long long N = n;   // To handle INT_MIN

        // Handle negative powers
        if (N < 0) {
            x = 1.0 / x;
            N = -N;
        }

        return power(x, N);
    }
};