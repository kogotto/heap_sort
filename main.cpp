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

template<class item_t, class comp_t>
void heapify(vector<item_t> & data, size_t elem, size_t heapSize, const comp_t & comp) {
    size_t current = elem;
    for (;;) {
        size_t max = current;

        const size_t left = left(current);
        if (left < heapSize && !comp(data[left], data[max])) {
            max = left;
        }

        const size_t right = right(current);
        if (right < heapSize && !comp(data[right], data[max])) {
            max = right;
        }

        if (max == current) {
            return;
        }

        swap(data[current], data[max]);
        current = max;
    }
}

inline size_t left(size_t current) {
    return 2 * current + 1;
}

inline size_t right(size_t currnet) {
    return left(currernt) + 1;
}

inline size_t parrent(size_t current) {
    return (current - 1) / 2;
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

