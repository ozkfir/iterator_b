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
    return this->items.size();
}

MagicalContainer::MagicalContainer() {
    items1.clear();
    items.clear();
    items2.clear();
    items3.clear();
}
//MagicalContainer::~MagicalContainer() {
//    for (int* ptr : items1) {
//        delete ptr;
//    }
////    for (int i = 0; i < items1.size(); ++i) {
////        delete items1[(size_t )i];
//    items1.clear();  // Optional, but recommended to clear the vector after deallocating the memory
//    items2.clear();  // Optional, but recommended to clear the vector after deallocating the memory
//    items3.clear();  // Optional, but recommended to clear the vector after deallocating the memory
//    items.clear();  // Optional, but recommended to clear the vector after deallocating the memory
//
//    }



std::vector<int*> MagicalContainer::getitems1() {return items1;}
std::vector<int*>  MagicalContainer::getitems2() {return items2;}
std::vector<int*> MagicalContainer::getitems3() {return items3;}


void MagicalContainer::addElement(int num) {
    int *temp1= new int(num);
    items.push_back(*temp1);
    int index = 0;
    while (index < items1.size() && *items1[(size_t)index] < num) {
        index++;
    }
    items1.insert(items1.begin() + index, temp1);

    if(isPrime(num)){
        index = 0;
        while (index < items3.size() && *items3[(size_t)index] < num) {
            index++;
        }
        items3.insert(items3.begin() + index, temp1);
    }
    items2.clear();
    bool isLeft = true;
    size_t middle = items1.size()/2;
    size_t indexC = 0;
    while (indexC != middle) {
        items2.push_back(items1[indexC]);
        indexC = items1.size() - indexC;
        if(isLeft) indexC--;

        //toggle
        isLeft = !isLeft;
    }
    items2.push_back(items1[indexC]);
}


void MagicalContainer::removeElement(int num) {
    auto it = std::lower_bound(items.begin(), items.end(), num);

    if (it != items.end()) {

        for (auto it = items1.begin(); it != items1.end();) {
            if (**it == num) {
                it = items1.erase(it);
                break;
            } else {
                ++it;
            }
        }

        for (auto it = items3.begin(); it != items3.end();) {
            if (**it == num) {
                it = items3.erase(it);
                break;
            } else {
                ++it;
            }
        }
        items2.clear();
        bool isLeft = true;
        size_t middle = items1.size()/2;
        size_t indexC = 0;
        while (indexC != middle) {
            items2.push_back(items1[indexC]);
            indexC = items1.size() - indexC;
            if(isLeft) indexC--;

            //toggle
            isLeft = !isLeft;
        }
        items2.push_back(items1[indexC]);
//int * temp= items[find(items.begin(), items.end(), num)];
        items.erase(std::remove(items.begin(), items.end(), num), items.end());

    }else
        throw runtime_error("");
}

