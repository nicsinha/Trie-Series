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
    bool getEnd()
    {
        return flag;
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

    bool checkIfPrefixExist(string word) 
    {
        bool ans = true;
        Node* temp = root;
        for(int i=0;i<word.length();i++)
        {
            if(temp->containKey(word[i]))
            {
                temp = temp->next(word[i]);
                if(!temp->getEnd())
                {
                    return false;
                }
            }
            else {
                return false;
            }
        }
        return true;
    }
    
};

string completeString(int n,vector<string> &a)
{
    string ans = "";
    Trie trie;

    for(auto &it:a){
        trie.insert(it);
    }

    for(auto &it:a) {

        if(trie.checkIfPrefixExist(it)) {

            if(it.length() > ans.length()) {
                ans = it;
            }
            else if(it.length() == ans.length() && it<ans) {

                ans = it;
            }

        }
    }
}