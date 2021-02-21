#include <iostream>
#include <vector>
// design could be a sort function which can be included by other files.
// Inside this file, different sorting algorithms can be implemented.
// the sort() function can have a default implementation and an argument selecting a custom implementation.

std::vector<int> merge(std::vector<int>& arr1, std::vector<int>& arr2)
{
    std::vector<int> ans;

    int l{0};
    int r{0};

    while (l<arr1.size() && r<arr2.size())
    {
        if (arr1[l] < arr2[r])
        {
            ans.push_back(arr1[l]);
            l++;
        }
        else
        {
            ans.push_back(arr2[r]);
            r++;
        }
    }

    while (l<arr1.size())
    {
        ans.push_back(arr1[l]);
        l++;
    }

    while (r<arr2.size())
    {
        ans.push_back(arr2[r]);
        r++;
    }

    return ans;
}

std::vector<int> merge_sort(std::vector<int>& arr)
{
    if (arr.size() < 2)
    {
        return arr;
    }

    int mid = arr.size() / 2;

    std::vector<int> arr1;
    std::vector<int> arr2;

    for (int i=0; i<mid; i++)
    {
        arr1.push_back(arr[i]);
    }

    for (int i=mid; i<arr.size(); i++)
    {
        arr2.push_back(arr[i]);
    }

    arr1 = merge_sort(arr1);
    arr2 = merge_sort(arr2);
    return merge(arr1, arr2);
}

void swap(std::vector<int>& arr, int p1, int p2)
{
    int temp{arr[p1]};
    arr[p1] = arr[p2];
    arr[p2] = temp;
}

int quick_sort_partition(std::vector<int>& arr, int left_idx, int right_idx)
{
    int ptr1{left_idx - 1};

    for (int ptr2=left_idx; ptr2<right_idx; ptr2++)
    {
        if (arr[ptr2] <= arr[right_idx])
        {
            ptr1++;
            swap(arr, ptr1, ptr2);
        }
    }

    swap(arr, ptr1 + 1, right_idx);
    return (ptr1 + 1);
}

void quick_sort_helper(std::vector<int>& arr, int left_idx, int right_idx)
{
    if (left_idx < right_idx)
    {
        int pivot{quick_sort_partition(arr, left_idx, right_idx)};
        quick_sort_helper(arr, left_idx, pivot - 1);
        quick_sort_helper(arr, pivot + 1, right_idx);
    }
}

void quick_sort(std::vector<int>& arr)
{
    quick_sort_helper(arr, 0, arr.size() - 1);
}

int main()
{
    std::vector<int> arr{5, 34, 7, 6, 23, 65, 2, 1, 3};
    // arr = merge_sort(arr);
    quick_sort(arr);

    for (int i=0; i<arr.size(); i++)
    {
        std::cout << arr[i] << ' ';
    }
    std::cout << '\n';

    return 0;
}