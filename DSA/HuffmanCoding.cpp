#include <iostream>
#include <queue>
#include <unordered_map>

// Huffman tree node
struct Node {
    char data;
    int frequency;
    Node* left;
    Node* right;

    Node(char data, int frequency) : data(data), frequency(frequency), left(nullptr), right(nullptr) {}
};

// Comparison function for priority queue
struct Compare {
    bool operator()(Node* left, Node* right) {
        return left->frequency > right->frequency;
    }
};

// Traverse the Huffman tree and generate Huffman codes
void generateCodes(Node* root, std::string code, std::unordered_map<char, std::string>& codes) {
    if (root == nullptr) {
        return;
    }

    // Leaf node
    if (!root->left && !root->right) {
        codes[root->data] = code;
    }

    // Recursive calls for left and right subtrees
    generateCodes(root->left, code + "0", codes);
    generateCodes(root->right, code + "1", codes);
}

// Build Huffman tree and generate Huffman codes
std::unordered_map<char, std::string> buildHuffmanTree(const std::string& text) {
    // Count the frequency of each character
    std::unordered_map<char, int> frequency;
    for (char c : text) {
        frequency[c]++;
    }

    // Priority queue to store the Huffman tree nodes
    std::priority_queue<Node*, std::vector<Node*>, Compare> pq;

    // Create a leaf node for each character and add it to the priority queue
    for (const auto& pair : frequency) {
        pq.push(new Node(pair.first, pair.second));
    }

    // Build the Huffman tree
    while (pq.size() > 1) {
        // Extract the two nodes with the lowest frequency
        Node* left = pq.top();
        pq.pop();
        Node* right = pq.top();
        pq.pop();

        // Create a new internal node with the combined frequency
        Node* newNode = new Node('\0', left->frequency + right->frequency);
        newNode->left = left;
        newNode->right = right;

        // Add the new node back to the priority queue
        pq.push(newNode);
    }

    // Root of the Huffman tree
    Node* root = pq.top();

    // Generate Huffman codes
    std::unordered_map<char, std::string> codes;
    generateCodes(root, "", codes);

    // Delete the Huffman tree
    delete root;

    return codes;
}

int main() {
    std::string text = "hello world";

    // Build Huffman tree and generate Huffman codes
    std::unordered_map<char, std::string> codes = buildHuffmanTree(text);

    // Print Huffman codes
    std::cout << "Huffman Codes:\n";
    for (const auto& pair : codes) {
        std::cout << pair.first << ": " << pair.second << std::endl;
    }

    return 0;
}
