#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#ifndef MAGICAL
#define MAGICAL
#include <string>
#include <vector>
#include <set>

namespace ariel {}

    class MagicalContainer {
    public:
        std::vector<int> items;
        std::vector<int*> items1;
        std::vector<int*> items2;
        std::vector<int*> items3;


    public:
    MagicalContainer();
        void  addElement(int num);
        int size();
        void removeElement(int num);
//        ~MagicalContainer();
        std::vector<int*> getitems1();
        std::vector<int*> getitems2();
        std::vector<int*> getitems3();

    class iterator{
        std::vector<int *> M_container;
        size_t currentIndex;
    public:
        iterator(std::vector<int *> *container, size_t currentIndex_) : M_container(*container), currentIndex(currentIndex_){};

        int getsize();
        int operator*();
        std::vector<int *> * getvector();
        std::vector<int *> getvector2();
        iterator& operator++();
//        iterator(vector<int*> container*,int num):kind(num),M_container(container){}
//        iterator(iterator* iter,int num){}
        bool operator!=(const iterator other) const;
        bool operator> (const iterator other) const;
        bool operator< (const iterator other) const;
        void operator= (const iterator other) const;
        bool operator==(const iterator other) const;
        ~iterator();
        };


        class AscendingIterator: public iterator{
        public:
            AscendingIterator(MagicalContainer container_);
            AscendingIterator( AscendingIterator* iter,size_t currentIndex);
            AscendingIterator begin();
            AscendingIterator end();
            ~AscendingIterator();
        };

        class SideCrossIterator: public iterator{
        public:
            SideCrossIterator(MagicalContainer container_);
            SideCrossIterator( SideCrossIterator* iter,size_t currentIndex);
            SideCrossIterator begin();
            SideCrossIterator end();
            ~SideCrossIterator();
        };


        class PrimeIterator: public iterator{
        public:
            PrimeIterator(MagicalContainer container_);
            PrimeIterator( PrimeIterator* iter,size_t currentIndex);
            PrimeIterator begin();
            PrimeIterator end();
            ~PrimeIterator();
        };
};

#endif
////int getcurrentIndex();
////void  set_currentIndex_plus_one();
//
//virtual iterator& operator++();
