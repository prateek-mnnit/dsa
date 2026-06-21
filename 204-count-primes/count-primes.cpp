class Solution {
public:
    bool isPrime(int num, vector<int>& vec, int n){
        if(vec[num]==1){
            for(int j=2*num; j<n; j+=num){
                vec[j] = 0;
            }
            return true;
        }    
        return false;
    }
    int countPrimes(int n) {
        vector<int> vec(n+1,1);

        int count = 0;
        
        for(int i=2; i<n; i++){
            if(isPrime(i,vec,n))
                count++;
        }  

        return count; 
    }
};