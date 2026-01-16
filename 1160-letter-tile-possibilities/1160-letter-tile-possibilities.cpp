class Solution {
public:
    int f(map<char, int> &mp, set<char> st) {
        if(!st.size()) return 0;

        int ans = st.size();
        for(auto &[aa, bb] : mp) {
            if(bb == 0) continue;
            
            mp[aa]--;
            if(bb == 0) st.erase(aa);

            ans += f(mp, st);
            if(bb == 0) st.insert(aa);
            mp[aa]++;
        }

        return ans;
    }
    int numTilePossibilities(string tiles) {
        map<char, int> mp; set<char> st;
        for(auto &ch : tiles) st.insert(ch);
        for(auto &ch : tiles) mp[ch]++;

        return f(mp, st);
    }
};