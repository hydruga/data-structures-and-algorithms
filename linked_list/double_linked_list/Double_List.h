//
// Created by xenopheon on 10/17/21.
//

#ifndef WEEK7_DOUBLE_LINKED_LIST_DOUBLE_LIST_H
#define WEEK7_DOUBLE_LINKED_LIST_DOUBLE_LIST_H


template <typename T>
class Double_List {
protected:
    struct ListNode{
        T value;
        ListNode *next;
        ListNode *prev;

        ListNode(T item, ListNode *nex = nullptr, ListNode *p= nullptr){
            value=item;
            next=nex;
            prev = p;
        };
    };
    ListNode *head;
    ListNode *tail;
    int num_items;

public:
    Double_List() { head = nullptr, tail= nullptr, num_items=0; }
    ~Double_List();
    void push_front(const T&);
    void push_back(const T&);
    void pop_front();
    void pop_back();
    void display_backward();
    void display_forward();
    T& front() const;
    T& back() const;
    bool empty() const;
    size_t size() const;

};
template < typename T>
T& Double_List<T>::front() const
{
    return head->value;
}
template < typename T>
T& Double_List<T>::back() const
{
    return tail->value;
}
template <typename T>
void Double_List<T>::push_back(const T& item)
{
    if(tail != nullptr)
    {
        tail->next = new ListNode(item, nullptr, tail);
        tail = tail->next;
        num_items++;
    }
    else //list is empty
    {
        push_front(item);
    }

    num_items++;
}
template<typename T>
void Double_List<T>::push_front(const T& item)
{
    head = new ListNode(item, head, nullptr); //item is value of item, head->next = head, head->prev = nullptr
    if (head->next != nullptr)
    {
        head->next->prev = head;
    }
    if(tail == nullptr)
    {
        tail = head;
    }
    num_items++;
}

template <typename T>
void Double_List<T>::pop_front()
{
    if(head == nullptr)
    {
        throw std::invalid_argument
            ("Attempted to call pop_front() on empty list");
    }
    ListNode *old_front = head;
    head = head->next;
    delete old_front;
    if (head != nullptr)
    {
        head->prev = nullptr;
    }
    else
    {
        tail = nullptr;
    }
    num_items--;
}

template <typename T>
void Double_List<T>::pop_back()
{
    if (tail == nullptr)
        throw std::invalid_argument
        ("Attempted to call pop_back() on empty list");
    ListNode *old_back = tail;
    tail= tail->prev;
    delete old_back;
    if(tail != nullptr)
    {
        tail->next = nullptr;
    }
    else
    {
        head = nullptr;
    }
    num_items--;
}


template <typename T>
size_t Double_List<T>::size() const
{
    return num_items;
}
template <typename T>
Double_List<T>::~Double_List<T>()
{

    while(head != nullptr)
    {
        ListNode *garbage = head;
        head = head->next;
        delete garbage;
    }
    tail = nullptr;
    num_items = 0;
}
template<typename T>
void Double_List<T>::display_forward()
{
    ListNode *nodePtr = head;
    if (head == nullptr) return;
    while (nodePtr){
        std::cout << nodePtr->value << " --> ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}
template<typename T>
void Double_List<T>::display_backward()
{
    ListNode *nodePtr = tail;
    if (head == nullptr) return;
    while(nodePtr){
        std::cout << nodePtr->value << " <-- ";
        nodePtr = nodePtr->prev;
    }
    std::cout << std::endl;
}




#endif //WEEK7_DOUBLE_LINKED_LIST_DOUBLE_LIST_H
