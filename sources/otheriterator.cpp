
#include <cmath>
#include "MagicalContainer.hpp"
using namespace std;














MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer container_):iterator(&container_.items1,0) {}
MagicalContainer::AscendingIterator::AscendingIterator(MagicalContainer::AscendingIterator *iter,size_t currentIndex):iterator((iter->getvector()),currentIndex) {}
MagicalContainer::AscendingIterator::~AscendingIterator() {}



MagicalContainer::PrimeIterator:: PrimeIterator(MagicalContainer container_):iterator(&container_.items3,0) {}
MagicalContainer::PrimeIterator:: PrimeIterator(MagicalContainer::PrimeIterator *iter,size_t currentIndex):iterator((iter->getvector()),currentIndex) {}
MagicalContainer::PrimeIterator::~PrimeIterator() {}





MagicalContainer::SideCrossIterator:: SideCrossIterator(MagicalContainer container_):iterator(&container_.items2,0) {}
MagicalContainer::SideCrossIterator:: SideCrossIterator(MagicalContainer::SideCrossIterator *iter,size_t currentIndex):iterator((iter->getvector()),currentIndex) {}
MagicalContainer::SideCrossIterator::~SideCrossIterator() {}





MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::begin(){return {this,0};}
MagicalContainer::AscendingIterator MagicalContainer::AscendingIterator::end() {return {this, (size_t)this->getsize()};}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::begin(){return {this,0};}
MagicalContainer::SideCrossIterator MagicalContainer::SideCrossIterator::end() {return {this, (size_t)this->getsize()};}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::begin(){return {this,0};}
MagicalContainer::PrimeIterator MagicalContainer::PrimeIterator::end() {return {this, (size_t)this->getsize()};}




//
//MagicalContainer::PrimeIterator &MagicalContainer::PrimeIterator::operator++() {
//    do {
//        set_currentIndex_plus_one();
//    } while (this->getcurrentIndex()!=this->end().getcurrentIndex() && !isPrime(*this[getcurrentIndex()]));
//    return *this;
//}
