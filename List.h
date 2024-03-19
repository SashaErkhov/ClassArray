#ifndef LIST_PVM_2023
#define LIST_PVM_2023
#include <stdexcept>
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
    List(size_t size=0){
        size_=0;
        beg_=nullptr;
        end_=nullptr;
    }
    size_t getSize()const;
    ~List(){
        node* now;
	    while(beg_){
		    now = beg_->next;
		    delete beg_;
		    beg_ = now;
	    }
	    beg_ = end_ = nullptr;
	    size_ = 0;
    }
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
    Adder.data__ = elem;
    Adder.next__ = nullptr;
    ++size_;
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

#endif // !LIST_PVM_2023
