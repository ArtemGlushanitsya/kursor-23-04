// Kursor 23 04 2017
//наследование класса

//prog 1
/*
#include <iostream>

class A
{
public:
	A(const int i): i(i)
	{}
private:
	int i;

	friend std::ostream& operator << (std::ostream& s, const A& a);
};

class B: public A
{
public:
	B(const int i): A(i)
	{}
};

int main(void)
{
	const A a(111);
	std::cout << a << std::endl;
	const B b(222);
	std::cout << b << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a) // overload operator
{
	return s << a.i;
}*/

//prog 1(1)
/*
#include <iostream>

class A
{
public:
	A(const int i) : i(i)
	{}
private:
	int i;

	friend std::ostream& operator << (std::ostream& s, const A& a);
};

class B : public A
{
public:
	B(const int i) : A(i)
	{}
};

int main(void)
{
	const B b(1234567);
	const A* a(&b);
	std::cout << *a << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a) // overload operator
{
	return s << a.i;
}*/

//prog 1(2)
/*
#include <iostream>

class A
{
public:
	A(const int i) : i(i)
	{}

private:
	int i;

	friend std::ostream& operator << (std::ostream& s, const A& a);
};

class B: public A
{
public:
	B(const int i, const int j) : A(i), i(j)
	{}

private:
	int i;

	friend std::ostream& operator << (std::ostream& s, const B& b);
};

int main(void)
{
	const A a(111111);
	std::cout << a << std::endl;
	const B b(222222, 333333);
	std::cout << b << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.i;
}

std::ostream& operator << (std::ostream& s, const B& b)
{
	const A& a(b);
	return s << a << ' ' << b.i;
}*/

//prog 1(3)
/*
#include <iostream>

class A
{
public:
	A(const int i) : i(i)
	{}

	auto& get(void) const
	{
		return *this;
	}
private:
	int i;

	friend std::ostream& operator << (std::ostream& s, const A& a);
};

class B : public A
{
public:
	B(const int i, const int j) : A(i), i(j)
	{}

private:
	int i;

	friend std::ostream& operator << (std::ostream& s, const B& b);
};

int main(void)
{
	const A a(111111);
	std::cout << a << std::endl;
	const B b(222222, 333333);
	std::cout << b << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.i;
}

std::ostream& operator << (std::ostream& s, const B& b)
{
	return s << b.get() << ' ' << b.i;
}*/

//prog 1(4)
/*
#include <iostream>

class A
{
public:
	A(const float f) : f(f)
	{}

	auto& get(void) const
	{
		return *this;
	}

	void set(const float f)
	{
		A::f = f;
	}
private:
	float f;

	friend std::ostream& operator << (std::ostream& s, const A&);
};

class B : public A
{
public:
	B(const float f, const int i) : A(f), i(i)
	{}

	void set(const int i)
	{
		B::i = i;
	}

private:
	int i;

	friend std::ostream& operator << (std::ostream& s, const B&);
};

int main(void)
{
	A a(1.11);
	std::cout << a << std::endl;
	a.set(2.22);

	B b(3.33, 333333);
	std::cout << b << std::endl;
	b.set(44444); // сэт накриывает сэт баз класса
	std::cout << b << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.f;
}

std::ostream& operator << (std::ostream& s, const B& b)
{
	return s << b.get() << ' ' << b.i;
}*/

//prog 1(5)
/*
#include <iostream>

class A
{
public:
	A(const float f) : f(f)
	{}

	auto& get(void) const
	{
		return *this;
	}

	void set(const float f)
	{
		A::f = f;
	}
private:
	float f;

	friend std::ostream& operator << (std::ostream& s, const A&);
};

class B : public A
{
public:
	using A::A;

	B(const float f, const int i) : A(f), i(i)
	{}

	using A::set; // юзинг должен быть в паблике

	void set(const int i)
	{
		B::i = i;
	}

private:
	int i{};

	friend std::ostream& operator << (std::ostream& s, const B&);
};

int main(void)
{
	A a(1.11f);
	std::cout << a << std::endl;
	a.set(2.22f);
	std::cout << a << std::endl;

	B b(3.33f, 33333);
	std::cout << b << std::endl;
	b.set(4.44f);
	b.set(44444);
	std::cout << b << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.f;
}

std::ostream& operator << (std::ostream& s, const B& b)
{
	return s << b.get() << ' ' << b.i;
}*/

