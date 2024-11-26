#include <iostream>
#include <vector>
using namespace std;

class HashTable
{
private:
    int tableSize;
    int numElements;
    float loadFactor;
    vector<int> table;
    vector<bool> deleted;

    int hashFunction(int key)
    {
        return key % tableSize;
    }

    void resize()
    {
        int oldTableSize = tableSize;
        tableSize *= 2;
        vector<int> oldTable = table;
        vector<bool> oldDeleted = deleted;

        table = vector<int>(tableSize, -1);
        deleted = vector<bool>(tableSize, false);
        numElements = 0;

        for (int i = 0; i < oldTableSize; i++)
        {
            if (oldTable[i] != -1 && !oldDeleted[i])
            {
                insert(oldTable[i]);
            }
        }
    }

public:
    HashTable(int initialSize, float threshold) : tableSize(initialSize), loadFactor(threshold), numElements(0)
    {
        table = vector<int>(tableSize, -1);
        deleted = vector<bool>(tableSize, false);
    }

    void insert(int key)
    {
        if ((float)numElements / tableSize > loadFactor)
        {
            resize();
        }

        int index = hashFunction(key);
        for (int i = 0; i < tableSize; i++)
        {
            int probeIndex = (index + i) % tableSize;
            if (table[probeIndex] == -1 || deleted[probeIndex])
            {
                table[probeIndex] = key;
                deleted[probeIndex] = false;
                numElements++;
                return;
            }
        }
        cout << "Hash table is full. Could not insert key " << key << endl;
    }

    bool search(int key)
    {
        int index = hashFunction(key);
        for (int i = 0; i < tableSize; i++)
        {
            int probeIndex = (index + i) % tableSize;
            if (table[probeIndex] == -1)
            {
                return false;
            }
            if (table[probeIndex] == key)
            {
                return true;
            }
        }
        return false;
    }

    void display()
    {
        cout << "Hash Table" << endl;
        for (int i = 0; i < tableSize; i++)
        {
            cout << "Index " << i << ": ";
            if (table[i] == -1)
            {
                cout << (deleted[i] ? "Deleted" : "Empty") << endl;
            }
            else
            {
                cout << table[i] << endl;
            }
        }
    }
};

int main()
{
    HashTable hashTable(7, 0.75);

    int studentIds1[] = {12, 22, 32, 42, 52, 62};
    for (int id : studentIds1)
    {
        hashTable.insert(id);
    }
    cout << "After Insertions:\n";
    hashTable.display();

    cout << "\nSearch Results:\n";
    cout << "22: " << (hashTable.search(22) ? "Found" : "Not Found") << endl;
    cout << "42: " << (hashTable.search(42) ? "Found" : "Not Found") << endl;
    cout << "72: " << (hashTable.search(72) ? "Found" : "Not Found") << endl;

    hashTable.insert(72);
    hashTable.insert(82);
    cout << "\nAfter Insertions and Resizing:\n";
    hashTable.display();
}
