#include <iostream>
using namespace std;
// інтерфейс, що описує функтори - унарні предикати
template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};

// реалізуємо інтерфейс функтором - перевірка, чи значення дорівнює нулю
template<class T>
class Zero : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		T zero = T();
		return x == zero;
	}
};
// реалізуємо інтерфейс функтором - перевірка, чи значення додатне
// працює лише для числових типів
template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};
// реалізуємо інтерфейс функтором - перевірка, чи значення від'ємне
// працює лише для числових типів
template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};
// реалізуємо інтерфейс функтором - перевірка, чи значення парне
// працює лише для цілих типів
template<class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};
// реалізуємо інтерфейс функтором - перевірка, чи значення не парне
// працює лише для цілих типів
template<class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 != 0;
	}
};
// дублюємо всі елементи
// begin - ітератор початку вхідного контейнера (вказує на перший елемент)

// end - ітератор кінця вхідного контейнера (вказує на елемент після останнього)
// to - ітератор початку результуючого контейнера (вказує на перший елемент)
template<class T>
int replace(T * begin, T * end, T * to)
{
	int n = 0;
	for (T* start = begin; start < end; start++)
	{
		for (T* from = begin; from < end; from++) // from - ітератор вхідного контейнера
		{ // вказує на поточний елемент
			*to = *from;
			to++;
			T* temp = to;
			to = to + 1;
			++to = temp;
			*to = *end-1; 
			*to = *from;
			to++;
		    temp = to;
			to = to + 1;
			++to = temp;
			*to = *end - 1;
		}
		//n++;
		end--;
	}
	return n;
}
// дублюємо елементи, для яких предикат p набуває значення true
// begin - ітератор початку вхідного контейнера (вказує на перший елемент)
// end - ітератор кінця вхідного контейнера (вказує на елемент після останнього)
// to - ітератор початку результуючого контейнера (вказує на перший елемент)
template<class T>
int replace_if(T* begin, T* end, T* to, Predicate<T>& p)
{
	int n = 0; // n - кількість елементів у результуючому контейнері
	for (T* start = begin; start < end; start++)
	{
		for (T* from = start; from < end; from++) // from - ітератор вхідного контейнера
		{ // вказує на поточний елемент // скопіювали елемент
			
			if (p(*from)) // якщо справджується умова предикату
			{
				*to = *from;
				to++;
				T* temp = to;
				to = to + 1;
				++to = temp;
				*to = *end-1;
			}
		}
		n++;
		end--;
	}
	return n;
}
int main()
{
	const int x = 10;
	int a[x]; // вхідний контейнер
	cout << "Input container:\n";
	cout << endl;
	for (int k = 0; k < x; k++)
	{
		a[k] = k;
		cout << a[k] << '\t';
	}
	cout << endl;
	int b[1], c[5]; // результуючі контейнери
// (потрібно виділити достатньо пам'яті)

	cout << "\nreplace all container:\n";
	int u = replace(&a[0], &a[x], &b[0]); // продублювали всі елементи
	cout << endl;
	for (int i = 0; i < u; i++)
		cout << b[i] << '\t'; // вивели результат
	cout << endl;

	Predicate<int>* even = new Even<int>(); // функтор: "парні елементи"

	cout << "replace if container:\n";
	int n = replace_if(&a[0], &a[x], &c[0], *even); // викинули парні елементи
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << c[i] << '\t';
	cout << endl;
	
	return 0;

}