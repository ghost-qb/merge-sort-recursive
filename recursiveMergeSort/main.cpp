//
//  main.cpp
//  recursiveMergeSort
//
//  Created by Quan Bach  on 8/21/17.
//  Copyright © 2017 QB. All rights reserved.
//

#include <cstdio>
#include <vector>

using namespace std;

//merge sort recursive function to sort an vector
vector <int> mergeSortRecursive (vector <int> _unsorted);

// function to join 2 sorted vectors
vector <int> joinVectors (vector <int> _left, const vector <int> _right);

//function to print the vector to output
void printVector (vector <int> _sorted);

int main() {
    
    auto numVec = vector<int>();
    
    numVec.push_back(5);
    numVec.push_back(1);
    numVec.push_back(3);
    numVec.push_back(7);
    numVec.push_back(2);
    numVec.push_back(4);
    numVec.push_back(6);
    //numVec.push_back(9);
    
    printf("unsorted array: ");
    printVector(numVec);
    
    // sort the vector
    auto sorted = mergeSortRecursive(numVec);
    
    printf("sorted array: ");
    printVector(sorted);
    
    return 0;
}


vector <int> mergeSortRecursive (vector <int> _unsorted)
{
    //check the base case
    if  (_unsorted.size() == 1)
        return _unsorted;
  
    //recursive steps
    auto leftHalf       = vector<int>();
    auto rightHalf      = vector<int>();
    int index = _unsorted.size() * 0.5;
        
    for (auto i = 0; i < index; i++)
    {
        leftHalf.push_back(_unsorted[i]);
    }
    for (auto j = index; j < _unsorted.size(); j++)
    {
        rightHalf.push_back(_unsorted[j]);
    }
    
    //recursively sort each half
    vector <int> sortedL = mergeSortRecursive(leftHalf);
    vector <int> sortedR = mergeSortRecursive(rightHalf);
    
    //join the sorted halves to one vector
    vector <int> sortedVec = joinVectors(sortedL, sortedR);
    
    return sortedVec;
    
}



vector <int> joinVectors (const vector <int> _left , const vector <int> _right)
{
    auto sorted = vector <int>();
    int j = 0;
    int i = 0;
    
    // joining step
    while (j+i < _left.size() + _right.size())
    {
        //check if the left half is out of range
        if ( i == _left.size())
        {
            sorted.push_back(_right[j]);
            ++j;
        }
        //check if the right half is out of range
        else if (j == _right.size())
        {
            sorted.push_back(_left[i]);
            ++i;
        }
        //sorting step from 2 halves
        else if (_left[i] < _right[j])
        {
            sorted.push_back(_left[i]);
            ++i;
        }
        //sorting step from 2 halves 
        else
        {
            sorted.push_back(_right[j]);
            ++j;
        }
    }
    
    return sorted;
}

void printVector (vector <int> _sorted)
{
    for(auto i = 0; i < _sorted.size(); ++i)
    {
        if(i == 0) {
            printf("[");
        }
        printf("%d", _sorted[i]);
        if(i == _sorted.size() -1) {
            printf("]\n");
        } else {
            printf(",");
        }
    }
}
