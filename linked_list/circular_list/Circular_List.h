
template <typename T>
class Circular_List {
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
    Circular_List() {
        front_of_queue = nullptr;
        front_of_queue->next = back_of_queue;
        back_of_queue= nullptr;
        back_of_queue->next = front_of_queue;
        num_items=0; }
    ~Circular_List();
    void pushBack(const T&);
    void pushFront(const T&);
    T& front();
    void popFront();
    void display();
    bool empty() const;
    size_t size() const;

};
template <typename T>
void Circular_List<T>::pushBack(const T& item)
{
        ListNode *temp = back_of_queue;
        back_of_queue = new ListNode(item);
        temp->next = back_of_queue;
        back_of_queue->next = front_of_queue;

        num_items++;
}
template <typename T>
void Circular_List<T>::pushFront(const T& item)
{
        ListNode *temp = front_of_queue;
        front_of_queue = new ListNode(item);
        front_of_queue->next = temp;
        num_items++;
}

template<typename T>
T& Circular_List<T>::front()
{
    return front_of_queue->value;
}
template <typename T>
void Circular_List<T>::popFront()
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
bool Circular_List<T>::empty() const
{
    return front_of_queue == nullptr;
}
template <typename T>
size_t Circular_List<T>::size() const
{
    return num_items;
}
template <typename T>
Circular_List<T>::~Circular_List<T>()
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
void Circular_List<T>::display()
{
    ListNode *nodePtr = front_of_queue;
    ListNode *secPtr = front_of_queue->next;
    if (empty()) return;
    while ( nodePtr->value != secPtr->value ){
        std::cout << nodePtr->value << " --> ";
        nodePtr = nodePtr->next;
        secPtr = secPtr->next->next;
    }
    std::cout << std::endl;
}



