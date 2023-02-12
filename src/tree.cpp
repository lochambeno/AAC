#include <tree.hpp>
#include <iostream>

Node::Node(){
    _node_left = nullptr;
    _node_right = nullptr;

    _weight = 0;
    _value = 0;
}
Node::Node(int weight, char value){
    _node_left = nullptr;
    _node_right = nullptr;

    _weight = weight;
    _value = value;
}

Node::Node(int weight, char value, Node * n1, Node * n2){
    _node_left = n1;
    _node_right = n2;

    _weight = weight;
    _value = value;
}

Node::Node(Node const & n){
    _node_left = n._node_left;
    _node_right = n._node_right;

    _weight = n.getWeight();
    _value = n.getValue();
}

/*Node::Node(Node && n){
    _node_left = n.getLeft();
    _node_right = n.getRight();

    _weight = n.getWeight();
    _value = n.getValue();
}*/

void Node::setLeft(Node * n_node){
    _node_left = n_node;
}

void Node::setRight(Node * n_node){
    _node_right = n_node;
}

void Node::setValue(char value){
    _value = value;
}

void Node::setWeight(int weight){
    _weight = weight;
}

//on renvois l'inverse car on a besoin d'avoir le plus petit element en haut de la file
bool operator<(const Node & n1, const Node & n2){
    return !(n1.getWeight() < n2.getWeight());
}

Tree::Tree(){
    _root = nullptr;
}

Tree::Tree(Node * root){
    _root = root;
}

Tree::Tree(Node & root){
    _root = &root;
}


void Tree::printTree(){
    if(_root != nullptr){
        std::cout << 0 << " :: " << char(_root->getValue()) << " : " << _root->getWeight() << "\n";
        printTree(_root->getLeft(), 1);
        printTree(_root->getRight(), 1);
    }
}

void Tree::printTree(Node * node, int etage){
    if(node != nullptr){
        std::cout << etage << " :: " << char(node->getValue()) << " : " << node->getWeight() << "\n";
        printTree(node->getLeft(), etage + 1);
        printTree(node->getRight(), etage + 1);
    }
}