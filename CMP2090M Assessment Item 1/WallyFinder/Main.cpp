// CMP2090M Assesment Item 1


#include <stdio.h>

#include "LargeImage.h"

using namespace std;


int main()
{
	RefImage wallyImage = RefImage("Wally_grey.txt", 49, 36);
	LargeImage sceneImage = LargeImage("Cluttered_scene.txt", 768, 1024);

	sceneImage.TemplateMatch(wallyImage);

	printf("Succesfully found Wally and listed all the best matches.\n\n");
	printf("To view Wally's location on the .pgm navigate to the project files folder: WallyFinder/WallyFinder.\n");
	sceneImage.WriteBestMatchesToPGM(wallyImage.GetHeight(), wallyImage.GetWidth());

	return 0;
}