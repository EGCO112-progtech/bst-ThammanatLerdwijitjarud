// An integer binary search tree

struct TreeNode {                                           
    struct TreeNode *leftPtr; // pointer to left subtree
   int data; // node value                               
    struct TreeNode *rightPtr; // pointer to right subtree
}; // end structure treeNode 
        
typedef struct TreeNode * TreeNodePtr; // synonym for TreeNode*
                    
typedef struct {
	int size;
	TreeNodePtr root;
}BST;

// prototypes

void insertNode( BST *, int );

void insertNode_R(TreeNodePtr * t,int value){
  if(*t==NULL){
   *t =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(*t){
		(*t)->leftPtr=NULL;
		(*t)->rightPtr=NULL;
		(*t)->data=value;
   }
  }
  else{
     if((*t)->data>=value) //left
     {
      insertNode_R(&(*t)->leftPtr,value);
     }  
     else //right
     {
      insertNode_R(&(*t)->rightPtr,value);
     }
      
   }
}

void insertNode( BST *b, int value ){
	 TreeNodePtr t =b->root,new_node;
	 int inserted=0; // insert ไม่สำเร็จ
	new_node =(TreeNodePtr) malloc(sizeof(struct TreeNode));
	if(new_node){
		new_node->leftPtr=NULL;
		new_node->rightPtr=NULL;
		new_node->data=value;
		/*First Node*/
		if(b->root==NULL)	b->root=new_node;
		else {
      while(!inserted){
         if(t->data >=value){
         /* move/insert to the left*/
            if(t->leftPtr==NULL)
            {
               t->leftPtr=new_node;
               inserted=1;
            }
            else {
               t=t->leftPtr;
               if(t==NULL)
               {
                  t->leftPtr=new_node;
                  inserted=1;
               }
            }
         }
         else{
            /* move/ insert to the right*/
            if(t->rightPtr==NULL)
            {
               t->rightPtr=new_node;
               inserted=1;
            }
            else
            {
               t=t->rightPtr;
               if(t==NULL)
               {
                  t->rightPtr=new_node;
                  inserted=1;
               }
            }
         }
      }
	}//end while		
  b->size++;
  }
  
}//end function


void inOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
        
      inOrder( treePtr->leftPtr ); //Recursion to the left
 
      printf("%3d",treePtr->data) ;  //print the value 
   
      inOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                         
} // end 

void preOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
 
      printf("%3d",treePtr->data) ;  //print the value 

      preOrder( treePtr->leftPtr ); //Recursion to the left
   
      preOrder( treePtr->rightPtr ); //Recursion to the right
   } // end if                       
} // end 

void postOrder( TreeNodePtr treePtr )
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) {        
 
      postOrder( treePtr->leftPtr ); //Recursion to the left
   
      postOrder( treePtr->rightPtr ); //Recursion to the right

      printf("%3d",treePtr->data) ;  //print the value 
   } // end if                        
} // end

void TOrder( TreeNodePtr treePtr ,int l)
{ 
   // if tree is not empty, then traverse
   if ( treePtr != NULL ) { 
      TOrder( treePtr->rightPtr,l+1); //Recursion to the left
      for(int i=0;i<l;i++)
      {
         printf("    ");
      }
      printf("%3d\n",treePtr->data) ;  //print the value
   
      TOrder( treePtr->leftPtr,l+1); //Recursion to the right
   } // end if                        
} // end

// void printTree(TreeNodePtr treePtr,int l)
// {
//    int i;
//    if(treePtr!=NULL)
//    {
     
//    }
// }
