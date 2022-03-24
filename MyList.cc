#ifndef MYLIST_H
#define MYLIST_H
#include <iostream>
using namespace std;
#define MAXROW 7
#define MAXCOL 27
template <class T>

//MyList Class
//Objective: MyList is a template class for a 2D array. It can be used to hold any data type, and is used within the context of the program to hold chars.

class MyList
{
  public:
    T** contents = new T*[MAXROW];
    MyList();
    ~MyList();
    T get(int r, int c);
    void add(int r, int c, T s);
    void del(int r, int c);
    void delList();
    void print();
  private:

};
#endif

//ctor, builds the list, with size based on MAXROW and MAXCOL
template <class T>
MyList<T>::MyList(){
  for (int i = 0; i < MAXROW; i++){
    contents[i] = new T[MAXCOL];
  }
}

template <class T>
MyList<T>::~MyList(){}

//a function to delete all contents of the list
template <class T>
void MyList<T>::delList(){
  for (int i=0; i<MAXROW; i++)
      delete[] contents[i];

    delete[] contents;
}

//a get function
template <class T>
T MyList<T>::get(int r,int c){
  return contents[r][c];
}

//a set function
template <class T>
void MyList<T>::add(int r,int c, T s){
  contents[r][c] = s;
}
//a del function, replaces with null.
template <class T>
void MyList<T>::del(int r,int c){
  contents[r][c] = NULL;
  //should only delete content
  //control will handle replacing nulls with spaces, as this has to be a list that can take any type
}

//prints the contents of the list
template <class T>
void MyList<T>::print(){
  for (int i = 0; i < MAXROW; i++){
    for (int j=0; j< MAXCOL; j++){
      cout << contents[i][j] << " ";
    }
    cout<< endl;
  }
}
