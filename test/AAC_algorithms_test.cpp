// Entetes //---------------------------------------------------------------------------------------
#include "catch.hpp"
#include "tree.hpp"
#include "huffman.hpp"

#include <iostream>

// Tests //-----------------------------------------------------------------------------------------

//------------------------------------------------------------------------------------------------ 1
TEST_CASE ( "AAC_tree::Constructeurs par défaut" ) {
 
    Tree tree;
    Node node;

    REQUIRE (tree.getRoot() == nullptr);
    REQUIRE (node.getValue() == 0);
}

TEST_CASE ("AAC_tree::Constructeurs avec arguments"){

    Node node(2, 'b');
    Tree tree(node);
    
    REQUIRE (node.getValue() == 'b');
    REQUIRE (node.getWeight() == 2);

    REQUIRE (tree.getRoot() != nullptr);
    REQUIRE (tree.getRoot()->getWeight() == 2);
}

TEST_CASE ("AAC_Huffman::Initialisation Huffman (un caractere)"){
    std::vector<Node> huffman;

    huffman = huffman_init("A");

    REQUIRE(huffman.begin()->getValue() == 'A');
}


TEST_CASE ("AAC_Huffman::Initialisation Huffman (plusieurs caracteres)"){
    std::vector<Node> huffman;

    huffman = huffman_init("ABC");
    auto iter = huffman.begin();

    REQUIRE(iter->getValue() == 'A');
    iter++;
    REQUIRE(iter->getValue() == 'B');
    iter++;
    REQUIRE(iter->getValue() == 'C');
}

TEST_CASE ("AAC_Huffman::Initialisation Huffman (caracteres identiques)"){
    std::vector<Node> huffman;

    huffman = huffman_init("AAA  C");
    auto iter = huffman.begin();

    REQUIRE(iter->getWeight() == 3);
    iter++;
    REQUIRE(iter->getWeight() == 2);
    iter++;
    REQUIRE(iter->getWeight() == 1);
}

TEST_CASE ("AAC_Huffman::Huffman tree (un caractere)"){
    std::vector<Node> huffman;
    Tree huffman_t;

    huffman = huffman_init("A");
    huffman_t = huffman_tree(huffman);

    REQUIRE(huffman_t.getRoot()->getValue() == 'A');
}

TEST_CASE ("AAC_Huffman::Huffman tree (deux caracteres)"){
    std::vector<Node> huffman;
    Tree huffman_t;

    huffman = huffman_init("AB");
    huffman_t = huffman_tree(huffman);

    REQUIRE(huffman_t.getRoot()->getValue() == 0);
    REQUIRE(huffman_t.getRoot()->getWeight() == 2);
    REQUIRE(huffman_t.getRoot()->getLeft()->getWeight() == 1);
    REQUIRE(huffman_t.getRoot()->getRight()->getWeight() == 1);
}

TEST_CASE ("AAC_Huffman::Huffman tree (plusieurs caracteres)"){
    std::vector<Node> huffman;
    Tree huffman_t;

    huffman = huffman_init("AAAA BB CCC");
    huffman_t = huffman_tree(huffman);

    huffman_t.printTree();
    std::cout << "/************************* FIN TEST HUFFMAN TREE *************************/ \n";

    REQUIRE(huffman_t.getRoot()->getValue() == 0);
    REQUIRE(huffman_t.getRoot()->getWeight() == 11);
}

TEST_CASE ("AAC_Huffman::Huffman map"){
    std::vector<Node> huffman;
    std::map<char, std::string> huffman_m;
    Tree huffman_t;

    huffman = huffman_init("AAAA BB CCC");
    huffman_t = huffman_tree(huffman);
    huffman_m = huffman_map(huffman_t);    

    REQUIRE(huffman_m.at('A').size() <  huffman_m.at('B').size());
    std::cout << "/************************* FIN TEST HUFFMAN MAP *************************/ \n";

}

TEST_CASE ("Test final"){
    std::vector<Node> huffman;
    std::map<char, std::string> huffman_m;
    Tree huffman_t;

    huffman = huffman_init("Ceci est un exemple de code de Huffman.");
    huffman_t = huffman_tree(huffman);
    huffman_m = huffman_map(huffman_t);    

    REQUIRE(huffman_m.at('e').size() <  huffman_m.at('c').size());
}


// Fin //-------------------------------------------------------------------------------------------
