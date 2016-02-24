#pragma once
class Zone
{
	private:
		int id;

		int width;
		int height;

		int x;
		int y;

	public:
		Zone();
		Zone(int pwidth, int pheight, int px, int py);
		bool isEmpty();

		void setWidth(int width);
		void setHeight(int height);
		void setId(int pid);

		int getWidth() const;
		int getHeight() const;
		int getX() const;
		int getY() const;
		int getId() const;
};