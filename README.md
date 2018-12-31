# amt-vlc
Module for the VLC media player leveraging AMT functionality

Added AMT access module to VLC. To use:  
-Open VLC  
-File->Open Network (or alternatively <Control-N>)
-In URL, type out the stream you want with the following format: 'amt://[source_addr]@[group_addr]'  
* The source_addr parameter is optional and only used for SSM.  
* The group_addr is always required.  
* source_addr, group_addr or the AMT relay can be FQDN defined in DNS
  
Some known working streams to try out include:  
amt://129.174.131.51@233.44.15.9  

If you need to change/input the relay address, go to VLC->Preferences->Show all->Input/Codecs->Access Modules->AMT and change the address. This defaults to the TJ relay amt-relay.m2icast.net since that was the first one on the MBone.  This relay trutns two IP's namely 162.250.137.254 and 198.38.23.145.  The first AMT relay to return a packet is selected.
