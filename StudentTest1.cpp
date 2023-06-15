#include "doctest.h"
#include <iostream>
using namespace std;
#include "sources/MagicalContainer.hpp" //no need for other includes

using namespace ariel;
TEST_CASE("MagicalContainer") {
    MagicalContainer container;

    SUBCASE("size & addElement") {
        CHECK(container.size() == 0);
        container.addElement(7);
        container.addElement(9);
        CHECK(container.size() == 2);
        container.addElement(5);
        CHECK(container.size() == 3);

        container.removeElement(7);
        CHECK(container.size() == 2);
        container.removeElement(9);
        container.removeElement(5);
        CHECK(container.size() == 0);

        container.addElement(7);
        CHECK_THROWS(container.addElement(7));
    }

    SUBCASE("removeElement") {
        CHECK_THROWS(container.removeElement(9));
        CHECK_THROWS(container.removeElement(7));
        container.addElement(7);
        container.addElement(9);
        container.addElement(5);
        container.removeElement(5);
        CHECK_THROWS(container.removeElement(5));
        CHECK_THROWS(container.removeElement(0));
    }
}

TEST_CASE("AscendingIterator") {
    MagicalContainer container;
    container.addElement(7);
    container.addElement(9);
    container.addElement(1);
    container.addElement(3);

    CHECK(container.size() == 4);

    SUBCASE("order & iterator") {
        MagicalContainer::AscendingIterator Iter1(container);
        int arr[4] = {1,3, 7,9};
        int i = 0;
        for (auto it = Iter1.begin(); it != Iter1.end(); ++it) {
            CHECK(arr[i] == *it);
            i++;
        }
    }

    SUBCASE("begin & end") {
        MagicalContainer::AscendingIterator Iter1(container);
        CHECK(Iter1.begin() == Iter1);
        CHECK(Iter1.begin() < Iter1.end());
        CHECK(Iter1.begin() != Iter1.end());

        ++Iter1;
        ++Iter1;
        ++Iter1;
        ++Iter1;

        CHECK(Iter1 == Iter1.end());
    }

    SUBCASE("++,*") {
        MagicalContainer::AscendingIterator Iter1(container);
        CHECK(*Iter1 == 1);
        ++Iter1;
        CHECK(*Iter1 == 3);
        ++Iter1;
        CHECK(*Iter1 == 7);
        ++Iter1;
        CHECK(*Iter1 == 9);
        ++Iter1;
        CHECK(Iter1 == Iter1.end());
        CHECK_THROWS(++Iter1);
        CHECK_THROWS(*Iter1);
    }

    SUBCASE("<, >") {
        MagicalContainer::AscendingIterator Iter1(container);
        CHECK(Iter1.begin() < Iter1.end());

        ++Iter1;
        CHECK((Iter1 < Iter1.end() && Iter1.end() > Iter1));
        CHECK_FALSE((Iter1 > Iter1.end() || Iter1.end() < Iter1));

        ++Iter1;
        CHECK((Iter1 < Iter1.end() && Iter1.end() > Iter1));
        CHECK_FALSE((Iter1 > Iter1.end() || Iter1.end() < Iter1));

        ++Iter1;
        CHECK((Iter1 < Iter1.end() && Iter1.end() > Iter1));
        CHECK_FALSE((Iter1 > Iter1.end() || Iter1.end() < Iter1));

        ++Iter1;
        CHECK(Iter1 == Iter1.end());
    }

    SUBCASE("==, !=") {
        MagicalContainer::AscendingIterator Iter1(container);
        CHECK(Iter1.begin() != Iter1.end());
        CHECK_FALSE(Iter1.begin() == Iter1.end());

        ++Iter1;
        ++Iter1;
        CHECK(Iter1 != Iter1.end());
        CHECK_FALSE(Iter1 == Iter1.end());

        ++Iter1;
        ++Iter1;
        CHECK(Iter1 == Iter1.end());
        CHECK_FALSE(Iter1 != Iter1.end());
    }

    SUBCASE("=") {
        MagicalContainer::AscendingIterator Iter1(container);
        MagicalContainer::AscendingIterator Iter2(container);

        ++Iter1;
        ++Iter1;
        CHECK(*Iter1 == 7);

        Iter2 = Iter1;
        CHECK(*Iter2 == 7);
    }

    SUBCASE("2 iterators") {
        MagicalContainer::AscendingIterator Iter1(container);
        MagicalContainer::AscendingIterator Iter2(container);

        ++Iter1;
        CHECK(Iter1 != Iter2);
        CHECK_FALSE(Iter1 == Iter2);
        CHECK(Iter1 > Iter2);
        CHECK_FALSE(Iter1 < Iter2);

        ++Iter2;
        CHECK(Iter1 == Iter2);
        CHECK_FALSE(Iter1 != Iter2);
        CHECK_FALSE(Iter1 > Iter2);
        CHECK_FALSE(Iter1 < Iter2);
    }

    SUBCASE("2 containers") {
        MagicalContainer container2;
        container2.addElement(7);
        container2.addElement(9);
        container2.addElement(1);
        container2.addElement(3);

        MagicalContainer::AscendingIterator Iter1(container);
        MagicalContainer::AscendingIterator Iter2(container2);
        CHECK_THROWS(Iter1 = Iter2);
    }
    SUBCASE("add in middle") {
        MagicalContainer::AscendingIterator Iter(container);
        ++Iter;
        ++Iter;
        CHECK(*Iter ==7);
        container.addElement(5);
        CHECK(*Iter ==7);
        container.removeElement(5);
        CHECK(*Iter ==7);

    }
}









