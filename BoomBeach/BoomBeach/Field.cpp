#include "Field.h"
#include <cstdlib>
#include <ctime>

Field::Field()
{
	width = 20;
	height = 20;
	data = new int[width * height];

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
		offset = width;
	}
	else if (rand == 2)
	{
		x = 0;
		y = height - 1;
		offset = 1;
	}
	else if (rand == 3)
	{
		x = width - 1;
		y = 0;
		offset = width;
	}
	int randUnreach;

	for (int i = 0; i < width * height; i++)
	{
		randUnreach = std::rand() % width/2 - width/4;
		if (randUnreach == 0)
			data[i] = -3;
		else
			data[i] = -1;
	}

	for (int i = 0; i < 12; i++)
	{
		data[x + y * width] = -2;
		x += offset;
	}
}

Field::~Field()
{
	delete &data;
}

Field::Field(int w, int h)
{
	width = w;
	height = h;
	data = new int[w * h];

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
		offset = width;
	}
	else if (rand == 2)
	{
		x = 0;
		y = height - 1;
		offset = 1;
	}
	else if (rand == 3)
	{
		x = width - 1;
		y = 0;
		offset = width;
	}

	int randUnreach;
	for (int i = 0; i < w * h; i++)
	{
		randUnreach = std::rand() % width / 2 - width / 4;
		if (randUnreach == 0)
			data[i] = -3;
		else
			data[i] = -1;
	}

	for (int i = 0; i < 12; i++)
	{
		data[x + y * width] = -2;
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
	Zone z = Zone();

	for (int i = 0; i < width * height; ++i)
	{
		int x = 0;
		int y = 0;
		for (; x < w; x++)
		{
			for (; y < h; y++)
			{
				if (data[i + x + y * width] != -1)
					break;
			}
			if (y < h)
				break;
		}
		if (x == w && y == h)
		{
			return Zone(w, h, i % width, i / width);
		}
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
				data[i + j * width] = z.getId();
			}
		}
	}
	//zone non vide
	else
		return false;
}

void Field::Erase(Zone z)
{
	for (int i = z.getX(); i < z.getX() + z.getWidth(); i++)
	{
		for (int j = z.getY(); j < z.getY() + z.getHeight(); j++)
		{
			data[i + j * width] = -1;
		}
	}
}

int Field::GetNearestBuilding(int x, int y)
{
	return 0;
}



int Field::getWidth() const
{
	return width;
}

int Field::getHeight() const
{
	return height;
}

int* Field::getData()
{
	return data;
}