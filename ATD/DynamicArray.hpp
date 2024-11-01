//=================================================================================================================
/**
* Example of implementation of a class that defines dynamic arrays.
*/
//=================================================================================================================
#ifndef DYNAMICARRAY_HPP
#define DYNAMICARRAY_HPP
// Includes
#include <stdexcept> // For std::out_of_range
#include "../Movie/Movie.hpp"
/**
* Class that defines a dynamic array.
*
* @tparam T Type of the elements in the array.
*/
template <typename T>
class DynamicArray {
public:

using value_type = T;
/**
* Default constructor. The array is empty.
*/
DynamicArray() = default;
/**
* Constructor that initializes all elements with a constant value.
*/
DynamicArray(const T& value, unsigned int size) : size_(size), capacity_(size)
{
data_ = new T[capacity_];
for (unsigned int i = 0; i < size_; ++i)
data_[i] = value;
}
/**
* Copy constructor.
*/
DynamicArray(const DynamicArray& other)
{
size_ = other.size_;
capacity_ = other.capacity_;
data_ = new T[capacity_];
for (unsigned int i = 0; i < size_; ++i)
data_[i] = other.data_[i];
}
/**
* Move constructor.
*/
DynamicArray(DynamicArray&& other) noexcept : data_(other.data_),
size_(other.size_), capacity_(other.capacity_)
{
other.data_ = nullptr;
other.size_ = 0;
other.capacity_ = 0;
}
/**
* Destructor. Deallocates the memory.
*/
~DynamicArray()
{
if (data_ != nullptr)
delete[] data_;
}
/**
* Copy assignment operator.
*/
DynamicArray& operator=(const DynamicArray& other)
{
if (this != &other) {
if (data_ != nullptr)
delete[] data_;
size_ = other.size_;
capacity_ = other.capacity_;
data_ = new T[capacity_];
for (unsigned int i = 0; i < size_; ++i)
data_[i] = other.data_[i];
}
return *this;
}
/**
* Move assignment operator.
*/
DynamicArray& operator=(DynamicArray&& other) noexcept
{
if (this != &other) {
if (data_ != nullptr)
delete[] data_;
data_ = other.data_;
size_ = other.size_;
capacity_ = other.capacity_;
other.data_ = nullptr;
other.size_ = 0;
other.capacity_ = 0;
}
return *this;
}
/**
* Returns the size of the array.
*/
unsigned int size() const
{
return size_;
}

unsigned int capacity() const
{
return capacity_;
}

void print() const
{
    for (unsigned int i = 0; i < size_; ++i){
        std::cout << data_[i] << " ";
    }
    std::cout << std::endl;
}

/**
* Checks if the array is empty.
*/
bool empty() const
{
return size_ == 0;
}
/**
* Access an element of the array (without bound checking).
*
* @param[in] index The index of the element to access.
*
* @return The element at the given index.
*/
T& operator[](unsigned int index)
{
return data_[index];
}
/**
* Access an element of the array (without bound checking).
*
* @param[in] index The index of the element to access.
*
* @return The element at the given index.
*/
const T& operator[](unsigned int index) const
{
return data_[index];
}
/**
* Access an element of the array (with bound checking).
*
* @param[in] index The index of the element to access.
*
* @return The element at the given index.
*/
T& at(unsigned int index)
{
if (index >= size_) {
throw std::out_of_range("Index out of range");
}
return data_[index];
}
/**
* Access an element of the array (with bound checking).
*
* @param[in] index The index of the element to access.
*
* @return The element at the given index.
*/
const T& at(unsigned int index) const
{
if (index >= size_) {
throw std::out_of_range("Index out of range");
}
return data_[index];
}
/**
* Access the first element of the array.
*/
T& front()
{
return data_[0];
}
/**
* Access the first element of the array.
*/
const T& front() const
{
return data_[0];
}
/**
* Access the last element of the array.
*/
T& back()
{
return data_[size_ - 1];
}
/**
* Access the last element of the array.
*/
const T& back() const
{
return data_[size_ - 1];
}
/**
* Fills the array with a value.
*
* @param[in] value The value to fill the array with.
*/
void fill(const T& value)
{
for (unsigned int i = 0; i < size_; ++i) {
data_[i] = value;
}
}
/**
* Finds the index of a value in the array.
*
* @param[in] value The value to be found.
*
* @return The index of the value in the array, or -1 if the value is not
found.
*/
int find(const T& value)
{
int index = -1;
for (int i = 0; i < (int)size_; ++i) {
if (data_[i] == value) {
index = i;
break;
}
}
return index;
}
/**
* Clears the array and deallocates the memory.
*/
void clear()
{
if (data_ != nullptr)
delete[] data_;
data_ = nullptr;
size_ = 0;
}
/**
* Resizes the array and fills the new elements with a value.
*
* @param newSize The new size of the array.
* @param value The value to fill the new elements with.
*/
void resize(unsigned int newSize)
{
// Allocate a new array
T* newData = new T[newSize];
// Copy the elements to the new array
unsigned int copySize = (newSize < size_) ? newSize : size_;
for (unsigned int i = 0; i < copySize; ++i)
newData[i] = data_[i];
// Delete the old array and update the pointer
if (data_ != nullptr)
delete[] data_;
// Update the pointer and size
data_ = newData;
size_ = newSize;
}
/**
* Resizes the array and fills the new elements with a value.
*
* @param newSize The new size of the array.
* @param value The value to fill the new elements with.
*/
void resize(unsigned int newSize, const T& value)
{
// Allocate a new array
T* newData = new T[newSize];
// Copy the elements to the new array
unsigned int copySize = (newSize < size_) ? newSize : size_;
for (unsigned int i = 0; i < copySize; ++i)
newData[i] = data_[i];
// Fill the new elements with the value
for (unsigned int i = copySize; i < newSize; ++i)
newData[i] = value;
// Delete the old array and update the pointer
if (data_ != nullptr)
delete[] data_;
// Update the pointer and size
data_ = newData;
size_ = newSize;
}
/**
* Inserts a new element at a specific position.
*
* @param index The position where the element will be inserted.
*/
void insert(unsigned int index, const T& value)
{
if (index > size_) {
throw std::out_of_range("Index out of range");
}
resize(size_ + 1);
for (unsigned int i = size_ - 1; i > index; --i) {
data_[i] = data_[i - 1];
}
data_[index] = value;
}
/**
* Erases an element at a specific position.
*
* @param[in] index The position of the element to erase.
*/
void erase(unsigned int index)
{
if (index >= size_) {
throw std::out_of_range("Index out of range");
}
for (unsigned int i = index; i < size_ - 1; ++i) {
data_[i] = data_[i + 1];
}
resize(size_ - 1);
}
/**
* Inserts a new element at the end of the array.
*
* @param[in] value The value to insert.
*/
void push_back(const T& value)
{
resize(size_ + 1);
data_[size_ - 1] = value;
}
/**
* Removes the last element of the array.
*/
void pop_back()
{
if (size_ > 0) {
resize(size_ - 1);
}
}
/**
* Inserts a new element at the front of the array.
*
* @param[in] value The value to insert.
*/
void push_front(const T& value)
{
insert(0, value);
}
/**
* Removes the first element of the array.
*/
void pop_front()
{
erase(0);
}

void printDb() const {
    for (unsigned int i = 0; i < size_; ++i) {
        const Movie& movie = data_[i]; // Obtén la película actual
        std::cout << "ID: " << movie.getId() 
                  << ", Title: " << movie.getTitle() 
                  << ", Year: " << movie.getYear() 
                  << ", Age: " << movie.getAge() 
                  << ", Rotten Tomatoes: " << movie.getRottenTomatoes() 
                  << ", Netflix: " << (movie.isNetflix() ? "Yes" : "No")
                  << ", Hulu: " << (movie.isHulu() ? "Yes" : "No")
                  << ", Prime Video: " << (movie.isPrimeVideo() ? "yes" : "No")
                  << ", Disney Plus: " << (movie.isDisneyPlus() ? "yes" : "No")
                  << ", Tipo: " << movie.getType() << std::endl;
    }
}

private:
T* data_{nullptr}; // Pointer to the dynamic array
unsigned int size_{0}; // Current size of the array
unsigned int capacity_{0};
};
#endif
//=================================================================================================================
// END OF FILE
//===================================================================================
