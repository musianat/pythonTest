#include "LinkedList.h"
#include <fstream>
#include <iostream>
#include <utility>
LinkedList::LinkedList()
{
    head=nullptr;
    tail=nullptr;
}
LinkedList::LinkedList(DoubleLinkNode node)
{
    head=&node;
    tail=&node;
}
LinkedList::LinkedList(const LinkedList &obj)
{
     DoubleLinkNode* cpy=new DoubleLinkNode;
     head=cpy;

    DoubleLinkNode* cpyPtr=cpy;
    DoubleLinkNode* ptr=obj.head;
    while(ptr)
    {

        cpyPtr->setArabic(ptr->getArabic()); // copies values
        cpyPtr->setRoman(ptr->getRoman());
         ptr=ptr->getNext();
        if(ptr){ // if another node
        cpyPtr->setNext(new DoubleLinkNode); //move to next node
        cpyPtr=cpyPtr->getNext();
        }

    }
    cpyPtr->setNext(nullptr); // adds a null pointer to last node


}
LinkedList::~LinkedList()
{
     DoubleLinkNode* ptr=head;
    while(ptr)
    {
        DoubleLinkNode* hold=ptr;
         //hold pointer to node being delted
        head=ptr->getNext();
         ptr=ptr->getNext(); // moves list to next node
        delete hold; // deletes node


    }
}

void LinkedList::AddNode(DoubleLinkNode* &hold) // adds nodes to linked list
{
   // cout<<"test1  ";
                       //cout<< arabic <<"\t"<<roman<<endl;

	DoubleLinkNode* ptr = head;

	//DoubleLinkNode* hold = new DoubleLinkNode(arabic,roman); // creates new node
	//hold->setArabic(arabic); // inputs data into the node
	//hold->setRoman(roman);
	//hold->setNext(nullptr);
	//cout << hold->getArabic() << endl;
	//cout << head->getNext()->getArabic()<<endl;
	if(!head) // if this is the first node
       {

        head=hold; // make the new node the first node
       // cout<<"head"<<endl;
      // cout<<head->getRoman();
       }
	else
	{
		while(ptr->getNext() != nullptr) // move to last node
			ptr=ptr->getNext();

		ptr->setNext(hold); //adds new node to last node
		hold->setPrev(ptr);
		tail=hold;
		//cout<<"  middle  "<<endl;
//		       cout<<head->getRoman();

	}
}


DoubleLinkNode * LinkedList::midNode( DoubleLinkNode * startNode , DoubleLinkNode * endNode) // calclutes midpoint of the section
{
     if( startNode == NULL )
     {
         // If the linked list is empty
         return NULL;
     }

    DoubleLinkNode* slowPtr = startNode;
    DoubleLinkNode* fastPtr = startNode;// -> next; // moves twice as fast as slow pointer

    if(startNode==endNode) // if at same spot return slowptr
        return slowPtr;
    while ( fastPtr != endNode && fastPtr!=NULL) // move fast pointer until endnode
     {
         fastPtr = fastPtr ->getNext() ;

         if( fastPtr != endNode && fastPtr!=NULL)
             {
             slowPtr = slowPtr->getNext() ;//for each loop iteration, slowPtr moves  one while fastPtr moves two nodes
             fastPtr = fastPtr->getNext() ;
             }
     }
     return slowPtr ; // return middle
}


