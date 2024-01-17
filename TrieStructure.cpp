#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int *link[26];
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
                link[word[i] - 'a'] = 1;
                temp->put(word[i], new Node());

            }
            // move to the next reference trie.
            temp->next(word[i]);

        }
        temp->setEnd();
    }
    
    
};


