#include<bits/stdc++.h>
using namespace std;


// Input = "abab"

// output - {},a,ab,aba,abab,b,ba,bab

struct Node
{
    Node* links[26];

    bool containKey(char ch) {
        return links[ch - 'a']!=NULL;
    }

    void put(char ch, Node* node) {
        links[ch - 'a'] = node;
    }

    Node* next(char ch)
    {
        return links[ch - 'a'];
    }

};

class Trie 
{
    Node* root;

    int subString = 0;

    public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {

        Node *temp = root;

        for(int i=0;i<word.length();i++)
        {
            if(!temp->containKey(word[i])) {

                temp->put(word[i],new Node());
                subString += 1;
            }
            temp = temp->next(word[i]);
            
        }
        cout<<word<<"   inserted into Trie"<<endl;
    }
    int countString()
    {
        return subString;
    }
};

int main()
{
    string s = "abab";

    Trie trie;

    for(int i=0;i<s.length();i++)
    {
        string sub = "";
        for(int j=i;j<s.length();j++)
        {
           sub = sub+s[j];
        }
        cout<<sub<<endl;
        trie.insert(sub);
    }
    cout<<trie.countString()+1;

    return 0;
}
