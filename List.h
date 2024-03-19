#ifndef LIST_PVM_2023
#define LIST_PVM_2023

//TODO
template<typename T>
class List
{
private:
    struct node
    {
        T data__;
        node* next__;
    };
    size_t size_;
    node* beg_;
    node* end_;
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

template<typename T>
void List<T>::addElement(T elem)
{
    node Adder;
    Adder.data__=elem;
    Adder.next__=nullptr;
    end_->next__=&Adder;
    end_=&Adder;
}

#endif // !LIST_PVM_2023
