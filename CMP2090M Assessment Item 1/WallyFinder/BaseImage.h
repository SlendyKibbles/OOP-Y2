// CMP2090M Assesment Item 1


#pragma once

#ifndef BASE_IMAGE_FILE
#define BASE_IMAGE_FILE

#include <string>

#include "ReadWriteFunctions.h"


struct MatchStruct
{
	int col;
	int row;
	int similarity;
};

class BaseImage 
{

	protected:
	
	int width, height, length;

	// greyscale data of image
	double* data;

	public:

	// constructors and destructors
	BaseImage();
	BaseImage(int sizeR, int sizeC);
	BaseImage(const std::string& fileName, int sizeR, int sizeC);
	~BaseImage();

	// functions
	void ReadData(const std::string& fileName, int sizeR, int sizeC);
	virtual void WritePGM(const std::string& fileName, double* data, int h, int w);
	double GetValueAt(int x, int y) const;
	void SetValueAt(int x, int y, double value);

	int GetWidth() const;
	int GetLength() const;
	int GetHeight() const;
};
#endif