#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "Orderedlist.h"
using namespace std;

TEST_CASE("Test can create and render List Nodes") {
    Orderedlist<int> list;
    list.insert_item(1);
    list.insert_item(3);




    CHECK(list.to_string() == "1, 23, 46");
}

TEST_CASE("Test Ordered Linked Lists") {
    Orderedlist<int> orderedList;
    orderedList.insert_item(10);
    orderedList.insert_item(14);
    orderedList.insert_item(5);
    orderedList.insert_item(2);
    orderedList.insert_item(21);
    orderedList.insert_item(2000);
    orderedList.insert_item(0);

    CHECK(orderedList.to_string() == "2000, 21, 14, 10, 5, 2, 0");
}