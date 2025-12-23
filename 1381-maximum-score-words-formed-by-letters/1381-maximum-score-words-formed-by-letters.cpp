class Solution {
public:
    int maxScoreWords(vector<string>& words, vector<char>& letters, vector<int>& score) {
        map<int, int> mp;
        for(int i = 0; i < 26; i++) mp[i] = score[i];

        map<int, int> av;
        for(int i = 0; i < letters.size(); i++) av[letters[i] - 'a']++;

        map<int, int> cur;
        int ans = 0;

        function<void (int i)> f = [&](int i) -> void {
            if(i >= words.size()) {
                int sc = 0;
                for(auto &[aa, bb] : cur) {
                    if(av[aa] < bb) sc = -1e9;
                    else sc += mp[aa] * bb;
                }
                ans = max(ans, sc);
                return;
            }
            for(auto &ch : words[i]) {
                cur[ch - 'a']++;
            }
            f(i + 1);
            for(auto &ch : words[i]) {
                cur[ch - 'a']--;
            }
            f(i + 1);
        };
        f(0);

        return ans;
    }
};