#include "stdio.h"
#include <iostream>
#include <string>

int str_loc = -1;

struct node {
    char c;
    struct node *left, *right; 
    node(char c) {
        this->c = c;
        left = right = NULL;
    }
};

node* build_tree(std::string &s) {
    str_loc++;
    // printf("building %c at %d\n", s[str_loc], str_loc);
    if (str_loc == s.size()) return NULL;
    // root of tree 
    struct node* root = new node(s[str_loc]);

    root->left = root->c == '#' ? NULL : build_tree(s);
    root->right = root->c == '#' ? NULL : build_tree(s);
    return root;
}

void print_tree(node *root) {
    if(!root) return;
    print_tree(root->left);
    root->c == '#' ? : printf("%c", root->c);
    print_tree(root->right);
}

int main() {
    std::string s; 
    std::cin >> s;

    // build tree
    node *tree_root_node = build_tree(s);

    // print pre order
    print_tree(tree_root_node);
}