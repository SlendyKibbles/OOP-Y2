// CMP2090M Assesment Item 1


#include "RefImage.h"


RefImage::RefImage() = default;

RefImage::RefImage(const std::string & fileName, int sizeR, int sizeC)
{
	printf("Starting the search for Wally. Reading the %s file\n", fileName.c_str());
	ReadData(fileName, sizeR, sizeC);
}

RefImage::~RefImage() = default;