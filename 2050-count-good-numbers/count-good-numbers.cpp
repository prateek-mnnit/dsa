class Solution {
public:
    long long MOD = 1000000007;
    long long f(int x, long long n){
        if(n == 0){
            return 1;
        }
        else{
            if(n%2 == 0){
                long long temp = f(x,n/2);
                return temp*temp % MOD;
            }
            else{
                long long temp = f(x,n/2);
                return temp*temp*x % MOD;
            }
        }
    }
    int countGoodNumbers(long long n) {
        long long N = n/2;
        if(n%2 == 0){
            return f(5,N)*f(4,N) % MOD;
        }else{
            return f(5,N+1)*f(4,N) % MOD;
        }
    }
};