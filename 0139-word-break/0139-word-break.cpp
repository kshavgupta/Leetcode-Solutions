class Solution {
 
public:
    map<string,bool> m;
    bool wordBreak(string s, vector<string>& wordDict) {
        if(find(wordDict.begin(), wordDict.end(), s) != wordDict.end()) return true;
        if(m.find(s) != m.end()) return m[s];
        for(int i=1; i<s.size(); i++){
            string left = s.substr(0,i);
            if(find(wordDict.begin(),wordDict.end(),left) != wordDict.end() && wordBreak(s.substr(i),wordDict)){
                return m[s] = true;
            }
        }
   
        return m[s] = false;
    }
    
};