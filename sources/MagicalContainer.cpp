#include <iostream>
#include <cmath>
#include "MagicalContainer.hpp"
#include <algorithm>

using namespace std;




MagicalContainer::MagicalContainer() {
    items1 = make_shared<vector<shared_ptr<int>>>();
    items2 = make_shared<vector<shared_ptr<int>>>();
    items3 = make_shared<vector<shared_ptr<int>>>();
    iterators = make_shared<vector<MagicalContainer::iterator *>>();
}
MagicalContainer::~MagicalContainer() {}


int MagicalContainer::size() {
    return static_cast<int>(items1->size());
}


void MagicalContainer::addElement(int num) {
    shared_ptr<int> temp1 = make_shared<int>(num);
    int index = 0;

    //add to  Ascending
    while (index < items1->size() && *(*items1)[(size_t)index] < num) {
        index++;
    }
    if(index < items1->size() &&*(*items1)[(size_t)index] == num)
        throw runtime_error("");
    notify(num, 1);
    items1->insert(items1->begin() + index, temp1);

    //add to Prime
    if (isPrime(num)) {
        index = 0;
        while (index < items3->size() && *(*items3)[(size_t)index] < num) {
            index++;
        }
        items3->insert(items3->begin() + index, temp1);
    }

    //change SideCross
    items2->clear();
    bool isLeft = true;
    size_t middle = items1->size() / 2;
    size_t indexC = 0;
    while (indexC != middle) {
        items2->push_back((*items1)[indexC]);
        indexC = items1->size() - indexC;
        if (isLeft) indexC--;
        isLeft = !isLeft;
    }
    items2->push_back((*items1)[indexC]);
//    notify(num, 1);
}




void MagicalContainer::removeElement(int num) {
    bool temp = false;
    for (size_t i = 0; i < items1->size(); ++i) {
        if (num == *(*items1)[i]) {
            temp = true;
            break;
        }
    }
    if (temp) {
        //remove from Prime
        for (auto it = items3->begin(); it != items3->end();) {
            if (**it == num) {
                it = items3->erase(it);
                break;
            } else {
                ++it;
            }
        }
        //remove from Ascending
        for (auto it = items1->begin(); it != items1->end(); ++it) {
            if (**it == num) {
                it = items1->erase(it);
                break;
            }
        }
        //change SideCross
        items2->clear();
        bool isLeft = true;
        size_t middle = items1->size() / 2;
        size_t indexC = 0;
        while (indexC != middle) {
            items2->push_back((*items1)[indexC]);
            indexC = items1->size() - indexC;
            if (isLeft) indexC--;
            isLeft = !isLeft;
        }
        items2->push_back((*items1)[indexC]);
    } else {
        throw runtime_error("");
    }
    notify(num, -1);
}





void MagicalContainer::addp(MagicalContainer::iterator* pointer) {
    iterators->push_back(pointer);
}

void MagicalContainer::removep(MagicalContainer::iterator* pointer) {
    auto it = find(iterators->begin(), iterators->end(), pointer);
    if (it != iterators->end()) {
        iterators->erase(it);
    }
}

void MagicalContainer::notify(int num, int add) {
    for (size_t i = 0; i < iterators->size(); ++i) {
        (*iterators)[i]->update(num, add);
    }
}




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