#ifndef AAC_ALGORITHMS_TREE_HPP
#define AAC_ALGORITHMS_TREE_HPP

#include <vector>

/*
    L'arbre doit pouvoir :
    - Contenir des char et des int
    - C'est un arbre binaire.
    - L'arbre n'est pas forcément complet !

    L'arbre doit contenir :
    - Des noeuds composé de :
        - Un entier
        - Un caractère

    L'algorithme prend en entrée une chaine de caractère et renvois une suite de bits.
    - On peut utiliser un tableau de booleen pour representer cette chaine ?
    - On stocke dans un fichier ? Mais du coup comment on le lit ?
*/
class Node{
    private: 
        int     _weight;
        char    _value;

        Node*   _node_left;
        Node*   _node_right;

    public:
        Node();
        Node(int, char);
        Node(int, char, Node *, Node *);
        
        Node(Node const &);
//        Node(Node const &&);

        Node * getLeft() { return _node_left; }
        Node * getRight() { return _node_right; }

        int getValue() const{ return _value; }
        int getWeight() const{ return _weight; }

        void setLeft(Node *);
        void setRight(Node *);
        void setValue(char);
        void setWeight(int);

        friend bool operator<(const Node &, const Node &);
};

class Tree{
    
    private:
        Node * _root;

    public:
        Tree();
        Tree(Node *);
        Tree(Node &);

        Node * getRoot() { return _root; };

        void printTree();
        void printTree(Node *, int);
};

#endif