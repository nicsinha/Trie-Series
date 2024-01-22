#include<bits/stdc++.h>
using namespace std;

class Node {
    public:
    Node* links[26];
    bool flag = false;

    bool containKey(char ch) {
        return links[ch - 'a'] != NULL;
    }

    void put(char ch, Node* node)
    {
        links[ch - 'a'] = node;
    }

    Node* next(char ch) {
        return links[ch - 'a'];
    }

    void setEnd()
    {
        flag = true;
    }

};

class Trie {

    private:

    Node* root;

    public:

    Trie() {
        root = new Node();
    }

    void insert(string word)
    {
        Node *temp = root;
        for(int i=0;i<word.length();i++)
        {
            if(!temp->containKey(word[i]))
            {
                temp->put(word[i], new Node()); 
            }
            // move to the next reference trie.
            temp = temp->next(word[i]);  

        }
        cout<<word<<"   inserted into Trie"<<endl;
        temp->setEnd();
    }


};