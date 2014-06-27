#include <iostream>
#include <vector>
#include <functional>
using namespace std;

template<class item_t, class comp_t>
void heapSort(vector<item_t> & data, const comp_t & comp = comp_t())
{
    const size_t size = data.size();
    buildHeap(data, comp);
    for (size_t i = 0; i < size - 1; ++i) {
        swap(data[0], data[size - i - 1]);
        heapify(data, 0, size - i - 1, comp);
    }
}

template<class item_t, class comp_t>
void buildHeap(vector<item_t> & data, const comp_t & comp)
{
    const size_t size = data.size();
    const size_t last = size - 1;
    for (int i = parrent(last); i >= 0; --i) {
        heapify(data, i, size, comp);
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

