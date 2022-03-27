
#ifndef QUEUE_LIST_LIST_QUEUE_H
#define QUEUE_LIST_LIST_QUEUE_H

template <typename T>
class List_Queue {
protected:
    struct ListNode{
        T value;
        ListNode *next;

        ListNode(T item, ListNode *nex = nullptr){
            value=item;
            next=nex;
        };
    };
    ListNode *front_of_queue;
    ListNode *back_of_queue;
    int num_items;
public:
    List_Queue() { front_of_queue = nullptr, back_of_queue= nullptr, num_items=0; }
    ~List_Queue();
    void push(const T&);
    T& front();
    void pop();
    void display();
    bool empty() const;
    size_t size() const;

};
template <typename T>
void List_Queue<T>::push(const T& item)
{
    if(front_of_queue == nullptr)
    {
        back_of_queue = new ListNode(item);
        front_of_queue = back_of_queue;
    }
    else {
        back_of_queue->next = new ListNode(item);
        back_of_queue = back_of_queue->next;
    }
    num_items++;
}
template<typename T>
T& List_Queue<T>::front()
{
    return front_of_queue->value;
}
template <typename T>
void List_Queue<T>::pop()
{
    ListNode *old_front = front_of_queue;
    front_of_queue = front_of_queue->next;
    if (front_of_queue == nullptr)
    {
        back_of_queue = nullptr;
    }
    delete old_front;
    num_items--;
}
template <typename T>
bool List_Queue<T>::empty() const
{
    return front_of_queue == nullptr;
}
template <typename T>
size_t List_Queue<T>::size() const
{
    return num_items;
}
template <typename T>
List_Queue<T>::~List_Queue<T>()
{
    ListNode *nodePtr = front_of_queue;
    while(nodePtr != nullptr)
    {
        ListNode *garbage = nodePtr;
        nodePtr = nodePtr->next;
        delete garbage;
    }
}
template<typename T>
void List_Queue<T>::display()
{
    ListNode *nodePtr = front_of_queue;
    if (empty()) return;
    while (nodePtr){
        std::cout << nodePtr->value << " --> ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}


#endif //QUEUE_LIST_LIST_QUEUE_H
