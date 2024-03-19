#ifndef LIST_PVM_2023
#define LIST_PVM_2023
#include <stdexcept>
//TODO
template<typename T>
class List //Need T()
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
    node* caret_;
public:
    List(size_t size=0):size_(size);
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

    void rewindCaret();
    bool isCaretAtEnd();
    T getElement();
    void moveToNextPos();
};

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
List<T>::List(size_t size): size_(size){
    if(size==0){
        size_=0;
        beg_=nullptr;
        end_=nullptr;
    } else {
        for(size_t i=0; i<size; ++i){
            this->addElement(T());
        }
    }
}

template<typename T>
List<T>::~List(){
    node* now;
	while(beg_){
		now = beg_->next;
		delete beg_;
		beg_ = now;
	}
	beg_ = end_ = nullptr;
	size_ = 0;
}

template<typename T>
void List<T>::addElement(T elem)
{
    node Adder=new node;
    Adder.data__ = elem;
    Adder.next__ = nullptr;
    if(size_!=0)
    {
        end_->next__=&Adder;
        end_=&Adder;
    }
    else
    {
        beg_=&Adder;
        end_=&Adder;
    }
    ++size_;
}

template<typename T>
void List<T>::removeElement(size_t pos)
{
		node* current = beg_;
		node* prev = nullptr;
		size_t i=0;
		while (current != nullptr) {
			if (i == pos) {
				if (prev == nullptr) {
					beg_ = current->next__;
				} else {
					prev->next__ = current->next__;
				}

				if (current == end_) {
					end_ = prev;
				}

				node* nextNode = current->next__;
				delete current;
				current = nextNode;
			} else {
				prev = current;
				current = current->next__;
			}
		}
}

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

template<typename T>
void List<T>::moveToNextPos(){
    caret_=caret_->next__;
}

#endif // !LIST_PVM_2023
