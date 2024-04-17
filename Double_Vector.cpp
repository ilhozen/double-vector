#include "Double_Vector.h"
#include<iostream>
#include <stdexcept>
using namespace std;

Double_vector::Double_vector() :sz(0), array_capacity(100){
    items = new double[array_capacity];
}

Double_vector::Double_vector(double lst[], int n):array_capacity(n){
    items = new double[array_capacity];
    for (int i = 0; i < n; i++) {
        items[i] = lst[i];
    }
    sz = n;
}

Double_vector::Double_vector(int n, double val) :sz{ n }, array_capacity{ n } {
    items = new double[array_capacity];
    for (int i = 0; i < sz; i++) {
        items[i] = val;
    }
}

Double_vector::Double_vector(const Double_vector& x) {
    array_capacity = x.array_capacity;
    sz = x.sz;
    items = new double[array_capacity];
    for (int i = 0; i < x.sz; i++) {
        items[i] = x.items[i];
    }
}

void Double_vector::print()const {
    int i = 0;
    cout << "v={";
    for (; i < sz - 1; i++) {
        cout << items[i]<<",";
    }
    if(sz<=0)
        cout << "}"<<endl;
    else
        cout << items[i] << "}" << endl;
}

void Double_vector::push_back(const double& val) {
    if (sz < this->array_capacity) {
        items[sz] = val;
        sz++;
    }
    else {
        double *new_elements = new double[array_capacity * 2];
        array_capacity *= 2 ;
        for (int i = 0; i < sz; i++)
            new_elements[i] = items[i];
        delete []items;
        items = new_elements;
        items[sz] = val;
        sz++;
    }
}

void Double_vector::push_back( double ls[],int n) {
        double* new_elements = new double[array_capacity +n];
        array_capacity += n;
        for (int i = 0; i < sz; i++)
            new_elements[i] = items[i];
        delete[]items;
        items = new_elements;
        for (int i = 0; i < n; i++)
            items[i + sz] = ls[i];
        sz += n;
        
}

void Double_vector::pop_back(){
    double* new_arr = new double[sz-1];
    for (int i = 0; i < sz-1; i++) {
        new_arr[i] = items[i];
    }
    delete[] items;
    items = new_arr;
    array_capacity = sz-1;
    sz--;
}

void Double_vector::insert(int pos, double value) {
    if (pos < 0 || pos >= sz) {
        cout << "Given position does not exist." << endl;
    }
    else {
        if(sz >= array_capacity){
                double* new_arr = new double[array_capacity * 2];
                array_capacity *= 2;
                for (int i = 0; i < pos; i++) {
                    new_arr[i] = items[i];
                }
                new_arr[pos] = value;
                for (int i = pos + 1; i < sz + 1; i++) {
                    new_arr[i] = items[i - 1];
                }
                delete[] items;
                items = new_arr;
                sz++;
            }
        else {
            for (int i = sz - 1; i >= pos; i--) {
                items[i + 1] = items[i];
            }
            items[pos] = value;
            sz++;
        }
    }
}

void Double_vector::erase(int pos) {
    if (pos < 0 || pos >= sz) {
        cout << "Given position does not exist." << endl;
    }
    else {
        double* new_arr = new double[sz - 1];
        for (int i = 0; i < pos; i++) {
            new_arr[i] = items[i];
        }
        for (int i = pos; i < sz - 1; i++) {
            new_arr[i] = items[i + 1];
        }
        delete[] items;
        items = new_arr;
        array_capacity = sz - 1;
        sz--;
    }
}

int Double_vector::size()const {
    return sz;
}

int Double_vector::max_size()const {
    return array_capacity;
}

void Double_vector::resize(int n, double val) {
    if (n < sz) {
        double* new_arr = new double[n];
        for (int i = 0; i < n; i++) {
            new_arr[i] = items[i];
        }
        delete[] items;
        items = new_arr;
        array_capacity = n;
        sz = n;
    }
    if (n > sz) {
        double* new_arr = new double[n];
        for (int i = 0; i < sz; i++) {
            new_arr[i] = items[i];
        }
        for (int i = sz; i < n; i++) {
            new_arr[i] = val;
        }
        delete[] items;
        items = new_arr;
        array_capacity = n;
        sz = n;
    }
}

int Double_vector::capacity() const{
    return array_capacity * sizeof(double);
}

double& Double_vector::operator[](int pos) {
    return items[pos];
}

const double& Double_vector::operator[](int pos) const {
    return items[pos];
}

const double& Double_vector::at(int pos) const {
    if (pos < 0 || pos >= sz) {
        throw std::out_of_range("Index does not exist.");
    }
    return items[pos];
}

double& Double_vector::at(int pos){
    if (pos < 0 || pos >= sz) {
        throw std::out_of_range("Index does not exist.");
    }
    return items[pos];
}

bool Double_vector::operator==(const Double_vector& rhs)const {
    if (this->sz != rhs.sz) return false;

    for (int i = 0; i < sz; i++)
        if (this->items[i] != rhs.items[i]) {
             return false;
        }
    return true;
    
}
bool Double_vector::operator!=(const Double_vector& rhs)const {
    
    return !(*this == rhs);

}

Double_vector Double_vector::operator+(const Double_vector &other)const {
    Double_vector res;
    int totalCap = this->sz + other.sz;
    if (res.array_capacity < totalCap) {
        res.array_capacity = totalCap;
        delete[]res.items;
    }
    int i;
    for ( i = 0; i < this->sz; i++)
        res.items[i] = this->items[i];
    res.sz = this->sz;
    for (i = 0; i < other.sz; i++)
        res.items[i + res.sz] = other.items[i];
    res.sz = this->sz + other.sz;
    this->print();
    other.print();
    res.print();
    return res;
}

void displayVectorInfo(const Double_vector& vec, const std::string& name) {
    std::cout << "Size of " << name << ": " << vec.size() << "\n";
    std::cout << "Capacity of " << name << ": " << vec.capacity() << "\n";
    std::cout << "Contents of " << name << ": ";
    for (int i = 0; i < vec.size(); ++i) {
        std::cout << vec[i] << " ";
    }
    std::cout << "\n\n";
}