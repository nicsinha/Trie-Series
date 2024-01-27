#include<bits/stdc++.h>
using namespace std;

struct Node {

    Node* links[2];

    bool containkey(int bit)
    {
        return links[bit]!=NULL;
    }

    Node* next(int bit)
    {
        return links[bit];
    }

    void put(int bit,Node* node)
    {
        links[bit] = node;
    }
};

class Trie {

    Node* root;

    public:

    Trie() {
        root = new Node();
    }

    void insert(int num) {

        Node* temp = root;

        for(int i=31;i>=0;i--) {

            int bit = (num>>i) & 1;

            if(!temp->containkey(bit)) {

                temp->put(bit,new Node());
            }
            temp = temp->next(bit);
        }
        cout<<num <<"        inserted into Trie"<<endl;
    }
    //Trying to find the oppsite bit of a number, for maximum xor.

    int findMax(int x) {

        Node* temp = root;
        int ans = 0;
        for(int i=31;i>=0;i--) {
            
            int bit = (x >> i) & 1;

            if(temp->containkey(1 - bit)) {

                ans = ans | (1<<i);
                temp = temp->next(1- bit);
            }
            else {
                temp = temp->next(bit);
            }
        }
        return ans;
    }
};

int main() {

    Trie trie;

    vector<int> v{9,8,7,5,4};

    for(auto i:v)
    {
        trie.insert(i);
    }

    cout<<trie.findMax(8);

}