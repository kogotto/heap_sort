#include <iostream>
#include <vector>
#include <functional>
#include <algorithm>
using namespace std;



inline size_t leftChild(size_t current) {
    return 2 * current + 1;
}



inline size_t rightChild(size_t current) {
    return leftChild(current) + 1;
}



inline size_t parrent(size_t current) {
    return (current - 1) / 2;
}



template<class item_t, class comp_t>
void heapify(vector<item_t> & data, size_t elem, size_t heapSize, const comp_t & comp) {
    size_t current = elem;
    for (;;) {
        size_t max = current;

        const size_t left = leftChild(current);
        if (left < heapSize && !comp(data[left], data[max])) {
            max = left;
        }

        const size_t right = rightChild(current);
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



template<class item_t, class comp_t>
void buildHeap(vector<item_t> & data, const comp_t & comp)
{
    const size_t size = data.size();
    if (size <= 1) {
        return;
    }

    const size_t last = size - 1;
    for (int i = parrent(last); i >= 0; --i) {
        heapify(data, i, size, comp);
    }
}



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



struct point_t {
    explicit point_t(int x = 0, int y = 0):
        x(x),
        y(y)
    {}

    int x;
    int y;
};

bool operator == (const point_t & left, const point_t & right) {
    return (left.x == right.x) && (left.y == right.y);
}



double tan(const point_t & origin, const point_t & end) {
    return (static_cast<double>(end.y - origin.y)) / (end.x - origin.x);
}



struct point_comparator_t {
    point_comparator_t(const vector<point_t> & data) {
        size_t min = 0;
        for (size_t i = 1; i < data.size(); ++i) {
            if ((data[min].x == data[i].x) &&
                    (data[min].y > data[i].y)) {
                min = i;
                continue;
            }

            if (data[min].x > data[i].x) {
                min = i;
            }
        }

        first = data[min];
    }

    bool operator () (const point_t & left, const point_t & right) const {
        if (left == first) {
            return true;
        }

        if (right == first) {
            return false;
        }

        return tan(first, right) < tan(first, left);
    }

private:
    point_t first;
};



int main()
{
    vector<point_t> data;

    size_t size = 0;
    cin >> size;
    if (size == 0) {
        return 0;
    }

    for (size_t i = 0; i < size; ++i) {
        int x = 0;
        cin >> x;
        int y = 0;
        cin >> y;
        data.push_back(point_t(x, y));
    }

    heapSort(data, point_comparator_t(data));

    for (size_t i = 0; i < data.size(); ++i) {
        cout << data[i].x << " " << data[i].y << endl;
    }

    return 0;
}

