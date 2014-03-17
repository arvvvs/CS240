#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include <string>
#include "preLab09.h"
#include <sstream>
using namespace std;

BinNode::BinNode(){
  right=NULL;
  left=NULL;
  data=NULL;
}
BST::BST(){
  root=0;
  //std::deque<int> value2;
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
  tReturn=iFind(root, data);
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
  else{
      cout<<"tree is unbalanced"<<endl;
      return false;
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
    BinNode* litem=find(dData);
    cout<<litem->data<<endl;
    reInsert(item);
  }}
  else{
    cout<<"no such data"<<endl;
  }
}
void BST::reInsert(BinNode* tree){
  if(tree->left->data==-1 && tree->right->data==-1){
    tree->data=-1;
  }
  else if(tree->left->data==-1 && tree->right->data!=-1){
    tree=tree->right;
    tree->left->data=-1;
  }
  else if(tree->left->data!=-1 && tree->right->data==-1){
      tree=tree->left;
      tree=tree->right;
  }
  else if(tree->left->data!=-1 && tree->right->data!=-1){
    BinNode* iFound=rFind(tree->left, -1);
    if(iFound->left->data==-1){
    iFound->left=tree->right;
    tree=tree->left;
    tree->right->data=-1;
    } 
    else if(iFound->right->data==-1){
    iFound->right=tree->right;
    tree=tree->left;
    tree->right->data=-1;
    }
  }
}
void BST::write(string file_name){
  ofstream oFile;
  oFile.open(file_name.data());
  wpre_order(oFile);
 // if(!oFile.is_open()){
   // std::cerr<<"error in opening files"<<endl;
 // }  
 /* while(!value2.empty())
  {
    int v;
    v=value2.front();
    cout<<v<<endl;
    oFile<<v<<endl;
    value2.pop_front();
  }*/
  oFile.close();
}
void BST::wpre_order(ofstream& out){
  if(root==NULL || root->data==-1){
    cout<<"Empty"<<endl;
  }
  else if(root!=0){
    out<<root->data<<" ";
  //value2.push_back(root->data);
    wrpre_order(root->left, out);
    wrpre_order(root->right, out);
  }}
