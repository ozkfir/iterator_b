#include <iostream>
#include <cmath>
#include "MagicalContainer.hpp"
using namespace std;


std::vector<int *> *MagicalContainer::iterator::getvector() {return &M_container;}
std::vector<int *> MagicalContainer::iterator::getvector2() {return M_container;}
MagicalContainer::iterator::~iterator() {}

//int MagicalContainer::iterator::getcurrentIndex() {return currentIndex;}
//
//void  MagicalContainer::iterator::set_currentIndex_plus_one() {currentIndex++;}
bool MagicalContainer::iterator::operator!=(const MagicalContainer::iterator other) const {return this->currentIndex != other.currentIndex;}

bool MagicalContainer::iterator::operator<(const MagicalContainer::iterator other) const {return  this->currentIndex < other.currentIndex;}

bool MagicalContainer::iterator::operator>(const MagicalContainer::iterator other) const {return  this->currentIndex > other.currentIndex;}

bool MagicalContainer::iterator::operator==(const MagicalContainer::iterator other) const {return this->currentIndex == other.currentIndex;}

void MagicalContainer::iterator::operator=(const MagicalContainer::iterator other) const {
    if(&(this->M_container)!=&(other.M_container))
        throw runtime_error(" ");
//    int temp=other.currentIndex;
//    this->currentIndex = temp;
//    this->M_container=other.M_container;/////////////distrucur?
}


int MagicalContainer::iterator::getsize() {return this->M_container.size();}



int MagicalContainer::iterator::operator*() {return *(this->M_container[currentIndex]);}

MagicalContainer::iterator& MagicalContainer::iterator::operator++() {
    if(this->M_container.size()<=currentIndex)
        throw runtime_error("");
    currentIndex+=1;
    return *this;
}

