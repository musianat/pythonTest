#include "DoubleLinkNode.h"

DoubleLinkNode::DoubleLinkNode()
{
    roman="";
    arabic=0;
    prev=nullptr;
    next=nullptr;
}

DoubleLinkNode::DoubleLinkNode(const DoubleLinkNode& obj)
{
    roman=obj.roman;
    arabic=obj.arabic;
    next=obj.next;//test
    prev=obj.prev;
}
DoubleLinkNode::DoubleLinkNode(int n,string s)
{
    roman=s;
    arabic=n;
    prev=nullptr;
    next=nullptr;
}
