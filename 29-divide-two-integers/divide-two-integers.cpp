class Solution {
public:
    int divide(int dividend, int divisor) {

        if (dividend == 0)
            return 0;
        if (divisor == 1)
            return dividend;
        if (divisor == -1) {
            if (dividend == INT_MIN)
                return INT_MAX;
            return -dividend;
        }

        long long dvd = llabs((long long)dividend);
        long long dvs = llabs((long long)divisor);

        long long count = 0;

        while (dvd >= dvs) {
            dvd -= dvs;
            count++;
        }

        bool negative =
            (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);

        if (negative) {
            count = -count;
        }

        return (int)count;
    }
};