#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <string>
#include <deque> 
using namespace std;

class BinNode{
  public:
  int data;
  BinNode* left;
  BinNode* right;
  BinNode();
  void setLeft(BinNode* aLeft);
  void setRight(BinNode* aRight);
  void setData(int aData);  


};
class BST{
  public: 
  BST();
  BinNode* rFind(BinNode* tree, int aData);
  int height();
  int iHeight(BinNode* tree); 
  BinNode* root;
  void reInsert(BinNode* tree);
  bool empty();
  bool is_BST();
  bool ris_BST(BinNode* tree);
  bool search(int aData);
  BinNode* find(int bData);
  BinNode* iFind(BinNode* tree, int aData);
  void rInsert(int cData, BinNode* current);
  void rpre_order(BinNode* thyNode);
  void rin_order(BinNode* thyNode);
  void rpost_order(BinNode* thyNode);
  bool isBalanced();  
  bool is_balanced();
  void insert(int cData);
  void remove(int dData);
  void pre_order();
  void in_order();
  void post_order();
  void write(string file_name);
  void read(string file_name);
  void vWrite(std::deque<int> values);
  void lWrite(int value, BinNode* current);
  void lrWrite(int value, BinNode* current);
  void flrWrite(int value, BinNode* current);
  void rWrite(int value, BinNode* current);
  void rlWrite(int value, BinNode* current);
  void frlWrite(int value, BinNode* current);
           

};
