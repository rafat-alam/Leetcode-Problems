class Solution {
public:
    int mirrorDistance(int n) {
        long long t = n;
        long long r = 0;
        while(n > 0) {
            r *= 10;
            r += (n % 10);
            n /= 10;
        }

        return abs(t - r);
    }
};