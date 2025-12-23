class Solution {
public:
    int garbageCollection(vector<string>& gg, vector<int>& t) {
        int m = 0, p = 0, g = 0;
        int tm = 0, tp = 0, tg = 0;

        for(int i = 0; i < gg.size(); i++) {
            if(i != 0) {
                tm += t[i - 1];
                tp += t[i - 1];
                tg += t[i - 1];
            }
            for(int j = 0; j < gg[i].size(); j++) {
                if(gg[i][j] == 'M') {
                    m += (tm + 1);
                    tm = 0;
                }
                if(gg[i][j] == 'P') {
                    p += (tp + 1);
                    tp = 0;
                }
                if(gg[i][j] == 'G') {
                    g += (tg + 1);
                    tg = 0;
                }
            }
        }
        return m + p + g;
    }
};