#ifndef LIST_PVM_2023
#define LIST_PVM_2023
#include <stdexcept>
//TODO
template<typename T>
class List
{
private:
    size_t size_;
    node* beg_;
    node* end_;
    struct node
    {
        T data__;
        node* next__;
    };
public:
    List(size_t size=0);
    size_t getSize()const;
    ~List();
    void addElement(T elem);
    void removeElement(size_t pos);
    T getElement(size_t  pos);
    void setElement(size_t pos, T value);

    List(const List&);
    List(List&&);
    List& operator=(const List&);
    List& operator=(List&&);
};

void List<T>::setElement(size_t pos, T value) {
    // this func set element with value on pos 
    if (pos >= size_) {
        throw std::out_of_range("pos out of range");
    }

    node* current = beg_;
    for (size_t i = 0; i < pos; i++) {
        current = current->next__;
    }

    current->data__ = value;
}
#endif // !LIST_PVM_2023
