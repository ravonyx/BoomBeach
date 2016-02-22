#include "Field.h"

Field::Field()
{
	data = new int[20 * 20];
	for (int i = 0; i < 20 * 20; i++)
	{
		data[i] = -1;
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

	bool widthOK = false;
	bool heightOK = false;
	int x = 0;
	int y = 0;
	for (int i = 0; i < width*height; i++)
	{
		for (int j = 0; j < height; j++)
		{
			if (data[i] == -1)
			{
				for (int i = 0; i < width; i++)
				{
					if (data[i + j * width] == -1)
						continue;
					else if (data[i + j * width] == -1 && i == 0)
						x = i + j * width;
					else if (data[i + j * width] == -1 && i == width - 1)
						widthOK = true;
					else
						break;
				}

				if (widthOK == true)
				{
					for (int j = 0; i < height; j++)
					{
						if (data[i + j * width] == -1)
							continue;
						else if (data[i + j * width] == -1 && j == 0)
							y = i + j * width;
						else if (data[i + j * width] == -1 && j == height - 1)
							heightOK = true;
						else
							break;
					}
				}
				if (widthOK == true && heightOK == true)
					break;
				
			}
		}
	
	}

	if (widthOK == true && heightOK == true)
	{
		return Zone(width, height, x, y);
	}
	else
		return Zone();
}

bool Field::Build(Zone z)
{
	if (z.getId() == 0)
	{
		for (int i = z.getX(); i < z.getWidth(); i++)
		{
			for (int j = z.getY(); i < z.getHeight(); j++)
			{
				data[i + j * z.getWidth()] = z.getId();
			}
		}
	}
	//zone non vide
	else
		return false;
}

void Field::Erase(Zone z)
{
	for (int i = z.getX(); i < z.getWidth(); i++)
	{
		for (int j = z.getY(); i < z.getHeight(); j++)
			data[i + j * z.getWidth()] = -1;
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