// CMP2090M Assesment Item 1


#pragma once

#ifndef REF_IMAGECLASS_FILE
#define REF_IMAGECLASS_FILE

#include "BaseImage.h"


class RefImage : public BaseImage
{

	private:

	public:

    // constructors and destructors
	RefImage();
	RefImage(const std::string& fileName, int sizeR, int sizeC);
	~RefImage();
};

#endif
