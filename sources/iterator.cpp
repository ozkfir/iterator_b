#include <iostream>
#include <cmath>
#include "MagicalContainer.hpp"
using namespace std;

int MagicalContainer::iterator::getsize() {return this->M_container->size();}
std::shared_ptr<std::vector<std::shared_ptr<int>>> MagicalContainer::iterator::getvector() {return M_container;}
MagicalContainer::iterator::~iterator() {}

bool MagicalContainer::iterator::operator!=(const MagicalContainer::iterator other) const {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    return this->currentIndex != other.currentIndex;}

bool MagicalContainer::iterator::operator<(const MagicalContainer::iterator other) const {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    return  this->currentIndex < other.currentIndex;}

bool MagicalContainer::iterator::operator>(const MagicalContainer::iterator other) const {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    return  this->currentIndex > other.currentIndex;}

bool MagicalContainer::iterator::operator==(const MagicalContainer::iterator other) const {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    return this->currentIndex == other.currentIndex;}

void MagicalContainer::iterator::operator=( MagicalContainer::iterator other)  {
    if ((this->M_container) != (other.M_container))
        throw runtime_error(" ");
    currentIndex = other.currentIndex;
}

int& MagicalContainer::iterator::operator*() {
    if (currentIndex >= M_container->size())
        throw runtime_error("Invalid iterator dereference");
    return *(*M_container)[currentIndex];
}

MagicalContainer::iterator& MagicalContainer::iterator::operator++() {
    if(this->M_container->size()<=currentIndex)
        throw runtime_error("");
    currentIndex+=1;
    return *this;
}

