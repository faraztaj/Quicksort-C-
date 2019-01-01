/*
Author: Faraz Taj
Description: Very simple program to implement the quicksort algorithim on any given numbers
             in an array. Each call is printed in the correct order starting from the intial
             (first) call that is generated.  
*/

#include <iostream>
using namespace std;

//Simple swap method that will allow values to swap indexes
void swap(int v[], int i, int j){
    int temp;
    temp = v[i];
    v[i]=v[j];
    v[j] = temp;
}
void quickSort(int v[], int left, int right){
    int i, last;
     cout << "(v," << left << "," << right << ")" << endl;
     //If left is larger or equal to the right then then rest of the code will not execute
    if(left >= right)
        return;
    //call swap on left and left plus right divded by two
    swap(v, left, (left+right)/2);
    //Set last to equal left
    last = left;
    // continue to execute this loop until i is less than or equal to right
    for(i = left + 1; i <= right; i++)
        /*This condition will keep checking if the value at index position i is less than value at
        index position left until this for loop has completed*/
        if(v[i] < v[left])
        //Note the pre increment that will increase last by one before swap call
            swap(v, ++last, i);
    //call swap on left and last
    swap(v, left, last);
    //Print calls
    cout<< "CALLING QUICKSORT ON: " << left << " and " << last-1 << endl;
    quickSort(v, left, last-1);
    cout<< "CALLING QUICKSORT ON: " << last+1 << " and " << right << endl;
    quickSort(v, last+1, right);

}

int main()
{
    //Enter numbers to insert into the quicksort algorithm
    int numArray[] = {21, 9, 58, 1, 16, 33};
    //First call that is initiated 
    cout << "FIRST CALL: " << endl;
    quickSort(numArray, 0, 5);
} 