//prog 1(6)
/*
#include <iostream>

class A
{
public:
	A(const float f) : f(f)
	{}

	auto& get(void) const
	{
		return *this;
	}

	void set(const float f)
	{
		A::f = f;
	}
private:
	float f;

	friend std::ostream& operator << (std::ostream& s, const A&);
};

class B : public A
{
public:
	using A::A;

	B(const float f, const int i) : A(f), i(i)
	{}

	using A::set;

	void set(const int i)
	{
		B::i = i;
	}

private:
	int i{};

	friend std::ostream& operator << (std::ostream& s, const B&);
};

int main(void)
{
	B b(1.11f);
	std::cout << b << std::endl;
	b.set(2.22f);
	b.set(22222);
	std::cout << b << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.f;
}

std::ostream& operator << (std::ostream& s, const B& b)
{
	return s << b.get() << ' ' << b.i;
}*/

//prog 1(7)
/*
#include <iostream>

class A
{
public:
	A(void)
	{}

	A(const float f) : f(f)
	{}

	auto& get(void) const
	{
		return *this;
	}

	void set(const float f)
	{
		A::f = f;
	}
private:
	float f{};

	friend std::ostream& operator << (std::ostream& s, const A&);
};

class B : public A
{
public:
	using A::A;

	B(void)
	{}

	B(const float f, const int i) : A(f), i(i)
	{}

	using A::set;

	void set(const int i)
	{
		B::i = i;
	}

private:
	int i{};

	friend std::ostream& operator << (std::ostream& s, const B&);
};

int main(void)
{
	A a;
	std::cout << a << std::endl;

	B b;
	std::cout << b << std::endl;
	b.set(2.22f);
	b.set(22222);
	std::cout << b << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.f;
}

std::ostream& operator << (std::ostream& s, const B& b)
{
	return s << b.get() << ' ' << b.i;
}*/

//prog 1(8)
/*
#include <iostream>

class A
{
public:
	A(void)
	{}

	A(const float f) : f(f)
	{}

	void set(const float f)
	{
		A::f = f;
	}
protected:
	float f{};

	friend std::ostream& operator << (std::ostream& s, const A&);
};

class B : public A
{
public:
	using A::A;

	B(void)
	{}

	B(const float f, const int i) : A(f), i(i)
	{}

	using A::set;

	void set(const int i)
	{
		B::i = i;
	}

private:
	int i{};
};

int main(void)
{
	B b(1.11f);
	std::cout << b << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.f;
}
*/

//prog 1(9)
/*
#include <iostream>

class A
{
public:
	A(void)
	{}

	A(const float f) : f(f)
	{}

	void set(const float f)
	{
		A::f = f;
	}
protected:
	float f{};

	friend std::ostream& operator << (std::ostream& s, const A&);
};

class B : public A
{
public:
	using A::A;

	B(void)
	{}

	B(const float f, const int i) : A(f), i(i)
	{}

	using A::set;

	void set(const int i)
	{
		B::i = i;
	}

protected:
	int i{};
};

class C : public B
{
public:
	C(const float f, const int i) : B(f, i)
	{}
private:
	friend std::ostream& operator << (std::ostream& s, const C& c);
};

int main(void)
{
	C c(1.11f, 11111);
	std::cout << c << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.f;
}

std::ostream& operator << (std::ostream& s, const C& c)
{
	return s << c.f << ' ' << c.i;
}*/

//prog 1(10)

#include <iostream>

class A
{
public:
	A(void)
	{}

	A(const float f) : f(f)
	{}

	void set(const float f)
	{
		A::f = f;
	}
protected:
	float f{};

	friend std::ostream& operator << (std::ostream& s, const A&);
};

class B : protected A
{
public:
	using A::A;

	B(void)
	{}

	B(const float f, const int i) : A(f), i(i)
	{}

	using A::set;

	void set(const int i)
	{
		B::i = i;
	}

protected:
	friend std::ostream& operator << (std::ostream& s, const B& b);

	int i{};
};

class C : B
{
public:
	C(const float f, const int i) : B(f, i)
	{}

private:
	friend std::ostream& operator << (std::ostream& s, const C& c);
};

int main(void)
{
	C c(1.11f, 11111);
	std::cout << c << std::endl;
}

std::ostream& operator << (std::ostream& s, const A& a)
{
	return s << a.f;
}

std::ostream& operator << (std::ostream& s, const B& b)
{
	return s << b.f << ' ' << b.i;
}

std::ostream& operator << (std::ostream& s, const C& c)
{
	return s << c.f << ' ' << c.i;
}