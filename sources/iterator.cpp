#include <iostream>
#include <cmath>
#include "MagicalContainer.hpp"

using namespace std;


int MagicalContainer::iterator::getsize() {
    return this->M_container->size();
}

MagicalContainer *MagicalContainer::iterator::getmagical() {
    return magical;
}
std::shared_ptr<std::vector<std::shared_ptr<int>>> MagicalContainer::iterator::getvector() {
    return M_container;
}

MagicalContainer::iterator::iterator(std::shared_ptr<std::vector<std::shared_ptr<int>>> container,size_t currentIndex_, MagicalContainer* point)
        : M_container(container), currentIndex(currentIndex_), magical(point) {
    point->addp(this);
}







int& MagicalContainer::iterator::operator*() {
    if (this->M_container->size() <= currentIndex)
        throw runtime_error("");
    return *(*M_container)[currentIndex];
}

MagicalContainer::iterator& MagicalContainer::iterator::operator++() {
    if (this->M_container->size() <= currentIndex)
        throw runtime_error("");
    currentIndex += 1;
    return *this;
}

bool MagicalContainer::iterator::operator!=(const MagicalContainer::iterator& other) const {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    return this->currentIndex != other.currentIndex;
}

bool MagicalContainer::iterator::operator<(const MagicalContainer::iterator &other) const {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    return this->currentIndex < other.currentIndex;
}

bool MagicalContainer::iterator::operator>(const MagicalContainer::iterator &other) const {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    return this->currentIndex > other.currentIndex;
}

bool MagicalContainer::iterator::operator==(const MagicalContainer::iterator &other) const {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    return this->currentIndex == other.currentIndex;
}

void MagicalContainer::iterator::operator=(const MagicalContainer::iterator other) {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    currentIndex = other.currentIndex;
}





void MagicalContainer::iterator::update(int num, int add) {
    if (auto* ascIter = dynamic_cast<AscendingIterator*>(this)) {
        if (currentIndex == M_container->size()||currentIndex == M_container->size()+1 || (currentIndex < M_container->size() && *(*M_container)[currentIndex] > num))
            this->currentIndex += (size_t)(add);


    } else if (auto* sideCrossIter = dynamic_cast<SideCrossIterator*>(this)) {
        if (currentIndex == M_container->size()||currentIndex == M_container->size()+1)
            this->currentIndex += (size_t)(add);


    } else if (auto* primeIter = dynamic_cast<PrimeIterator*>(this)) {
        if (isPrime(num))
            if (currentIndex == M_container->size()||currentIndex == M_container->size()+1|| (currentIndex < M_container->size() && *(*M_container)[currentIndex] > num))
                this->currentIndex += (size_t)(add);
    }
}



MagicalContainer::iterator::~iterator() {
    this->magical->removep(this);
}
