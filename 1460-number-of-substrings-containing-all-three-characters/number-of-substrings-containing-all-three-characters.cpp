class Solution {
public:

    int numberOfSubstrings(string s) {
        int n = s.size();
        vector<int> v(3,-1);

        int count = 0;
        
        for(int i=0; i<n; i++){
            v[s[i]-'a'] = i;
            
            if(v[0]>=0 && v[1]>=0 && v[2]>=0){
                int mini = *min_element(v.begin(),v.end());
                count = count + mini + 1;
            }
            
        }

        return count;
        
    }
};

// int calculate(string s) {
    //     int s = s.size();
    //     int l = 0, r = 0;
    //     int count = 0;
    //     int a = 0, b = 0, c = 0;

    //     while(r<n){
    //         if(s[r] == 'a'){
    //             a++;
    //         }
    //         if(s[r] == 'b'){
    //             b++;
    //         }
    //         if(s[r] == 'c'){
    //             c++;
    //         }

            
    //     }
    // }