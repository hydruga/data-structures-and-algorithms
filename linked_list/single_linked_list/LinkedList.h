
#ifndef LINKED_LISTS_LINKEDLIST_H
#define LINKED_LISTS_LINKEDLIST_H

template <typename T>
class LinkedList {
protected:
    struct ListNode{
        T value;
        ListNode *next;


        ListNode(T val, ListNode *nex = nullptr)
        {
            value = val;
            next = nex;
        }
    };
    ListNode *head;

public:
    LinkedList() { head = nullptr; }
    ~LinkedList();
    void insert(T value);
    void deleteNode(T value);
    void display();
    int find(T value);
    bool isEmpty();
};
template <typename T>
bool LinkedList<T>::isEmpty()
{
    return head == nullptr;
}

template <typename T>
void LinkedList<T>::insert(T value)
{
    if (isEmpty())
        head = new ListNode(value);
    else
    {
        ListNode *nodePtr = head;
        while (nodePtr->next != nullptr)
            nodePtr = nodePtr->next;
        nodePtr->next = new ListNode(value);
    }
}//end of add
template <typename T>
void LinkedList<T>::deleteNode(T value)
{
    ListNode  *nodePtr , *previousNodePtr;
    if (isEmpty()) return;
    if (head->value == value)
    {
        nodePtr = head;
        head = head->next;
        delete nodePtr;
    }
    else
    {
        nodePtr = head;
        while(nodePtr != nullptr && nodePtr->value != value)
        {
            previousNodePtr = nodePtr;
            nodePtr = nodePtr->next;
        }
        if (nodePtr)
        {
            previousNodePtr->next = nodePtr->next;
            delete nodePtr;
        }
    }
}
template <typename T>
void LinkedList<T>::display()
{
    ListNode *nodePtr = head;
    if (isEmpty()) return;
    while (nodePtr){
        std::cout << nodePtr->value << " --> ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}

template <typename T>
int LinkedList<T>::find(T value)
{
    int nodePosition=0;
    ListNode *nodePtr = head;
    if (isEmpty()) { return -1; }
    if (!(head->value == value)) {
        while (nodePtr != nullptr && nodePtr->value != value) {
            nodePtr= nodePtr->next;
            ++nodePosition;
            if (nodePtr->value != value && nodePtr == nullptr)
            {
                return -1;
            }
        }
        return nodePosition;
    } else { return 0; }
}
template <typename T>
LinkedList<T>::~LinkedList<T>()
{
    ListNode *nodePtr = head;

    while(nodePtr != nullptr)
    {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}

#endif //LINKED_LISTS_LINKEDLIST_H
