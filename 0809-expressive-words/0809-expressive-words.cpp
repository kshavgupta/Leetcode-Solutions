class Solution {
public:
    bool check(string S, string W) {
        int n = S.size(), m = W.size(), i = 0, j = 0;
        for (int i2 = 0, j2 = 0; i < n && j < m; i = i2, j = j2) {
            if (S[i] != W[j]) return false;
            while (i2 < n && S[i2] == S[i]) i2++;
            while (j2 < m && W[j2] == W[j]) j2++;
            if (i2 - i != j2 - j && i2 - i < max(3, j2 - j)) return false;
        }
        return i == n && j == m;
    }
    
    int expressiveWords(string s, vector<string>& w) {
        int ans = 0;
        for(int i = 0; i < w.size(); i++){
            if(check(s, w[i])) ans++;
        }
        return ans;
    }
};