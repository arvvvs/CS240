#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <string>
#include "preLab09.h"
using namespace std;

BinNode::BinNode(){
  right=NULL;
  left=NULL;
  data=NULL;
}
BST::BST(){
  root=0;
 }
bool BST::empty(){
  bool boolChicken;
  if(height()==0){
   return boolChicken=false;  
  }
  else if(height()>0){
    boolChicken=true;
  }
  return boolChicken;
}
int BST::height(){
  if(root==NULL){
    return 0;
  }
  int height;
  height=iHeight(root);
  return height;  
}
int BST::iHeight(BinNode* tree){
  if(tree==NULL){
    return 0;
  }    
  int left=iHeight(tree->left);
  int right=iHeight(tree->right);
  return 1+max(left, right);
}
void BinNode::setLeft(BinNode* aLeft){
  left=aLeft;
}
void BinNode::setRight(BinNode* aRight){
  right=aRight;
}
void BinNode::setData(int aData){
  data=aData;
}
/*BST::find(int bData){
  BinNode* current=root;
  BinNode* toReturn=NULL;
  bool isFound=false;
  while((isFound==false)&&(current->data!=NULL)){
    if(key< current->data){
      current=current->left;
    }
    else if(key> current->data){
      current=current->right;
    }
    else if(key==current->data){
    toReturn=current; 
    isFound=true;     
     
    }}
    return toReturn;
  }   
BST::search(int aData){
  BinNode* searchFind=NULL;
  searchFind=find(aData);
  if(searchFind!=NULL){
    return searchFind;
  }  
 return searchFind;
  }*/
bool BST::search(int aData){
  if(root==NULL){
    cout<<"not found"<<endl;
    return false;
  }
  else if(root->data==aData){
    cout<<"found"<<endl;
    return true;

	}
	else{
		BinNode* check;
		check=iFind(root, aData);
	
	if(check!=NULL){
		cout<<"found"<<endl;
    return true;
	}
	else{
    cout<<"not found"<<endl;
		return false;
	}}
}
BinNode* BST::find(int data){
	BinNode* tReturn;
  iFind(root, data);
  return tReturn;
}
BinNode* BST::iFind(BinNode* tree, int aData){
	if(tree==NULL){
		return NULL;
	}
	else if(tree->data==aData){
		return tree;
	}
	else{		
	BinNode* left=iFind(tree->left, aData);
	BinNode* right=iFind(tree->right, aData);
	if(left!=NULL){
		return left;
	}	
	else if(right!=NULL){
		return right;
	}
	else{
		return NULL;
	}
	}
  }

 
bool BST::isBalanced(){
  
  if(root==NULL){
    cout<<"Tree is empty"<<endl;
    return true;
  }
  else{
    int lh=iHeight(root->left);
    int rh=iHeight(root->right);
    if(abs(lh-rh)>1){
      cout<<"tree is balanced"<<endl;
      return true;
    }
  }}
bool BST::is_BST(){
  if(root==NULL){
    return true;
  }
  else if(root->left!=NULL && root->left->data!=-1 && root->left->data>=root->data){
    return false;
  }
  else if(root->right!=NULL && root->right->data!=-1 && root->right->data<=root->data)
  {
    return false;
  }
  else if(root->left!=NULL && root->left->data!=-1 && ris_BST(root->left)==false){
    return false;
  }
  else if(root->right!=NULL && root->right->data!=-1 && ris_BST(root->right)==false){
    return false;
  }
  else{
    return true;
  }
} 
bool BST::ris_BST(BinNode* tree){
  if(tree->left!=NULL && tree->left->data!=-1 && tree->left->data>=tree->data){
    return false;
  }
  else if(tree->right!=NULL && tree->right->data!=-1 && tree->right->data>=tree->data){
    return false;
  }
  else if(tree->left!=NULL && tree->left->data!=-1 && ris_BST(root->left)==false){
    return false;
  }
  else if(tree->right!=NULL && tree->right->data!=-1 && ris_BST(root->right)==false){
    return false;
  }
  else{
    return true;
  }
}
void BST::insert(int cData){
  if(root==NULL || root->data==NULL || root->data==-1){
    BinNode* item=new BinNode();
    BinNode* itemL=new BinNode();
    BinNode* itemR=new BinNode();
    item->data=cData;
    itemL->data=-1;
    itemR->data=-1;
    root=item;
    root->left=itemL;
    root->right=itemR;
  }
  else{
    BinNode* found=new BinNode();
    found=rFind(root, -1); 
     rInsert(cData, found);
    
  }

}
void BST::rInsert(int cData, BinNode* current){
  BinNode* itemL=new BinNode();
  BinNode* itemR=new BinNode();
  BinNode* itemN=new BinNode();
  itemL->data=-1;
  itemR->data=-1;
  itemN->data=cData;
  itemN->left=itemL;
  itemN->right=itemR;
  if(current->left->data==-1){
    current->left=itemN;
    current->left->left=itemL;
    current->left->right=itemR;
  } 
  else if(current->right->data==-1){
    current->right=itemN;
    current->right->left=itemL;
    current->right->right=itemR;
    
  }
} 

