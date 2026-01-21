class Solution {
public:
    int minSteps(string s, string t) {
        multiset<char> st;
        for(auto &ch : s) {
            st.insert(ch);
        }
        for(auto &ch : t) {
            if(st.find(ch) != st.end()) {
                st.erase(st.find(ch));
            }
        }
        return st.size();
    }
};