// CMP2090M Assesment Item 1


#include "BaseImage.h"


// constructor
BaseImage::BaseImage()
{
	this->data = nullptr;
	this->width = 0;
	this->height = 0;
	this->length = 0;
}

BaseImage::BaseImage(int sizeR, int sizeC)
{
	width = sizeC;
	height = sizeR;
	length = sizeC * sizeR;
	data = new double[length];

	for (int x = 0; x < height; x++)
	{
		for (int y = 0; y < width; y++)
			data[x + (width * y)] = 0.0;
	}
}

// constructor to hold file name as well as the width and height
BaseImage::BaseImage(const std::string& fileName, int sizeR, int sizeC)
{
	ReadData(fileName, sizeR, sizeC);
}

// destructor deletes data
BaseImage::~BaseImage()
{
	delete[] data;
}

void BaseImage::ReadData(const std::string& fileName, int sizeR, int sizeC)
{
	data = read_text(fileName, sizeR, sizeC);
	width = sizeC;
	height = sizeR;
	length = sizeC * sizeR;
}

void BaseImage::WritePGM(const std::string& fileName, double* data, int h, int w)
{
	write_pgm(fileName, data, height, width, 255);
}

// takes values from data and if user request out of bounds throw error
double BaseImage::GetValueAt(int x, int y) const
{
	double value = NULL;
	if ((x >= 0) && (x < width))
	{
		if ((y >= 0) && (y < height))
			value = data[x + (width * y)];
	}
	else
	{
		value = -1;
	}

	return value;
}

// set the desired data point and if user request out of bounds throw error
void BaseImage::SetValueAt(int x, int y, double value)
{
	if ((x >= 0) && (x < width))
	{
		if ((y >= 0) && (y < height))
			data[x + (width * y)] = value;
	}
	else
	{
		printf("ERROR: x or y is out of bounds.\n");
	}
}

int BaseImage::GetWidth() const
{
	return this->width;
}

int BaseImage::GetLength() const
{
	return this->length;
}

int BaseImage::GetHeight() const
{
	return this->height;
}