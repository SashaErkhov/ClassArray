#ifndef LIST_PVM_2023
#define LIST_PVM_2023

//TODO
template<typename T>
class List
{
private:
    
public:
    List(size_t size=0);
    size_t getSize()const;
    ~List();
    void addElement(T elem);
    void removeElement(size_t pos);
    T getElement(size_t  pos);
    void setElement(size_t pos, T value);

    List(const List&);
    List(List&&));
    List& operator=(const List&);
    List& operator=(List&&);
};

#endif // !LIST_PVM_2023
