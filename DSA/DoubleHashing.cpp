#include <iostream>
#include <vector>

class HashTable {
private:
    static const int TABLE_SIZE = 10;
    std::vector<int> table;

public:
    HashTable() {
        table.resize(TABLE_SIZE, -1);
    }

    // Hash function to calculate the hash value
    int hash(int key) {
        return key % TABLE_SIZE;
    }

    // Hash function for double hashing
    int hash2(int key) {
        // Prime number smaller than the table size
        return 7 - (key % 7);
    }

    // Function to insert a key into the hash table
    void insert(int key) {
        int index = hash(key);
        int originalIndex = index;

        int stepSize = hash2(key);

        while (table[index] != -1) {
            index = (index + stepSize) % TABLE_SIZE;
            // If we wrap around to the original index, the table is full
            if (index == originalIndex) {
                std::cout << "Hash table is full. Cannot insert key " << key << std::endl;
                return;
            }
        }

        table[index] = key;
        std::cout << "Inserted key " << key << " at index " << index << std::endl;
    }

    // Function to search for a key in the hash table
    bool search(int key) {
        int index = hash(key);
        int originalIndex = index;

        int stepSize = hash2(key);

        while (table[index] != -1) {
            if (table[index] == key) {
                return true;
            }
            index = (index + stepSize) % TABLE_SIZE;
            // If we wrap around to the original index, the key is not found
            if (index == originalIndex) {
                break;
            }
        }

        return false;
    }

    // Function to display the hash table
    void display() {
        std::cout << "Hash Table:" << std::endl;
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != -1) {
                std::cout << "Index " << i << ": " << table[i] << std::endl;
            }
        }
    }
};

int main() {
    HashTable hashTable;

    // Insert keys into the hash table
    hashTable.insert(3);
    hashTable.insert(9);
    hashTable.insert(7);
    hashTable.insert(11);
    hashTable.insert(5);
    hashTable.insert(16);
    hashTable.insert(23);

    // Search for keys in the hash table
    std::cout << "Key 9 found? " << (hashTable.search(9) ? "Yes" : "No") << std::endl;
    std::cout << "Key 15 found? " << (hashTable.search(15) ? "Yes" : "No") << std::endl;

    // Display the hash table
    hashTable.display();

    return 0;
}
