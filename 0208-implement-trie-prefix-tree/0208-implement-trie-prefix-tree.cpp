class TrieNode{
  public:
    vector<TrieNode*> dict;
    bool isEnd;
    TrieNode(){
        isEnd = false;
        dict.resize(26, nullptr);
    }
};
class Trie {
public:
    TrieNode* root;
    
    /** Initialize your data structure here. */
    Trie() {
        root = new TrieNode();
    }
    
    /** Inserts a word into the trie. */
    void insert(string s){
        TrieNode* node = root;
        for(int i = 0; i < s.length(); i++){
            if(node->dict[s[i]-'a'] == NULL){
                node->dict[s[i]-'a'] = new TrieNode();
            }
            node = node->dict[s[i]-'a'];
        }
        node->isEnd = true;
    }
    
    /** Returns if the word is in the trie. */
    bool search(string s){
        TrieNode* node = root;
        for(int i = 0; i < s.length(); i++){
            if(node->dict[s[i]-'a'] == NULL) return false;
            node = node->dict[s[i]-'a'];
        }
        return node->isEnd;
    }
    
    /** Returns if there is any word in the trie that starts with the given prefix. */
    bool startsWith(string s) {
        TrieNode* node = root;
        for(int i=0;i<s.length();i++){
            if(node->dict[s[i]-'a']==nullptr)
                return false;
            node = node->dict[s[i]-'a'];
        }
        return true;
    }
};
