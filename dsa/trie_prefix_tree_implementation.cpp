#include<bits/stdc++.h>
using namespace std;

struct TrieNode {
    TrieNode *child[26];
    bool wordEnd = false;
};

class Trie {
    TrieNode *root;
public:
    Trie() {
        root = new TrieNode();
        root->wordEnd = false;
        for(int i = 0; i < 26; i++) {
            root->child[i] = NULL;
        }
    }
    
    void insert(string word) {
        TrieNode *curr = root;
        for(char c: word) {
            if(curr->child[c-'a'] == NULL) {
                // new node
                TrieNode* node = new TrieNode();
                curr->child[c-'a'] = node; 
            }
            curr = curr->child[c-'a'];
        }
        curr->wordEnd = true;
    }
    
    bool search(string word) {
        TrieNode *curr = root;
        for(char c: word) {
            if(curr->child[c-'a'] == NULL) {
                return false;
            }
            curr = curr->child[c-'a'];
        }
        return curr->wordEnd;
    }
    
    bool startsWith(string prefix) {
        TrieNode *curr = root;
        for(char c: prefix) {
            if(curr->child[c-'a'] == NULL) {
                return false;
            }
            curr = curr->child[c-'a'];
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */

int main() {
  Trie t;
  vector<string> arr = {"and", "ant", "do", "geek", "dad", "ball"};
  for (const string& s : arr) {
      t.insert(s);
  }

  // One by one search strings
  vector<string> searchKeys = {"do", "gee", "bat"};
  for (string& s : searchKeys) {
      cout << "Key : " << s << "\t";
      if (t.search(s)) 
          cout << "Present\n";
      else 
         cout << "Not Present\n";        
    }
    
  // Starts with string prefix
  cout << endl;
  vector<string> keys = {"do", "gee", "bat"};
  for (string& s : keys) {
      cout << "Key starts with : " << s << "\t";
      if (t.startsWith(s)) 
          cout << "Present\n";
      else 
         cout << "Not Present\n";        
    }
    return 0;
}
