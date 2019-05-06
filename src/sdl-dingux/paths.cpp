
// Paths module
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <errno.h>
#include "burner.h"

char szAppHomePath[MAX_PATH] = "./.fba-a320";			// ~/.fba-a320
char szAppSavePath[MAX_PATH] = "./.fba-a320/saves";		// ~/.fba-a320/saves
char szAppConfigPath[MAX_PATH] = "./.fba-a320/configs";	// ~/.fba-a320/configs
char szAppHiscorePath[MAX_PATH] = "./.fba-a320/hiscore";	// ~/.fba-a320/highscore // for burn/hiscore.cpp
char szAppSamplesPath[MAX_PATH] = "./.fba-a320/samples";	// ~/.fba-a320/samples // for burn/snd/samples.cpp
char szAppPreviewPath[MAX_PATH] = "./.fba-a320/previews";	// ~/.fba-a320/previews
char szAppRomPaths[DIRS_MAX][MAX_PATH] = {{"./"}, {"/usr/local/share/roms/"}, {"roms/"}, {"roms/fba/"}, };

void BurnPathsInit()
{
#ifndef WIN32
	char *home = getenv("HOME");
	printf("HOME: '%s' \n", home);
	if (home) sprintf(szAppHomePath, "%s/.fba-a320", home);
	mkdir(szAppHomePath, 0777);
	if (!errno) {
		getcwd(szAppHomePath, MAX_PATH);
		strcat(szAppHomePath, "/.fba-a320");
		mkdir(szAppHomePath, 0777);
	}

	sprintf(szAppSavePath, "%s/saves", szAppHomePath);
	mkdir(szAppSavePath, 0777);

	sprintf(szAppConfigPath, "%s/configs", szAppHomePath);
	mkdir(szAppConfigPath, 0777);

	sprintf(szAppPreviewPath, "%s/previews", szAppHomePath);
	mkdir(szAppPreviewPath, 0777);

	sprintf(szAppSamplesPath, "%s/samples", szAppHomePath);
	mkdir(szAppSamplesPath, 0777);
#else
	getcwd(szAppHomePath, MAX_PATH);
	strcat(szAppHomePath, "/.fba-a320");
	mkdir(szAppHomePath);

	sprintf(szAppSavePath, "%s/saves", szAppHomePath);
	mkdir(szAppSavePath);

	sprintf(szAppConfigPath, "%s/configs", szAppHomePath);
	mkdir(szAppConfigPath);

	sprintf(szAppPreviewPath, "%s/previews", szAppHomePath);
	mkdir(szAppPreviewPath);

	sprintf(szAppSamplesPath, "%s/samples", szAppHomePath);
	mkdir(szAppSamplesPath);
#endif
}
