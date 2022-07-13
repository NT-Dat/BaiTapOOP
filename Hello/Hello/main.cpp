#include <iostream>
#include <vector>
#include <list>
#include <memory>
#include<map>
using namespace std;

template <class T> class Vector{
private:
    int size;   // bien luu do dai cua vector
    int capacity;   // bien luu dung luong cua vector
    T *array;  // tao con tro chua mang
    void expand(int newCapacity); // ham tang dung luong vector
public:
    Vector();  // ham tao vector
    ~Vector(); // ham huy vector
    Vector & operator=(Vector & rhs); //  ham nap chong toan tu gan
    int Size(); // ham tra ve kich thuoc
    bool empty(); // ham kiem tra vector giong
    T & operator[](int index);  // ham nap chong toan tu truy cap chi so vector
    void push_back(T newElement); // ham day phan tu vao cuoi vector
    void pop_back();  //ham xoa phan tu cuoi vector
    void insert(int pos, T newElement); // ham them phan tu vao vi tri pos
    void erase(int pos); //ham xoa phan tu tai vi tri pos
    void clear(); // ham xoa tat ca cac phan tu vector
};

template <class T> Vector<T>::Vector()
    {
        this->size = 0;
        this->capacity = 10;
        this->array = new T[capacity];
    }

template <class T> Vector<T>::~Vector()
    {
        delete[] this->array;
    }

template <class T> Vector<T>& Vector<T>::operator=(Vector & rhs)
    {
        if (this != &rhs) // ngan can tu sao chep
        {
            delete[] this->array;          // xoa mang hien tai
            this->size = rhs.size;         // dat kich thuoc moi
            this->capacity = rhs.capacity; // dat dung luong moi
            this->array = new T[capacity]; // tao mang moi

            // Sao chep cac phan tu tu phai sang trai
            for (int i = 0; i < this->size; i++)
                this->array[i] = rhs.array[i];
        }

        return *this; // tra ve vector ve trai sau khi gan xong
    }

template <class T> int Vector<T>::Size()
{
        return this->size;
}

template <class T> bool Vector<T>::empty()
    {
        return (this->size == 0);
    }

template <class T> T & Vector<T>::operator[](int index)
    {
        return this->array[index];
    }

template <class T>void Vector<T>::expand(int newCapacity)
{
        if (newCapacity <= this->size)
            return;

        T * old = this->array;            // old tro toi mang cu
        this->array = new T[newCapacity]; // array tro toi mang moi

        for (int i = 0; i < this->size; i++)
            this->array[i] = old[i];      // sao chep phan tu tu mang cu sang mang moi

        delete[] old;               // xoa mang cu
        this->capacity = newCapacity;     // dat dung luong moi
}

template <class T> void Vector<T>::push_back(T newElement)
    {
        // Gap doi dung luong neu vector day
        if (this->size == capacity)
            expand(2 * this->size);

        // Chen phan tu moi vao ngay sau phan tu cuoi cung
        this->array[this->size] = newElement;

        // Tang kich thuoc
        this->size++;
    }

template <class T> void Vector<T>::pop_back()
    {
        this->size--;
    }

template <class T> void Vector<T>::insert(int pos, T newElement)
    {
        // Gap doi dung luong neu vector day
        if (this->size == this->capacity)
            expand(2 * size);

        // Dich cac phan tu sang phai de tao cho trong cho viec chen
        for (int i = this->size; i > pos; i--)
            this->array[i] = this->array[i - 1];

        // Dat phan tu moi vao vi tri chen
        this->array[pos] = newElement;

        // Tang kich thuoc
        this->size++;
    }

template <class T> void Vector<T>::erase(int pos)
    {
        // Dich cac phan tu sang trai de lap day cho trong de lai do viec xoa
        for (int i = pos; i < this->size - 1; i++)
            this->array[i] = this->array[i + 1];

        // Giam kich thuoc
        this->size--;
    }

template <class T> void Vector<T>::clear()
    {
        this->size = 0;
    }

class A{
public:
    string name;
    A(){cout << "Constructor A\n";}
    virtual ~A() {cout << "Destrutor A\n";}
    virtual void Func(void){
        cout << "Func A\n";
    }
};

class B : public A{
public:
    B(){cout << "Constructor B\n";}
    ~B() {cout << "Destrutor B\n";}
    void Func(void){
        cout << "Func B\n";
    }
};

int main()
{   
    return 0;
 }
