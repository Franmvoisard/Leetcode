struct TrieNode {
public:
    TrieNode* children[26] = {nullptr};
    bool isEndOfWord = false;

    TrieNode() : isEndOfWord(false) {}

    ~TrieNode() {
        for (auto& node : children) {
            delete node;
        }
    }
};

class Trie {
public:
    TrieNode* rootNode;
    Trie() { rootNode = new TrieNode(); }

    ~Trie() { delete rootNode; }

    //Time: O( word.size() )
    //Space: O( word.size() )
    void insert(string word) {
        TrieNode* node = rootNode;
        for (int i = 0; i < word.size(); i++) {
            int c = word[i] - 'a';
            if (node->children[c]) {
                node = node->children[c];
            } else {
                node->children[c] = new TrieNode();
                node = node->children[c];
            }
        }
        node->isEndOfWord = true;
    }

    //Time: O( word.size() )
    //Space: O( 1 )
    bool search(string word) {
        TrieNode* node = rootNode;
        for (int i = 0; i < word.size(); i++) {
            int c = word[i] - 'a';
            if (node->children[c]) {
                node = node->children[c];
            } else {
                return false;
            }
        }
        return node->isEndOfWord;
    }
    //Time: O( prefix.size() )
    //Space: O( 1 )
    bool startsWith(string prefix) {
        TrieNode* node = rootNode;
        for (int i = 0; i < prefix.size(); i++) {
            int c = prefix[i] - 'a';
            if (node->children[c]) {
                node = node->children[c];
            } else {
                return false;
            }
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
