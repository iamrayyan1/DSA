#include <iostream>
using namespace std;

struct Book
{
    int id;
    int valid;
};

class HashTable
{
private:
    static const int TABLE_SIZE = 10;
    static const int MAX_CHAIN = 10;
    Book table[TABLE_SIZE][MAX_CHAIN];

    int hashFunction(int authorId)
    {
        return authorId % TABLE_SIZE;
    }

public:
    HashTable()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            for (int j = 0; j < MAX_CHAIN; j++)
            {
                table[i][j].valid = 0;
            }
        }
    }

    void insertBook(int bookId)
    {
        int authorId = bookId / 100;
        int index = hashFunction(authorId);

        for (int j = 0; j < MAX_CHAIN; j++)
        {
            if (table[index][j].valid == 0)
            {
                table[index][j].id = bookId;
                table[index][j].valid = 1;
                return;
            }
        }
    }

    bool searchBook(int bookId)
    {
        int authorId = bookId / 100;
        int index = hashFunction(authorId);

        for (int j = 0; j < MAX_CHAIN; j++)
        {
            if (table[index][j].valid == 1 && table[index][j].id == bookId)
            {
                return true;
            }
        }
        return false;
    }

    bool deleteBook(int bookId)
    {
        int authorId = bookId / 100;
        int index = hashFunction(authorId);

        for (int j = 0; j < MAX_CHAIN; j++)
        {
            if (table[index][j].valid == 1 && table[index][j].id == bookId)
            {
                table[index][j].valid = 0;
                return true;
            }
        }
        return false;
    }

    void display()
    {
        for (int i = 0; i < TABLE_SIZE; i++)
        {
            cout << "Index " << i << ": ";
            for (int j = 0; j < MAX_CHAIN; j++)
            {
                if (table[i][j].valid == 1)
                {
                    cout << table[i][j].id << " ";
                }
            }
            cout << endl;
        }
    }
};

int main()
{
    HashTable hashTable;

    hashTable.insertBook(101);
    hashTable.insertBook(102);
    hashTable.insertBook(103);
    hashTable.insertBook(201);
    hashTable.insertBook(202);
    hashTable.insertBook(301);
    hashTable.insertBook(302);
    hashTable.insertBook(303);
    hashTable.insertBook(304);
    cout << "After Insertions:\n";
    hashTable.display();

    cout << "\nSearch Results:\n";
    cout << "Book 101: " << (hashTable.searchBook(101) ? "Found" : "Not Found") << endl;
    cout << "Book 202: " << (hashTable.searchBook(202) ? "Found" : "Not Found") << endl;
    cout << "Book 999: " << (hashTable.searchBook(999) ? "Found" : "Not Found") << endl;

    hashTable.deleteBook(101);
    hashTable.deleteBook(202);
    cout << "\nAfter Deletions:\n";
    hashTable.display();
}
