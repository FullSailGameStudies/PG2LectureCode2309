#pragma once
#include <iostream>

class Enclosing 
{
private:
	int x;

	/* start of Nested class declaration */ 
	class Nested 
	{
		int y;
		void NestedFun(Enclosing* e) {
			std::cout << e->x; // works fine: nested class can access 
							   // private members of Enclosing class
		}
	}; // declaration Nested class ends here

	void AccessNested(Nested* n)
	{
		//std::cout << n->y;
	}


}; // declaration Enclosing class ends here
