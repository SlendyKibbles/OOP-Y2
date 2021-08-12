// CMP2090M Assesment Item 1


#pragma once
#include <vector>

#ifndef LARGE_IMAGECLASS_FILE
#define LARGE_IMAGECLASS_FILE

#include "BaseImage.h"
#include "RefImage.h"



class LargeImage : public BaseImage
{

	private:
	std::vector<MatchStruct> bestMatches;

	public:

	// constructors and destructors
	LargeImage();
	LargeImage(std::string fileName, int sizeR, int sizeC);
	~LargeImage();

	void TemplateMatch(RefImage& refImage);
	void WriteBestMatchesToPGM(int h, int w);
	int CheckCentrePoint(int x, int y, RefImage& refImage);
};

#endif