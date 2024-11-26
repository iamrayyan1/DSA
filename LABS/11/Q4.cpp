#include <iostream>
#include <vector>
using namespace std;

class HashTable
{
private:
    static const int TABLE_SIZE = 11;
    vector<int> table;
    vector<bool> deleted;

    int primaryHash(int id)
    {
        return id % TABLE_SIZE;
    }

    int secondaryHash(int id)
    {
        return 7 - (id % 7);
    }

public:
    HashTable()
    {
        table = vector<int>(TABLE_SIZE, -1);
        deleted = vector<bool>(TABLE_SIZE, false);
    }

    void insert(int id)
    {
        int index = primaryHash(id);
        int step = secondaryHash(id);

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            int probeIndex = (index + i * step) % TABLE_SIZE;
            if (table[probeIndex] == -1 || deleted[probeIndex])
            {
                table[probeIndex] = id;
                deleted[probeIndex] = false;
                return;
            }
        }
        cout << "Hash table is full.";
    }

    bool search(int id)
    {
        int index = primaryHash(id);
        int step = secondaryHash(id);

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            int probeIndex = (index + i * step) % TABLE_SIZE;
            if (table[probeIndex] == -1)
            {
                return false;
            }
            if (table[probeIndex] == id)
            {
                return true;
            }
        }
        return false;
    }

    bool remove(int id)
    {
        int index = primaryHash(id);
        int step = secondaryHash(id);

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            int probeIndex = (index + i * step) % TABLE_SIZE;
            if (table[probeIndex] == -1)
            {
                return false;
            }
            if (table[probeIndex] == id)
            {
                table[probeIndex] = -1;
                deleted[probeIndex] = true;
                return true;
            }
        }
        return false;
    }

    void display()
    {
        cout << "Hash Table:" << endl;
        for (int i = 0; i < TABLE_SIZE; i++)
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
    HashTable hashTable;

    int accountNumbers1[] = {101, 111, 121, 131, 141, 151};
    for (int id : accountNumbers1)
    {
        hashTable.insert(id);
    }
    cout << "\nAfter Insertions:\n";
    hashTable.display();

    cout << "\nSearch Results:\n";
    cout << "111: " << (hashTable.search(111) ? "Found" : "Not Found") << endl;
    cout << "141: " << (hashTable.search(141) ? "Found" : "Not Found") << endl;
    cout << "161: " << (hashTable.search(161) ? "Found" : "Not Found") << endl;

    hashTable.remove(111);
    hashTable.remove(131);

    cout << "\nAfter Deletions:\n";
    hashTable.display();

    hashTable.insert(161);
    hashTable.insert(171);

    cout << "\nAfter Additional Insertions:\n";
    hashTable.display();
}
