#include <iostream> //test
#include "Tree.hpp" 
#include <iomanip>      // std::setw

using namespace std;
using namespace ariel;


                                            // constractor //
    Tree::Tree()
    {
    Tree::myroot = NULL;
    }
                                            // distractor //   
    Tree::~Tree()
    {
        myroot = fun::makeEmpty(myroot);
    }
                                        
                                        ////// public methods ///////

 	void Tree::insert(int x){
		myroot = fun::insert(x,myroot);
	}
	void Tree::print() { 
		fun::display(myroot, 10);
	}
	int Tree::parent (int x){
		Node* temp =fun::parent(myroot,x);
		if (temp==NULL) {
			throw::invalid_argument("No Parent found");
			return -1;
		}
		else return temp->data;
	}
	int Tree::left(int x){
		return fun::left(x,myroot);
	}

	int Tree::right(int x){
		return fun::right(x,myroot);
	}
	int Tree::size(){
		int ans = fun::size(myroot);
		if(myroot == NULL){
			return 0;
		}else{
		return fun::size(myroot);

		}
	}

int ariel::Tree::root()

{
    if (myroot == NULL)
        throw std::invalid_argument("the root is not exist");

    return myroot->data;
}

	bool Tree::contains(int x)
	{
		Node* temp = fun::find(myroot, x);
		if(temp==NULL)return false;
		else 
			return true ;
	}

	void Tree::remove(int x)
	{
	    Node *removeNode = fun::find(myroot, x);

    if (removeNode == NULL)
    {
        throw std::invalid_argument("the number isn't exist ");
    }

    Node *temp = fun::remove(myroot,x);

    if (removeNode == myroot)
    {
        myroot = temp;
    }
    if (temp == NULL)
    {
        myroot = NULL;
    }
	}








                                        ////// end public methods ///////


                                        ////// private methods ///////

	// priting function that took from interent.									

    void fun::display(Node* p, int indent) {

    if (p != NULL) {
    if (p->right) {
      fun::display(p->right, indent + 4);
    }
    if (indent) {
      cout << setw(indent) << ' ';
    }
    if (p->right) cout << " /\n" << setw(indent) << ' ';
    cout << p->data << "\n ";
    if (p->left) {
      cout << setw(indent) << ' ' << " \\\n";
      fun::display(p->left, indent + 4);
    }
  }
}

// empty the tree //
 Node* fun::makeEmpty(Node* t)
    {
        if(t != NULL){
            fun::makeEmpty(t->left);
            fun::makeEmpty(t->right);
            delete t;
        }
        return NULL;
    }
 Node* fun::remove(Node* myroot, int data) {
	if (myroot == NULL)
        return myroot;

    if (data < myroot->data){

		Node* temp=fun::remove(myroot->left, data);
        myroot->left =temp;
		}
   
    else if (data > myroot->data)
		{

			Node* temp=fun::remove(myroot->right, data);
        myroot->right=temp;
}else
    {
      
        if (myroot->left == NULL)
        {
            Node *temp = myroot->right;
            delete myroot;
            return temp;
        }
        else if (myroot->right== NULL)
        {
            Node *temp = myroot->left;
            
            delete myroot;
            return temp;
        }
        Node *temp = fun::findMin(myroot->right);

      
        myroot->data=(temp->data);

        // Delete the inorder successor
        myroot->right=(fun::remove(myroot->right, temp->data));
    }
    return myroot;
}


Node* fun::findMin(Node* t)
{
	if(t == NULL)
		return NULL;
	else if(t->left == NULL)
		return t;
	else
		return fun::findMin(t->left);
}


Node* fun::insert(int x, Node* p){

	if(p == NULL){
		p = new Node;
		p->data = x;
		p->left = p->right = NULL;
	}
	else if (p->data == x){
	throw invalid_argument("This numer is allready in the Tree");

	}
	else if(x < p->data){
		p->left = fun::insert(x, p->left);
	}
	if(x > p->data)
		p->right = fun::insert(x, p->right);

		return p;
}


Node* fun::parent(Node* myroot, int n) {
	if (myroot == NULL){
		return NULL;
	}
	else if ( (myroot->left!=NULL && myroot->left->data == n) || ((myroot->right!=NULL) && (myroot->right->data == n)))
	{
			return myroot;
		}
		else {
			Node* result= fun::parent(myroot->left, n);
			if (result!=NULL){
				return result;
			}
			else{
				return fun::parent(myroot->right, n);
			}
		}

}
int fun::left(int x ,Node* myroot){

	Node* temp = fun::find(myroot,x);

	if(temp == NULL || temp->left == NULL){
		throw invalid_argument("left child not exist");
	} 
	else{
		return temp->left->data;
	}

}

int fun::right(int x ,Node* myroot){

	Node* temp = fun::find(myroot,x);

	if(temp == NULL || temp->right == NULL){
		throw invalid_argument("right child not exist");
	} 
	else{
		return temp->right->data;
	}

}

int fun::size(Node* myroot)  
{  
	if (myroot == NULL || myroot->data == 0)  
		return 0;  
	else
		return(fun::size(myroot->left) + 1 + fun::size(myroot->right));  
}

Node* fun::find(Node* t, int x)
{
	if(t == NULL)
		return NULL;
	else if(x < t->data)
		return fun::find(t->left, x);
	else if(x > t->data)
		return fun::find(t->right, x);
	else
		return t;
}






                                        ////// end  private methods ///////

