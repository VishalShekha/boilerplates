
struct node* buildTree() {
    int data;
    struct node* root = NULL;

    scanf("%d", &data);

    if (data == -1)
        return NULL;

    root = newNode(data);
    root->left = buildTree();
    root->right = buildTree();

    return root;
}

int main() {
    struct node* root = buildTree();

    if (isBST(root))
        printf("The given binary tree is a BST\n");
    else
        printf("The given binary tree is not a BST\n");

    return 0;
}