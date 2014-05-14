#ifndef __SCRAPER2VDR_H
#define __SCRAPER2VDR_H

#include <getopt.h>
#include <vdr/plugin.h>
#include "lib/common.h"
#include "config.h"
#include "setup.h"
#include "scrapmanager.h"
#include "update.h"
#include "services.h"

//***************************************************************************
// Constants
//***************************************************************************
static const char *VERSION        = "0.1.3";
static const char *VERSION_DATE   = "14.05.2014";
#define DB_API  4
static const char *DESCRIPTION    = "'scraper2vdr' plugin";
static const char *MAINMENUENTRY  = "Scraper2Vdr";

//***************************************************************************
// Globals
//***************************************************************************
cScraper2VdrConfig config;

//***************************************************************************
// cPluginScraper2vdr
//***************************************************************************

class cPluginScraper2vdr : public cPlugin {
private:
    cScrapManager *scrapManager;
    cUpdate *update;
public:
    cPluginScraper2vdr(void);
    virtual ~cPluginScraper2vdr();
    virtual const char *Version(void) { return VERSION; }
    virtual const char *VersionDate(void) { return VERSION_DATE; }
    virtual const char *Description(void) { return DESCRIPTION; }
    virtual const char *CommandLineHelp(void);
    virtual bool ProcessArgs(int argc, char *argv[]);
    virtual bool Initialize(void);
    virtual bool Start(void);
    virtual void Stop(void);
    virtual void Housekeeping(void);
    virtual void MainThreadHook(void);
    virtual cString Active(void);
    virtual time_t WakeupTime(void);
    virtual const char *MainMenuEntry(void) { return (config.mainMenuEntry)?MAINMENUENTRY:NULL; }
    virtual cOsdObject *MainMenuAction(void);
    virtual cMenuSetupPage *SetupMenu(void);
    virtual bool SetupParse(const char *Name, const char *Value);
    virtual bool Service(const char *Id, void *Data = NULL);
    virtual const char **SVDRPHelpPages(void);
    virtual cString SVDRPCommand(const char *Command, const char *Option, int &ReplyCode);
};

//***************************************************************************
#endif // __SCRAPER2VDR_H
