class WordDictionary {
public:
    WordDictionary() {
        root = new TrieNode();
    }
    
    void addWord(string word) {
        TrieNode* node = root;
        for (char c : word) {
            if (!node->children[c - 'a']) {
                node->children[c - 'a'] = new TrieNode();
            }
            node = node->children[c - 'a'];
        }
        node->isWord = true;
    }
    
    bool search(string word) {
        return search(word, root, 0);
    }

private:
    struct TrieNode {
        bool isWord;
        TrieNode* children[26];
        TrieNode() : isWord(false), children() {}
    };
    
    TrieNode* root;
    
    bool search(const string& word, TrieNode* node, int index) {
        if (index == word.size()) {
            return node->isWord;
        }
        if (word[index] != '.') {
            return node->children[word[index] - 'a'] && search(word, node->children[word[index] - 'a'], index + 1);
        } else {
            for (auto& child : node->children) {
                if (child && search(word, child, index + 1)) {
                    return true;
                }
            }
        }
        return false;
    }
};