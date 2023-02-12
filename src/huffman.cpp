#include "huffman.hpp"
#include <iostream>

//On cree une table contenant tous les noeuds pour chaque symboles ainsi que le nombre d'occurence de ce symbole.
std::vector<Node> huffman_init(std::string && message){
    std::vector<Node> weights;
    bool test_doublon = false;

    for(auto iter_message = message.begin(); iter_message < message.end(); iter_message++){
        test_doublon = false;
        auto iter_doublon = weights.begin();

        while(!test_doublon && iter_doublon < weights.end()){
            if(iter_doublon->getValue() == *iter_message){
                test_doublon = true;
            }
            else{
                iter_doublon++;
            }
        }

        if(test_doublon){
            iter_doublon->setWeight(iter_doublon->getWeight() + 1);
        }
        else{
            weights.push_back(Node(1, *iter_message));
        }
    }

    return weights;
}


//En argument, un vecteur contenant des noeuds
Tree huffman_tree(std::vector<Node> & weights){
    Tree huffman_tree;
    std::priority_queue<Node> queue;  

    Node * n1;
    Node * n2;  
    Node * n3;

    bool end = false;

    //on met tous les noeuds dans une file de priorite
    for(auto iter = weights.begin(); iter < weights.end(); iter++){
        queue.push(Node(*iter));
        //std::cout << iter->getValue() << " " << iter->getWeight() << "\n";
    }

    //on prend les deux noeuds avec le poids le plus petit
    while(!end && !queue.empty()){
        //si la file n'est pas vide
        n1 = new Node(queue.top());
        queue.pop();
        if(queue.empty()){
            end = true;
        }
        else{
            n2 = new Node(queue.top());
            queue.pop();

            n3 = new Node(
                n1->getWeight() + n2->getWeight(), 0, n2, n1 
            );
            queue.push(*n3);
        }   
    }
    if(end){
        huffman_tree = Tree(n1);
    }
    else
    {
        huffman_tree = Tree(n3);
    }

    return huffman_tree;
}

//TODO 
//la fonction qui permet d'avoir l'alphabet (sert juste pour l'exemple)
std::map<char, std::string> huffman_map(Tree huffman_tree){
    std::map<char, std::string> huffman_m;
    Node* iter;
    std::string iter_string;

    std::stack<Node*> stack_parcourt;

    //on a besoin d'une deuxieme pile pour les chaines que l'on va map
    std::stack<std::string> stack_string;

    //on fait un parcourt en profondeur
    stack_parcourt.push(huffman_tree.getRoot());
    while(!stack_parcourt.empty()){
        iter = stack_parcourt.top();
        stack_parcourt.pop();

        //si la pile de caractere est vide, alors on est a la racine
        if(!stack_string.empty()){
            iter_string = stack_string.top();
            stack_string.pop();
        }

        //si on va a droite, on ecrit 1
        if(iter->getRight() != nullptr){
            stack_parcourt.push(iter->getRight());
            stack_string.push(iter_string + "1");
        }

        //si on va a gauche, on ecrit 0
        if(iter->getLeft() != nullptr){
            stack_parcourt.push(iter->getLeft());
            stack_string.push(iter_string + "0");
        }

        if(iter->getValue() != 0){
            huffman_m.insert({iter->getValue(), iter_string});
            std::cout << char(iter->getValue()) << " : " << iter_string << "\n";
        }
    }
    
    return huffman_m;
}
