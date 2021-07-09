// brute force method
#include <iostream>
#include <vector>
#include <queue>
#include <string>

long int min_sum = 0;

struct Node {
    long int freq;
    Node *left, *right;
    Node(long int freq) {
        left = right = NULL;
        this->freq = freq;
    }
};

struct compare {
    bool operator()(Node* left, Node* right) {
        return (left->freq > right->freq);
    }
};

// depth first search
void calculate_compression(struct Node* root, int length){
    if (!root) return;
    
    if (root->left == NULL && root->right == NULL) {
        min_sum += root->freq * length;
    }

    calculate_compression(root->left, length + 1);
    calculate_compression(root->right, length + 1);
}

void huffman_code(long int freq[], long int size) {
    struct Node *left, *right, *root;

    // create a minimum heap and insert all nodes (nodes with smallest freq)
    std::priority_queue<Node*, std::vector<Node*>, compare> heap;

    for (int i = 0; i < (signed)size; i++)
        heap.push(new Node(freq[i]));

    while (heap.size() != 1) {
        left = heap.top();
        heap.pop();

        right = heap.top();
        heap.pop();

        root = new Node(left->freq + right->freq);

        root->left = left;
        root->right = right;

        heap.push(root);
    }

    calculate_compression(heap.top(), 0);
}

int main() {
    long int n;
    std::cin >> n;

    long int *candies = new long int[n];
    for (int i = 0; i < (signed)n; i++) 
        scanf("%lu", &candies[i]);

    huffman_code(candies, n);
    std::cout << min_sum;

    delete[] candies;
}