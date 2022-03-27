#include <iostream>
#include <queue>
using namespace std;

template<typename Item_Type>
class BinaryTree {
private:
    struct TreeNode {
        Item_Type value;
        TreeNode *left;
        TreeNode *right;
        bool is_red;
        TreeNode(Item_Type v, TreeNode *lPtr = nullptr, TreeNode *rPtr = nullptr, bool red = true) //This allows for default nullptrs on left and right
        {
            value= v;
            left = lPtr;
            right = rPtr;
            is_red = red;
        }
    };
    TreeNode *root;
    bool insert(TreeNode *&, Item_Type); // we have a private insert that makes changes to root.
    void displayInOrder(TreeNode *) const;
    void displayPreOrder(TreeNode *) const;
    void displayPostOrder(TreeNode *) const;
    void BFS(TreeNode *) const;
    void move_black_down(TreeNode *);


public:
    BinaryTree()
    {
        root = nullptr; //Don't forget your constructor!!!
    }
    bool insert(Item_Type data) {
        if (!root) {
            root = new TreeNode(data);
            root->is_red = false;
            return true;
        } else {
            bool return_value = insert(this->root, data);
            set_red(this->root, false);
            return return_value;
        }
    }

    void rotate_right(TreeNode *& local_root)
    {
        TreeNode *temp = local_root->left;
        local_root->left = temp->right;
        temp->right = local_root;
        local_root = temp;
    }
    void rotate_left(TreeNode *& local_root)
    {
        TreeNode *temp = local_root->right;
        local_root->right = temp->left;
        temp->left = local_root;
        local_root = temp;
    }
    bool find(Item_Type);
    void displayInOrder() const
    {
        displayInOrder(root);
    }
    void displayPreOrder() const
    {
        displayPreOrder(root);
    }
    void displayPostOrder() const
    {
        displayPostOrder(root);
    }
    void BFS() const
    {
        BFS(root);
    }
    bool is_red(TreeNode * node)
    {
    if (node != nullptr) {
        return node->is_red;
    } else {
        return false;
    }
}
    void set_red(TreeNode * node, bool red)
    {
        if (node != nullptr)
            node->is_red = red;
    }
};
template<typename Item_Type>
void BinaryTree<Item_Type>::move_black_down(TreeNode *tree) {
    // see if both children are red
    if (is_red(tree->left) && is_red(tree->right)) {
        //make them black and local root red
        set_red(tree->left, false);
        set_red(tree->right, false);
        set_red(tree, true);
    }
}
//Modified to check for red black
template<typename Item_Type>
bool BinaryTree<Item_Type>::insert(TreeNode *&tree,Item_Type data) {
        if (data < tree->value) {
            if (tree->left == nullptr) {
                tree->left = new TreeNode(data);
                return true;
            }
            else {
                // Check for two red children, swap colors if found
                move_black_down(tree);
                // Recusively insert into the left subtree
                bool return_value = insert(tree->left, data);
// See if the left-child is red
                if (is_red(tree->left)) {
                    // Need to check grandchildren
                    // Now check left grand child
                    if (is_red(tree->left->left)) {
                        // Child and left-left grandchild are both red
// Need to change colors and rotate
                        set_red(tree->left, false);
                        set_red(tree, true);
                        rotate_right(tree);
                        return return_value;
                    }
// Else check right grandchild
                    else if (is_red(tree->left->right)) {
                        // This will require a double rotation.
                        set_red(tree->left->right, false);
                        set_red(tree, true);
                        rotate_left(tree->left);
                        rotate_right(tree);
                        return return_value;
                    }
                    // else do nothing, the grandchildren are black
                } // else do nothing, the left child is black
                return return_value;
            }
        }
        else if (tree->value < data) {

        }
        else {
            return false;
        }
    }

template<typename Item_Type>
bool BinaryTree<Item_Type>::find(Item_Type data)
{
    {
        TreeNode *tree = root;
        while(tree)
        {
            if(tree->value == data)
                return true;
            else if (data < tree->value)
                tree = tree->left;
            else
                tree = tree->right;
        }
        return false;
    }
};
template<typename Item_Type>
void BinaryTree<Item_Type>::displayInOrder(TreeNode *tree) const
{
    if(tree)
    {
        displayInOrder(tree->left);
        cout << tree->value << " ";
        displayInOrder(tree->right);
    }
}
template<typename Item_Type>
void BinaryTree<Item_Type>::displayPreOrder(TreeNode *tree) const
{
    if(tree)
    {

        cout << tree->value << " ";
        displayPreOrder(tree->left);
        displayPreOrder(tree->right);
    }
}
template<typename Item_Type>
void BinaryTree<Item_Type>::displayPostOrder(TreeNode *tree) const
{
    if(tree)
    {
        displayPostOrder(tree->left);
        displayPostOrder(tree->right);
        cout << tree->value << " ";

    }
}
template<typename Item_Type>
void BinaryTree<Item_Type>::BFS(TreeNode *tree) const
{
    if(tree)
    {
            queue<TreeNode *> q;
            q.push(tree);
            while(!q.empty())
            {
                TreeNode *t = q.front();
                cout << t->value << " ";
                q.pop();

                if(t->left != nullptr)
                    q.push(t->left);
                if(t->right != nullptr)
                    q.push(t->right);

            }
    }
}

class tree_menu {
public:
    tree_menu() //constructor
    {
        char menu='C';
        BinaryTree<std::string> sTree;
        while (menu == 'C') {
            {
                char entry;
                cout << "******* Welcome to  Menu *******\n\n";
                cout << "Enter [X] to Exit \n";
                cout << "Enter [I] to Insert \n";
                cout << "Enter [F] to find data\n";
                cout << "Enter [B] to Breadth First Search of Tree\n";
                cin >> entry;
                system("clear");

                switch (toupper(entry)) {
                    case 'X' :
                        menu = entry;
                        break;
                    case 'I' : {
                        cout << "Enter string value to insert " << endl;
                        string val;
                        cin >> val;
                        sTree.insert(val);
                    }
                        break;
                    case 'F' : {
                        cout << "Enter the string to search for "<< endl;
                        string val;
                        cin >> val;
                        if(sTree.find(val))
                        { std::cout << val << " was found in tree.\n"; }
                        else { std::cout << val <<" was not in tree.\n"; }
                    }
                         break;
                    case 'B' : {
                        cout << "Level Order Traversal results: \n";
                        sTree.BFS();
                    }
                    case 'D' : {
                        cout << "In Order Display: \n";
                        sTree.displayInOrder();
                    }
                }

            }
        }
    }
    ~tree_menu(){ std::cout << "\nGoodbye!"; };
};

int main() {
    tree_menu menu;
    return 0;
}
