  /**
*	@author
*	@date
*	@file main.cpp
*	@brief driver for LinkedList demo
*/
#define CATCH_CONFIG_MAIN
#include <iostream>
#include "catch.hpp"
#include "LinkedListOfInts.h"


TEST_CASE("addBack should return true if element is added to the end of the list")//doesnt work it is adding to the list but it is adding the same way as add front is
{
	GIVEN("Elements 1,2,3 add it to the back of the list in order of 1,2,3 return true if list is in order 1,2,3 meaning it was successfully added false if otherwise")
	{
		LinkedListOfInts list;
		list.addBack(1);
		list.addBack(2);
		list.addBack(3);
		auto array = list.toVector();
		REQUIRE(array.size() == 3);
		REQUIRE(array.back() == 3);
		REQUIRE(array.front() == 1);
		//REQUIRE(array[2]==3);
		//REQUIRE(list.search(33) == true);
		//REQUIRE(list.search(1) == true);
	}
}
TEST_CASE("addFront should add an element to the front of the list")//works
{
	GIVEN("Elements 1,2,3 add it to the front of the list in order of 1,2,3 return true if list is in order 3,2,1 successfully false if not added successfully")
	{
		LinkedListOfInts list;
		list.addFront(1);
		list.addFront(2);
		list.addFront(3);
		auto array = list.toVector();
		// std::cout<< "Index 0: ";
		// std::cout<<array[0];
		// std::cout<<"\nIndex 1: ";
		// std::cout<<array[1];
		// std::cout<<"\nIndex 2: ";
		// std::cout<<array[2];
		// std::cout<<"\n";
		REQUIRE(array.front() == 3);
		REQUIRE(array.back() == 1);
		REQUIRE(list.size() == 3);
		//REQUIRE(array.front() == 1);
	}
}
TEST_CASE("isEmpty should return true if list is empty")//doesnt work returns true even elements are within list, i asusme its not getting the correct size
{
	GIVEN("A list with 1 element, the number of elements in the list should be equal to 1 therefore isEmpty should return false")
	{
		LinkedListOfInts list;
		list.addFront(2);
		list.addFront(33);
		list.addFront(1);
		list.addFront(43);
		auto array = list.toVector();
		REQUIRE(array.size()==4);
		REQUIRE(array.size() == list.size());//array size and list size are equal
		//REQUIRE(list.isEmpty() == true);
		REQUIRE(list.isEmpty() == false);//list should not be empty therfore it should return false
	}

}
TEST_CASE("size() should return the number of elements in the list")//this works
{
	GIVEN("A 101 elements the function size() should return the number of elements within list which is 101")
	{
		LinkedListOfInts list;
		for(int i = 0; i <100; i++)
		{
			list.addBack(i);
		}
		auto array = list.toVector();
		if(array.size() == 100)
		{
			REQUIRE(list.size()==100);
		}
		list.addFront(55);
		REQUIRE(list.size() == 101);
	}
}
TEST_CASE("search function should return true if given value is in list")//works
{
	GIVEN("A list containing the numbers 22,33,5,4,7 all numbers if searched should be found within list")
	{
		LinkedListOfInts list;
		list.addFront(5);
		list.addFront(7);
		list.addFront(22);
		list.addFront(4);
		list.addFront(33);
		REQUIRE(list.search(5)==true);
		REQUIRE(list.search(7) == true);
		REQUIRE(list.search(22) == true);
		REQUIRE(list.search(33) == true);
		REQUIRE(list.search(4) == true);
		REQUIRE(list.search(89) == false);
	}
}
TEST_CASE("removeBack() should return true if the back element was removed, false if the list is empty")//does not work
{

	LinkedListOfInts list;
	REQUIRE(list.removeBack() == false);
	GIVEN("Elements 1,2,3 remove back should remove 1, the size of the list should be updated and to reflect the removal of an element")
	{
		list.addFront(1);
		list.addFront(2);
		list.addFront(3);
		list.removeBack();
		auto array = list.toVector();
		// for(int i=0; i <list.size(); i++)
		// {
		// 	std::cout<<"in loop\n";
		// 	std::cout<<array[i];
		// }
		REQUIRE(list.removeBack() == true);//not reading list properly, removeBack returns false only if list is empty but it is returning false after elements were added into list
		REQUIRE(array.back()== 2);//last element should be 2 not 1
		//REQUIRE(array.front() == 3);
		// REQUIRE(list.size() == 2);//size of list should be 2 not 3
		// REQUIRE(array.size() == 2);
	}
}
TEST_CASE("removeFront() should return true if the front element of a list is removed, false if the list is empty")//does not work same reason as remove back
{
	GIVEN("Elements 1,2,3 in order of 3,2,1 remove front should remove the element 3")
	{
		LinkedListOfInts list;
		list.addFront(1);
		list.addFront(2);
		list.addFront(3);
		list.removeFront();
		auto array = list.toVector();
		REQUIRE(list.removeFront() == true);
		REQUIRE(array.at(0) == 2);
		REQUIRE(array.size() == 2);
		//REQUIRE(array.front() == 2);
		//REQUIRE(list.size() == 2);


	}
}
