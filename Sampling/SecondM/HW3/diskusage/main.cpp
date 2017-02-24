/////////////////////////////////////////
// Jacob Melton
// 905698368
// jmelton1@vt.edu
// ECE3574
// Homework 3
/////////////////////////////////////////
#include <QCoreApplication>
#include <QFileInfo>
#include <qmath.h>
#include <QString>
#include <QDebug>
#include <QDir>

#include <argumentlist.h>

/** @short Prints out the usage message as well as an error message
    describing why the provided options were incorrect.
    @param errorCode an integer value representing the error due to incorrect usage.
    0 - No options or resources given
    1 - No unit parameter
    2 - Multiple unit parameters
    3 - No type parameter or incorrect type
    4 - No depth parameter
    5 - Depth argument was not all or a uint
    6 - No resources given
    7 - One or more resources was invalid */
void usage(int errorCode) {
    switch(errorCode) {
    case 0:
        qDebug() << "No options or resources were given to diskusage. Please follow the usage instructions below." << endl;
        break;
    case 1:
        qDebug() << "No unit parameter was found. Please follow the usage instructions below." << endl;
        break;
    case 2:
        qDebug() << "Multiple unit options were found. Only one is allowed at once. Please follow the usage instructions below." << endl;
        break;
    case 3:
        qDebug() << "No type or an incorrect option for type was found. Please follow the usage instructions below." << endl;
        break;
    case 4:
        qDebug() << "No depth parameter was found. Please follow the usage instructions below." << endl;
        break;
    case 5:
        qDebug() << "The depth argument was not one of the valid options. Please follow the usage instructions below." << endl;
        break;
    case 6:
        qDebug() << "There were no resources provided. Please follow the usage instructions below." << endl;
        break;
    case 7:
        qDebug() << "One or more of the given resources was invalid. Please follow the usage instructions below." << endl;
        break;
    }

    qDebug() << "Usage - diskusage -depth=(all|<uint>) (-b|-k|-m) -<type> resource0 [resource1 [...]]" << endl
             << "- All options are mandatory" << endl
             << "- The b, k and m options are exclusive. Only use one at a time." << endl
             << "- The type field can be any combination of the letters f, s, and d. No repetition of letters is allowed." << endl
             << "- The resources refer to file system items and can be any number of entries. Resources must be valid, if not an error will be thrown." << endl;
    exit(-1);
}

/** @short Populates a QFileInfoList with the elements of the file system
    that are children of the given QDir and recurses when it finds another
    directory below it.
    @param dir - The directory we want to get the children of.
    @param dirTree - The QFileInfoList to populate with the structure
    of the file system. */
void makeDirFileInfo(QDir dir, QList<QFileInfo> &dirTree) {
    // Set up sorting, and filtering
    dir.setSorting(QDir::Name);
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    // Get the QFileInfo's of all the children of this directory.
    QFileInfoList dirContents = dir.entryInfoList();

    // For each entry in the directory we want to add it to our FileInfo list
    foreach (const QFileInfo &entry, dirContents) {
        dirTree.append(entry);
        // If the entry is a directory we want to recursevly call this function
        // but not if its a symlink
        if (entry.isDir() && !entry.isSymLink()) {
            QDir childDir(entry.filePath());
            makeDirFileInfo(childDir, dirTree);
        }
    }
}

/** @short Prints out the size as well as the unit of a file, dir or symlink
    given a QFileInfo of the filesystem entry we wish to print.
    @param entry - The QFileInfo we want to print the size and info of
    @param size - the size of the entry in bytes */
void printSize(QFileInfo entry, QList<bool> filters, qint64 size) {
    if(filters[3])
        qDebug("%-4lld B\t%s", size, qPrintable(entry.filePath()));
    else if(filters[4])
        qDebug("%-d kB\t%s", qCeil(size/1024.0), qPrintable(entry.filePath()));
    else if(filters[5])
        qDebug("%-d MB\t%s", qCeil(size/1048576.0), qPrintable(entry.filePath()));
}

/** @short Finds the total size of all the contents of a directory in bytes
    @param dir - the directory you want the total size of the contents */
qint64 getChildSize(QDir dir) {
    qint64 retSize = 0;
    dir.setSorting(QDir::Name);
    dir.setFilter(QDir::Dirs | QDir::Files | QDir::NoDotAndDotDot);
    QFileInfoList dirContents = dir.entryInfoList();

    foreach (const QFileInfo &entry, dirContents) {
        retSize += entry.size();
        if (entry.isDir() && !entry.isSymLink()) {
            QDir childDir(entry.filePath());
            retSize += getChildSize(childDir);
        }
    }
    return retSize;
}

/** @short Print out the QFileInfo with all pertinent information
    @param entry - the entry we want to print
    @param filters - a list of booleans corresponding to
    various filter options */
