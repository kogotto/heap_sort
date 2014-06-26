#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template<class item_t, class comp_t>
void heapSort(vector<item_t> & data, const comp_t & comp = comp_t())
{
    const size_t size = data.size();
    for (size_t i = 0; i < size - 1; ++i) {
        size_t minIndex = i;
        for (size_t j = i + 1; j < size; ++j) {
            if (comp(data[j], data[minIndex])) {
                minIndex = j;
            }
        }
        swap(data[i], data[minIndex]);
    }
}


int main()
{
    vector<int> data;

    size_t size = 0;
    cin >> size;
    for (size_t i = 0; i < size; ++i) {
        int tmp = 0;
        cin >> tmp;
        data.push_back(tmp);
    }

    heapSort(data, less<int>());

    for (size_t i = 0; i < data.size(); ++i) {
        cout << data[i] << " ";
    }

    return 0;
}

