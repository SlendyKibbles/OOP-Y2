// CMP2090M Assesment Item 1


#include "LargeImage.h"


// checks the centre pixel and a surrounding padding 
// returns similarity in percentage
// 0 intended correct 'is'
int LargeImage::CheckCentrePoint(int x, int y, RefImage& refImage)
{
	int indexX = refImage.GetWidth() / 2;
	int indexY = refImage.GetHeight() / 2;
	int totalSimilarity = 0;

	for (int i = -4; i < 6; i++)
	{
		double pixVal1 = GetValueAt(x + indexX + i, y + indexY);
		double pixVal2 = refImage.GetValueAt(indexX + i, indexY);
		totalSimilarity += abs(pixVal1 - pixVal2);

		pixVal1 = GetValueAt(x + indexX, y + indexY + i);
		pixVal2 = refImage.GetValueAt(indexX, indexY + i);
		totalSimilarity += abs(pixVal1 - pixVal2);
	}
	return totalSimilarity;
}

void LargeImage::TemplateMatch(RefImage& refImage)
{
	this->bestMatches = std::vector<MatchStruct>();
	bestMatches.push_back(MatchStruct{ 0, 0, 2147483647 });

	for (int x = 0; x <= GetWidth() - refImage.GetWidth(); x++)
	{
		for (int y = 0; y <= GetHeight() - refImage.GetHeight(); y++)
		{
			int sim = CheckCentrePoint(x, y, refImage);
			int at = 0;
			for (auto itr = bestMatches.rbegin(); itr != bestMatches.rend();)
			{
				MatchStruct match = *itr;
				if (match.similarity > sim)
				{
					itr++;
				}
				else
				{
					at = itr - bestMatches.rbegin();
					break;
				}

				at = itr - bestMatches.rbegin();
			}

			if (at > 0 && at < 6)
			{
				bestMatches.insert(bestMatches.end() - at, MatchStruct{ x, y, sim });
				printf("Sorting and finding the next best match\n");
				printf("Best match X: %i Y: %i is: %i\n \n", x, y, sim);
			}

			if (bestMatches.size() > 5)
				bestMatches.erase(bestMatches.begin() + 5, bestMatches.end());
		}
	}
}

void LargeImage::WriteBestMatchesToPGM(int h, int w)
{
	for (MatchStruct match : bestMatches)
	{
		for (int x = 0; x <= w; x++)
			SetValueAt(match.col + x, match.row, 0);

		for (int y = 0; y <= h; y++)
			SetValueAt(match.col, match.row + y, 0);

		for (int x = 0; x <= w; x++)
			SetValueAt(match.col + x, match.row + h, 0);

		for (int y = 0; y <= h; y++)
			SetValueAt(match.col + w, match.row + y, 0);
	}
	write_pgm("WallyMatches.pgm", this->data, this->height, this->width, 255);
}

LargeImage::LargeImage()
{
}

LargeImage::LargeImage(std::string fileName, int sizeR, int sizeC)
{
	ReadData(fileName, sizeR, sizeC);
}

LargeImage::~LargeImage()
{
}