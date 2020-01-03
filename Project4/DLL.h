//Project 4
//After "BEGIN MODIFICATION BELOW" Written by Andrew Decrem
//Doubly Linked List project

#pragma once
#include <iostream>
using std::cout;
using std::ostream;
#include <string>
using std::string;
#include <vector>
using std::vector;
#include <sstream>
using std::ostringstream;
// DO NOT MODIFY
//
// Node
//
struct Node {
    string key{};
    int value{};
    Node *next = nullptr;
    Node *prev = nullptr;
    Node() = default;
    Node(string, int, Node * = nullptr, Node * = nullptr);
    bool operator==(const Node &) const;
    friend ostream &operator<<(ostream &out, const Node &n) {
        out << n.key << ":" << n.value;
        return out;
    }
};

Node::Node(string key_, int value_, Node *prev_, Node *next_) {
    key = key_;
    value = value_;
    prev = prev_;
    next = next_;
}

bool Node::operator==(const Node &n) const {
    if ((key == n.key) && (value == n.value)) {
        return true;
    } else {
        return false;
    }
}

// DO NOT MODIFY
//
// DLL
//
class DLL {
private:
    Node *head_ = nullptr;
    Node *tail_ = nullptr;
    size_t sz_ = 0;

public:
    DLL() = default;
    DLL(vector<Node>);
    DLL(const DLL &);
    DLL &operator=(DLL list);
    ~DLL();
    Node *get_head();
    Node *get_tail();
    size_t get_size();
    Node add_back(string, int);
    Node add_front(string, int);
    Node add_after(string, string, int);
    Node search(string);
    Node remove_front();
    Node remove_back();
    Node remove_key(string);
    int update_value(string, int);
    friend ostream &operator<<(ostream &out, const DLL &list) {
        auto itr = list.head_;
        ostringstream oss;
        for (; itr != nullptr; itr = itr->next) {
            oss << itr->key << ":" << itr->value << ", ";
        }
        string ans = oss.str();
        ans = ans.substr(0, ans.size() - 2);
        out << ans;
        return out;
    }
};

Node *DLL::get_head() { return head_; }
Node *DLL::get_tail() { return tail_; }
size_t DLL::get_size() { return sz_; }

DLL::~DLL() {
    while (head_)
        delete std::exchange(head_, head_->next);
}

DLL & DLL::operator =(DLL list) {
    using std::swap;
    swap(head_,list.head_);
    swap(tail_,list.tail_);
    swap(sz_,list.sz_);
    return *this;
}

DLL::DLL(const DLL &list) {
    for (Node *p = list.head_; p; p = p->next)
        add_back(p->key, p->value);
}

DLL::DLL(vector<Node> vec) {
    for (const auto &node : vec)
        add_back(node.key, node.value);
}

/* BEGIN MODIFICATION BELOW */

Node DLL::add_back(string str, int num) {//function to add node to back of doubly linked list
    Node *n1 = new Node(str, num);//created new node
    if(tail_ != nullptr) {//if list isn't empty
        tail_->next=n1;//tail's next is the new node
        n1->next=nullptr;//make the next null
        n1->prev=tail_;//reassign tail
        tail_=n1;//make tail new node
        sz_++;//adjust size
    }else if(sz_ == 0){//if list is empty
        head_ = n1;//head  & tail are n1
        tail_ = n1;
        sz_++;//adjust size
    }else{
        n1=head_;//if only 1 node
    }
    return *n1;
}
/*ADD BACK
 * Create new node
 * check if at end
 * reassign tail
 * edge cases
 */
Node DLL::add_front(string str, int num) {//function to add node to front of doubly linked list
    Node *n1 = new Node(str, num);//create new node
    if (head_ != nullptr) {//if list isn't empty
        head_->prev=n1;//previous of head is n1
        n1->prev=nullptr;//previous is null
        n1->next=head_;//reassign head
        head_=n1;//make head new node
        sz_++;//adjust size
    }else if(sz_ == 0){//if list is empty
        head_=n1;//head and tail are n1
        tail_=n1;
        sz_++;//adjust size
    }else{
        n1=tail_;//if only one node
    }
    return *n1;
}
/*ADD FRONT
 * create new node
 * check if empty
 * reassign head
 * edge cases
 */

