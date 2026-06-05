class Solution {
public:
    double f(double x, int n){
        if(n == 0){
            return 1;
        }
        else{
            if(n%2 == 0){
                double temp = f(x,n/2);
                return temp*temp;
            }
            else{
                double temp = f(x,n/2);
                return temp*temp*x;
            }
        }
    }
    double myPow(double x, int n) {
        if(n>=0){
            return f(x,n);
        }
        else{
            long long N = n;
            N = -N;
            return 1/f(x,N);
        }
    }
};