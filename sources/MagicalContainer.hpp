#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#ifndef MAGICAL
#define MAGICAL
#include <string>
#include <vector>
#include <set>
#include <memory>

namespace ariel {}

    class MagicalContainer {
        std::shared_ptr<std::vector<std::shared_ptr<int>>>  items1;
        std::shared_ptr<std::vector<std::shared_ptr<int>>> items2;
        std::shared_ptr<std::vector<std::shared_ptr<int>>>  items3;
    public:
    MagicalContainer();
        void  addElement(int num);
        int size();
        void removeElement(int num);
        ~MagicalContainer();


    class iterator{
    public:
        std::shared_ptr<std::vector<std::shared_ptr<int>>>  M_container;
        size_t currentIndex;
    public:
        iterator(std::shared_ptr<std::vector<std::shared_ptr<int>>> container, size_t currentIndex_) : M_container(container), currentIndex(currentIndex_){};

        int getsize();
        std::shared_ptr<std::vector<std::shared_ptr<int>>> getvector();
        int& operator*();
        iterator& operator++();
        bool operator!=(const iterator other) const;
        bool operator> (const iterator other) const;
        bool operator< (const iterator other) const;
        void operator= (iterator other) ;
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
