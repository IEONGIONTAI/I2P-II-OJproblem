#include <cstddef>
#include <iostream>
#define NAN -1

namespace std
{
	template<typename T> class vector {
		public:
			vector() {
                arr = new T[1];
                CAPACITY = 1;
                SIZE = 0;
			}
			void push_back(T x) {
                if (SIZE == CAPACITY) {
                    int* temp = new T[2 * CAPACITY];

                    for (int i = 0; i < CAPACITY; i++) {
                        temp[i] = arr[i];
                    }
                    delete[] arr;
                    CAPACITY *= 2;
                    arr = temp;
                }

                arr[SIZE] = x;
                SIZE++;
			}
			void pop_back() {
                arr[SIZE--] = NAN;
			}
			T & operator [] (const int &x) {
                return arr[x];
			}
			const T & operator [] (const int &x) const {
                return arr[x];
			}
			size_t size() {
                return SIZE;
			}
			size_t capacity() {
			    if(CAPACITY == 1 && SIZE == 0) return 0;
                else return CAPACITY;
			}
			void reserve(size_t x) {
			    if(CAPACITY <= x)
                    CAPACITY = x;
                else return;
			}
			void clear() {
                SIZE = 0;
			}
		private:
			T *arr;
			size_t CAPACITY;
			size_t SIZE;
	};
}

template class std::vector<int>;
