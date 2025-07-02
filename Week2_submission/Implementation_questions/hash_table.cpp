#include<bits/stdc++.h>
using namespace std;

template<typename X, typename Y>

class HashTable {
    private:
        const int size = 100;
        list<pair<X, Y>> table[100];

        int HashFunc(const X& key) const {
            return hash<X>{}(key) % size; // hash<X>{}(key) returns a hash value for the key, it comes in act in different data types.
        }

    public:
        void Insert(const X& key, const Y& value){
            int index = HashFunc(key);
            list<pair<X, Y>>& list_ = table[index];

            for (auto& pair : list_) {
                if(pair.first == key) {
                    pair.second = value;
                    return;
                }
            }
            list_.push_back(make_pair(key, value));
        }

        void Remove(const X& key){
            int index = HashFunc(key);
            list<pair<X, Y>>& list_ = table[index];

            for( auto& pair : list_ ){
                if(pair.first == key){
                    list_.remove(pair);
                    return;
                }
            }
        }

        Y find(const X& key) const {
            int index = HashFunc(key);
            const auto& list_ = table[index];

            for (const auto& pair : list_) {
                if (pair.first == key) {
                    return pair.second;  
                }
            }
            return Y(); // return a default value if the key is not found like for int : 0, for string : "" etc.
        }
};


int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    HashTable<string, int> hashTable;
    hashTable.Insert("apple", 1);
    hashTable.Insert("banana", 2);
    hashTable.Insert("orange", 3);

    int value=2;
    if (hashTable.find("banana")) {
        cout << "Found banana with value: " << value << endl;
    } else {
        cout << "Banana not found." << endl;
    }

    hashTable.Remove("apple");
    if (hashTable.find("apple")) {
        cout << "Found apple with value: " << value << endl;
    } else {
        cout << "Apple not found." << endl;
    }

    return 0;
}