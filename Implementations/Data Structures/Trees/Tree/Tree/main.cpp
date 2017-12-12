#include "tree.h"
#include <queue>
#include <random>
#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
void TestInsert1(void)
{
  Tree tree;
  for (int i = 0; i < 10; ++i)
    tree.insert(i);

  tree.printValues();
}

void TestInsert2(void)
{
  Tree tree;
  tree.insert(6);
  tree.insert(1);
  tree.insert(88);
  tree.insert(5);
  tree.insert(134);
  tree.insert(2);
  tree.insert(1111);

  tree.printValues();
}

void TestInsert3(void)
{
  Tree tree;
  tree.insert(6);
  tree.printValues();
}

void TestInsert4(void)
{
  Tree tree;
  for (int i = 0; i < 100; ++i)
    tree.insert(rand() % 100);

  tree.printValues();
}

void TestInsertRecurv1(void)
{
  Tree tree;
  for (int i = 0; i < 10; ++i)
    tree.insertRecurv(i);

  tree.printValues();
}

void TestInsertRecurv2(void)
{
  Tree tree;
  tree.insertRecurv(6);
  tree.insertRecurv(1);
  tree.insertRecurv(88);
  tree.insertRecurv(5);
  tree.insertRecurv(134);
  tree.insertRecurv(2);
  tree.insertRecurv(1111);

  tree.printValues();
}

void TestInsertRecurv3(void)
{
  Tree tree;
  for (int i = 0; i < 1000; ++i)
    tree.insertRecurv(i);

  tree.printValues();
}

void TestInsertRecurv4(void)
{
  Tree tree;
  tree.insertRecurv(1);

  tree.printValues();
}

void TestFind1(void)
{
  Tree tree;
  for (int i = 0; i < 10; ++i)
    tree.insert(i);
  std::cout << tree.find(1) << std::endl;
  std::cout << tree.find(2) << std::endl;
  std::cout << tree.find(11) << std::endl;
}

void TestFind2(void)
{
  Tree tree;
  for (int i = 0; i < 10; ++i)
  {
    tree.insert(i);
    std::cout << tree.find(i) << std::endl;
  }
}

void TestFind3(void)
{
  Tree tree;
  tree.insert(66);
  tree.insert(12);
  tree.insert(3);
  tree.insert(568);
  tree.insert(5);
  tree.insert(47);
  tree.insert(12409);
  tree.insert(555);
  tree.insert(66);
  std::cout << tree.find(12409) << std::endl;
  std::cout << tree.find(66) << std::endl;
  std::cout << tree.find(5) << std::endl;
}

void TestFind4(void)
{
  Tree tree;
  for (int i = 0; i < 10; ++i)
    tree.insert(i);
  for (int i = 10; i < 20; ++i)
    std::cout << tree.find(i) << std::endl;
}

void TestHeight1(void)
{
  Tree tree;
  tree.insert(6);
  tree.insert(4);
  tree.insert(8);
  tree.insert(7);
  tree.insert(9);
  tree.insert(13);
  tree.insert(12);

  tree.printValues();
  std::cout << tree.height() << std::endl;
}

void TestHeight2(void)
{
  Tree tree;
  for (int i = 0; i < 10; ++i)
    tree.insert(i);

  std::cout << tree.height() << std::endl;
}

void TestHeight3(void)
{
  Tree tree;
  for (int i = 0; i < 100; ++i)
    tree.insert(i);

  std::cout << tree.height() << std::endl;
}

void TestHeight4(void)
{
  Tree tree;
  tree.insert(1);

  std::cout << tree.height() << std::endl;
}

void TestHeight5(void)
{
  Tree tree;
  for (int i = 0; i < 1000; ++i)
    tree.insert(rand() % 1000);

  Tree tree2;
  for (int i = 0; i < 1000; ++i)
    tree2.insertRecurv(rand() % 1000);

  std::cout << tree.height() << std::endl;
  std::cout << tree2.height() << std::endl;
}

void TestHeight6(void)
{
  Tree tree;
  std::cout << tree.height() << std::endl;
}

void TestCount1(void)
{
  Tree tree;
  for (int i = 0; i < 1000; ++i)
    tree.insert(rand() % 1000);

  std::cout << tree.count() << std::endl;
}

void TestCount2(void)
{
  Tree tree;
  for (int i = 0; i < 327; ++i)
    tree.insert(rand() % 1000);

  std::cout << tree.count() << std::endl;
}

void TestCount3(void)
{
  Tree tree;
  tree.insert(1);

  std::cout << tree.count() << std::endl;
}

void TestCount4(void)
{
  Tree tree;
  tree.insert(6);
  tree.insert(6);
  tree.insert(6);

  std::cout << tree.count() << std::endl;
}

void TestCount5(void)
{
  Tree tree;

  std::cout << tree.count() << std::endl;
}

void TestMin1(void)
{
  Tree tree;
  tree.insert(1);

  std::cout << tree.min() << std::endl;
}

void TestMin2(void)
{
  Tree tree;
  for (int i = 0; i < 100; ++i)
    tree.insert(rand() % 100);

  std::queue<Node*> levelOrderList;
  levelOrderList.push(tree.root_);
  while (!levelOrderList.empty())
  {
    Node* currNode = levelOrderList.front();
    if (currNode->left != nullptr)
      levelOrderList.push(currNode->left);
    if (currNode->right != nullptr)
      levelOrderList.push(currNode->right);
    cout << currNode->data;
    levelOrderList.pop();
  }

  std::cout << tree.min() << std::endl;
}

void TestMin3(void)
{
  Tree tree;
  for (int i = 0; i < 100; ++i)
    tree.insert(rand() % 1000);

  tree.printValues();
  std::cout << tree.min() << std::endl;
}

void levelOrder(Node * root)
{
  if (root == nullptr)
    return;
  queue<Node*> levelOrderList;
  levelOrderList.push(root);
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
Node *lca(Node *root, int v1, int v2)
{
  //vector<node*> v1Parents;
  //SearchNodesRec(root, v1Parents, v1);
  //vector<node*> v2Parents;
  //SearchNodesRec(root, v2Parents, v2);
  //
  //node* parentValue;
  //for(auto tempValue : v1Parents)
  //{
  //  for(auto tempValue2 : v2Parents)
  //  {
  //    if(tempValue->data == tempValue2->data)
  //    {
  //      parentValue = tempValue;
  //      break;
  //    }
  //  } 
  //}
  //Decide if you have to call recursively
  //Samller than both
  if (root->data < v1 && root->data < v2) {
    return lca(root->right, v1, v2);
  }
  //Bigger than both
  if (root->data > v1 && root->data > v2) {
    return lca(root->left, v1, v2);
  }

  //Else solution already found
  return root;

}
int main(void)
{

//  int value = 3;
//  value = value << 2;
//  function1(value);
//  function2(value);
//  function3(&value);
//  //TestInsert1();
//  //TestInsert2();
//  //TestInsert3();
//  //TestInsert4();
//  //TestInsertRecurv1();
//  //TestInsertRecurv2();
//  //TestInsertRecurv3();
//  //TestInsertRecurv4();
//  //TestFind1();
//  //TestFind2();
//  //TestFind3();
//  //TestFind4();
//  //TestHeight1();
//  //TestHeight2();
//  //TestHeight3();
//  //TestHeight4();
//  //TestHeight5();
//  //TestHeight6();
//  //TestCount1();
//  //TestCount2();
//  //TestCount3();
//  //TestCount4();
//  //TestCount5();
  TestMin1();
  TestMin2();
  TestMin3();
  return 0;
}