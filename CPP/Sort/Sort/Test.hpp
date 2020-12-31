//
//  Test.hpp
//  Sort
//
//  Created by MarkWu on 2019/10/21.
//  Copyright © 2019 Zego. All rights reserved.
//

#ifndef Test_h
#define Test_h
#include <cassert>
#include <iostream>
#include <chrono>

using namespace std;

class TestSortingAlgorithm
{
private:
    static void PrintData(int data[], unsigned int size)
    {
        cout << "[TestSortingAlgorithm::PrintData], size:" << size << endl;
        
        if (data == nullptr)
        {
            cout << "[TestSortingAlgorithm::PrintData] Error, data is nullptr" << endl;
            return;
        }
        
        for (unsigned int i = 0; i < size; i++)
        {
            cout << data[i] << "\t";
        }
        
        cout << endl << endl;
    }

    
    static bool VerifyOrderOfData(int sorted_data[], unsigned int size_of_data, bool from_small_to_large)
    {
        bool passed = true;
        
         for (unsigned int i = 0; i < (size_of_data - 1); i++)
         {
            if (from_small_to_large)
            {
                if (sorted_data[i] > sorted_data[i+1])
                {
                    passed = false;
                    break;
                }
            }
            else
            {
                if (sorted_data[i] < sorted_data[i+1])
                {
                    passed = false;
                    break;
                }
            }
         }
        
        sprintf(buf_of_log_, "[TestSortingAlgorithm::VerifyOrderOfData] passed: %d\n", passed);
        cout << buf_of_log_;
    
        return passed;
    }
    
public:
      static int* GenerateTestData(unsigned int size)
      {
          cout << "[TestSortingAlgorithm::GenerateTestData], size:" << size << endl;
          
          if (size == 0)
          {
              cout << "[TestSortingAlgorithm::GenerateTestData] Error, size must be larger than 0" << endl;
              return nullptr;
          }
          
          int *data = (int *)malloc(size * sizeof(int));
          if (data == nullptr)
          {
              cout << "[TestSortingAlgorithm::GenerateTestData] Error, malloc failed" << endl;
              return nullptr;
          }
          
          memset(data, 0, size * sizeof(int));
          
          srand((unsigned) time(nullptr));
          for (unsigned i = 0; i < size; i++)
          {
              data[i] = rand() % size;
          }
          
          return data;
      }
    
    static bool Test(bool(*sort_func)(int *, int), int *data, unsigned int size_of_data)
    {
//        assert(sort_func(nullptr, size_of_data) == false);
        
        int *copy_of_data = (int *)malloc(size_of_data * sizeof(int));
        if (copy_of_data == nullptr)
        {
            cout << "[TestSortingAlgorithm::Test], Malloc Error!" << endl;
            return false;
        }
        
        memcpy(copy_of_data, data, size_of_data * sizeof(int));
        
//        PrintData(copy_of_data, size_of_data);
        
         std::chrono::milliseconds start_time = std::chrono::duration_cast< std::chrono::milliseconds >(
               std::chrono::system_clock::now().time_since_epoch()
           );
        
        assert(sort_func(copy_of_data, size_of_data) == true);
        
        std::chrono::milliseconds end_time = std::chrono::duration_cast< std::chrono::milliseconds >(
            std::chrono::system_clock::now().time_since_epoch()
        );
        
//        PrintData(copy_of_data, size_of_data);
        
        cout << "[TestSortingAlgorithm::Test], time consumed: " << (end_time.count() - start_time.count()) << "ms" << endl;
        
        assert(VerifyOrderOfData(copy_of_data, size_of_data, true) == true);
        
        cout << "[TestSortingAlgorithm::Test] Done" << endl << endl;
        
        free(copy_of_data);
        
        return false;
    }
    
private:
    static char buf_of_log_[1024];
};

char TestSortingAlgorithm::buf_of_log_[1024] = {0};

#endif /* Test_h */