void printDirTree(QFileInfo entry, QList<bool> filters) {
    qint64 size = 0;

    // Are we printing files?
    if (filters[0]) {
        if(entry.isFile() && !entry.isSymLink()) {
            size = entry.size();
            printSize(entry, filters, size);
        }
    }
    // Are we printing symlinks?
    if (filters[1]) {
        if(entry.isSymLink()) {
            size = entry.size();
            printSize(entry, filters, size);
        }
    }
    // Are we printing directories?
    if (filters[2]) {
        if(entry.isDir() && !entry.isSymLink()) {
            size = getChildSize(QDir(entry.absoluteFilePath())) + entry.size();
            printSize(entry, filters, size);
        }
    }
}

int main(int argc, char * argv[]) {
    QCoreApplication myApp(argc, argv);
    ArgumentList argList(argc, argv);
    QList<QFileInfo> dirTree;
    QList<bool> filters;
    QString appname = argList.takeFirst();
    QString depth, path;
    bool bytes = false, kilobytes = false, megabytes = false;
    bool file = false, dir = false, sym = false;
    bool ok;
    int parentDepth = 0;
    uint thisDepth = 0;

    // ** Option parsing logic STARTS **
    // Do we even have enough arguments?
    if (argc < 2)
        usage(0);

    // Get the depth value and check if its empty, not a valid UInt or not all.
    depth = argList.getSwitchEqualsArg("-depth");
    depth.toUInt(&ok);
    if (depth.isEmpty())
        usage(4);
    else if (!ok && depth != "all")
        usage(5);

    // Determine the unit argument
    bytes = argList.getSwitch("-b");
    kilobytes = argList.getSwitch("-k");
    megabytes = argList.getSwitch("-m");

    // Check if we got a unit argument
    if (!(bytes || kilobytes || megabytes))
        usage(1);

    // Check to see if multiple unit parameters were set
    if (!((bytes ^ kilobytes ^ megabytes) && !(bytes && kilobytes && megabytes)))
        usage(2);

    // Determine the type arguments
    if (argList.getSwitch("-f"))
        file = true;
    else if (argList.getSwitch("-d"))
        dir = true;
    else if (argList.getSwitch("-s"))
        sym = true;
    else if (argList.getSwitch("-fd") || argList.getSwitch("-df")) {
        file = true;
        dir = true;
    }
    else if (argList.getSwitch("-fs") || argList.getSwitch("-sf")) {
        file = true;
        sym = true;
    }
    else if (argList.getSwitch("-ds") || argList.getSwitch("-sd")) {
        dir = true;
        sym = true;
    }
    else if (argList.getSwitch("-fds") || argList.getSwitch("-fsd") ||
             argList.getSwitch("-dfs") || argList.getSwitch("-dsf") ||
             argList.getSwitch("-sdf") || argList.getSwitch("-sfd")) {
        file = true;
        dir = true;
        sym = true;
    }
    else
        usage(3);

    // Check if there are any resources after we have removed all the options
    if (argList.size() < 1)
        usage(6);

    // Check if our resources are valid directories
    for(int i = 0; i < argList.size(); i++) {
        QDir tmpDir(argList[i]);
        QFile tmpFile(argList[i]);
        if(!tmpDir.exists() && !tmpFile.exists())
            usage(7);
    }
    // ** Option parsing logic STOPS **

    // Sort our argList since it now contains the resources we need to traverse.
    // And create a list of our boolean flags for later now that all options have been parsed
    argList.sort();
    filters << file << sym << dir << bytes << kilobytes << megabytes;

    // Loop through the ordered argList and create a resouce visitor when we get to each one
    // Utilize the recursive processResouce function to enumerate and fill the object with
    // the correct size info.
    while (!argList.isEmpty()) {
        path = argList.takeFirst();
        QFileInfo info(path);
        // Append the file info to our dirTree
        dirTree.append(info);
        // If we have a directory we need to build out its children so we want
        // to execute our recusive function on it.
        if (info.isDir() && !info.isSymLink())
            makeDirFileInfo(QDir(info.filePath()), dirTree);
        // Find the highest directory depth
        if (parentDepth > info.canonicalPath().split("/").size() || parentDepth == 0) {
            if (info.isSymLink())
                parentDepth = info.absolutePath().split("/").size();
            else
                parentDepth = info.canonicalPath().split("/").size();
        }
    }

    // Now loop through our list of QFileInfo objects and print them out
    foreach (const QFileInfo &entry, dirTree) {
        // Find out the depth of this entry
        if (entry.isSymLink())
            thisDepth = entry.absolutePath().split("/").size();
        else
            thisDepth = entry.canonicalPath().split("/").size();

        // Do printing of all or some depending on depth option
        if (depth == "all") {
            printDirTree(entry, filters);
        }
        else {
            if((thisDepth - parentDepth) <= depth.toUInt())
                printDirTree(entry, filters);
        }
    }

    exit(0);
}
