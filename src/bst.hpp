#pragma once

// include this library to use NULL, otherwise use nullptr instead
#include <cstddef>
#include <iostream>
#include "node.hpp"

template<class T>
class BST{
public:
    // Constructor for the BST class, creates an empty tree
    BST(void);
    // Destructor for the BST class, destroys the tree
    ~BST(void);
    // Inserts data into the tree
    // param: The data to be inserted into the tree
    void insert(T);
    // Removes data from the tree
    // param: The data to be removed from the tree
    void remove(T);
    // Performs an inorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *inorder(void);
    // Performs an postorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *postorder(void);
    // Performs an preorder traversal
    // returns: pointer to a vector containing the tree traversal
    std::vector<T> *preorder(void);
    // Searches the tree for a given value
    // param: the data to search for
    // returns: a pointer to the node containing the data or NULL if the data
    //          was not found
    Node<T> *search(T);
    // Gets the current number of nodes in the tree
    // returns: the number of nodes in the tree
    int get_size(void);
private:
    // the root node of the tree
    Node<T> *root;
    // the number of nodes in the tree
    int node_count;
};

template<class T>
BST<T>::BST()
{
    root = NULL;
    node_count = 0;
}

template<class T>
BST<T>::~BST()
{
    root = NULL;
    while(root != NULL)
    {
        remove(root->get_data());
    }
}

template<class T>
 std::vector<T> * BST<T>::inorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}


template<class T>
 std::vector<T> * BST<T>::preorder()
{
    std::vector<T> *vec = new std::vector<T>;
    return vec;
}


template<class T>
 std::vector<T> * BST<T>::postorder()
{
    std::vector<T> *vec = new std::vector<T>;

    return vec;
}

template<class T>
void BST<T>::insert(T new_data)
{
    Node<T> *new_node = new Node<T>(new_data);
    Node<T> *current = root;
    if(root == NULL)
    {
        root->set_data(new_data);
        root->set_left(NULL);
        root->set_right(NULL);
    }
    else
    {
            while(current != NULL){
            if(new_node->get_data() < current->get_data())
            {
                if(current->get_left() == NULL)
                {
                    new_node->set_left(current);
                    current = NULL;
                }
                else
                {
                    current->set_left(current);
                }
            }

            else
            {
                if(current->get_right() == NULL)
                {
                    new_node->set_right(current);
                    current = NULL;
                }
                else
                {
                    current->set_right(current);
                }
            }
        }
        new_node->set_left(NULL);
        new_node->set_right(NULL);
    }
}


template<class T>
Node<T> *BST<T>::search(T val)
{
    Node<T> *cur = root;
    Node<T> *tmp = new Node<T>(val);
    if(root == NULL)
    {
        return NULL;
    }
    else if(val == root->get_data())
    {
        return root;
    }
    else
    {
        while(cur != NULL)
        {
            if(val > cur->get_data())
            {
                if(tmp == cur->get_left())
                {
                    return cur->get_left();
                    cur = NULL;
                }
                else
                {
                    cur->set_left(cur);
                }
            }
            else if(tmp == cur->get_right())
            {
                return cur->get_right();
                cur = NULL;
            }
                else
                {
                    cur->set_right(cur);
                }
        }
    }
    return NULL;
}



template<class T>
void BST<T>::remove(T val)
{
    Node<T> *del;
    if(search(val) != NULL)
    {
        
    }
}



template<class T>
int BST<T>::get_size()
{
    int count = 0, count2 = 0;
    Node<T> *cur = root;
    Node<T> *cur2 = root;
    if(root == NULL)
    {
        return 0;
    }
    while(cur != NULL)
    {
        cur->set_left(cur);
        count++;
    }
    while(cur2 != NULL)
    {
        cur2->set_right(cur2);
        count2++;
    }
    return count + count2;
}