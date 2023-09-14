/**
 * @brief main.cpp: A file of the StormText project.
 * @author Bright Software Foundation.
 * @date May 27 2023
 *
 * See the project QMake file for details.
 */


#define BR_STORMTEXT
#define BR_STORMTEXT_1
#define BR_STORMTEXT_1_0_0
#define BR_STORMTEXT_0_7_0_OR_GREATER
#define BR_STORMTEXT_1_0_0_OR_GREATER

#include "BrStormTextApplication.hpp"
#include "BrStormTextMainWindow.hpp"


int main(int argc, char *argv[])
{
    try
    {
        QList<QString> argvFiles = {};

        if (argc >= 2)
        {
            for (int i = 1; i < argc; i++)
            {
                if (QFile(QString(argv[i])).exists()) argvFiles.push_back(QString(argv[i]));
            }
        }

        BrStormTextApplication app(argc, argv);
        BrStormTextMainWindow mw(argvFiles, &app);
        app.setConstructed(true);
        mw.showMaximized();

        return app.exec();
    }

    catch (std::exception &e)
    {
        Q_UNUSED(e)
        return 1;
    }
}

