class Solution {
public:
    long long countPairs(vector<string>& words) {
        map<string, int> mp;
        for(auto &word : words) {
            int shift = word[0] - 'a';
            
            for(auto &w : word) {
                w = char((w - 'a' - shift + 26) % 26 + 'a');
            }
            mp[word]++;
        }
        long long ans = 0;
        for(auto &[aa, bb] : mp) {
            ans += (bb * (bb - 1LL)) / 2;
        }
        return ans;
    }
};