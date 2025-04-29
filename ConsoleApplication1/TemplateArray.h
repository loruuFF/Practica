#pragma once
#include <iostream>
using namespace std;

template<class T>
class Array {
    T* mas = nullptr;
    int size;

public:
    Array();                                
    Array(const Array<T>& other);           
    Array(Array<T>&& other);                
    Array<T>& operator=(const Array<T>& other); 
    Array<T>& operator=(Array<T>&& other);      
    ~Array();                               

    void Output() const;

    T& operator[](int index);
    int GetSize() const { return size; }
    const T* GetPtr() const { return mas; }
    void SetSize(int s);
    void SetPtr(T* ptr, int size); // move

    void AddLast(const T& value);
    void DellLast();
    void Add(int index, const T& value);
    void Dell(int index);

    template<typename U>
    friend ostream& operator<<(ostream& out, const Array<U>& arr);

    template<typename U>
    friend istream& operator>>(istream& in, Array<U>& arr);
};

template<class T>
Array<T>::Array() {
    size = 10;
    mas = new T[size];
    for (int i = 0; i < size; i++)
        mas[i] = T(); 
}

template<class T>
Array<T>::Array(const Array<T>& other) {
    size = other.size;
    mas = new T[size];
    for (int i = 0; i < size; ++i)
        mas[i] = other.mas[i];
}

template<class T>
Array<T>::Array(Array<T>&& other) {
    mas = other.mas;
    size = other.size;
    other.mas = nullptr;
    other.size = 0;
}

template<class T>
Array<T>& Array<T>::operator=(const Array<T>& other) {
    if (this != &other) {
        delete[] mas;
        size = other.size;
        mas = new T[size];
        for (int i = 0; i < size; ++i)
            mas[i] = other.mas[i];
    }
    return *this;
}

template<class T>
Array<T>& Array<T>::operator=(Array<T>&& other) {
    if (this != &other) {
        delete[] mas;
        mas = other.mas;
        size = other.size;
        other.mas = nullptr;
        other.size = 0;
    }
    return *this;
}

template<class T>
Array<T>::~Array() {
    delete[] mas;
}

template<class T>
T& Array<T>::operator[](int index) {
    return mas[index];
}

template<class T>
void Array<T>::SetSize(int s) {
    if (s < 0) return;
    T* temp = new T[s]{};
    for (int i = 0; i < (s < size ? s : size); i++)
        temp[i] = mas[i];
    delete[] mas;
    mas = temp;
    size = s;
}

template<class T>
void Array<T>::SetPtr(T* ptr, int size) {
    delete[] mas;
    mas = ptr;
    this->size = size;
}

template<class T>
void Array<T>::AddLast(const T& value) {
    T* temp = new T[size + 1];
    for (int i = 0; i < size; i++)
        temp[i] = mas[i];
    temp[size] = value;
    delete[] mas;
    mas = temp;
    size++;
}

template<class T>
void Array<T>::DellLast() {
    if (size == 0) return;
    T* temp = new T[size - 1];
    for (int i = 0; i < size - 1; i++)
        temp[i] = mas[i];
    delete[] mas;
    mas = temp;
    size--;
}

template<class T>
void Array<T>::Add(int index, const T& value) {
    if (index < 0 || index > size) return;
    T* temp = new T[size + 1];
    for (int i = 0; i < index; i++)
        temp[i] = mas[i];
    temp[index] = value;
    for (int i = index; i < size; i++)
        temp[i + 1] = mas[i];
    delete[] mas;
    mas = temp;
    size++;
}

template<class T>
void Array<T>::Dell(int index) {
    if (index < 0 || index >= size) return;
    T* temp = new T[size - 1];
    for (int i = 0; i < index; i++)
        temp[i] = mas[i];
    for (int i = index + 1; i < size; i++)
        temp[i - 1] = mas[i];
    delete[] mas;
    mas = temp;
    size--;
}

template<class T>
void Array<T>::Output() const {
    for (int i = 0; i < size; i++)
        cout << mas[i] << "\t";
    cout << endl;
}

template<typename U>
ostream& operator<<(ostream& out, const Array<U>& arr) {
    for (int i = 0; i < arr.size; i++)
        out << arr.mas[i] << " ";
    return out;
}

template<typename U>
istream& operator>>(istream& in, Array<U>& arr) {
    for (int i = 0; i < arr.size; i++)
        in >> arr.mas[i];
    return in;
}