TEST_CASE("SideCrossIterator") {
    MagicalContainer container;
    container.addElement(7);
    container.addElement(9);
    container.addElement(1);
    container.addElement(3);

    CHECK(container.size() == 4);

    SUBCASE("order & iterator") {

        int arr[4]={1,9,3,7};
        MagicalContainer::SideCrossIterator crossIter(container);
        int j=0;
        for (auto it = crossIter.begin(); it != crossIter.end(); ++it) {
            std::cout << *it << ' ';
            CHECK(arr[j]==*it);
            j++;
        }
    }

    SUBCASE("begin & end") {
        MagicalContainer::SideCrossIterator Iter1(container);
        CHECK(Iter1.begin() == Iter1);
        CHECK(Iter1.begin() < Iter1.end());
        CHECK(Iter1.begin() != Iter1.end());

        ++Iter1;
        ++Iter1;
        ++Iter1;
        ++Iter1;

        CHECK(Iter1 == Iter1.end());
    }

    SUBCASE("++,*") {
        MagicalContainer::SideCrossIterator Iter1(container);
        CHECK(*Iter1 == 1);
        ++Iter1;
        CHECK(*Iter1 == 9);
        ++Iter1;
        CHECK(*Iter1 == 3);
        ++Iter1;
        CHECK(*Iter1 == 7);
        ++Iter1;
        CHECK(Iter1 == Iter1.end());
        CHECK_THROWS(++Iter1);
        CHECK_THROWS(*Iter1);
    }

    SUBCASE("<, >") {
        MagicalContainer::SideCrossIterator Iter1(container);
        CHECK(Iter1.begin() < Iter1.end());

        ++Iter1;
        CHECK((Iter1 < Iter1.end() && Iter1.end() > Iter1));
        CHECK_FALSE((Iter1 > Iter1.end() || Iter1.end() < Iter1));

        ++Iter1;
        CHECK((Iter1 < Iter1.end() && Iter1.end() > Iter1));
        CHECK_FALSE((Iter1 > Iter1.end() || Iter1.end() < Iter1));

        ++Iter1;
        CHECK((Iter1 < Iter1.end() && Iter1.end() > Iter1));
        CHECK_FALSE((Iter1 > Iter1.end() || Iter1.end() < Iter1));

        ++Iter1;
        CHECK(Iter1 == Iter1.end());
    }

    SUBCASE("==, !=") {
        MagicalContainer::SideCrossIterator Iter1(container);
        CHECK(Iter1.begin() != Iter1.end());
        CHECK_FALSE(Iter1.begin() == Iter1.end());

        ++Iter1;
        ++Iter1;
        CHECK(Iter1 != Iter1.end());
        CHECK_FALSE(Iter1 == Iter1.end());

        ++Iter1;
        ++Iter1;
        CHECK(Iter1 == Iter1.end());
        CHECK_FALSE(Iter1 != Iter1.end());
    }

    SUBCASE("=") {
        MagicalContainer::SideCrossIterator Iter1(container);
        MagicalContainer::SideCrossIterator Iter2(container);

        ++Iter1;
        ++Iter1;
        CHECK(*Iter1 == 3);

        Iter2 = Iter1;
        CHECK(*Iter2 == 3);
    }

    SUBCASE("2 iterators") {
        MagicalContainer::SideCrossIterator Iter1(container);
        MagicalContainer::SideCrossIterator Iter2(container);

        ++Iter1;
        CHECK(Iter1 != Iter2);
        CHECK_FALSE(Iter1 == Iter2);
        CHECK(Iter1 > Iter2);
        CHECK_FALSE(Iter1 < Iter2);

        ++Iter2;
        CHECK(Iter1 == Iter2);
        CHECK_FALSE(Iter1 != Iter2);
        CHECK_FALSE(Iter1 > Iter2);
        CHECK_FALSE(Iter1 < Iter2);
    }

    SUBCASE("2 containers") {
        MagicalContainer container2;
        container2.addElement(7);
        container2.addElement(9);
        container2.addElement(1);
        container2.addElement(3);

        MagicalContainer::SideCrossIterator Iter1(container);
        MagicalContainer::SideCrossIterator Iter2(container2);

        CHECK_THROWS(Iter1 = Iter2);
    }
}













