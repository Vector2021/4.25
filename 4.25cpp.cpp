#include<iostream>
#include<vector>
#include<memory>
using namespace std;



class student {
public:
    void func(int age,int id)
    {
        _age = age;
        _id = id;
    }
    void print()
    {
        cout << _age << _id << endl;
    }
private:
    int _age;
    int _id;
};
int main()
{
    student L;
    L.func(18,111);
    L.print();
}


class base {
public:
	virtual void func()
	{
		cout << "i am father!" << endl;
	}
};
class derived : public base {
public:
	void func()
	{
		cout << "i am son!" << endl;
	}
};

void foo(base& b)
{
	b.func();
}

int main()
{
	base b;
	derived d;
	base* p = &d;
	base& br = d;
	
	b.func();
	d.func();
	p->func();
	br.func();
	foo(d);
}


void Qsort(int* a, int start, int end)
{
	int i = start;
	int j = end;
	int key = a[i];
	if (i > j)
		return;
	while (i < j)
	{
		while (i < j && a[j] >= key)
		{
			j--;
		}
		a[i] = a[j];
		while (i < j && a[i] <= key)
		{
			i++;
		}
		a[j] = a[i];
	} 
    a[i] = key;
	Qsort(a, start, i - 1);
	Qsort(a, i + 1, end);
}

//定义一个学生类
class Student {
public:
	Student() {} //构造函数

	~Student() {} //析构函数
	
    //类内定义定义函数
	void print() {
		cout << age << " " << id << endl;
	}
protected:
	char name; //姓名
	int age = 18;  //年龄
	int id = 1111111;  //学号
};

int main()
{
	Student WY;//定义第一个学生对象
	WY.print(); //在类外调用类内函数
	
	Student GC; //定义第二个学生对象
	GC.print(); //在类外调用类内函数
}

多态：父类的指针或者引用表现出多态，既可以表现出父类的形态，又可以表现出子类的形态；
class base {
public:
	void func()
	{
		cout << "base func!" << endl;
	}
};

class derived : public base
{
public:
	void func()
	{
		cout << "derived func!" << endl;
	}
};

void foo(base& b)
{
	b.func();
}
 
int main()
{
	base b;
	derived d;
	
	base *p = &d;//父类指针指向了子类对象
	base& br = d;//父类引用指向子类对象；

	b.func();//父类版本
	d.func();//子类版本
	p->func();
	br.func();
	foo(d);
}



class Buffer {
public:
	typedef unsigned char byte;
	Buffer(const size_t buffer_size) {};
	Buffer(const Buffer& obj);
	Buffer(Buffer&& obj);
	Buffer& operator = (Buffer& obj);
	Buffer& operator = (Buffer&& obj);
	~Buffer();
private:
	size_t buf_size{ 0 };
	 byte* buf{ nullptr };
};

class Son : public Buffer {
public:
	
};
class yuan {
public:
	yuan() {
		int r;
		int d;
	}
	void print()
	{
		cout << d << endl;
		cout << this->d << endl;
		cout << (*this).d << endl;
	}
private:
	int d = 10;
	int r = 5;
};
int main()
{
	yuan c;
	c.print();
}


int main()
{
	vector<int> v;
	int a[10] = {1,2,3,4,5,6,7,8,9,10};
	for (int i = 0; i < 10; ++i)
	{
		v.push_back(a[i]);
		cout << v[i] << endl;
		v.pop_back();
		cout << v[i] << endl;
	}
	
}


int* fun()
{
	int* p = new int(10);
	return p;
}

int main()
{
	int* q = fun();
	cout << q << endl;
	cout << *q << endl;
	delete q;
	cout << q << endl;
}




new的基本用法
void test()
{
    int*  arr = new int[10];
    for (int i = 0; i < 10; ++i)
    {
        arr[i] = i;
        cout << arr[i] << endl;
    }
    delete[] arr;
    /*for (int i = 0; i < 10; ++i)
    {
        cout << arr[i] << endl;
    }*/

}

int main() {
    test();
    return 0;
}