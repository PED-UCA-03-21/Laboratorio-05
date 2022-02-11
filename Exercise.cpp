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
      
      if(p->next == head) {
        return " -> " + to_string(p->value);
      }

      return " -> " + to_string(p->value) + _toString(p->next);
    }

  public:
    CircleList();
    Node *getHead();
    Node *getTail();
    void insertAtStart(int value);
    void insertAtEnd(int value);
    void insert(int value, bool atStart);
    void showAt(int position);
    string toString();
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

void CircleList::insertAtStart(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if(!head) {
    head = newNode;
    head->next = head;
    return;
  }

  Node *tail = getTail();

  tail->next = newNode;
  newNode->next = head;
  head = newNode;
}

void CircleList::insertAtEnd(int value) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if(!head) {
    head = newNode;
    head->next = head;
    return;
  }

  Node *tail = getTail();
  tail->next = newNode;
  newNode->next = head;
}

void CircleList::insert(int value, bool atStart) {
  Node *newNode = new Node;
  newNode->value = value;
  newNode->next = NULL;

  if(!head) {
    head = newNode;
    head->next = head;
    return;
  }

  Node *tail = getTail();
  tail->next = newNode;
  newNode->next = head;

  if(atStart) {
    head = newNode;
  }
}

string CircleList::toString() {
  return "Data [" + _toString(head) + " ]";
}

void CircleList::showAt(int position) {
  Node *p = head;

  if(!p) {
    cout << "Lista vacía" << endl;
  }

  for(int i=0; i<position; i++) {
    p = p->next;
  }

  cout << "El elemento en " << position << ": " << p->value << endl;
}

int main() {
  CircleList l1 = CircleList();

  cout << "Insertar al inicio: " << endl;
  for(int i = 0; i < 10; i ++) {
    l1.insert(i, true);
  }

  cout << "L1: " << l1.toString() << endl << endl;

  cout << "Insertar al final: " << endl;
  for(int i = 0; i < 10; i ++) {
    l1.insert(i*2, false);
  }

  cout << "L1: " << l1.toString() << endl << endl;

  cout << "Pruebas de Show At: " << endl;
  
  cout << "Pos: 0" << endl;
  l1.showAt(0);
  cout << "Pos: 10" << endl;
  l1.showAt(10);
  cout << "Pos: 19" << endl;
  l1.showAt(19);
  cout << "Pos: 20" << endl;
  l1.showAt(20);
  cout << "Pos: 25" << endl;
  l1.showAt(25);

  return 0;
}