#include"IntCell.h"
/**
* Constuct the IntCell with intialValue
*/
IntCell::IntCell(int initialValue):storedValue(initialValue)
{
}
/**
*return the stored value
**/
int IntCell::read() const
{
	return storedValue;
}
/**
* Store x.
*/
void IntCell::write(int x)
{
	storedValue=x;
}