Node DLL::add_after(string add_key, string str, int num){//add after found node
    Node *n1 = new Node(str,num);//make new node
    Node* searcher = head_;//indexer
    while(searcher != nullptr){//if indexer doesnt go beyond end
        if(searcher->key == add_key){//if a nodes key is the required key
            Node *n3 = searcher->next;//create temp variable
            if(searcher->next!=nullptr) {//if not at end
                searcher->next = n1;//new node is next
                n1->prev=searcher;//new nodes previous is searcher
                n1->next=n3;//assign temp
                n3->prev=n1;//temp's previous is new node
            }else if(searcher->next == nullptr){//if at end
                n1->prev=searcher;//assign previous
                tail_->next=n1;//assign next
                tail_=n1;//tail is new variable
                n1->next= nullptr;//make new null
            }
            sz_++;//adjust size
            return *n1;
        }
        searcher=searcher->next;//move for indexer
    }
    return Node("",0);//if not found
}
/*ADD AFTER
 * create new node
 * create indexer
 * find node
 * add after a found node
 * add if at end
 * adjust size
*/
Node DLL::remove_back(){//remove last node
    Node *n1 = tail_;//new node is last node
        if (sz_ == 0) {//if empty
            head_= nullptr;
            tail_= nullptr;
            return Node("", 0);
        }else if(sz_ == 1) {//if one
            tail_ = nullptr;
            head_ = nullptr;
            sz_ = 0;
        } else{//normal case
            tail_ = tail_->prev;//reassign tail
            tail_->next= nullptr;//make past end null
            sz_--;//adjust size
        }
        return *n1;
}
/*REMOVE BACK
 * if empty
 * if one
 * remove back normal case
 * reassign tail
 * adjust size
 */

Node DLL::remove_front(){//remove front node
    Node *n1 = head_;//new node is head
        if (sz_ == 0) {//if empty
            head_= nullptr;
            tail_= nullptr;
            return Node("", 0);
        } else if (sz_ == 1){//if list is one long
            head_ = nullptr;
            tail_ = nullptr;
            sz_ = 0;
        } else{//normal case
            head_ = head_->next;//reassign head
            head_->prev = nullptr;//make old null
            sz_--;//adjust size
        }
        return *n1;
}

/*REMOVE FRONT
 * if empty
 * if one
 * normal remove front test case
 * adjust head
 * adjust size
 */

Node DLL::remove_key(string to_remove){//remove key if found
    Node* searcher = head_;//set new node to beginning
    while(searcher != nullptr){//indexer
        if(searcher->key == to_remove){//if found
           if(sz_==1){//if one
               head_= nullptr;
               tail_= nullptr;
               sz_=0;
           }else if(searcher->next== nullptr && sz_>1){//if at tail
               tail_ = tail_->prev;
               tail_->next= nullptr;
               sz_--;
               return *searcher;
           }else if(searcher->prev == nullptr && sz_>1){//if at head
               head_ = head_->next;
               head_->prev = nullptr;
               sz_--;
               return *searcher;
           }else{
               Node *tmp = searcher->next;//create temp variable
               searcher->prev->next=tmp;//nodes previous's next is temp
               tmp->prev=searcher->prev;//temp's previous is searcher's previous
               sz_--;//adjust size
               return *searcher;
           }
        }
        searcher=searcher->next;//next for indexer
    }
    return Node("",0);//if list is empty

}
/*REMOVE KEY
 * indexer
 *  index
 *  if found
 *  if size is one
 *  if at tail
 *  if at head
 *  normal remove test case
 *  remove key
 *  adjust pointers
 *  adjust size
 *  return
 */

Node DLL::search(string find_key){//search for node
    Node* searcher = head_;//create new node at head
    while(searcher != nullptr){//indexer
        if(searcher->key == find_key) {//if found
            return *searcher;
        }
        searcher=searcher->next;//indexer next
    }
    return Node("",0);//if empty
}
/*SEARCH
 * create indexer
 * while not at end
 * if found
 * return searcher
 */

int DLL::update_value(string find_key, int new_value){//update value function
    Node* searcher = head_;//set new node to head
    while(searcher != nullptr){//indexer
        if(searcher->key == find_key){//if found
            searcher->value=new_value;//set new value
            return new_value;//return new value
        }
        searcher=searcher->next;//indexer next
    }
    return -1;//if not found
}
/*UPDATE VALUE
 * indexer
 * if not at end/empty
 * if found
 * adjust value
 */

//Used wikipedia link provided to understand how it works
//https://en.wikipedia.org/wiki/Doubly_linked_list
//Watched youtube video on doubly linked lists
//https://www.youtube.com/watch?v=k0pjD12bzP0
//Watched the video below for understanding on what exactly inserting a node entailed, but code wasn't used.
//https://www.youtube.com/watch?v=jkbS-bKXTEE
