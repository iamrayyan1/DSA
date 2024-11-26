#include <iostream>
using namespace std;

class HashTable
{
private:
    static const int TABLE_SIZE = 7;
    int table[TABLE_SIZE];
    bool deleted[TABLE_SIZE];

    int hashFunction(int memberId)
    {
        return memberId % TABLE_SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; ++i)
        {
            table[i] = -1;
            deleted[i] = false;
        }
    }

    void insert(int memberId)
    {
        int index = hashFunction(memberId);

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            int probeIndex = (index + i) % TABLE_SIZE;
            if (table[probeIndex] == -1 || deleted[probeIndex])
            {
                table[probeIndex] = memberId;
                deleted[probeIndex] = false;
                return;
            }
        }
        cout << "Hash table is full\n";
    }

    bool search(int memberId)
    {
        int index = hashFunction(memberId);

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            int probeIndex = (index + i) % TABLE_SIZE;
            if (table[probeIndex] == -1)
            {
                return false;
            }
            if (table[probeIndex] == memberId)
            {
                return true;
            }
        }
        return false;
    }

    bool remove(int memberId)
    {
        int index = hashFunction(memberId);

        for (int i = 0; i < TABLE_SIZE; i++)
        {
            int probeIndex = (index + i) % TABLE_SIZE;
            if (table[probeIndex] == -1)
            {
                return false;
            }
            if (table[probeIndex] == memberId)
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

    int memberIds[] = {10, 20, 30, 40, 50, 60};
    for (int id : memberIds)
    {
        hashTable.insert(id);
    }
    cout << "After Insertions:\n";
    hashTable.display();

    cout << "\nSearch Results:\n";
    cout << "30: " << (hashTable.search(30) ? "Found" : "Not Found") << endl;
    cout << "50: " << (hashTable.search(50) ? "Found" : "Not Found") << endl;
    cout << "70: " << (hashTable.search(70) ? "Found" : "Not Found") << endl;

    hashTable.remove(20);
    hashTable.remove(40);
    cout << "\nAfter Deletions:\n";
    hashTable.display();

    hashTable.insert(70);
    hashTable.insert(80);
    cout << "\nAfter Insertions:\n";
    hashTable.display();
}