TEST_CASE("PrimeIterator") {
    MagicalContainer container;
    container.addElement(7);
    container.addElement(9);
    container.addElement(1);
    container.addElement(3);

    CHECK(container.size() == 4);

    SUBCASE("order & iterator") {
        int arr2[2]={3,7};
        int j=0;
        MagicalContainer::PrimeIterator primeIter(container);
        for (auto it = primeIter.begin(); it != primeIter.end(); ++it) {
            CHECK(arr2[j]==*it);
            j++;
        }
    }

    SUBCASE("begin & end") {
        MagicalContainer::PrimeIterator Iter1(container);
        CHECK(Iter1.begin() == Iter1);
        CHECK(Iter1.begin() < Iter1.end());
        CHECK(Iter1.begin() != Iter1.end());

        ++Iter1;
        ++Iter1;

        CHECK(Iter1 == Iter1.end());
    }

    SUBCASE("++,*") {
        MagicalContainer::PrimeIterator Iter1(container);
        CHECK(*Iter1 == 3);
        ++Iter1;
        CHECK(*Iter1 == 7);
        ++Iter1;
        CHECK(Iter1 == Iter1.end());
        CHECK_THROWS(++Iter1);
        CHECK_THROWS(*Iter1);
    }

    SUBCASE("<, >") {
        MagicalContainer::PrimeIterator Iter1(container);
        CHECK(Iter1.begin() < Iter1.end());


        ++Iter1;
        CHECK((Iter1 < Iter1.end() && Iter1.end() > Iter1));
        CHECK_FALSE((Iter1 > Iter1.end() || Iter1.end() < Iter1));

        ++Iter1;
        CHECK(Iter1 == Iter1.end());
    }

    SUBCASE("==, !=") {
        MagicalContainer::PrimeIterator Iter1(container);
        CHECK(Iter1.begin() != Iter1.end());
        CHECK_FALSE(Iter1.begin() == Iter1.end());

        ++Iter1;
        CHECK(Iter1 != Iter1.end());
        CHECK_FALSE(Iter1 == Iter1.end());

        ++Iter1;
        CHECK(Iter1 == Iter1.end());
        CHECK_FALSE(Iter1 != Iter1.end());
    }

    SUBCASE("=") {
        MagicalContainer::PrimeIterator Iter1(container);
        MagicalContainer::PrimeIterator Iter2(container);

        ++Iter1;
        CHECK(*Iter1 == 7);

        Iter2 = Iter1;
        CHECK(*Iter2 == 7);
    }

    SUBCASE("2 iterators") {
        MagicalContainer::PrimeIterator Iter1(container);
        MagicalContainer::PrimeIterator Iter2(container);

        ++Iter1;
        CHECK(Iter1 != Iter2);
        CHECK_FALSE(Iter1 == Iter2);
        CHECK(Iter1 > Iter2);
        CHECK_FALSE(Iter1 < Iter2);

        ++Iter2;
        CHECK(Iter1 == Iter2);
        CHECK_FALSE(Iter1 != Iter2);
        CHECK_FALSE(Iter1 > Iter2);
        CHECK_FALSE(Iter1 < Iter2);
    }

    SUBCASE("2 containers") {
        MagicalContainer container2;
        container2.addElement(7);
        container2.addElement(9);
        container2.addElement(1);
        container2.addElement(3);

        MagicalContainer::PrimeIterator Iter1(container);
        MagicalContainer::PrimeIterator Iter2(container2);
        CHECK_THROWS(Iter1 = Iter2);
    }
    SUBCASE("add in middle") {

        MagicalContainer::PrimeIterator Iter(container);
        ++Iter;
        CHECK(*Iter ==7);
        container.addElement(5);
        CHECK(*Iter ==7);
        container.removeElement(5);
        CHECK(*Iter ==7);

    }
}



























