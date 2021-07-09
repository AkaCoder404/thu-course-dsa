#include <iostream>
#define MAX_TREE_HT 50

unsigned long int compressed_val = 0;


struct MinHeapNode {
  unsigned long int freq;
  struct MinHeapNode *left, *right;
};

struct MinHeap {
  unsigned size;
  unsigned capacity;
  struct MinHeapNode **array;
};

struct MinHeapNode *newNode(unsigned long int freq) {
  struct MinHeapNode *temp = (struct MinHeapNode *)malloc(sizeof(struct MinHeapNode));

  temp->left = temp->right = NULL;
  temp->freq = freq;
  return temp;
}

struct MinHeap *createMinHeap(unsigned capacity) {
  struct MinHeap *minHeap = (struct MinHeap *)malloc(sizeof(struct MinHeap));
  minHeap->size = 0;
  minHeap->capacity = capacity;
  minHeap->array = (struct MinHeapNode **)malloc(minHeap->capacity * sizeof(struct MinHeapNode *));
  return minHeap;
}

void swapMinHeapNode(struct MinHeapNode **a, struct MinHeapNode **b) {
  struct MinHeapNode *t = *a;
  *a = *b;
  *b = t;
}

void minHeapify(struct MinHeap *minHeap, int idx) {
  int smallest = idx;
  unsigned int left = 2 * idx + 1;
  unsigned int right = 2 * idx + 2;

  if (left < minHeap->size && minHeap->array[left]->freq < minHeap->array[smallest]->freq)
    smallest = left;

  if (right < minHeap->size && minHeap->array[right]->freq < minHeap->array[smallest]->freq)
    smallest = right;

  if (smallest != idx) {
    swapMinHeapNode(&minHeap->array[smallest],
           &minHeap->array[idx]);
    minHeapify(minHeap, smallest);
  }
}

struct MinHeapNode *extractMin(struct MinHeap *minHeap) {
  struct MinHeapNode *temp = minHeap->array[0];
  minHeap->array[0] = minHeap->array[minHeap->size - 1];

  --minHeap->size;
  minHeapify(minHeap, 0);

  return temp;
}

void insertMinHeap(struct MinHeap *minHeap, struct MinHeapNode *minHeapNode) {
  ++minHeap->size;
  int i = minHeap->size - 1;

  while (i && minHeapNode->freq < minHeap->array[(i - 1) / 2]->freq) {
    minHeap->array[i] = minHeap->array[(i - 1) / 2];
    i = (i - 1) / 2;
  }

  minHeap->array[i] = minHeapNode;
}

void buildMinHeap(struct MinHeap *minHeap) {
  int n = minHeap->size - 1;
  int i;

  for (i = (n - 1) / 2; i >= 0; --i)
    minHeapify(minHeap, i);
}

int isLeaf(struct MinHeapNode *root) {
  return !(root->left) && !(root->right);
}

struct MinHeap *createAndBuildMinHeap( long int freq[], int size) {
  struct MinHeap *minHeap = createMinHeap(size);

  for (int i = 0; i < size; ++i)
    minHeap->array[i] = newNode(freq[i]);

  minHeap->size = size;
  buildMinHeap(minHeap);

  return minHeap;
}

struct MinHeapNode *buildHfTree(long int freq[], int size) {
  struct MinHeapNode *left, *right, *top;
  struct MinHeap *minHeap = createAndBuildMinHeap(freq, size);

  while (minHeap->size!= 1) {
    left = extractMin(minHeap);
    right = extractMin(minHeap);

    top = newNode(left->freq + right->freq);

    top->left = left;
    top->right = right;

    insertMinHeap(minHeap, top);
  }
  return extractMin(minHeap);
}

void printHuffmanCodes(struct MinHeapNode *root, int arr[], int top) {
  if (root->left) {
    arr[top] = 0;
    printHuffmanCodes(root->left, arr, top + 1);
  }
  if (root->right) {
    arr[top] = 1;
    printHuffmanCodes(root->right, arr, top + 1);
  }
  if (isLeaf(root)) {
    compressed_val += root->freq * top;
  }
}

void HuffmanCodes(long int freq[], int size) {
  struct MinHeapNode *root = buildHfTree(freq, size);
  int *arr = new int[size];
  printHuffmanCodes(root, arr, 0);
}

int main() {
  long int n;
  std::cin >> n;
  
  long int *candies = new long int[n];
  for (int i = 0; i < (signed)n; i++) 
        scanf("%lu", &candies[i]);

  HuffmanCodes(candies, n);
  std::cout << compressed_val;
}