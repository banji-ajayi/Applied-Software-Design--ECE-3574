#include "libraryui.h"
#include "library.h"

bool saved(false);
QTextStream cout(stdout);
QTextStream cin(stdin);


int main() {

   Library lib;
   LibraryUI libui(&lib);
   while(1) {
      switch(libui.nextTask()) {
      case LibraryUI::Read: libui.read();
         saved = false;
         break;
      case LibraryUI::Add: libui.enterData();
         saved = false;
         break;
      case LibraryUI::Find: libui.find();
         break;
      case LibraryUI::Remove: libui.remove();
         saved = false;
         break;
      case LibraryUI::Save: libui.save();
         saved = true;
         break;
      case LibraryUI::List: libui.list();
         break;
      case LibraryUI::Quit: libui.prepareToQuit(saved);
         break;
      default:
         break;
      }
   }
}