BinNode* BST::rFind(BinNode* tree, int aData){
	if(tree==NULL){
	}
	else if(tree->left->data==aData){
		return tree;
	}
  else if(tree->right->data==aData){
    return tree;
  }
	else{		
    rFind(tree->left, aData);
    rFind(tree->right, aData);
//	BinNode* left=iFind(tree->left, aData);
//	BinNode* right=iFind(tree->right, aData);
//	if(left!=NULL && left->left->data==-1){
//		return left;
//	}	
//	else if(right!=NULL && right->left->data==-1){
//		return right;
//	}
//	else{
//    cout<<"no -1 found.  obvious issue returning NULL"<<endl;
//		return NULL;
//	}
//	}
}}
void BST::remove(int dData){
  BinNode* item=new BinNode();
  item=find(dData);
  if(search(dData)==true){
    if(root->data==dData){
    BinNode* item1=new BinNode();
    item1=rFind(root->left, -1);
//  else if(root==NULL){
  //  cout<<"empty"<<endl;
//  }
  if(root->left->data==-1 && root->right->data==-1){
    root->data=-1;
  }
  else if(root->left->data==-1 && root->right->data!=-1){
    root=root->right;
  }
  else if(root->left->data!=-1 && root->right->data==-1){
    root=root->left;
    
  }
  else if(root->left->data!=-1 && root->right->data!=-1){
    if(item1->right->data==-1){
      item1->right=root->right;
      root=root->left;
      cout<<root->data<<endl;  
      }
    else if(item1->left->data==-1){
      item1->left=root->right;
      root=root->left;
      
      cout<<root->data<<endl; 
    }
    
    }    
}
  else{

    cout<<dData<<endl;
    BinNode* storage=new BinNode();
    storage=item->right;
    BinNode* storage2=new BinNode();
    storage2=rFind(item->left, -1);
    item=item->left;
    storage2->left=storage;
  }}
  else{
    cout<<"no such data"<<endl;
  }
}
void BST::pre_order(){
  if(root==NULL || root->data==-1){
    cout<<"Binary tree is empty"<<endl;
  }
 // else if(root!=0 && root->data!=-1 && root->left->data==-1 && root->right->data==-1){
   // cout<<root->data<<endl;
 // }
 // else if(root!=NULL && root->data!=-1 && root->left->data!=-1 && root->right->data==1){
   // cout<<root->data<<" ";
   // rpre_order(root->left);
 // }
 // else if(root!=0 && root->left->data==-1 && root->right->data!=-1){
  //  cout<<root->data<<" ";
   // rpre_order(root->right);
 // }
  else if(root!=0){
    cout<<root->data<<" ";
    rpre_order(root->left);
    rpre_order(root->right);
  }
}
void BST::rpre_order(BinNode* thyNode){
 if(thyNode==0 || thyNode->data==-1){
  } 
//  else if(thyNode!=0 && thyNode->data!=-1 && thyNode->left->data==-1 && thyNode->right->data==-1){
  //  cout<<thyNode->data<<endl;
//  }
//  else if(thyNode!=0 && thyNode->data!=-1 && thyNode->left->data!=-1 && thyNode->right->data==1){
 //   cout<<thyNode->data<<" ";
   // rpre_order(thyNode->left);
 // }
//  else if(thyNode!=0 && thyNode->data!=-1 && thyNode->left->data==-1 && thyNode->right->data!=-1){
  //  cout<<thyNode->data<<" ";
   // rpre_order(thyNode->right);
 // }
 else if(thyNode!=0){
    cout<<thyNode->data<<" ";
    rpre_order(thyNode->left);
    rpre_order(thyNode->right);
  } 
  }
