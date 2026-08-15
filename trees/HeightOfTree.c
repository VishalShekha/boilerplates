Problem Statement



Given an array representing the parent-child relationship in a binary tree, find the tree's height without building it. 



The parent-child relationship is defined by (A[i], i) for every index i in the array. The root node's value will be i if -1 is present at index i in the array.



The depth of a node is the total number of edges from the node to the tree's root node. The root is the only node whose depth is 0. 



The height of a node is the total number of edges on the longest path from the node of a leaf. The height of a tree would be the height of its root node or equivalently the depth of its deepest node. A leaf node will have a height of 0.



Example



Parent: [-1, 0, 0, 1, 2, 2, 4, 4]

Index: [0, 1, 2, 3, 4, 5, 6, 7]

 

-1 is present at index 0, which implies that the binary tree root is node 0.
0 is present at index 1 and 2, which implies that the left and right children of node 0 are 1 and 2.
1 is present at index 3, which implies that the left or the right child of node 1 is 3.
2 is present at index 4 and 5, which implies that the left and right children of node 2 are 4 and 5.
4 is present at index 6 and 7, which implies that the left and right children of node 4 are 6 and 7.


The corresponding binary tree is:

Build Binary Tree from Parent Array



Output: The height of the binary tree is 3.

Input format :
The first line contains a single integer N, which represents the number of nodes in the tree.

The next N lines consist of an integer in each line, and the last line of input consists of the ith integer representing the parent of the ith node.

If the ith node is the root node, then the corresponding value will be -1.

Output format :
The output consists of a single integer, which represents the height of the tree.

Code constraints :
1 ≤ N ≤ 10

Sample test cases :
Input 1 :
8
-1
0
0
1
2
2
4
4
Output 1 :
3
Input 2 :
4
-1
0
1
1
Output 2 :
2
Note :


#include <stdio.h>

int parent[100];
int height[100];

int getHeight(int node) {
    if (height[node] != -1) {
        return height[node]; 
    }
    if (parent[node] == -1) {
        height[node] = 0; 
        return height[node];
    }
    height[node] = getHeight(parent[node]) + 1;
    return height[node];
}

int main() {
    int n;
    scanf("%d", &n);
    
    for (int i = 0; i < n; i++) {
        scanf("%d", &parent[i]);
    }

    for (int i = 0; i < n; i++) {
        height[i] = -1;
    }

    int maxHeight = 0;
    for (int i = 0; i < n; i++) {
        maxHeight = (maxHeight > getHeight(i)) ? maxHeight : getHeight(i);
    }

    printf("%d\n", maxHeight);
    return 0;
}