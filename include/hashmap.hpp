#ifndef HASHMAP_H
#define HASHMAP_H

#include <string_view>
#include <cmath>

template <typename T>
void DeletePointer(T*&);

// Safely deletes the provided pointer
template <typename T>
void DeletePointer(T*& pointer)
{
    delete pointer;
    pointer = nullptr;
}

template <class T>
struct UniquePtr
{
    T* Pointer;

    UniquePtr<T>& operator =(T* pointer)
    {
        return *this = UniquePtr(pointer);
    }

    T& operator *()
    {
        return *this->Pointer;
    }

    bool operator !()
    {
        return !this->Pointer;
    }

    UniquePtr(T* pointer): Pointer(pointer)
    {
    }

    ~UniquePtr()
    {
        if (this->Pointer)
            DeletePointer(this->Pointer);
    }
};

template<typename T, typename U>
struct Entry
{
    T Key;

    U Data;

    UniquePtr<Entry<T, U> > Next;

    Entry(T key, U data, Entry<T, U>* next = nullptr) : Key(key), Data(data), Next(next)
    {
    }
};

template <typename T, typename U>
class LinkedList
{
public:
        class Iterator
        {
        public:
            Entry<T, U>* Pointer;

            Iterator& operator ++()
            {
                this->Pointer = this->Pointer->Next.Pointer;

                return *this;
            }

            Iterator operator ++(int)
            {
                Iterator iterator = *this;

                this->Pointer = this->Pointer->Next.Pointer;

                return iterator;
            }


            Entry<T, U>& operator *()
            {
                return *this->Pointer;
            }

            bool operator !=(const Iterator &iterator)
                {
                return (this->Pointer != iterator.Pointer);
            }

            Iterator(T* pointer) : Pointer(pointer)
            {
            }
        };

        UniquePtr<Entry<T, U> > Head;

        LinkedList<T, U>::Iterator begin()
        {
            return (this->Head.Pointer);
        }

        LinkedList<T, U>::Iterator end()
        {
            return nullptr;
        }

        Entry<T, U>& Traverse()
        {
            if (!this->Head)
                return *this->Head;

           Entry<T, U>* node;

            for (auto& temp : *this)
                node = &temp;

            return *node;
        }

        Entry<T, U>& PushValue(T key, U value)
        {
            return *(this->Traverse().Next = new Entry<T, U>(key, value));
        }

        T GetValueAtKey(T key)
        {
            for (auto& temp : *this)
                if (temp.Key == key)
                    return temp.Data;

            return 0;
        }

        LinkedList() : Head(nullptr)
        {
        }

        LinkedList(T value)
        {
            this->Head = new Entry<T, U>(value);
        }
};

template<class T>
class HashCallable
{
public:
        int64_t operator ()(T key){
            return 0;
        }
};

template<>
class HashCallable<std::string_view>
{
public:
    unsigned int Hash(std::string_view str, uint64_t constant = 31)
    {
        int size = str.size(),
            hash = 0;

        for (int x = 0; x < size; x++)
            hash += ((int)str.data()[x] * pow(constant, x));

        return (hash);
    }

    int64_t operator ()(std::string_view key)
    {
        return this->Hash(key);
    }

    HashCallable()
    {
    }
};


template<class T = std::string_view, class U = std::string_view, size_t Size = 1000, const int hashConst = 31>
class Hashmap
{
protected:
        HashCallable<T> HashFunction;

public:
        LinkedList<T, U> Entries[Size];


        T GetValue(T key)
        {
            int hash;

            if (!this->Entries[hash = this->HashFunction(key)].Head)
                return 0;

            return this->Entries[hash].GetValueAtKey(key);
        }

        Entry<T, U>& AddValue(T key, U value)
        {
            int hash;

            if (!this->Entries[(hash = this->HashFunction(key))].Head)
            {
                this->Entries[hash] = LinkedList<T, U>();
                return this->Entries[hash].PushValue(key, value);
            }

            return this->Entries[hash].PushValue(key, value);
        }


        // Hashmap() : HashFunction(HashCallable<T>())
        // {
        // }

        Hashmap(HashCallable<T> stringHashCallable = HashCallable<T>()) : HashFunction(stringHashCallable)
        {}

        ~Hashmap()
        {
        }
};

#endif //
       // HASHMAP_H_
