#include<bits/stdc++.h>
using namespace std;

struct Node
{
    Node* links[26];
    int SC = 0;
    int EW = 0;

    bool containKey(char ch) {
        return links[ch-'a']!=NULL;
    }

    void put(char ch, Node* node){
        links[ch-'a'] = node;
    }

    void increaseSC(){
        SC += 1;
    }
    void increaseEW(){
        EW += 1;
    }
    void decreaseSC(){
        SC -= 1;
    }
    void decreaseEW(){
        EW -= 1;
    }

    int getSC()
    {
        return SC;
    }
    int getEW()
    {
        return EW;
    }

    Node* next(char ch) {
        return links[ch-'a'];
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
        Node* temp = root;

        for (int i = 0; i < word.length(); i++)
        {
            if(!temp->containKey(word[i]))
            {
                Node *n = new Node();
                temp->put(word[i],n);
            }
            temp = temp->next(word[i]); 
            temp->increaseSC(); 
        }
        temp->increaseEW();
    }

    int countPrefix(string word)
    {
        Node* temp = root;

        for(int i=0;i<word.length();i++)
        {
            if(temp->containKey(word[i]))
            {
                temp = temp->next(word[i]);
            }
            else {
                return 0;
            }
        }
        return temp->getSC();
    }

    
};
int main()
{
    string s[] = {"apple","apple","apps"};

    Trie T ;
    for(int i=0;i<3;i++)
    {
        T.insert(s[i]);
    }
    cout<<T.countPrefix("apple");
    

}



