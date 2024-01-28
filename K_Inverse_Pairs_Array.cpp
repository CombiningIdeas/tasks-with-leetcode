//#include <iostream>
//#include <vector>
//#include <algorithm>
//
//using namespace std;
//using elementType = long long int;
//
///*
//For an integer array nums, an inverse pair is a pair of integers [i, j] 
//where 0 <= i < j < nums.length and nums[i] > nums[j].
//Given two integers n and k, return the number of different arrays 
//consist of numbers from 1 to n such that there are exactly k inverse pairs. 
//Since the answer can be huge, return it modulo 109 + 7.
//*/
//
////фукнции, которые нам понадобяться
//
//template<typename T>
//auto printVector(vector<T>& elements, int size) -> void;
//
//template <typename T>
//int permutations(vector<T>& elements, vector<vector<T>>& result,
//	int size, int k);
//
//template <typename T>
//auto countingTheNumberOfInversions(vector<vector<T>> elements, 
//	int lengthLine, int k) -> int;
//
//
//class Solution
//{
//public:
//    int kInversePairs(int n, int k) 
//	{
//		//сделаем проверку на k = 0, тогда возможен лишь один единственный вариант ответа
//		//это нужно для потимизации алгоритма.
//		if (k == 0)
//			return 1;
//
//		//это тоже сделанно для оптимизации, потому что ясно, что если попробовать
//		//проверить результат руками то ответ будет нужный.
//		if (k == 1)
//			return (n - 1);
//
//		vector<elementType> arrayOrdered;
//		arrayOrdered.resize(n);
//		//vector<int>::iterator it = arrayOrdered.begin();// тут можжно обойтись
//		//и без итератора
//		vector<vector<elementType>> arrayOrderedReversed;
//		for (int ii = 0; ii < n; ii++)
//			arrayOrdered[ii] = (ii + 1);
//		printVector(arrayOrdered, n);
//
//		// проверяем количество элементов, которое можно вместить в вектор без
//		//нового выделения памяти
//		cout << "Количество capacity: " << arrayOrdered.capacity() << endl;
//		cout << "Длинна вектора: " << arrayOrdered.size() << endl << endl;
//		//получаем ровно столько элементов, сколько щас в векторе
//		
//
//		// а теперь напишем основной алгоритм программы:
//		//поскольку случаев после к = 2, бывает очень очень много, то легче всего использовать
//		//перебор, это легче всего понять и быстро действие языка позволяет нам так тратить
//		//time complexity
//
//		int result = permutations(arrayOrdered, arrayOrderedReversed, n, k);
//
//		return  result;
//    }
//};
//
//int main()
//{
//	//system("chcp 1251");
//	setlocale(LC_ALL, "Russian");
//
//	int n = 11, k = 3;
//	cout << "Исходные данные: " << endl << n << " - длинна вектора"
//		<< endl << k << " - количество нужных инверсий в векторе." << endl << endl;
//
//	Solution object;
//	int result = object.kInversePairs(n, k);
//
//
//	cout << "Количесво нужных нам массивов: " << result << endl;
//
//	return 0;
//}
//
//
//template<typename T>
//auto printVector(vector<T>& elements, int size) -> void
//{
//	cout << "исходный вектор: " << endl;
//	for (int i = 0; i < size; ++i)
//		cout << elements.at(i) << " ";
//	cout << std::endl;
//}
//
//
//template <typename T>
//int permutations(vector<T>& elements, vector<vector<T>>& result,
//	int size, int k)
//{
//	do
//	{
//		result.push_back(elements);
//	} while (next_permutation(elements.begin(), elements.end()));
//
//	int counter = countingTheNumberOfInversions(result, size, k);
//
//	return counter;
//}
//
//
//template <typename T>
//auto countingTheNumberOfInversions(vector<vector<T>> elements, 
//	int lengthLine, int k) -> int
//{
//	// Для подсчета числа инверсий в перестановке необходимо подсчитать 
//	// для каждого элемента перестановки сколько элементов больших него стоит 
//	// перед ним(или сколько элементов меньших него стоит за ним) 
//	// и все эти числа сложить.
//	int counter = 0;
//
//	//// Вывод результатов, для проверки работы всей программы
//	//cout << "Итоговый двумерный вектор: " << endl;
//	//for (const auto& vec : elements)
//	//{
//	//	cout << "(";
//
//	//	for (const auto& elem : vec)
//	//		cout << elem << " ";
//
//	//	cout << ")" << endl;
//	//	count += 1;
//	//}
//
//	//поскольку это двумерный массив, то нужно это учитывать, при подсчете счетчика:
//	int numberOfLines = elements.size();//это длинна двумерного вектора, 
//	//тоесть количество строк в нем, именно строк а не стобцов.
//	cout << "количество строк: " << numberOfLines;
//	int result_count = 0;
//	for (int hh = 0; hh < numberOfLines; hh++)
//	{
//		for (int ii = lengthLine - 1; ii >= 0; ii--)
//			for (int jj = 0; jj < ii; jj++)
//			{
//				if (elements[hh][jj] > elements[hh][ii])
//					counter++;
//
//				if (counter > k)
//					break;
//			}
//
//		if (counter == k)
//			result_count++;
//		counter = 0;//не забываем затем обнулять счетчик после каждый строке вектора
//	}
//
//	cout << endl;
//	
//	return result_count;
//}







////итоговый алгоритм для github:
//using namespace std;
//using elementType = long long int;
//
//template <typename T>
//auto countingTheNumberOfInversions(vector<vector<T>> elements,
//	int lengthLine, int k) -> int
//{
//	int counter = 0;
//	int numberOfLines = elements.size();
//	int result_count = 0;
//	for (int hh = 0; hh < numberOfLines; hh++)
//	{
//		for (int ii = lengthLine - 1; ii >= 0; ii--)
//			for (int jj = 0; jj < ii; jj++)
//			{
//				if (elements[hh][jj] > elements[hh][ii])
//					counter++;
//				if (counter > k)
//					break;
//			}
//		if (counter == k)
//			result_count++;
//		counter = 0;
//	}
//	cout << endl;
//
//	return result_count;
//}
//
//
//template <typename T>
//int permutations(vector<T>& elements, vector<vector<T>>& result,
//	int size, int k)
//{
//	do
//	{
//		result.push_back(elements);
//	} while (next_permutation(elements.begin(), elements.end()));
//
//	int counter = countingTheNumberOfInversions(result, size, k);
//
//	return counter;
//}
//
//
//class Solution
//{
//public:
//	int kInversePairs(int n, int k)
//	{
//		if (k == 0)
//			return 1;
//
//		if (k == 1)
//			return (n - 1);
//
//		vector<elementType> arrayOrdered;
//		arrayOrdered.resize(n);
//		vector<vector<elementType>> arrayOrderedReversed;
//		for (int ii = 0; ii < n; ii++)
//			arrayOrdered[ii] = (ii + 1);
//
//		int result = permutations(arrayOrdered, arrayOrderedReversed, n, k);
//
//		return  result;
//	}
//};



////Решение с гитхаба:
//class Solution {
//public:
//	int kInversePairs(int n, int k)
//	{
//		int array1[1001][1001] = {1};
//		for (int i = 1; i <= n; i++)
//			for (int j = 0; j <= k; j++)
//				for (int x = 0; x <= min(j, i - 1); x++)
//					if (j - x >= 0)
//						array1[i][j] = (array1[i][j] + array1[i - 1][j - x]) % 1000000007;
//
//		return array1[n][k];
//	}
//};