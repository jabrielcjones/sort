/** @file LIstA.h */

#ifndef H_ListA
#define H_ListA

const int MAX_LIST = 10000;

/** ADT list - array-based implementation */
class List
{
   public:
      /** Default constructor */
      //List();

      /** Constructor */
      List(int new_size = MAX_LIST);

      /** Deconstructor
      ~List(); */

   // list operations:
      /** Determines whether a list is empty.
       *  @pre None.
       *  @post None.
       *  @return True if the list is empty; otherwise returns
       *          false. */
      bool isEmpty() const;

      /** Determines the length of a list.
       *  @pre None.
       *  @post None.
       *  @return The number of items that are currently in the
       *          list. */
      int getLength() const;

      /** Inserts an item into the list at position index.
       *  @pre 1 <= index <= getLength() + 1.
       *  @post If insertion is successful, newItem is at position
       *        index in the list, and other items are renumbered
       *        accordingly, and success is true; otherwise
       *        success is false.
       *  @param index  The list positionat which to insert
                        newItem.
       *  @param newItem  The ListItemType to insert into the
       *                  list.
       *  @param success  Error condition indicator. */
      void insert(int index,
                  const int& newItem,
                  bool& success);

      /** Deletes an item from the list at a given position.
       *  @pre 1 <= index <= getLength().
       *  @post If 1 <= index <= getLength(), the item at position
       *        index in the list is deleted, other items are
       *        renumbered accordingly, and succes is true;
       *        otherwise success is false.
       *  @param index  The lsit position orm.
       *  @param success  Error condition indicator. */
      void remove(int index,
                  bool& success);

      /** Retrieves a list item y position.
       *  @pre 1 <= index <= getLength().
       *  @post If 1 <= index <= getLength(), dataItem is the
       *        value of the desired item and success is true;
       *        otherwise success is false.
       *  @param index  The list position to retrieve from.
       *  @param dataItem  The list item retrieved from the
       *                   list.
       *  @param success  Error condition indicator. */
      void retrieve(int index,
                    int& dataItem,
                    bool& success);


   private:
      /** pointer to hold the items in the list */
      int           *items;

      /** number of items in list */
      int           size;

      /** max size of the array */
      int           array_size;

      /** Converts the postition of an item in a list to the
       *  correct index within its array representation.
       * @pre 1 <= index <= getLength().
       * @param index  The list position to translate.
       * @return The array index corresponding to list position
       *         index. */
      int translate(int index) const;

      /** Sorts the items in the list into ascending order.
       * @pre 1 <= size */
      //void sort();
}; // end List
// End of header file.

#endif
