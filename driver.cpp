#include "ListA.h"               // ADT list operations
#include "random.h"
#include <iostream>
#include <cctype>
#include <sys/timeb.h>           // for time functions

using namespace std;

const int MAX = 100;

/** Displays the items on the list.
       *  @pre none
       *  @post Items on list are displayed.
       *  @param list  The list to be displayed. */
void displayList(List, int);


/** Fills list with random integers.
       *  @pre none
       *  @post List filled with random integers.
       *  @param items  The array to be filed with random integers. */
void fillRandomInt(int*, int);


/** Inserts items into list.
       *  @pre none
       *  @post List filled with items.
       *  @param list  The list to be filed with random integers.
       *  @param success Error condition indicator*/
void insertItems(List&, int*, int);


/** Sorts the items in the list into ascending order.
       * @pre  none
       * @post Items are sorted in ascending order
       * @param  items The array to be sorted */
void ascendingOrder(int*, int);


/** Sorts the items in the list into descending order.
       * @pre  none
       * @post Items are sorted in descending order
       * @param  items The array to be sorted */
void descendingOrder(int*, int);


/** Prompts the user to enter size of the list.
       * @pre none.
       * @post size of the list is entered.
       * @returns size of the list. */
int getSize();

void displayItems(int*, int);
void displayTimeConsumed(timeb, timeb, int);


int main()
{
   timeb          begin, finish;
   int            size = getSize();
   int            *items = new int[size];
   List           aList(size);

   fillRandomInt(items, size);
   //ascendingOrder(items, size);
   descendingOrder(items, size);
   //displayItems(items, size);
   //cout << endl;
   ftime(&begin);
   insertItems(aList, items, size);
   //displayList(aList, size);
   ftime(&finish);
   displayTimeConsumed(begin, finish, size);
}


void displayItems(int* items, int size)
{
   for (int i = 0; i < size; ++i)
      cout << i + 1  << ". " << items[i] << endl;
}


void displayList(List list, int size)
{
   int      dataItem;
   bool     success;

   for (int pos = 1; pos <= size; ++pos)
   {
      list.retrieve(pos, dataItem, success);

      if (success)
         cout << pos
              << ". "
              << dataItem
              << endl;
   }
}


void fillRandomInt(int* items, int size)
{
   Random randomizer;

   for (int i = 0; i < size; ++i)
      items[i] = randomizer.next(1000);
}


void insertItems(List& list, int* items, int size)
{
   bool     success;
   int      list_item, list_size;

   for (int i = 0; i < size; ++i)
   {
      if (list.isEmpty())
      {
         list.insert(1, items[i], success);
      }
      else
      {
         for (int index = 1; index <= list.getLength(); ++index)
         {
            int list_item;
            list.retrieve(index, list_item, success);

            if (items[i] < list_item)
            {
               list.insert(index, items[i], success);
               index = list.getLength() + 1;
            }
            else if (index == list.getLength())
            {
               list.insert(index + 1, items[i], success);
               index = list.getLength() + 1;
            }
         }
      }
   }
}


void ascendingOrder(int* items, int size)
{
   int      highest_index;
   int      first;
   int      temp;

   for(int i = 0; i < size; ++i)
      items[i] = i + 1;
}


void descendingOrder(int* items, int size)
{
   int      highest_index;
   int      first;
   int      temp;

   for(int i = 0; i < size; ++i)
      items[i] = size - i;
}


int getSize()
{
   int   size;

   cout << "Enter a number for the size of the list: ";
   cin >> size;

   return size;
}


void displayTimeConsumed(timeb begin,
                         timeb finish,
                         int n)
{
   double time1, time2;

   time1 = begin.time + begin.millitm / 1000.0;
   time2 = finish.time + finish.millitm / 1000.0;
   cout << "Beginning time in seconds = "
   << time1
   << endl;
   cout << "Finishing time in seconds = "
   << time2
   << endl;
   cout << "It took "
        << time2 - time1
   << " second(s) to insert "
   << n
   << " items."
   << endl;
}  // end of displayTimeConsumed
