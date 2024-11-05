#include <iostream>
#include <cmath>

const double* aver(const double* arr, size_t size, double& average) {
    double sum = 0.0;
    for (size_t i = 0; i < size; i++) {
        sum += arr[i];
    }
    average = sum / size;

    const double* closest = &arr[0];
    for (size_t i = 1; i < size; i++) {
        if (std::abs(arr[i] - average) < std::abs(*closest - average)) {
            closest = &arr[i];
        }
    }
    return closest;
}

int main () {
    using std::cout; using std::endl;

	double arr[] = {1, 2, -1.5 , 3.25, 5.5, 7.75, -0.25, 5.75};
	size_t size = std::size(arr);
      // or
	  // size_t size = sizeof(arr)/sizeof(arr[0]);
    double average = 0;
    const double* p = aver(arr, size, average);
    cout << *p << " " << average << endl;
}