void BST::wrpre_order(BinNode* thyNode, ofstream& out){
  if(thyNode==0){
  }
  else if(thyNode!=NULL){
    //return thyNode->data;
    //value2.push_back(thyNode->data);
    out<<thyNode->data<<" ";
    wrpre_order(thyNode->left, out);
    wrpre_order(thyNode->right, out);
//    value2.push_back(thyNode->data);
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
void BST::read(string file_name){
  ifstream iFile;
  iFile.open(file_name.data());
  if(!iFile.is_open()){
    std::cerr<<"error in opening files";
  }
  string line;
  while(getline(iFile,line)){
    std::stringstream lineStream(line);
    std::deque<int> values;
    int n;
    while(lineStream>>n){
      values.push_back(n);
    }
    std::deque<int> values1=values;
    //while(!values1.empty()){
     // std::cout<<values1.front()<<endl;
    //  values1.pop_front();
   // }
    vWrite(values); 
  }
}
bool BST::symmetry(){
  if(root->left==NULL || root->right==NULL){
    return true;
  }
  return root->left->data==root->right->data && rSymmetry(root->left, root->right);
}
bool BST::rSymmetry(BinNode* right, BinNode* left){
  if(right==NULL && left==NULL){
    return true;  
  }
  return root->left->data==root->right->data && rSymmetry(right->right, left->left) && rSymmetry(left->right, right->left);

}
void BST::vWrite(std::deque<int> values){
  
 // for(int i=0; i<values.size(); i++){
    while(!values.empty()){
      if(root==NULL){
      BinNode* item=new BinNode();
      root=item;
      BinNode* item2=new BinNode();
      root->left=item2;
      BinNode* item3=new BinNode();
      root->right=item3;
      root->data=values.front();
      values.pop_front(); 
    } 
    else if(iFind(root->left, NULL)!=NULL){
      lWrite(values.front(), root);
      values.pop_front();
    }
    else if(iFind(root->right, NULL)!=NULL)
    {
      rWrite(values.front(), root);
      cout<<values.front()<<endl;
      values.pop_front();
    }
  else{
     cout<<"invalid data insertions cannot be performed"<<endl;
    //  cout<<values.front()<<endl;
    //  values.pop_front();
        }
    }
} 

  void BST::lWrite(int value, BinNode* current){
   // if(current->left->left->data!=-1 && current->left->right->data!=-1){
    if(current->left->data==NULL){
      current->left->data=value;
      BinNode* item1=new BinNode();
      BinNode* item2=new BinNode();
      if(value!=-1){
      current->left->right=item1;
      current->left->left=item2;  
      }
    }
    else if(current->left->data!=-1 && current->left->data!=NULL){
      lWrite(value, current->left);
    }
    else if(current->left->data==-1){
      lrWrite(value, current);
    }
  }
    /*if(iFind(current->right, NULL)==NULL){
      flrWrite(value, root);
      
    }
    else{
      lrWrite(value, current);
    }*/

  void BST::lrWrite(int value, BinNode* current){
    if(current->right->data==NULL){
      current->right->data=value;
      if(value!=-1){
        BinNode* item1=new BinNode();
        BinNode* item2=new BinNode();
        current->right->right=item1;
        current->right->left=item2;
      }
    }
    else if(current->right->data!=-1 && current->right->data!=NULL){
      current=current->right;
      lWrite(value, current);
    }
    else if(current->right->data==-1){
      flrWrite(value, root->left);
    }
}
  void BST::flrWrite(int value, BinNode* current){
       BinNode* preCurrent=new BinNode(); 
       if(current->data==NULL){
          current->data=value;
          if(value!=-1){
            BinNode* item1=new BinNode();
            BinNode* item2=new BinNode();
            current->left=item1;
            current->right=item2;
          }  
        } 
       else if(iFind(current->left,NULL)!=NULL){
          current=current->left;
          preCurrent=current;  
          }  
        else if(iFind(current->left,NULL)==NULL){
           flrWrite(value, preCurrent->right);
        }
  }
  void BST::rWrite(int value, BinNode* current){
    if(current->right->data==NULL){
        current->right->data=value;
        BinNode* item1=new BinNode();
        BinNode* item2=new BinNode();
        if(value!=-1){
          current->right->right=item1;
          current->right->left=item2;
        }
    }
    else {
      //current=current->left;
      
      rrWrite(value, current->right);
    }
      
    //current->right->data==-1
}
  void BST::rrWrite(int value, BinNode* current){
    if(iFind(current->left, NULL)!=NULL){
      rlWrite(value, current);
    }
    else if(current->right->data!=NULL && current->right->data!=-1){
      rrWrite(value, current->right);
    }
    else if(current->right->data==NULL){
      current->right->data=value;
        if(value!=-1){
          BinNode* item1=new BinNode();
          BinNode* item2=new BinNode();
          current->right->right=item1;
          current->right->left=item2;
        }
      }
  

  }
  void BST::rlWrite(int value, BinNode* current){
    /*  if(current->left->data=NULL){
        current->left->data=value;
      if(value!=-1){
         BinNode* item1=new BinNode();
         BinNode* item2=new BinNode();
         current->right=item1;
         current->left=item2;
      }
    }*/
    

 if(current->left->data==NULL){
        current->left->data=value;
        if(value!=-1){
          BinNode* item1=new BinNode();
          BinNode* item2=new BinNode();
          current->left->right=item1;
          current->left->left=item2; 
        }
      }
      else if(current->left->data!=-1 && current->left->data!=NULL){
        current=current->left;
        rlWrite(value, current);
      } 
      else if(current->left->data==-1 && current->right->data==NULL){
         current->right->data=value;
         if(value!=-1){
          BinNode* item2=new BinNode();
          BinNode* item1=new BinNode();
          current->right->right=item2;
          current->right->left=item1;
         }
      }
      else if(current->left->data==-1 && current->right->data!=NULL && current->right->data!=-1){
      current=current->right;
      rlWrite(value, current);  
    }
      else if(current->left->data==-1 && current->right->data==-1){
        frlWrite(value, root->right);
      }
  }

  void BST::frlWrite(int value, BinNode* current){
}/*       BinNode* preCurrent=new BinNode(); 
       if(current->data==NULL){
          current->data=value;
          if(value!=-1){
            BinNode* item1=new BinNode();
            BinNode* item2=new BinNode();
            current->left=item1;
            current->right=item2;
          }  
        } 
       else if(iFind(current->left, NULL)==NULL){
          current=current->right;
          }  
        else if(iFind(current->left, NULL)!=NULL){
         //  flrWrite(value, current->left);
             rlWrite(value, current->left); 
         }
}*/
 /*   else if(current->right->data==-1 && current->right->data==NULL){
      current->right->data=value;
    }
    else if(current->left->right->data!=-1 && current->left->right->data!=NULL){
      current=current->left->right;
      lWrite(value, current);
    }*/
    
    

/*    int vWrite=lWrite(values[i], current);
    if(vWrite==-1){
      rWrite(values[i], current);
    } 
  }
}
int BST::lWrite(int value, BinNode* current){
    if(current->left->left->data!=-1 && current->left->right->data!=-1){
    if(current->left->data==NULL){
      current->left->data=value;
    }
    else if(current->left->left->data==-1){
        int rData=lrWrite(value, current);
        if(rData==-1){
          return -1;
        }
    } 
    else if(current->left->data!=-1 && current->left->data!=NULL){
      current=current->left;
      lWrite(value, current);
    
  }
  else{
    lWrite(value, current->right);
  }
    
}
int BST::lrWrite(int value, BinNode* current){
    if(current->right==NULL){
      curret->right->data=value;
    }
    else if(current->left->data==-1 && current->left->right==-1){
        current->right->data=data;
        lWrite(value, current->right);
    }
    else if(
}*/
