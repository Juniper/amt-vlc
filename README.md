# amt-vlc
Module for the VLC media player leveraging AMT functionality

Added AMT access module to VLC. To use:  
-Open VLC  
-File->Open Network  
-In URL, type out the stream you want with the following format: 'amt://[source_addr]@[group_addr]'  
* The source_addr parameter is optional and only used for SSM.  
* The group_addr is always required.  
  
Some known working streams to try out include:
amt://129.174.131.51@233.44.15.9
amt://131.128.93.40@233.56.12.1
amt://131.128.93.40@233.56.12.2
amt://131.128.93.40@233.56.12.3

If you need to change/input the relay address, go to VLC->Preferences->Show all->Input/Codecs->Access Modules->AMT and change the address. In theory this could be the IANA-defined relay anycast address, but since 198.38.23.145 is the only known relay on the MBONE at the moment, this is the default.
