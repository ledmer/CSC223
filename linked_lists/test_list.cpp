#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest.h>
#include <string>
#include "LinkedList.h"
using namespace std;

TEST_CASE("Test basic list of strings operations") {
    LinkedList<string> toppings;
    toppings.insert_at_front("cheese");
    CHECK(toppings.to_string() == "cheese");
    toppings.insert_at_front("anchovies");
    CHECK(toppings.to_string() == "anchovies, cheese");
    toppings.insert_at_front("onions");
    CHECK(toppings.to_string() == "onions, anchovies, cheese");
    CHECK(toppings.remove_from_front() == "onions");
    CHECK(toppings.to_string() == "anchovies, cheese");
}


TEST_CASE("Test number of nodes") {
    LinkedList<string> toppings;
    toppings.insert_at_front("cheese");
    CHECK(toppings.size() == 1);
    toppings.insert_at_front("anchovies");
    CHECK(toppings.size() == 2);
    toppings.insert_at_front("onions");
    CHECK(toppings.size() == 3);
    toppings.remove_from_front();
    CHECK(toppings.size() == 2);
}
TEST_CASE("Test item retrieval by integer position") {
    LinkedList<string> toppings;
    toppings.insert_at_front("cheese");
    toppings.insert_at_front("anchovies");
    toppings.insert_at_front("onions");
    //onions, anchovies, cheese
    CHECK(toppings.get_item(1) == "onions");
    CHECK(toppings.get_item(2) == "anchovies");
    CHECK(toppings.get_item(3) == "cheese");
}
TEST_CASE("Test item insertion on a specific position"){
    LinkedList<string> toppings;
    toppings.insert_at_front("cheese");
    toppings.insert_at_front("anchovies");
    toppings.insert_at_front("onions");
    toppings.insert_item("onionrings", 1);
    CHECK(toppings.to_string() == "onionrings, onions, anchovies, cheese");
    toppings.insert_item("creamcheese", 4);
    CHECK(toppings.to_string() == "onionrings, onions, anchovies, creamcheese, cheese");


}

TEST_CASE("Test item removal on a specific position"){
    LinkedList<string> toppings;
    toppings.insert_at_front("cheese");
    toppings.insert_at_front("anchovies");
    toppings.insert_at_front("onions");
        CHECK(toppings.to_string() == "onions, anchovies, cheese");

    CHECK(toppings.remove_item(1) == "onions");
    CHECK(toppings.to_string() == "anchovies, cheese");
    CHECK(toppings.remove_item(2) == "cheese");


}