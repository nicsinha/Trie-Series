#include<bits/stdc++.h>
using namespace std;


// Input = "abab"

// output - {},a,ab,aba,abab,b,ba,bab = 8

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

    int subString = 1;

    public:

    Trie() {
        root = new Node();
    }

    void insert(string word) {

        for(int i=0;i<word.length();i++)
        {
            Node *temp = root;
            for(int j=i;j<word.length();j++)
            {
                if(!temp->containKey(word[i])) {

                    temp->put(word[i],new Node());
                    subString += 1;
                }
                temp = temp->next(word[i]);
            }

            
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
    trie.insert(s);
    cout<<trie.countString();

    return 0;
}
