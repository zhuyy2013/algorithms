//
//  main.cpp
//  Sort2
//
//  Created by Yanhui Liang on 2/8/15.
//  Copyright (c) 2015 Yanhui Liang. All rights reserved.
//

#include <iostream>


void insertSort(int num[], int len)
{
    int temp, idx = 0;
    
    for (int i = 1; i < len; i++) // current number
    {
        temp = num[i];
        for (int j = i-1; j >=0; j--)  // sorted numbers
        {
            if (temp < num[j])   // move backwards
            {
                num[j+1] = num[j];
            }
            else
            {
                idx = j+1;    // get the position to put current number
                break;
            }
            
        }
        num[idx] = temp;
        
    }
}

int main(int argc, const char * argv[])
{

    // insert sort
    
    int num[] = {3,1,9,4,8,10};
    
    insertSort(num, 6);
    
    
    // insert code here...
    std::cout << "Hello, World!\n";
    return 0;
}

