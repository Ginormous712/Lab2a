#include <iostream>
#include <string>
#include <vector>
#include <ctime>
#include <fstream>
#include <Windows.h>
#include <conio.h>

using namespace std;

struct Point
{
	double x;
	double y;
	double z;

	Point()
	{
		x = 0.0;
		y = 0.0;
		z = 0.0;
	}

	Point(double x, double y, double z)
	{
		this->x = x;
		this->y = y;
		this->z = z;
	}

	void print()
	{
		cout << "X: " << x << endl;
		cout << "Y: " << y << endl;
		cout << "Z: " << z << endl;

	}
	
};

struct StackArray
{
	Point* data;
	//Point top;
	size_t size;

	StackArray()
	{
		data = nullptr;
		//top = {};
		size = 0;
	}
	~StackArray()
	{
		delete[] data;
	}

	StackArray create_emtpy()
	{
		return StackArray();
	}

	void push(Point item)
	{
		Point* temporary;
		temporary = data;

		data = new Point[size + 1];
		size++;

		for (size_t i = 0; i < size - 1; i++)
		{
			data[i] = temporary[i];
		}
		data[size - 1] = item;

		if (size > 0)
		{
			delete[] temporary;
		}

	}

	void pop()
	{
		if (size != 0)
		{
			Point* temporary;
			temporary = data;

			data = new Point[size - 1];
			size--;

			for (size_t i = 0; i < size; i++)
			{
				data[i] = temporary[i];
			}
			delete[] temporary;
		}
		
	}

	void peek()
	{
		if (size != 0)
		{
			data[size - 1].print();
		}
		else
		{
			cout << "Stack is empty!" << endl;
		}
	}

	bool is_empty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}
};

struct StackVector
{
	vector<Point> data;
	Point top;
	size_t size;

	StackVector()
	{
		data = {};
		top = {};
		size = 0;
	};

	StackVector create_emtpy()
	{
		return StackVector();
	}

	void push(Point point)
	{
		data.push_back(top);
		top = point;
		size++;
	}

	void pop()
	{
		if (size != 0)
		{
			top = data[size - 1];
			data.pop_back();
			size--;
		}
	}

	void peek()
	{
		if (size != 0)
		{
			top.print();
		}
		else
		{
			cout << "Stack is empty" << endl;
		}
	}

	bool is_empty()
	{
		if (size == 0)
		{
			return true;
		}
		return false;
	}
};

struct Node
{
	Point data;
	Node* next;
	Node()
	{
		data = {};
		next = nullptr;
	}

	Node(Point data, Node* next)
	{
		data = this->data;
		next = this->next;
	}
};

struct List
{
	Node* first;
	Node* last;

	List()
	{
		first = nullptr;
		last = nullptr;
	}

	List create_empty()
	{
		return List();
	}

	void push(Point item)
	{
		Node* tmp = new Node;
		tmp->data = item;
		tmp->next = nullptr;
		if (first != nullptr)
		{
			last->next = tmp;
			last = tmp;
		}
		else
		{
			first = tmp;
			last = tmp;
		}
	}

	void pop()
	{
		if (first != nullptr)
		{
			Node* tmp = first;
			if (tmp->next != nullptr)
			{
				while (tmp->next != last)
				{
					tmp = tmp->next;
				}
				last = tmp;
				tmp->next = nullptr;
			}
			else
			{
				first = nullptr;
				last = nullptr;
			}
		}
		else
		{
			cout << "Stack is empty\n";
		}
	}

	void peek()
	{
		if (first != nullptr)
		{
			last->data.print();
		}
		else
		{
			cout << "Stack is empty!\n";
		}
	}

	bool is_empty()
	{
		if (first == nullptr)
		{
			return true;
		}
		else
		{
			return false;
		}
	}

};

void test(bool num)
{
	int r = 0;
	while (true)
	{
		if (num)
		{
			cout << "\tстек на основі\n";
			cout << "\t\t1. масиву\n";
			cout << "\t\t2. вектору\n";
			cout << "\t\t3. лінійного списку\n";
			StackArray a;
			StackVector b;
			List c;
			r = _getch() - 48;
			while (true)
			{
				if (r == 1)
				{
					cout << "\t\t\t1. додати елемент\n";
					cout << "\t\t\t2. показати верхній елемент\n";
					cout << "\t\t\t3. видалити елемент\n";
					cout << "\t\t\t4. перевірити чи стек пустий\n";
					r = _getch() - 48;
					if (r == 1)
					{
						cout << "\t\t\t\tвведіть координати";
						double x, y, z;
						cin >> x >> y >> z;
						a.push(Point(x, y, z));
					}
					else if (r == 2)
					{
						a.peek();
					}
					else if (r == 3)
					{
						a.pop();
					}
					else if (r == 4)
					{
						if (a.is_empty())
						{
							cout << "\t\t\t\tстек пустий\n";
						}
						else
						{
							cout << "\t\t\t\tстек не пустий\n";
						}
					}
					else
					{
						continue;
					}
				}
				else if (r == 2)
				{
					cout << "\t\t\t1. додати елемент\n";
					cout << "\t\t\t2. показати верхній елемент\n";
					cout << "\t\t\t3. видалити елемент\n";
					cout << "\t\t\t4. перевірити чи стек пустий\n";
					r = _getch() - 48;
					if (r == 1)
					{
						cout << "\t\t\t\tвведіть координати";
						double x, y, z;
						cin >> x >> y >> z;
						b.push(Point(x, y, z));
					}
					else if (r == 2)
					{
						b.peek();
					}
					else if (r == 3)
					{
						b.pop();
					}
					else if (r == 4)
					{
						if (b.is_empty())
						{
							cout << "\t\t\t\tстек пустий\n";
						}
						else
						{
							cout << "\t\t\t\tстек не пустий\n";
						}
					}
					else
					{
						continue;
					}
				}
				else if (r == 3)
				{
					cout << "\t\t\t1. додати елемент\n";
					cout << "\t\t\t2. показати верхній елемент\n";
					cout << "\t\t\t3. видалити елемент\n";
					cout << "\t\t\t4. перевірити чи стек пустий\n";
					r = _getch() - 48;
					if (r == 1)
					{
						cout << "\t\t\t\tвведіть координати";
						double x, y, z;
						cin >> x >> y >> z;
						c.push(Point(x, y, z));
					}
					else if (r == 2)
					{
						c.peek();
					}
					else if (r == 3)
					{
						c.pop();
					}
					else if (r == 4)
					{
						if (c.is_empty())
						{
							cout << "\t\t\t\tстек пустий\n";
						}
						else
						{
							cout << "\t\t\t\tстек не пустий\n";
						}
					}
					else
					{
						continue;
					}
				}
				else
				{
					continue;
				}
			}
		}
		else
		{
			break;
		}
	}

}



int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	int r = 0;

	while (1)
	{
		std::cout << "Режими роботи:\n";
		std::cout << "1.	Інтерактивний діалоговий режим\n";
		std::cout << "2.	Демонстраційний режим\n";
		std::cout << "3.	Вихід із программи\n";
		r = _getch() - 48;
		if (r == 1)
		{
			test(true);

		}
		else if (r == 2)
		{
			test(false);
		}
		else if (r == 3)
			break;
		else continue;
	}
}
