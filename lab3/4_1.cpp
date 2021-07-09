#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <set>
#include <algorithm>
#include <tuple>
using namespace std;

// #define max(a,b) (a > b) ? a : b;


struct Node {
    int key;             
    int count;           
    struct Node* left, *right;     
    int height;           
    int desc;             
};
  
int max(int a, int b) {
  return (a > b) ? a : b;
}

int height(struct Node* node) {
    if (node == NULL) return 0;
    return node->height;
}

int getBalance(struct Node* node) {
    if (node == NULL) return 0;
    return height(node->left) - height(node->right);
}

// return the  node with minimum key value found in that tree
struct Node* minValueNode(struct Node* node) {
    struct Node* current = node;
    /* loop down to find the leftmost leaf */
    while (current->left != NULL)
        current = current->left;
  
    return current;
}

struct Node* newNode(int key) {
    struct Node* node = (struct Node*) malloc(sizeof(struct Node));
    node->key = key;
    node->left = NULL;
    node->right = NULL;
    node->height = 1;
    node->desc = 0;
    node->count = 1;
    return (node);
}
  
struct Node* rightRotate(struct Node* y) {
    struct Node* x = y->left;
    struct Node* T2 = x->right;
  
    // Perform rotation
    x->right = y;
    y->left = T2;
  
    // Update heights
    y->height = max(height(y->left), height(y->right)) + 1;
    x->height = max(height(x->left), height(x->right)) + 1;
  
    // calculate the number of children of x and y
    // which are changed due to rotation.
    int val = (T2 != NULL) ? T2->desc : -1;
    y->desc = y->desc - (x->desc + 1) + (val + 1);
    x->desc = x->desc - (val + 1) + (y->desc + 1);
  
    return x;
}
  
struct Node* leftRotate(struct Node* x) {
    struct Node* y = x->right;
    struct Node* T2 = y->left;
  
    // Perform rotation
    y->left = x;
    x->right = T2;
  
    // Update heights
    x->height = max(height(x->left), height(x->right)) + 1;
    y->height = max(height(y->left), height(y->right)) + 1;
  
    // calculate the number of children of x and y
    // which are changed due to rotation.
    int val = (T2 != NULL) ? T2->desc : -1;
    x->desc = x->desc - (y->desc + 1) + (val + 1);
    y->desc = y->desc - (val + 1) + (x->desc + 1);
  
    return y;
}
  
struct Node* insert(struct Node* node, int key, bool repeat) {
    /* 1. Perform the normal BST rotation */
    if (node == NULL) {
        return (newNode(key));
    }

    /* key value is equal */
    if (key == node->key) {
      (node->count)++;
      return node;
    }
  
    if (key < node->key) {
       node->left = insert(node->left, key, repeat);
       if(!repeat) node->desc++;
    }
    else if (key > node->key) {
        node->right = insert(node->right, key, repeat);
        if (!repeat) node->desc++;
    }
    // non equal keys
    // else return node;
  
    /* 2. Update height of this ancestor node */
    node->height = 1 + max(height(node->left), height(node->right));
  
    /* 3. Get the balance factor of this ancestor
        node to check whether this node became
        unbalanced */
    int balance = getBalance(node);
  
    // If node becomes unbalanced, 4 cases arise
  
    // Left Left Case
    if (balance > 1 && key < node->left->key)
      return rightRotate(node);
  
    // Right Right Case
    if (balance < -1 && key > node->right->key)
      return leftRotate(node);
  
    // Left Right Case
    if (balance > 1 && key > node->left->key) {
      node->left = leftRotate(node->left);
      return rightRotate(node);
    }
  
    // Right Left Case
    if (balance < -1 && key < node->right->key) {
      node->right = rightRotate(node->right);
      return leftRotate(node);
    }
  
    /* return the (unchanged) node pointer */
    return node;
}
  
struct Node* deleteNode(struct Node* root, int key)
{
    // STEP 1: PERFORM STANDARD BST DELETE
  
    if (root == NULL) return root;
  
    // If the key to be deleted is smaller than the
    // root's key, then it lies in left subtree
    if (key < root->key) {
        root->left = deleteNode(root->left, key);
        root->desc = root->desc - 1;
    }  
    // If the key to be deleted is greater than the
    // root's key, then it lies in right subtree
    else if (key > root->key) {
        root->right = deleteNode(root->right, key);
        root->desc = root->desc - 1;
    }
  
