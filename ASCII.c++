#include <iostream>
#include <windows.h>
#include <thread>
#include <chrono>

using namespace std;

void clearScreen() {
    system("cls");
}

const string frame1 = R"(

        .,-%%o,.
      .:i$$$$$$$$b.
    .iIS$$$$$$$$$$$k.
   iISZ$$$$$$$$$$$ZSI.
 .:?SSZ$8$$$$$$$$$$i:
 :-.iiSZ$8Z$$$$$$$$$:i
i:JiI7$$8XSZ$$$$$7.S
:j?oo^"-o?iZ$o"o4L ?
-?         .i$;      'ki
:i.       J7$L      .$:
j$b,_.,d7  ?b-_,,d$7
`$$?i:$7    $?i?Z$$'
 --oo4iJk.:_$Ii"^,
  :   .?Si$$Ii?L   J
  :. :'?I'op:"'   ji
  -i.   "a' ^"    -S:
   :$.i-._u-i,d$?'
     ?IS$Z$Z$$$?
      o?SSZ$Z7'

)";

const string frame2 = R"(
        .,-%%o,.
      .:i$$$$$$$$b.
    .iIS$$$$$$$$$$$k.
   iISZ$$$$$$$$$$$ZSI.
 .:?SSZ$8$$$$$$$$$$i:
 :-.iiSZ$8Z$$$$$$$$$:i
i:JiI7$$8XSZ$$$$$7.S
:j?oo^"-o?iZ$o"o4L ?
-?         .i$;      'ki
:i.       J7$L      .$:
j$b,_.,d7  ?b-_,,d$7
`$$?i:$7    $?i?Z$$'
 --oo4iJk.:_$Ii"^,
  :   .?Si$$Ii?L   J
  :. :'?I'op:"'   ji
  :
  :
  -i.  "a'  ^"    -S:
   :$.i-._u-i,d$?'
     ?IS$Z$Z$$$?
      o?SSZ$Z7'

)";

const string frame3 = R"(
        .,-%%o,.
      .:i$$$$$$$$b.
    .iIS$$$$$$$$$$$k.
   iISZ$$$$$$$$$$$ZSI.
 .:?SSZ$8$$$$$$$$$$i:
 :-.iiSZ$8Z$$$$$$$$$:i
i:JiI7$$8XSZ$$$$$7.S
:j?oo^"-o?iZ$o"o4L ?
-?         .i$;      'ki
:i.       J7$L      .$:
j$b,_.,d7  ?b-_,,d$7
`$$?i:$7    $?i?Z$$'
 --oo4iJk.:_$Ii"^,
  :   .?Si$$Ii?L   J
  :. :'?I'op:"'   ji
  :
  :
  :
  -i.  "a'  ^"    -S:
   :$.i-._u-i,d$?'
     ?IS$Z$Z$$$?
      o?SSZ$Z7'
      `
)";
const string frame4 = R"(
        .,-%%o,.
      .:i$$$$$$$$b.
    .iIS$$$$$$$$$$$k.
   iISZ$$$$$$$$$$$ZSI.
 .:?SSZ$8$$$$$$$$$$i:
 :-.iiSZ$8Z$$$$$$$$$:i
i:JiI7$$8XSZ$$$$$7.S
:j?oo^"-o?iZ$o"o4L ?
-?         .i$;      'ki
:i.       J7$L      .$:
j$b,_.,d7  ?b-_,,d$7
`$$?i:$7    $?i?Z$$'
 --oo4iJk.:_$Ii"^,
  :   .?Si$$Ii?L   J
  :. :'?I'op:"'   ji
  :
  :
  :
  :
  -i.  "a'  ^"    -S:
   :$.i-._u-i,d$?'
     ?IS$Z$Z$$$?
      o?SSZ$Z7'
      `
)";

int main() {
    while (true) {
        clearScreen();
        cout << frame1 << flush;
        this_thread::sleep_for(chrono::milliseconds(300));

        clearScreen();
        cout << frame2 << flush;
        this_thread::sleep_for(chrono::milliseconds(300));

        clearScreen();
        cout << frame3 << flush;
        this_thread::sleep_for(chrono::milliseconds(300));

        clearScreen();
        cout << frame4 << flush;
        this_thread::sleep_for(chrono::milliseconds(300));

        clearScreen();
        cout << frame3 << flush;
        this_thread::sleep_for(chrono::milliseconds(300));

        clearScreen();
        cout << frame2 << flush;
        this_thread::sleep_for(chrono::milliseconds(300));
    }

    return 0;
}