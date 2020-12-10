//Programmer: Phillip LaFrance
//Instructor: Patrick Taylor		//Section: A		//Date: 02/04/2018
//File: matrix_search.cpp		//Description: "Searches for a user defined string, inside a user defined 2D array of characters."
#include "matrix_search.h"

bool up_left_check(int sol[], string word, int i, int j, char **matrix);

bool up_check(int sol[], string word, int i, int j, char **matrix);

bool up_right_check(int sol[], string word, int i, int j, int cols, char **matrix);

bool right_check(int sol[], string word, int i, int j, int cols, char **matrix);

bool down_right_check(int sol[], string word, int i, int j, int rows, int cols, char **matrix);

bool down_check(int sol[], string word, int i, int j, int rows, char **matrix);

bool down_left_check(int sol[], string word, int i, int j, int rows, char **matrix);

bool left_check(int sol[], string word, int i, int j, char **matrix);

void get_identity(string my_id[])
{
    if (my_id[0].empty())
        cout << "No username." << endl;
    else
        cout << my_id[0] << endl;

    if (my_id[1].empty())
        cout << "No id." << endl;
    else
        cout << my_id[1] << endl;
}

char ** build_matrix(int rows, int cols)
{
  char **dynamicArray;
  if(rows>0 && cols>0)
  {
    dynamicArray = new char *[rows];
    for(int i=0; i<rows; i++)
        dynamicArray[i] = new char [cols];
    return dynamicArray;
  }
  else
  {
    cout << "Invalid parameter(s) for build_matrix." << endl;
    return dynamicArray = 0;
  }
}


void fill_matrix(int rows, int cols, char **matrix)
{
  if(rows<=0 || cols<=0)
    cout << "Invalid rows or cols parameter for fill_matrix." << endl;
  else if(matrix == NULL)
    cout << "Matrix cannot be filled because matrix has not been built." << endl;
  else
  {
    for (int i=0; i<rows; i++)
        for (int j=0; j<cols; j++)
            cin >> matrix[i][j];
    string temp;
    getline(cin, temp);
  }
}


void matrix_search(int sol[], string word, int rows, int cols, char **matrix)
{
  for (int i=0; i<rows; i++)
    for (int j=0; j<cols; j++)
        if(matrix[i][j]==word[0])
        {
            bool solution_found = false;
            solution_found=up_left_check(sol, word, i, j, matrix);
            if (!solution_found)
                solution_found=up_check(sol, word, i, j, matrix);
            if (!solution_found)
                solution_found=up_right_check(sol, word, i, j, cols, matrix);
            if (!solution_found)
                solution_found=right_check(sol, word, i, j, cols, matrix);
            if (!solution_found)
                solution_found=down_right_check(sol, word, i, j, rows, cols, matrix);
            if (!solution_found)
                solution_found=down_check(sol, word, i, j, rows, matrix);
            if (!solution_found)
                solution_found=down_left_check(sol, word, i, j, rows, matrix);
            if (!solution_found)
                solution_found=left_check(sol, word, i, j, matrix);
            if (solution_found)
                return;
        }
  cout << "The pattern was not found." << endl;
  for (int k=0; k<4; k++)
	  sol[k]=-1;
}

bool up_left_check(int sol[], string word, int i, int j, char **matrix)
{
  int r=i, c=j;
  int n=word.length();
  int counter=0;
  while (c-1>=0 && r-1>=0)
    {
        c--;
        r--;
        counter++;
        if(matrix[r][c]==word[counter])
        {
            if(counter==n-1)
            {
                sol[0]=i;
                sol[1]=j;
                sol[2]=r;
                sol[3]=c;
                cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")" << endl;
                return true;
            }
        }
        else
            return false;
    }
  return false;
}

