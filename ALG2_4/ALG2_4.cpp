#include <iostream>
#include <fstream>
#include <string>
#include <iomanip>
#include <vector>
#include <algorithm> 


using namespace std;

int find_closest(const std::vector<unsigned int>& vec, int value, int min_index, int max_index, int last_value);
int main()
{

    std::vector<unsigned int> myVector;

    const int arr_size = 10000;
    const int arr_a_range = 4000000000;

    for (int i = 0; i < arr_size; i++)
        myVector.push_back(rand() % arr_a_range);


    std::vector<unsigned int> myVector2;
    const int arr_size2 = 100;

    for (int i = 0; i < arr_size2; i++)
        myVector2.push_back(rand() % arr_a_range);

    /*const int arr_size = 10;
    std::vector<unsigned int> myVector{0,1,2,3,4,6,6,7,8,9};
    std::vector<unsigned int> myVector2{1,3,5,7};*/

    sort(myVector.begin(), myVector.end());

    cout << "prvych 10" << endl;
    for (size_t i = 0; i < 10; i++)
    {
        cout << myVector[i] << endl;
    }
    cout << endl;
    cout << "prostrednych 10" << endl;
    int middle_index = arr_size / 2;
    int v_index;
    for (size_t i = 0; i < 10; i++)
    {
        v_index = middle_index - 5 + i;
        cout << myVector[v_index] << endl;
    }
    cout << endl;
    cout << "poslednych 10" << endl;
    for (size_t i = 10; i >= 1; i--)
    {
        cout << myVector[arr_size - i] << endl;
    }

    cout << endl;
    cout << "Prvky pola B a ich najblizsie cisla z A" << endl;

    for (unsigned int n : myVector2) {
        cout << n << " ---> " << find_closest(myVector, n, 0, myVector.size(), n) << endl;
    }

   





    return 0;
}
/*
struct ClosestCmp {
    bool operator()(const int& x, const int& y) { return x > y; }
};

int find_closest(const std::vector<unsigned int>& vec, int value)
{
    std::vector<unsigned int>::const_reverse_iterator cri = std::lower_bound(vec.rbegin(), vec.rend(), value, ClosestCmp());
    if (cri != vec.rend()) {
        return *cri;
    }
    return -1;
}*/
int find_closest(const std::vector<unsigned int>& vec, int value, int min_index , int max_index, int last_value) {
    int middle_index = (max_index + min_index) / 2;
    int return_nubmer = vec[middle_index];
    if (vec[middle_index] > value)
    {
        if (return_nubmer==last_value)
        {
            return return_nubmer;
        }
        return_nubmer = find_closest(vec, value, min_index, middle_index, vec[middle_index]);
    }
    else if(vec[middle_index] < value){
        if (return_nubmer == last_value)
        {
            return return_nubmer;
        }
        return_nubmer = find_closest(vec, value, middle_index, max_index, vec[middle_index]);
    }
    return return_nubmer;
}