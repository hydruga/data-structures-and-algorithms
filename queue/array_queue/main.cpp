#include <iostream>
using namespace std;


template<typename Item_Type>
class queue {
public:
    queue();
    void push(const Item_Type& item);
    Item_Type& front();
    const Item_Type& front() const;
    void pop();
    bool empty() const;
    size_t size() const;
    void reallocate();
private:
    static const size_t DEFAULT_CAPACITY =10;
    size_t capacity;
    size_t num_items;
    size_t front_index;
    size_t rear_index;
    Item_Type* the_data;

}; // end of class

template <typename Item_Type>
queue<Item_Type>::queue(): capacity(DEFAULT_CAPACITY), num_items(0),
    front_index(0), rear_index(DEFAULT_CAPACITY-1),
    the_data(new Item_Type[DEFAULT_CAPACITY]){}

template<typename Item_Type>
void queue<Item_Type>::push(const Item_Type& item){
        if (num_items == capacity){
            reallocate();
        }
        num_items++;
        rear_index = (rear_index + 1) % capacity;
        the_data[rear_index] = item;
    }
template <typename Item_Type>
Item_Type& queue<Item_Type>::front(){
    return the_data[front_index];
}
template<typename Item_Type>
const Item_Type& queue<Item_Type>::front() const{
    return the_data[front_index];
}

template<typename Item_Type>
void queue<Item_Type>::pop(){
    front_index = (front_index + 1) % capacity;
    num_items--;
}

template<typename Item_Type>
bool queue<Item_Type>::empty() const {
    return num_items==0;
}
template<typename Item_Type>
size_t queue<Item_Type>::size() const{
    //exercise
}
template<typename Item_Type>
void queue<Item_Type>::reallocate(){
    size_t new_capacity = 2 * capacity;
    Item_Type* new_data = new Item_Type[new_capacity];
    size_t j = front_index;
    for (size_t i = 0; i < num_items; i++){
        new_data[i] = the_data[j];
        j = (j+1)%capacity;
    }
    front_index = 0;
    rear_index = num_items -1;
    capacity = new_capacity;
    std::swap(the_data, new_data);

    delete[] new_data;
}






int main() {
    queue<int> testq;
    //std::cout << testq.size();
    testq.push(83);
    testq.push(83);
    testq.push(92);
    testq.push(41);
    testq.push(101);
    testq.push(37);
    testq.push(14);

    cout << testq.front();
    testq.push(23);
    testq.pop();
    testq.pop();
    cout << testq.front();


    return 0;
}
