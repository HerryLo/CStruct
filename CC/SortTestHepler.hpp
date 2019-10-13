//
//  SortTestHepler.hpp
//  CC
//
//  Created by HerryLo on 2018/11/15.
//  Copyright © 2018年 HerryLo. All rights reserved.
//

#ifndef SortTestHepler_hpp
#define SortTestHepler_hpp

#include <stdio.h>
#include <ctime>
#include <cassert>

using namespace std;

// 生成长度n的随机数组，区间[rangeL, rangeR]
namespace SortTestHepler {
    // 随机生成数组
    int* generaterRamdom(int n, int rangeL, int rangeR) {
        int *arr = new int[n];
        srand(time(NULL));
        for(int i=0;i<n;i++){
            arr[i] = rand() % (rangeR - rangeL+1) +rangeL;
        }
        return arr;
    }
    
    // 获取数组的元素个数
    template<typename T>
    int getCout(T arr[], int n) {
        for(int i=0;i<n;i++){
            cout<<arr[i]<<' '<<i<<endl;
        }
        return 1;
    }
    
    //判断排序是否完成
    template<typename T>
    bool isSorted(T arr, int n){
        for(int i =0;i<n-1;i++){
            if(arr[i] > arr[i+1]){
                return false;
            }
        }
        return true;
    }
    
    // 计算排序时间
    template<typename T>
    void testSort(string sortName, void (*sort)(T[], int), T arr[], int n) {
        clock_t startTime = clock();
        sort(arr, n);
        clock_t endTime = clock();
        cout<< sortName << ":" <<double(endTime - startTime)/CLOCKS_PER_SEC<< " s" << endl;
        assert(isSorted(arr, n));
        return;
    }
}

#endif /* SortTestHepler_hpp */
