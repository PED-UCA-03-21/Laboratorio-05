#include <iostream>
#include <string>

using namespace std;

struct Node {
  int value;
  Node *next;
};

class CircleList {
  private:
    Node *head;
    
    Node *_getTail(Node *p) {
      if(p->next == head) {
        return p;
      }
      return _getTail(p->next);
    }

    string _toString(Node *p) {
      if(!p) return "";
      if(p->next == head){
        return " -> " + to_string(p->value);
      }
      
      return " -> " + to_string(p->value) + _toString(p->next);
    }

    void _deleteList(Node *p) {
      if(p->next != head) {
        _deleteList(p->next);
      }

      delete p;
    }

  public:
    CircleList();
    Node *getHead();
    Node *getTail();
    string toString();
    void insertAtStart(int value);
    void insertAtEnd(int value);
    void showElementAt(int position);
    void deleteList();
};

CircleList::CircleList() {
  head = NULL;
}

Node *CircleList::getHead() {
  return head;
}

Node *CircleList::getTail() {
  return _getTail(head);
}

string CircleList::toString() {
  return "Data [" + _toString(head) + " ]";
}

void CircleList::insertAtStart(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if(!head) {
    newNode->next = head;
    head = newNode;
    return;
  }

  Node *tail = _getTail(head);

  tail->next = newNode;
  newNode->next = head;
  head = newNode;
}

void CircleList::insertAtEnd(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if(!head) {
    newNode->next = head;
    head = newNode;
    return;
  }

  Node *tail = _getTail(head);

  tail->next = newNode;
  newNode->next = head;
}

void CircleList::showElementAt(int position) {
  Node *p = head;

  if(!p) {
    cout << "Empty list" << endl;
    return;
  }

  for (int i = 0; i < position; i++) {
    p = p->next;
  }

  cout << "Element at " << position << ": " << p->value << endl;
}

void CircleList::deleteList() {
  _deleteList(head);
  head = NULL;
}

int main(void){

}
