#include <iostream>
#include <cmath>
#include "MagicalContainer.hpp"
using namespace std;
#include <algorithm>
bool isPrime(int number) {
    if (number <= 1) {
        return false;
    }

    for (int i = 2; i <= sqrt(number); i++) {
        if (number % i == 0) {
            return false;
        }
    }

    return true;
}


int MagicalContainer::size() {
    return this->items1->size();
}

MagicalContainer::MagicalContainer() {
    items1 = std::make_shared<std::vector<std::shared_ptr<int>>>();
    items2 = std::make_shared<std::vector<std::shared_ptr<int>>>();
    items3 = std::make_shared<std::vector<std::shared_ptr<int>>>();
}
    MagicalContainer::~MagicalContainer() {
    }

void MagicalContainer::addElement(int num) {
    shared_ptr <int> temp1=std::make_shared<int>(num);
    int index = 0;
    while (index < items1->size() && *(*items1)[(size_t)index] < num) {
        index++;
    }

    items1->insert(items1->begin() + index, temp1);

    if(isPrime(num)){
        index = 0;
        while (index < items3->size() && *(*items3)[(size_t)index] < num) {
            index++;
        }
        items3->insert(items3->begin() + index, temp1);
    }
    items2->clear();
    bool isLeft = true;
    size_t middle = items1->size()/2;
    size_t indexC = 0;
    while (indexC != middle) {
        items2->push_back((*items1)[indexC]);
        indexC = items1->size() - indexC;
        if(isLeft) indexC--;

        //toggle
        isLeft = !isLeft;
    }
    items2->push_back((*items1)[indexC]);
}


void MagicalContainer::removeElement(int num) {
    bool temp = false;
    for ( int i = 0; i <items1->size() ; ++i) {
        if(num==*(*items1)[(size_t)i]){
            temp= true;
            break;
        }
    }
    if (temp) {

        for (auto it = items3->begin(); it != items3->end();) {
            if (**it == num) {
                it = items3->erase(it);
                break;
            } else {
                ++it;
            }
        }
        for (auto it = items1->begin(); it != items1->end(); ++it) {
            if (**it == num) {
//                delete *it;
//                *it = nullptr;
                it = items1->erase(it);
                break;
            }
        }

        items2->clear();
        bool isLeft = true;
        size_t middle = items1->size()/2;
        size_t indexC = 0;
        while (indexC != middle) {
            items2->push_back((*items1)[indexC]);
            indexC = items1->size() - indexC;
            if(isLeft) indexC--;

            //toggle
            isLeft = !isLeft;
        }
        items2->push_back((*items1)[indexC]);
    }else
        throw runtime_error("");
}