DoubleLinkNode* LinkedList::BinarySearchForInt( int val )
{
    //LinkedList copyL(*this);

    //copyL.bubbleSort();
	DoubleLinkNode* startNode=head;
	DoubleLinkNode* endNode=NULL;
 do
 {
 DoubleLinkNode* middle = midNode( startNode ,endNode ); // finds middle node
 //cout << middle->arabic << endl;
 //cout <<"endNode " <<endNode << endl;
 if( middle == NULL )
 {
 // Searched Element Not Present
 //deleteList(copyL);
 return NULL;
 }

 if( middle->getArabic() == val )
 {
   // delete copyL;
    return middle;
 }
 if(middle==startNode && middle==endNode)
 {
       // copyL.deleteList();
     return NULL;
 }
 else if ( middle->getArabic() < val )
 {
 // need to search in upper half
 startNode = middle->getNext();
 //cout << "test" <<startNode->arabic << endl;
 //startNode=middle;
 }
 else
 {
 // need to search in lower half
 endNode = middle;
 }
 if(startNode==NULL)
 {
     // deleteList(copyL);
     return NULL;
 }
//countnum++;
 }while(endNode == NULL || endNode->getNext() != startNode);

 // arabic not present
//  copyL.deleteList();
 return NULL;
}
void LinkedList::PrintToFile()
{
	DoubleLinkNode* ptr=head;

	ofstream out;
	out.open("sampleout.txt"); // opens output file change here

	while(ptr !=NULL)
	{
		//out << ptr->getRoman() << "\t " << ptr->getArabic() << endl; // write data to output file
		if(ptr==tail)
            		out << *ptr; // uses overloaded base node operator
        else
		out << *ptr << endl; // uses overloaded base node operator
		ptr=ptr->getNext();
	}
	out.close();
}
void LinkedList::PrintToScreen(char i) // print out linked list to screen
{
    int counter=0;
	DoubleLinkNode* ptr=head; // moves to first node
	//cout<<"test"<<endl;
	//cout<< head->getArabic()<<endl;
	switch(i)

	{
    case '0': //Roman and Arabic
        {
        while(ptr !=NULL)
            {
            //cout << ptr->getRoman() << "\t "  << ptr->getArabic() << endl; //
            cout << *ptr <<endl; // uses overloaded base node operator
            ptr=ptr->getNext();
            counter++; // goes to next node
            }
            break;
        }
    case '1': //Arabic
        {
        while(ptr !=NULL)
            {
            cout << ptr->getArabic() << endl; //
            ptr=ptr->getNext();
            counter++; // goes to next node
            }
            break;
        }
    case '2': //Roman
        {
        while(ptr !=NULL)
            {
            cout << ptr->getRoman() << endl; //
            ptr=ptr->getNext();
            counter++; // goes to next node
            }
            break;
        }

	}

}
void LinkedList::swapMiddle(DoubleLinkNode* &node)
{
    /*
	DoubleLinkNode* temp = prev->getNext(); //current

		prev->setNext(swap2); //puts second swap to prev

	temp->setNext(swap2->getNext()); //puts first swap to second swap

	prev->getNext()->setNext(temp); // puts swap 2 to current
	*/
	DoubleLinkNode* previousNode= node->getPrev();

	previousNode->setNext(node->getNext());         // this used to point to node
    previousNode->getPrev()->setNext(node);     // this used to point to previousNode
    node->setPrev(previousNode->getPrev()); // this used to point to previousNode
    node->getNext()->setPrev(previousNode);     // this used to point to node
    node->setNext(previousNode);
    previousNode->setPrev(node);

}
void LinkedList::swapHead() //swaps head node with first node
{
    //cout<<"test";
    DoubleLinkNode * node=head->getNext();
	DoubleLinkNode* previousNode= head;
	previousNode->setNext(node->getNext());
	previousNode->setPrev(node);         // this used to point to node
    //previousNode->getPrev()->setNext(node);     // this used to point to previousNode
    node->setPrev(nullptr); // this used to point to previousNode
    node->getNext()->setPrev(previousNode);     // this used to point to node
    node->setNext(previousNode);
   // previousNode->setPrev(node);
    head=node;


}
void LinkedList::swapEnd(DoubleLinkNode* &node) // swaps end node with second to last node
{
    /*
	DoubleLinkNode* temp = prev->getNext(); //current

    prev->setNext(swap2);
	temp->setNext(nullptr);
	prev->getNext()->setNext(temp);
*/

	DoubleLinkNode* previousNode= node->getPrev();
	previousNode->setNext(nullptr);         // this used to point to node
    previousNode->getPrev()->setNext(node);     // this used to point to previousNode
    node->setPrev(previousNode->getPrev()); // this used to point to previousNode
    //node->getNext()->setPrev(previousNode);     // this used to point to node
    node->setNext(previousNode);
    previousNode->setPrev(node);
    tail=previousNode;

}
void LinkedList::bubbleSort() // sorts arabic least to greatest
{
	//cout << "test";
	bool swapped=true;
	int length=0;
	DoubleLinkNode* cur=head;

	while(cur) //finds length of linked list
	{
		length++;
		cur=cur->getNext();
	}

	for(int i=0; /*i<length &&*/ swapped==true;i++) //outer loop
	{
	  //  PrintToScreen('0');
	  //  cout<<endl<<endl;
		swapped=false;
	//	cout << "test " << i << "  ";
		cur=head;
		//DoubleLinkNode* prev=nullptr;
		//prev->next=head;
		for(int j=0;cur->getNext()!=nullptr;j++) // innner loop
		{
			if(cur->getArabic() > cur->getNext()->getArabic()) // if first node is greater than second node
			{
			   // cout<<"swap";
			   cur=cur->getNext();
				if(cur->getPrev()==head) // if swapping first node
				{
				   // cout<<"head"<<endl;
					swapHead();
					//prev=head; // sets new swapped head
                    j++; // moves incremter forward since head has changed
				}
				else if(cur==tail) // if swapping at the end
				{
				  //  cout<<"end"<<endl;
					swapEnd(cur);
				}
				else{ // swapping in middle
                      //  cout << "middle"<<endl;
                       // cout<<cur->getPrev()->getPrev()->getArabic()<<"\t"<<cur->getPrev()->getArabic()<< "\t"<<cur->getArabic()<<endl;
				swapMiddle(cur);

				//prev=prev->getNext(); // move orevious because cur has already been moved
				}
				swapped=true;

				//cur=cur->getPrev();
			}
			else{ //if there is not a swap to be made go to the next node
			    	//if(j>1)
			    	//cout<<prev->arabic << "\t" << prev->next->arabic <<"\t"     << endl;
            if(j==length-1) // if at end
                break;
           // prev=cur;
			cur=cur->getNext();
			//if(cur->getNext()==nullptr)
              //  j++;
			}
		}
	}
}
void LinkedList::SortByRoman() // sorts alphabetically
{
    //cout << "test";
	bool swapped=true;
	int length=1; // check if this is the issue
	DoubleLinkNode* cur=head;

	while(cur->getNext()!=nullptr)
	{
		length++;
		cur=cur->getNext();
	}

	for(int i=0; i<length && swapped==true;i++) // outer loop
	{
		swapped=false;
		//cout << "test " << i << "  ";
		cur=head;
		//DoubleLinkNode* prev=nullptr;
		//prev->next=head;
		for(int j=0;cur->getNext()!=nullptr;j++) // inner loop
		{
			if(cur->getRoman() > cur->getNext()->getRoman()) // if first node is alphabtically greater swap
			{
			    cur=cur->getNext();
				if(cur->getPrev()==head) // if swap head
				{
					swapHead();
					//prev=head;
                    j++;
				}
				else if(cur==tail) // if swap end
					swapEnd(cur);
				else
                { // if swap middle
				swapMiddle(cur); // curent node increments by itself
				//cout << "middle";
				//prev=prev->getNext(); //incremnt prev node
				}
				swapped=true;
				//cur=cur->getPrev();
			}
			else{ // if there is no swap incremnt node
            if(j==length-1)
                break;
            //prev=cur;
			cur=cur->getNext();
			if(cur->getNext()==nullptr)
                j++;
			}
		}
	}
}
void LinkedList::deleteNode(DoubleLinkNode * ptr)
{
    if(ptr==head)
        deleteFirst();
    else if(ptr==tail)
        deleteLast();
    else
    {
        ptr->getPrev()->setNext(ptr->getNext());
        ptr->getNext()->setPrev(ptr->getPrev());
        delete ptr;
    }
}
void LinkedList::deleteFirst()
{
     DoubleLinkNode* hold=head;
            head=head->getNext();
            head->setPrev(nullptr);
            delete hold;
//            return head; //need to do
}
void LinkedList::deleteLast()
{
       DoubleLinkNode* hold=tail;
            tail=tail->getPrev();
            tail->setNext(nullptr);
            delete hold;
           // return tail;
}
 LinkedList LinkedList::operator += (DoubleLinkNode* node)
 {
     AddNode(node);
     return *this;
 }
        void LinkedList::operator --() //++prefix
        {
           return deleteFirst();
        }
       void LinkedList::operator --(int) //postfix
        {
            return deleteLast();
        }
