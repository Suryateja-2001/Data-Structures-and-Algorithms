#include<bits/stdc++.h>
using namespace std;

struct Hash
{
    int BUCKET;   //hash table size
    list<int> *hash_table;

    Hash(int b)
    {
        BUCKET = b;
        // creating array of list where each hash_table[i] is root for list for insertion incase of collision.
        hash_table = new list<int>[BUCKET];
    }


    void insert(int k)
    {
        int i = k % BUCKET;
        hash_table[i].push_back(k);
    }

    bool search(int k)
    {
        int i = k % BUCKET;
        for (auto x : hash_table[i])
            if (x == k)
                return true;
        return false;
    }
    
    void deleteItem(int k)
    {
        int i = k % BUCKET;
        hash_table[i].remove(k);
    }
};

int main()
{
    Hash h(7);
    h.insert(3);
    h.insert(8);
    h.insert(5);
    h.insert(1);
    h.insert(10);
    h.insert(6);

    cout << h.search(10) << endl;
    h.deleteItem(10);
    cout << h.search(1);

}