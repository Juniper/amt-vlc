# amt-vlc
Module for the VLC media player leveraging AMT functionality

Added AMT access module to VLC. To use:
-Open VLC
-File->Open Network
-In URL, type out the stream you want with the following format: 'amt://[source_addr]@[group_addr]'
  -The source_addr parameter is optional and only used for SSM.
  -The group_addr is always required.
  
If you need to change/input the relay address, go to VLC->Preferences->Show all->Input/Codecs->Access Modules->AMT and change the address. In theory this would be a relay anycast address, but with there only existing one you have to use the Juniper one.
