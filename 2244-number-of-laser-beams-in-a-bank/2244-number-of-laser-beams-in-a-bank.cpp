class Solution {
public:
    int numberOfBeams(vector<string>& bank) {
        vector<int> b;
        for(auto &s : bank) {
            int c = 0;
            for(auto &ch : s) if(ch == '1') c++;
            if(c != 0) b.push_back(c);
        }
        int ans = 0;
        for(int i = 1; i < b.size(); i++) {
            ans += b[i] * b[i - 1];
        }
        return ans;
    }
};