#ifndef LIST_PVM_2023
#define LIST_PVM_2023
#include <stdexcept>

//TODO: delete comments

template<typename T>
class List //Need T()
{
private:
    struct node
    {
        T data__;
        node* next__;
        //node();
        //~node();
    };
    size_t size_;
    node* beg_;
    node* end_;
public:
    List(size_t size = 0)
    {
        size_ = 0;
        beg_ = nullptr;
        end_ = nullptr;
        if (size != 0)
        {
            for (size_t i = 0; i < size; ++i)
            {
                this->addElement(T());
            }
        }
    }
    size_t getSize() const { return size_; };
    ~List();
    void removeElement(size_t pos);
    T getElement(size_t  pos);
    void setElement(size_t pos, T value);

    List(const List&);
    List(List&&);
    List& operator=(const List&);
    List& operator=(List&&);

    class iterator {
        node* current;
    public:
        iterator(node* el = nullptr) : current(el) {}
        iterator& operator++();
        //iterator& operator--();
        iterator operator++(int);
        //iterator& operator--(int);
        T& operator*() { return current->data__; }
        T& operator*() const { return current->data__; }
        bool operator==(const iterator& other) const { return current == other.current; }
        bool operator!=(const iterator& other) const { return current != other.current; }
        friend List;
    };
    iterator begin() const { return iterator(beg_); }
    iterator end() const { return iterator(nullptr); }
    void insert(const iterator& pos, const T& value);
    iterator addElement(T elem);
};

template<typename T>
void List<T>::insert(const iterator& pos, const T& value)
{
    node* new_node = new node{ value, nullptr };

    if (pos.current == beg_) {
        // Insert at the begin of the node
        new_node->next__ = beg_;
        beg_ = new_node;
        if (size_ == 0) end_ = new_node;
    }
    else {
        // Insert at the mid or end of the node
        node* previous = beg_;
        while (previous && previous->next__ != pos.current) {
            previous = previous->next__;
        }

        new_node->next__ = previous->next__;
        previous->next__ = new_node;

        if (previous == end_) {
            end_ = new_node;
        }
    }

    ++size_;
}

template<typename T>
List<T>::List(const List& other) : size_(other.size_), beg_(nullptr), end_(nullptr) {
    if (other.size_ == 0) {
        return;
    }

    node* current = other.beg_;
    while (current != nullptr) {
        addElement(current->data__);
        current = current->next__;
    }
}

template<typename T>
List<T>::List(List&& other) : size_(other.size_), beg_(other.beg_), end_(other.end_) {
    other.size_ = 0;
    other.beg_ = nullptr;
    other.end_ = nullptr;
}


template<typename T>
List<T>::~List() {
    node* now;
    while (beg_) {
        /*now = beg_->next__;
        delete beg_;
        beg_ = now;*/
        now = beg_;
        beg_ = beg_->next__;
        delete now;
    }
    beg_ = end_ = nullptr;
    size_ = 0;
}

template<typename T>
typename List<T>::iterator List<T>::addElement(T elem)
{
    node* Adder = new node;
    Adder->data__ = elem;
    Adder->next__ = nullptr;
    if (size_ != 0)
    {
        end_->next__ = Adder;
        end_ = Adder;
    }
    else
    {
        beg_ = Adder;
        end_ = Adder;
    }
    ++size_;
    return iterator(Adder);
}

template<typename T>
void List<T>::removeElement(size_t pos)
{
    node* current = beg_;
    node* prev = nullptr;
    size_t i = 0;
    while (current != nullptr) {
        if (i == pos) {
            if (prev == nullptr) {
                beg_ = current->next__;
            }
            else {
                prev->next__ = current->next__;
            }

            if (current == end_) {
                end_ = prev;
            }

            node* nextNode = current->next__;
            delete current;
            current = nextNode;
        }
        else {
            prev = current;
            current = current->next__;
        }
        ++i;
    }
    --size_;
} 

// !!! Needs fix and review !!!
//template<typename T>
//List<T>& List<T>::operator=(const List& other) {
//    if (this != &other) {
//        while (beg_ != nullptr) {
//            removeElement(beg_);
//        }
//        size_ = 0;
//        beg_ = end_ = nullptr;
//        caret_ = other.beg_;
//        while (caret_ != nullptr) {
//            addElement(caret_->data__);
//            caret_ = caret_->next__;
//        }
//    }
//    return *this;
//}
//
//template<typename T>
//List<T>& List<T>::operator=(List&& other) {
//    if (this != &other) {
//        while (beg_ != nullptr) {
//            removeElement(beg_);
//        }
//        size_ = 0;
//        beg_ = end_ = nullptr;
//
//        size_ = std::move(other.size_);
//        beg_ = std::move(other.beg_);
//        end_ = std::move(other.end_);
//
//        other.size_ = 0;
//        other.beg_ = other.end_ = nullptr;
//    }
//    return *this;
//}

template<typename T>
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

template<typename T>
T List<T>::getElement(size_t pos)
{
    if (pos < 0 || pos >= size_) {
        throw std::out_of_range("wrong position");
    }

    node* current = beg_;

    for (size_t i = 0; i < pos; i++) {
        current = current->next__;
    }

    return current->data__;
}

//template<typename T>
//List<T>::node::node(){
//    next__=nullptr;
//    //data__=nullptr;
//}

//template<typename T>
//List<T>::node::~node(){
//    delete next__;
//    //delete data__;
//}

template<typename T>
typename List<T>::iterator& List<T>::iterator::operator++() {
    if (current) {
        current = current->next__;
    }
    else {
        throw "Iterator: out of bounds";
    }
    return *this;
}

template<typename T>
typename List<T>::iterator List<T>::iterator::operator++(int) {
    node* tmp = current;
    if (current) {
        current = current->next__;
    }
    else {
        throw "Iterator: out of bounds";
    }
    return iterator(tmp);
}

//template<typename T>
//typename List<T>::iterator& List<T>::iterator::operator--(){
//    node* parent=nullptr;
//    node* now=beg_;
//    while(now!=nullptr && now!=current){
//        parent=now;
//        now=now->next__;
//    }
//    if(now!=current){
//        throw "Iterator: out of bound";
//    }
//    current=parent;
//    return *this;
//}

//template<typename T>
//typename List<T>::iterator& List<T>::iterator::operator--(int){
//    node* parent=nullptr;
//    node* now=beg_;
//    while(now!=nullptr && now!=current){
//        parent=now;
//        now=now->next__;
//    }
//    if(now!=current){
//        throw "Iterator: out of bound";
//    }
//    current=parent;
//    return iterator(now);
//}

#endif // !LIST_PVM_2023
