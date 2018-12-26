#include <iostream>
#include <string>
#include <vector>

using namespace std;

//suppose we only support chars between 'a' and 'z'
const int MAX_SIZE = 26;

struct trieNode {
    trieNode* subs[MAX_SIZE];
    bool isEnd;
};

//create new trie node
trieNode* getNode() {
    trieNode* trie = new trieNode();

    for (int i=0; i<MAX_SIZE; ++i) {
        trie->subs[i] = nullptr;
    }
    trie->isEnd = false;
    return trie;
}

//inserts string to our trieNode
void insert(trieNode* root, string text) {
    trieNode* node = root;

    for (char c : text) {
        int index = c - 'a';

        if (!node->subs[index]) {
            node->subs[index] = getNode();
        }
        node = node->subs[index];
    }
    node->isEnd = true;
}

//checks whether string exists or not 
bool exist(trieNode* root, string text) {
    trieNode* node = root;

    for (char c : text) {
        int index = c - 'a';
        if (!node->subs[index]) {
            return false;
        }
        node = node->subs[index];
    }

    return (nullptr != node && node->isEnd);
}

//reports existency of the text
void report(trieNode* root, string text) {
    cout << "'" << text << "' is exist: " << (exist(root, text) ? "yes" : "no") << endl;
}

int main() {

    vector<string> texts = {"the", "their", "by", "bye", "one", "two" };
    trieNode* root = getNode();  //create a new trie

    //insert each text
    for (string s : texts)
        insert(root, s);

    //search
    report(root, "the");
    report(root, "they");
    report(root, "their");
    report(root, "theirs");
    report(root, "apple");
    report(root, "oneday");
    report(root, "one");
    report(root, "b");
    report(root, "by");

    return 0;
}