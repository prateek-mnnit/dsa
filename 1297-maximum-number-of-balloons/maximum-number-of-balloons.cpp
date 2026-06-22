class Solution {
public:
    int maxNumberOfBalloons(string text) {
        int n = text.size();
        map<char,int> mp;
        mp['b'];
        mp['a'];
        mp['l'];
        mp['o'];
        mp['o'];
        mp['n'];

        for (int i = 0; i < n; i++) {
            auto it = mp.find(text[i]);

            if (it != mp.end()) {
                it->second++;
            }

        }
        return min({
            mp['b'],
            mp['a'],
            mp['l'] / 2,
            mp['o'] / 2,
            mp['n']
        });
    }
};