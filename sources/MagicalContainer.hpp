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
    public:
        ~MagicalContainer();
        MagicalContainer();



    class iterator{
        size_t currentIndex;
        MagicalContainer* magical;
        std::shared_ptr<std::vector<std::shared_ptr<int>>>  M_container;
    public:
        iterator(std::shared_ptr<std::vector<std::shared_ptr<int>>> container, size_t currentIndex_,  MagicalContainer*  point);
        virtual void update(int num,int odd);
        ~iterator();



        int getsize();
        MagicalContainer* getmagical();
        std::shared_ptr<std::vector<std::shared_ptr<int>>> getvector();



        int& operator*();
        iterator& operator++();
        void operator= (iterator other) ;
        bool operator!=(const iterator &other) const;
        bool operator> (const iterator &other) const;
        bool operator< (const iterator &other) const;
        bool operator==(const iterator &other) const;
        };



        class AscendingIterator: public iterator{
        public:
            AscendingIterator(MagicalContainer& container_);
            AscendingIterator( AscendingIterator* iter,size_t currentIndex);
            AscendingIterator begin();
            AscendingIterator end();
            ~AscendingIterator();
        };


        class SideCrossIterator: public iterator{
        public:
            SideCrossIterator(MagicalContainer &container_);
            SideCrossIterator( SideCrossIterator* iter,size_t currentIndex);
            SideCrossIterator begin();
            SideCrossIterator end();
            ~SideCrossIterator();
        };


        class PrimeIterator: public iterator{
        public:
            PrimeIterator(MagicalContainer &container_);
            PrimeIterator( PrimeIterator* iter,size_t currentIndex);
            PrimeIterator begin();
            PrimeIterator end();
            ~PrimeIterator();
        };

    private:
        std::shared_ptr<std::vector<std::shared_ptr<int>>>  items1;
        std::shared_ptr<std::vector<std::shared_ptr<int>>>  items2;
        std::shared_ptr<std::vector<std::shared_ptr<int>>>  items3;
        std::shared_ptr<std::vector<MagicalContainer::iterator*>> iterators;
    public:
        int size();
        void  addElement(int num);
        void removeElement(int num);

        void notify(int num,int odd);
        void addp(MagicalContainer::iterator* pointer);
        void removep(MagicalContainer::iterator* pointer);
    };


#endif
bool isPrime(int number);
