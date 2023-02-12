#ifndef AAC_ALGORITHMS_HUFFMAN_HPP
#define AAC_ALGORITHMS_HUFFMAN_HPP

#include <vector>
#include <string>
#include <queue>
#include <map>
#include <stack>
#include "tree.hpp"


std::vector<Node> huffman_init(std::string &&);
Tree huffman_tree(std::vector<Node> &);
std::map<char, std::string> huffman_map(Tree huffman_tree);
//std::string huffman_decode(Tree &);


#endif