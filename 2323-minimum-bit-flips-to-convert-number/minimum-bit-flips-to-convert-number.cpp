class Solution {
public:
    int minBitFlips(int start, int goal) {
        int n = 0;
        n = (start ^ goal);

        int count = 0;
        while (n) {
            count += (n & 1);
            n = n >> 1;
        }

        return count;
    }
};