    // if key is same as root's key, then, this node is to be deleted
    else {
        // if key is present more than once, simply decrement, count, and return
        if (root->count > 1) {
            (root->count)--;
            return root;
        }
  
        // node with only one child or no child
        if ((root->left == NULL) || (root->right == NULL)) {
  
            struct Node* temp = root->left ? root->left : root->right;
  
            // No child case
            if (temp == NULL) {
                temp = root;
                root = NULL;
                free(temp);
            } 
             // One child case 
            else {
                *root = *temp; // Copy the contents of
                free(temp); // the non-empty child
            }    
        } 
        else {
            // node with two children: Get the inorder
            // successor (smallest in the right subtree)
            struct Node* temp = minValueNode(root->right);
  
            // Copy the inorder successor's data to this node
            root->key = temp->key;
            root->count = temp->count;
            // root->desc = temp->desc;
            temp->count = 1;
            // temp->desc = 0;
  
            // Delete the inorder successor
            root->right = deleteNode(root->right, temp->key);
            root->desc = root->desc - 1;
        }
    }
  
    // If the tree had only one node then return
    if (root == NULL)
        return root;
  
    // update height
    root->height = 1 + max(height(root->left), height(root->right));
    // check for balance
    int balance = getBalance(root);
  
    // If this node becomes unbalanced, 4 cases arise
  
    // Left Left Case
    if (balance > 1 && getBalance(root->left) >= 0)
        return rightRotate(root);
  
    // Left Right Case
    if (balance > 1 && getBalance(root->left) < 0) {
        root->left = leftRotate(root->left);
        return rightRotate(root);
    }
  
    // Right Right Case
    if (balance < -1 && getBalance(root->right) <= 0)
        return leftRotate(root);
  
    // Right Left Case
    if (balance < -1 && getBalance(root->right) > 0) {
        root->right = rightRotate(root->right);
        return leftRotate(root);
    }
  
    return root;
}

// returns values greater than given x
int CountGreater(struct Node* root, int x) {
    int res = 0;
    // Search for x, while searching, keep updating res if x is greater than current node.
    while (root != NULL) {

        // size + count
        int desc = (root->right != NULL) ? root->right->desc + root->count -1 : -1;

        if (root->key > x) {
            res = res + desc + 1 + 1;
            root = root->left;
        } 
        else if (root->key < x)
            root = root->right;
        else {
            res = res + desc + 1;
            break;
        }
    }
    return res;
}

// returns kth greatest value
void Kth_largest(Node* absolute_root, Node* root, int k, int &c, std::vector<int> &r)  {

        
        // printf("%d %d\n", k, c);
        if (root == NULL || c >= k) {
            return;
        }
        // Follow reverse inorder traversal so that the
        // largest element is visited first
        Kth_largest(absolute_root, root->right, k, c, r);

        // Increment count of visited nodes
        c+= root->count;

        // If c becomes k now, then this is the k'th largest
        if (c == k)
        {
            int temp = root->key;
            printf("%d\n", temp);
            // printf("%d: kth largest is %d\n", k, root->key);
            absolute_root = deleteNode(absolute_root, temp);
            // r.push_back(temp);
    
        }
        // Recur for left subtree
        Kth_largest(absolute_root, root->left, k, c, r);
}

int main()
{
    struct Node* root = NULL;
    int m; 
    vector<int> r;
    
    std::set<int> s;    

    scanf("%d", &m);
    for (int i = 0; i < m; i++) {
      int op, d;
      scanf("%d %d", &op, &d);
      if (op == 1) { 
        if (!s.count(d)) {
            root = insert(root, d, false);
            s.insert(d);
        }
        else {       
            root = insert(root, d, true);
        }
        int count = CountGreater(root, d);
        // r.push_back(count);
        printf("%d\n", count);
      } 
      else if (op == 2) {
        int c = 0; 
        Kth_largest(root, root, d, c, r);

      }
    }

    // for(int i = 0; i < (signed)r.size(); i++) {
    //     printf("%d\n", r[i]);
    // }
}
