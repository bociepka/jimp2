//
// Created by Bartek on 19.03.2018.
//

#include "SmartTree.h"
#include <ostream>
#include <iostream>
#include <string>
#include <memory>
#include <vector>

namespace datastructures{

    std::unique_ptr <SmartTree> CreateLeaf(int value){
        std::unique_ptr<SmartTree> leaf = std::make_unique<SmartTree>();
        leaf->value=value;
        return leaf;
    }

    std::unique_ptr<SmartTree> InsertLeftChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> left_subtree){
        auto parent = std::make_unique<SmartTree>();
        parent = move(tree);
        parent -> left = move(left_subtree);
        return parent;
    }

    std::unique_ptr<SmartTree> InsertRightChild(std::unique_ptr<SmartTree> tree, std::unique_ptr<SmartTree> right_subtree){
        auto parent = std::make_unique<SmartTree>();
        parent = move(tree);
        parent -> right = move(right_subtree);
        return parent;
    }

    void PrintTreeInOrder(const std::unique_ptr<SmartTree> &unique_ptr, std::ostream *out){
        if(unique_ptr->left!=nullptr){
            PrintTreeInOrder(move(unique_ptr->left), out);
        }
        *out << unique_ptr->value<<", ";
        if(unique_ptr->right!=nullptr){
            PrintTreeInOrder(move(unique_ptr->right), out);
        }
    }
}
