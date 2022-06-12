#include <iostream>
using namespace std;
// інтерфейс, що описує функтори - унарні предикати
template<class T>
class Predicate
{
public:
	virtual bool operator () (T x) = 0;
};
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
template<class T>
class Positive : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x > 0;
	}
};

template<class T>
class Negative : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x < 0;
	}
};

template<class T>
class Even : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 == 0;
	}
};

template<class T>
class Odd : public Predicate<T>
{
public:
	virtual bool operator () (T x)
	{
		return x % 2 != 0;
	}
};

template<class T>
int replace(T* begin, T* end, T* to)
{
	T* n = end;
	for (T* from = begin; from < end; from++)
	{
		
		*to = *from;
		to++;
		T* temp = to;
		to = to +1 ;
		++to = temp;
		n--;
	}
	return *n;
}

template<class T>
int replace_if(T* begin, T* end, T* to, Predicate<T>& p)
{
	int n = 0; 
	for (T* i = begin; i < end; i++)
	{
		if (p(*i))
			n++;
	}
	for (T* start = begin; start < end; start++)
	{
		for (T* from = start; from < end; from++) 
		{ 
			
			if (p(*from)) 
			{
				*to = *from;
				to++;
				T* temp = to;
				to = to + 1;
				++to = temp;
				*to = *end-1;
			}
		}
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


	
	int b[x*3], c[x*3]; // результуючі контейнери


	cout << "\nreplace all container:\n";
	int u = replace(&a[0], &a[x], &b[0]); 
	cout << endl;
	for (int i = 0; i < u; i++)
		cout << b[i] << '\t'; 
	cout << endl;

	Predicate<int>* even = new Even<int>(); 

	cout << "\nreplace if container:\n";
	int n = replace_if(&a[0], &a[x], &c[0], *even); 
	cout << endl;
	for (int i = 0; i < n; i++)
		cout << c[i] << '\t';
	cout << endl;

	return 0;

} 