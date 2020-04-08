# amt-vlc
Module for the VLC media player leveraging AMT functionality

This is the repository used to develop an AMT access module for VLC.  This module has been merged 
into the mainline branch of VLC 4.0.0 and can be used by downloading any 4.0.0 nightly build of 
VLC after Nov 11, 2019 from https://nightlies.videolan.org/

The precompiled binaries in this repository are posted for historical purposes.  It is recommended to use mainline VLC code.

To use:
- Open VLC
- File->Open Network or Control-N
- In URL, type out the stream you want with the following format: 'amt://[source_addr]@[group_addr]'
  * The source_addr parameter is optional and only used for SSM.
  * The group_addr is always required.
  * source_addr, group_addr or the AMT relay can use a FQDN defined in DNS

Some known working streams to try out include:
- amt://129.174.131.51@233.44.15.9
- amt://198.116.200.36@233.1.14.13
- amt://162.250.138.201@232.162.250.138
- amt://162.250.138.201@232.162.250.139
- amt://162.250.138.201@232.162.250.140

If you need to change/input the relay address, go to VLC->Preferences->Show all->Input/Codecs->Access Modules->AMT and change the address. The default relay is amt-relay.m2icast.net, which currently maps to three DNS A records (162.250.137.254, 162.250.136.101 and 198.38.23.145).  The first AMT relay to return a packet is selected as the relay.
