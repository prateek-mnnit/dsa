class Solution {
public:
    int divide(int dividend, int divisor) {
        if(dividend == divisor){
            return 1;
        }
        if(dividend == INT_MIN && divisor == -1) return INT_MAX;
        bool sign = true;

        if(dividend < 0 && divisor > 0) sign = false;
        else if(dividend > 0 && divisor < 0) sign = false;

        long n = abs((long)dividend);
        long d = abs((long)divisor);

        long ans = 0;
        int count = 0;

        while(n >= d){
            count = 0;
            while((d<<(count+1)) <= n){
                count++;
            }
            ans = ans + (1<<count);
            n = n - (d<<count);
        }

        if(ans == (1<<31) && sign){
            return INT_MAX;
        }
        if(ans == (1<<31) && !sign){
            return INT_MIN;
        }

        

        if(sign){
            return ans;
        }
        else{
            return -ans;
        }




        // if (dividend == 0)
        //     return 0;
        // if (divisor == 1)
        //     return dividend;
        // if (divisor == -1) {
        //     if (dividend == INT_MIN)
        //         return INT_MAX;
        //     return -dividend;
        // }

        // long long dvd = llabs((long long)dividend);
        // long long dvs = llabs((long long)divisor);

        // long long count = 0;

        // while (dvd >= dvs) {
        //     dvd -= dvs;
        //     count++;
        // }

        // bool negative =
        //     (dividend < 0 && divisor > 0) || (dividend > 0 && divisor < 0);

        // if (negative) {
        //     count = -count;
        // }

        // return (int)count;
    }
};