bool up_check(int sol[], string word, int i, int j, char **matrix)
{
  int r=i, c=j;
  int n=word.length();
  int counter=0;
  while (r-1>=0)
    {
        r--;
        counter++;
        if(matrix[r][c]==word[counter])
        {
            if(counter==n-1)
            {
                sol[0]=i;
                sol[1]=j;
                sol[2]=r;
                sol[3]=c;
                cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")" << endl;
                return true;
            }
        }
        else
            return false;
    }
  return false;
}

bool up_right_check(int sol[], string word, int i, int j, int cols, char **matrix)
{
  int r=i, c=j;
  int n=word.length();
  int counter=0;
  while (c+1<cols && r-1>=0)
    {
        c++;
        r--;
        counter++;
        if(matrix[r][c]==word[counter])
        {
            if(counter==n-1)
            {
                sol[0]=i;
                sol[1]=j;
                sol[2]=r;
                sol[3]=c;
                cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")" << endl;
                return true;
            }
        }
        else
            return false;
    }
  return false;
}

bool right_check(int sol[], string word, int i, int j, int cols, char **matrix)
{
  int r=i, c=j;
  int n=word.length();
  int counter=0;
  while (c+1<cols)
    {
        c++;
        counter++;
        if(matrix[r][c]==word[counter])
        {
            if(counter==n-1)
            {
                sol[0]=i;
                sol[1]=j;
                sol[2]=r;
                sol[3]=c;
                cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")" << endl;
                return true;
            }
        }
        else
            return false;
    }
  return false;
}

bool down_right_check(int sol[], string word, int i, int j, int rows, int cols, char **matrix)
{
  int r=i, c=j;
  int n=word.length();
  int counter=0;
  while (c+1<cols && r+1<rows)
    {
        c++;
        r++;
        counter++;
        if(matrix[r][c]==word[counter])
        {
            if(counter==n-1)
            {
                sol[0]=i;
                sol[1]=j;
                sol[2]=r;
                sol[3]=c;
                cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")" << endl;
                return true;
            }
        }
        else
            return false;
    }
  return false;
}

bool down_check(int sol[], string word, int i, int j, int rows, char **matrix)
{
  int r=i, c=j;
  int n=word.length();
  int counter=0;
  while (r+1<rows)
    {
        r++;
        counter++;
        if(matrix[r][c]==word[counter])
        {
            if(counter==n-1)
            {
                sol[0]=i;
                sol[1]=j;
                sol[2]=r;
                sol[3]=c;
                cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")" << endl;
                return true;
            }
        }
        else
            return false;
    }
  return false;
}

bool down_left_check(int sol[], string word, int i, int j, int rows, char **matrix)
{
  int r=i, c=j;
  int n=word.length();
  int counter=0;
  while (c-1>=0 && r+1<rows)
    {
        c--;
        r++;
        counter++;
        if(matrix[r][c]==word[counter])
        {
            if(counter==n-1)
            {
                sol[0]=i;
                sol[1]=j;
                sol[2]=r;
                sol[3]=c;
                cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")" << endl;
                return true;
            }
        }
        else
            return false;
    }
  return false;
}

bool left_check(int sol[], string word, int i, int j, char **matrix)
{
  int r=i, c=j;
  int n=word.length();
  int counter=0;
  while (c-1>=0)
    {
        c--;
        counter++;
        if(matrix[r][c]==word[counter])
        {
            if(counter==n-1)
            {
                sol[0]=i;
                sol[1]=j;
                sol[2]=r;
                sol[3]=c;
                cout << "Start pos:(" << sol[0] << ", " << sol[1] << ") to End pos:(" << sol[2] << ", " << sol[3] << ")" << endl;
                return true;
            }
        }
        else
            return false;
    }
  return false;
}

void print_matrix(int rows, int cols, char **matrix)
{
  for (int i=0; i<rows; i++){
    for (int j=0; j<cols; j++){
        cout << matrix[i][j];
        if (j<cols-1)
            cout << " ";
    }
    cout << endl;
  }
}


void delete_matrix(int rows, char **matrix)
{
  for(int i=0; i<rows; i++)
    delete[] matrix[i];
  delete[] matrix;
  matrix=NULL;
}
