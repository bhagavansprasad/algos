#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include <unordered_map.h>

int main() {
    // Create an unordered_map
    std::unordered_map<int, char*> hashTable;

    // Insert key-value pairs
    hashTable.insert(std::make_pair(1, "John"));
    hashTable.insert(std::make_pair(2, "Alice"));
    hashTable.insert(std::make_pair(3, "Bob"));

    // Access elements using keys
    printf("Value at key 2: %s\n", hashTable[2]);

    // Modify existing value
    hashTable[3] = "Charlie";

    // Check if a key exists
    if (hashTable.find(4) != hashTable.end()) {
        printf("Key 4 exists\n");
    }
    else {
        printf("Key 4 does not exist\n");
    }

    // Remove a key-value pair
    hashTable.erase(1);

    // Iterate over the hash table
    for (auto it = hashTable.begin(); it != hashTable.end(); ++it) {
        printf("Key: %d, Value: %s\n", it->first, it->second);
    }

    return 0;
}

