#ifndef TREE_H
#define TREE_H
#include <iostream>
#include <algorithm>
//insert    // insert value into tree
//get_node_count // get count of values stored
//print_values // prints the values in the tree, from min to max
//delete_tree
//is_in_tree // returns true if given value exists in the tree
//get_height // returns the height in nodes (single node's height is 1)
//get_min   // returns the minimum value stored in the tree
//get_max   // returns the maximum value stored in the tree
//is_binary_search_tree
//delete_value
//get_successor // returns next-highest value in tree after given value, -1 if none

struct Node
{
public:
  Node* left;
  Node* right;
  int data;
};

class Tree
{
public:
  Tree()
  {
    root_ = nullptr;
  }

  Node* makeNode(int value)
  {
    Node* newNode = new Node;
    newNode->left = nullptr;
    newNode->right = nullptr;
    newNode->data = value;
    return newNode;
  }

  void insert(Node* currNode, int value)
  {
    Node* nextNode = nullptr;
    if (value > currNode->data)
    {
      if (currNode->right == nullptr)
      {
        currNode->right = makeNode(value);
        return;
      }
      insert(currNode->right, value);
    }
    else
    {
      if (currNode->left == nullptr)
      {
        currNode->left = makeNode(value);
        return;
      }
      insert(currNode->left, value);
    }
  }

  void insertRecurv(int value)
  {
    if (root_ == nullptr)
      root_ = makeNode(value);
    else
      insert(root_, value);
  }

  void insert(int value)
  {
    if (root_ == nullptr)
    {
      root_ = makeNode(value);
    }
    else
    {
      Node* currNode = root_;
      Node* newNode = makeNode(value);
      while (currNode != nullptr)
      {
        if (value > currNode->data)
        {
          if (currNode->right == nullptr)
          {
            currNode->right = newNode;
            return;
          }
          currNode = currNode->right;
        }
        else
        {
          if (currNode->left == nullptr)
          {
            currNode->left = newNode;
            return;
          }

          currNode = currNode->left;
        }
      }
    }
  }

  int count(Node* currNode)
  {
    if (currNode == nullptr)
      return 0;
    return count(currNode->left) + count(currNode->right) + 1;
  }

  int count(void)
  {
    return count(root_);
  }

  void printValues(Node* currNode)
  {
    if (currNode == nullptr)
      return;
    printValues(currNode->left);
    std::cout << currNode->data << ' ';
    printValues(currNode->right);
  }

  void printValues(void)
  {
    printValues(root_);
    std::cout << std::endl;
  }

  void deleteTree(void)
  {

  }

  bool find(Node* currNode, int value)
  {
    if (currNode == nullptr)
      return false;
    if (currNode->data == value)
      return true;
    return find(currNode->left, value) || find(currNode->right, value);
  }

  bool find(int value)
  {
    if (root_ == nullptr)
      return false;

    return find(root_, value);
  }

  int height(Node* currNode)
  {
    if (currNode == nullptr)
      return 0;
    return std::max(height(currNode->left), height(currNode->right)) + 1;
  }

  int height(void)
  {
    return height(root_);
  }

  int min(Node* currNode, int &currMin)
  {
    if (currNode == nullptr)
      return 0;
    if (currNode->data < currMin)
      currMin = currNode->data;

    min(currNode->left, currMin);
    min(currNode->right, currMin);

    return currMin;
  }

  int min(void)
  {
    if (root_ == nullptr)
      return -1;
    Node* currNode = root_;
    while (currNode->left != nullptr)
      currNode = currNode->left;
    return currNode->data;
  }

  int max(void)
  {
    if (root_ == nullptr)
      return -1;
    Node* currNode = root_;
    while (currNode->right != nullptr)
      currNode = currNode->right;
    return currNode->data;
  }

  void breadthTraversal(void)
  {
    if (root_ == nullptr)
      return;
    queue<Node*> levelOrderList;
    levelOrderList.push(root_);
    while (!levelOrderList.empty())
    {
      Node* currNode = levelOrderList.front();
      if (currNode->left != nullptr)
        levelOrderList.push(currNode->left);
      if (currNode->right != nullptr)
        levelOrderList.push(currNode->right);
      cout << currNode->data << ' ';
      levelOrderList.pop();
    }
  }

  bool isBinary(void)
  {
    return true;
  }

  void remove(int value)
  {

  }

  int successor(int value)
  {
    return 1;
  }


  Node* root_;
};

#endif // TREE_H