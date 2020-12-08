//Programmer: Phillip LaFrance
//Intructor: Patrick Taylor		//Section: A		//Date: 02/04/2018
//File: pa01.cpp				//Description: "Searches for a user defined string, inside a user defined 2D array of characters."
#include "matrix_search.h"

int main()
{
  int num_matrices, rows, cols, sol[4];
  string temp, word;

  do{
    cin >> num_matrices;
    getline(cin, temp);
    if (num_matrices<0)
        cout << "Please enter a positive number." << endl;
  }while(num_matrices<0);

  for (int i=1; i<=num_matrices; i++)
  {
    do{
        cin >> rows >> cols;
        getline(cin, temp);
        if(rows<0 || cols<0)
            cout << "Please enter positive numbers." << endl;
    }while(rows<0 || cols<0);
    char **my2dArray = build_matrix(rows, cols);
    fill_matrix(rows, cols, my2dArray);
    cin >> word;
    cout << "Searching for \"" << word << "\" in matrix " << i << " yields:" << endl;
    matrix_search(sol, word, rows, cols, my2dArray);
    delete_matrix(rows, my2dArray);
  }
  return 0;
}
