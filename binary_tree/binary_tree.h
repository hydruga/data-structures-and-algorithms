
#ifndef BTREE_BINARY_TREE_H
#define BTREE_BINARY_TREE_H
#include <sstream>
//try and use smart_pointer and ADT

template<typename T>
class BNode{
public:
    T data;
    BNode<T> *left;
    BNode<T> *right;
    BNode(): data(val),left(nullptr), right(nullptr) {}//constructor
    ~BNode(){ std::cout << " Removing Node " << data << " "; } //destructor
    virtual std::string to_string() const {
        std::ostringstream os;
        os << data;
        return os.str();
    }
} //end BNode class



template<typename T>
std::ostream& operator<<(std::ostream& out, const BNode& node){
    return out << node.to_string();
}

template<typename T>
class binary_tree {
public:
        binary_tree() : root(nullptr){} //constructor empty binary tree

        binary_tree(const T& the_data,
                    const binary_tree<T>& left_child = binary_tree(),
                    const binary_tree<T>right_child = binary_tree()) :
                    root(new BNode<T>(the_data, left_child.root, right_child.root)) { }

        virtual ~binary_tree(){ }
        binary_tree<T> get_left_subtree() const;
        binary_tree<T> get_right_subtree()const;
        const T& get_data() const;
        bool is_leaf() const;
        virtual std::string to_string() const;
        static binary_tree<T> read_binary_tree(std::istream& in);

protected:
        binary_tree(BNode<T>* new_root) : root(new_root) {}
        BNode<T>* root;
};

template<typename T>
binary_tree<T> //return type
binary_tree<T>::get_left_subtree() const
{
    if(root == nullptr){
        throw std::invalid_argument("get_left_subtree on empty tree")
    }
    return binary_tree<T>(root->left);
}

template<typename T>
binary_tree<T> //return type
binary_tree<T>::get_right_subtree() const
{
    if(root == nullptr){
        throw std::invalid_argument("get_right_subtree on empty tree")
    }
    return binary_tree<T>(root->right);
}

template<typename T>
bool binary_tree<T>::is_leaf() const
{
    if (root != nullptr){
        return root->left == nullptr && root->right == nullptr;
    }else
        return true;
}


#endif //BTREE_BINARY_TREE_H