void BST::in_order(){

 if(root==NULL || root->data==-1){
    cout<<"tree empty"<<endl;
  } 
//  else if(root!=NULL && root->data!=-1 && root->left->data==-1 && root->right->data==-1){
  //  cout<<root->data<<endl;
//  }
//  else if(root!=NULL && root->data!=-1 && root->left->data!=-1 && root->right->data==1){
 //   rin_order(root->left);
  //  cout<<root->data<<" ";
 // }
 // else if(root!=NULL && root->data!=-1 && root->left->data==-1 && root->right->data!=-1){
  //  cout<<root->data<<" ";
   // rin_order(root->right);
 // }
 else if(root!=NULL && root->data!=-1){
    rin_order(root->left);
    cout<<root->data<<" ";
    rin_order(root->right);
}
}
void BST::rin_order(BinNode* thyNode){

 if(thyNode==NULL || thyNode->data==-1){
   // cout<<"tree empty"<<endl;
  } 
//  else if(thyNode!=0 && thyNode->data!=-1 && thyNode->left->data==-1 && thyNode->right->data==-1){
//    cout<<thyNode->data<<endl;
//  }
//  else if(thyNode!=NULL && thyNode->data!=-1 && thyNode->left->data!=-1 && thyNode->right->data==1){
//    rin_order(thyNode->left);
//    cout<<thyNode->data<<" ";
//  }
//  else if(thyNode!=NULL && thyNode->data!=-1 && thyNode->left->data==-1 && thyNode->right->data!=-1){
//    cout<<thyNode->data<<" ";
 ///   rin_order(thyNode->right);
//  }
 else if(thyNode!=0 && thyNode->data!=-1){
    rin_order(thyNode->left);
    cout<<thyNode->data<<" ";
    rin_order(thyNode->right);
}}
void BST::post_order(){
  

 if(root==NULL || root->data==-1){
    cout<<"tree empty"<<endl;
  } 
//  else if(root!=NULL && root->data!=-1 && root->left->data==-1 && root->right->data==-1){
//    cout<<root->data<<endl;
//  }
//  else if(root!=NULL && root->data!=-1 && root->left->data!=-1 && root->right->data==1){
//    rpost_order(root->left);
//    cout<<root->data<<" ";
//  }
///  else if(root!=NULL && root->data!=-1 && root->left->data==-1 && root->right->data!=-1){
 ///   rpost_order(root->right);
//    cout<<root->data<<" ";
//  }
 else if(root!=NULL && root->data!=-1){
    rpost_order(root->left);
    rpost_order(root->right);
    cout<<root->data<<" ";
}
}
void BST::rpost_order(BinNode* thyNode){
 if(thyNode==NULL || thyNode->data==-1){
  } 
//  else if(thyNode!=NULL && thyNode->data!=-1 && thyNode->left->data==-1 && thyNode->right->data==-1){
  //  cout<<thyNode->data<<endl;
//  }
//  else if(thyNode!=NULL && thyNode->data!=-1 && thyNode->left->data!=-1 && thyNode->right->data==1){
 //   rpost_order(thyNode->left);
  //  
 //   cout<<thyNode->data<<" ";
//  }
 // else if(thyNode!=NULL && thyNode->data!=-1 && thyNode->left->data==-1 && thyNode->right->data!=-1){
  //  rpost_order(thyNode->right);
   // cout<<thyNode->data<<" ";
//  }
 else if(thyNode!=NULL && thyNode->data!=-1){
    rpost_order(thyNode->left);
    rpost_order(thyNode->right);
    cout<<thyNode->data<<" ";
}}

