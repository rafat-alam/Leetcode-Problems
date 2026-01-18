class Solution {
public:
    int vowelConsonantScore(string s) {
        int v = 0, c = 0;
        for(auto &ch : s) {
            if(ch == 'a' || ch == 'e' || ch == 'i' || ch == 'o' || ch == 'u') {
                v++;
            } else if(ch >= 'a' && ch <= 'z') {
                c++;
            }
        }


        if(c == 0) return 0;
        else return v / c;
    }
};