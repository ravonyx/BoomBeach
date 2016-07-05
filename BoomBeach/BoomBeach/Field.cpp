#include "Field.h"
#include <cstdlib>
#include <ctime>

Field::Field()
{
	_width = 20;
	_height = 20;
	_data = new int[_width * _height];

	int x, y;
	int offset;
	srand(std::time(0));
	int rand = std::rand() % 4;
	if (rand == 0)
	{
		x = 0;
		y = 0;
		offset = 1;
	}
	else if (rand == 1)
	{
		x = 0;
		y = 0;
		offset = _width;
	}
	else if (rand == 2)
	{
		x = 0;
		y = _height - 1;
		offset = 1;
	}
	else if (rand == 3)
	{
		x = _width - 1;
		y = 0;
		offset = _width;
	}
	int randUnreach;

	for (int i = 0; i < _width * _height; i++)
	{
		randUnreach = std::rand() % _width /2 - _width /4;
		if (randUnreach == 0)
			_data[i] = -3;
		else
			_data[i] = -1;
	}

	for (int i = 0; i < 12; i++)
	{
		_data[x + y * _width] = -2;
		x += offset;
	}
}

Field::Field(const Field &field)
{
	_height = field._height;
	_width = field._width;
	_data = field._data;
}

Field& Field::operator=(const Field& field)
{
	_height = field._height;
	_width = field._width;
	_data = field._data;
	return *this;
}


Field::~Field()
{
	delete _data;
}

Field::Field(int w, int h)
{
	_width = w;
	_height = h;
	_data = new int[w * h];

	int x, y;
	int offset;
	srand(std::time(0));
	int rand = std::rand() % 4;
	if (rand == 0)
	{
		x = 0;
		y = 0;
		offset = 1;
	}
	else if (rand == 1)
	{
		x = 0;
		y = 0;
		offset = _width;
	}
	else if (rand == 2)
	{
		x = 0;
		y = _height - 1;
		offset = 1;
	}
	else if (rand == 3)
	{
		x = _width - 1;
		y = 0;
		offset = _width;
	}

	int randUnreach;
	for (int i = 0; i < w * h; i++)
	{
		randUnreach = std::rand() % _width / 2 - _width / 4;
		if (randUnreach == 0)
			_data[i] = -3;
		else
			_data[i] = -1;
	}

	for (int i = 0; i < 12; i++)
	{
		_data[x + y * _width] = -2;
		x += offset;
	}
}

bool Field::IsEmpty(Zone z)
{
	if (z.isEmpty())
		return true;
	else
		return false;
}

Zone Field::FindEmptyZone(int w, int h)
{
	int lineNb = 0;
	for (int i = 0; i < _width * _height; ++i)
	{
		int x = 0;
		int y = 0;
		if (i % _width == 0)
			lineNb++;

		for (; x < w; x++)
		{
			for (y = 0; y < h; y++)
			{
				if (_data[i + x + y * _width] != -1)
					break;
			}
			if (y < h)
				break;
		}
		if (x == w && y == h && i + w < _width * lineNb)
			return Zone(w, h, i % _width, i / _width);
	}
	return Zone();
}

bool Field::Build(Zone &z)
{
	if (z.getId() != -1)
	{
		for (int i = z.getX(); i < z.getX() + z.getWidth(); i++)
		{
			for (int j = z.getY(); j <  z.getY() + z.getHeight(); j++)
			{
				_data[i + j * _width] = z.getId();
			}
		}
	}
	else
		return false;
}

void Field::Erase(Zone z)
{
	for (int i = z.getX(); i < z.getX() + z.getWidth(); i++)
	{
		for (int j = z.getY(); j < z.getY() + z.getHeight(); j++)
		{
			_data[i + j * _width] = -1;
		}
	}
}

std::ofstream& operator << (std::ofstream& os, const Field& f)
{
	os << f._width << std::endl;
	os << f._height << std::endl;

	for (int j = 0; j < f._height; j++)
	{
		for (int i = 0; i < f._width; i++)
		{
			os << std::setw(2) << f._data[i + j * f._width];
		}
		os << std::endl;
	}

	os << std::endl;
	return os;
}
std::ostream& operator << (std::ostream& os, const Field& f)
{
	os << "Width: " << f._width;
	os << " Height: " << f._height << std::endl;
	os << std::endl;
	for (int j = 0; j < f._height; j++)
	{
		os << std::setw(4) << "Ligne " << j;
		if (j < 10)
			os << " ";
		for (int i = 0; i < f._width; i++)
		{
			os << std::setw(4) << f._data[i + j * f._width];
		}
		os << std::endl << std::endl;
	}

	os << std::endl;
	return os;
}
std::istream& operator >> (std::istream& is, Field& f)
{
	is >> f._width;
	is >> f._height;

	const int size = f._width * f._height;
	int data;
	int index = 0;
	while (is.good())
	{
		is >> data;
		if (index < size)
		{
			f._data[index] = data;
			index++;
		}
	}
	return is;
}

int Field::GetNearestBuilding(int x, int y)
{
	return 0;
}

int Field::getWidth() const
{
	return _width;
}

int Field::getHeight() const
{
	return _height;
}

int* Field::getData()
{
	return _data;
}