#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node *link[26];
    bool flag = false;

    bool containKey(char ch)
    {
        return (link[ch - 'a'] != NULL);
    }
    void put(char ch, Node* node)
    {
        link[ch - 'a'] = node;
    }

    Node* next(char ch)
    {
        return link[ch - 'a'];
    }

    bool setEnd()
    {
        flag = true;
    }

    bool isEnd()
    {
        return flag;
    }
};


class Trie
{

private:

    Node *root;

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
            temp->next(word[i]);

        }
        temp->setEnd();
    }

    // Return true if the word is in the Trie
    bool search(string word)
    {
        Node* temp = root;

        for(int i=0;i<word.length();i++)
        {
            if(!temp->containKey(word[i]))
            {
                return false;
            }
            temp = temp->next(word[i]);
        }
        return temp->isEnd();
    }

    // Return true if the prefix is in the Trie
    bool startWith(string prefix)
    {
        Node* temp = root;

        for(int i=0;i<prefix.length();i++)
        {
            if(!temp->containKey(prefix[i]))
            {
                return false;
            }
            temp = temp->next(prefix[i]);
        }
        return true;
    }
    
    
};


