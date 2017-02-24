#ifndef ARGUMENTLIST_H
#define ARGUMENTLIST_H

#include <QStringList>


/** @short A simple interface for processing command line arguments
    An object which provides a simple interface to the command
    line arguments of a program. The methods @ref getSwitch(QString)
    and @ref getSwitchArg(QString) allow you to process and remove
    the switches and switched arguments in the command line, so
    that the remaining entries in the stringlist can be processed
    as a uniform list.

    @author ezust
    @since qt 3.2.1 */
class ArgumentList : public QStringList {
  public:
    /** @short Retrieve arguments from the qApp->arguments()
        Only works if a @ref QCoreApplication(argc, argv)
        was already created.
    */
    ArgumentList();
    /** @param argc number of arguments
        @param argv an array of command line arguments, as supplied to main().
        @see argsToStringList()
    */
    ArgumentList(int argc, char* argv[]);
    /** @short Function to allow conversion of QStringList to argument list
        @param argumentList the QStringList to be used to construct the new
        ArgumentList
    */
    ArgumentList(const QStringList& argumentList):
           QStringList(argumentList) {}

    /** @short Finds and removes a switch from the string list, if it exists.
        @param option the switch to search for
        @return true if the switch was found
    */
    bool getSwitch(QString option);
    /** @short finds/removes a switch and its accompanying argument
        from the string list, if the switch is found. Does nothing if
        the switch is not found.
        @param option the switch to search for
        @param defaultReturnValue the return value if option is not found in the stringlist
        @return the argument following option, or defaultValue if the
        option is not found.
    */
    QString getSwitchArg(QString option, QString defaultRetVal=QString());
    /** @short finds and removes a switch and its argument when
        the argument follows an equals sign.
        @param option The switch you want before the equals
        @return the argument after the equals sign.
    */
    QString getSwitchEqualsArg(QString option);

  private:
    /** @short (Re)loads argument lists into this object. This function
        is private because it is part of the implementation of the
        class and not intended to be used by client code.
    */
    void argsToStringlist(int argc,  char* argv[]);
};
#endif
