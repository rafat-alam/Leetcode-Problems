class Solution {
public:
    long long minimumCost(int cost1, int cost2, int costBoth, int need1, int need2) {
        long long mi = min(need1, need2);

        long long ans = 0;
        if(cost1 + cost2 > costBoth) {
            ans += (long long) mi * costBoth * 1LL;
        } else {
            ans += (long long) mi * (cost1 + cost2 + 0LL);
        }

        need1 -= mi;
        need2 -= mi;

        if(cost1 > costBoth) {
            ans += (long long)need1 * costBoth * 1LL;
        } else {
            ans += (long long)need1 * cost1 * 1LL;
        }
        if(cost2 > costBoth) {
            ans += (long long)need2 * costBoth * 1LL;
        } else {
            ans += (long long)need2 * cost2 * 1LL;
        }

        return ans;
    }
};