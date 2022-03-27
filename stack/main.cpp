#include <iostream>
#include <vector>
#include <string>

class StringReverser{
private:
    std::vector<char> vec;
    int maxSize;
    int top;
public:
    StringReverser(int max) : maxSize(max), top(-1)
    {
        vec.resize(maxSize);
    }
    void push(char j)
    {
        vec[++top] = j;
    }
    char pop()
    {
        return vec[top--];
    }
    char peek()
    {
        return vec[top];
    }
    bool isEmpty()
    {
        return (top == -1);
    }



};

int main() {
    std::cout << "Please input a sentence "<< std::endl;
    std::string greeting;
    std::getline (std::cin, greeting);
    StringReverser rev(greeting.size());
    for (int i=0; i < greeting.size(); i++)
    {
        rev.push(greeting[i]);
    }
    while (!rev.isEmpty())
    {
        std::cout << rev.pop();
    }

    return 0;
}
