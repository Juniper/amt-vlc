# Makefile for PO directory in any package using GNU gettext.
# Copyright (C) 1995-1997, 2000-2007, 2009-2010 by Ulrich Drepper <drepper@gnu.ai.mit.edu>
#
# Copying and distribution of this file, with or without modification,
# are permitted in any medium without royalty provided the copyright
# notice and this notice are preserved.  This file is offered as-is,
# without any warranty.
#
# Origin: gettext-0.19.8
GETTEXT_MACRO_VERSION = 0.19

PACKAGE = vlc
VERSION = 4.0.0-dev
PACKAGE_BUGREPORT = 

SED = /bin/sed
SHELL = /bin/sh


srcdir = ../../extras/package/win32/../../../po
top_srcdir = ../../extras/package/win32/../../..
VPATH = ../../extras/package/win32/../../../po

prefix = /home/nlandsberg/vlc/win32/_win32
exec_prefix = ${prefix}
datarootdir = ${prefix}/share
datadir = ${datarootdir}
localedir = ${datarootdir}/locale
gettextsrcdir = $(datadir)/gettext/po

INSTALL = /usr/bin/install -c
INSTALL_DATA = ${INSTALL} -m 644

# We use $(mkdir_p).
# In automake <= 1.9.x, $(mkdir_p) is defined either as "mkdir -p --" or as
# "$(mkinstalldirs)" or as "$(install_sh) -d". For these automake versions,
# ${SHELL} /home/nlandsberg/vlc/autotools/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, $(MKDIR_P) is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /home/nlandsberg/vlc/autotools/install-sh -d
install_sh = $(SHELL) ${SHELL} /home/nlandsberg/vlc/autotools/install-sh
MKDIR_P = /bin/mkdir -p
mkdir_p = $(MKDIR_P)

# When building gettext-tools, we prefer to use the built programs
# rather than installed programs.  However, we can't do that when we
# are cross compiling.
CROSS_COMPILING = @CROSS_COMPILING@

GMSGFMT_ = /usr/bin/msgfmt
GMSGFMT_no = /usr/bin/msgfmt
GMSGFMT_yes = /usr/bin/msgfmt
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
MSGFMT_ = /usr/bin/msgfmt
MSGFMT_no = /usr/bin/msgfmt
MSGFMT_yes = /usr/bin/msgfmt
MSGFMT = $(MSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = /usr/bin/xgettext
XGETTEXT_no = /usr/bin/xgettext
XGETTEXT_yes = /usr/bin/xgettext
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = msgmerge
MSGMERGE_UPDATE = /usr/bin/msgmerge --update
MSGINIT = msginit
MSGCONV = msgconv
MSGFILTER = msgfilter

POFILES =  $(srcdir)/ach.po $(srcdir)/af.po $(srcdir)/am.po $(srcdir)/an.po $(srcdir)/ar.po $(srcdir)/as_IN.po $(srcdir)/ast.po $(srcdir)/az.po $(srcdir)/be.po $(srcdir)/bg.po $(srcdir)/bn_IN.po $(srcdir)/bn.po $(srcdir)/br.po $(srcdir)/brx.po $(srcdir)/bs.po $(srcdir)/ca.po $(srcdir)/cgg.po $(srcdir)/ckb.po $(srcdir)/co.po $(srcdir)/cs.po $(srcdir)/cy.po $(srcdir)/da.po $(srcdir)/de.po $(srcdir)/el.po $(srcdir)/en_GB.po $(srcdir)/es.po $(srcdir)/et.po $(srcdir)/eu.po $(srcdir)/fa.po $(srcdir)/ff.po $(srcdir)/fi.po $(srcdir)/fr.po $(srcdir)/fur.po $(srcdir)/fy.po $(srcdir)/ga.po $(srcdir)/gd.po $(srcdir)/gl.po $(srcdir)/gu.po $(srcdir)/he.po $(srcdir)/hi.po $(srcdir)/hr.po $(srcdir)/hu.po $(srcdir)/hy.po $(srcdir)/ia.po $(srcdir)/id.po $(srcdir)/is.po $(srcdir)/it.po $(srcdir)/ja.po $(srcdir)/ka.po $(srcdir)/kk.po $(srcdir)/km.po $(srcdir)/kn.po $(srcdir)/ko.po $(srcdir)/ks_IN.po $(srcdir)/ky.po $(srcdir)/lg.po $(srcdir)/lt.po $(srcdir)/lv.po $(srcdir)/mai.po $(srcdir)/mk.po $(srcdir)/ml.po $(srcdir)/mn.po $(srcdir)/mr.po $(srcdir)/ms.po $(srcdir)/my.po $(srcdir)/nb.po $(srcdir)/ne.po $(srcdir)/nl.po $(srcdir)/nn.po $(srcdir)/oc.po $(srcdir)/or.po $(srcdir)/pa.po $(srcdir)/pl.po $(srcdir)/ps.po $(srcdir)/pt_BR.po $(srcdir)/pt_PT.po $(srcdir)/ro.po $(srcdir)/ru.po $(srcdir)/si.po $(srcdir)/sk.po $(srcdir)/sl.po $(srcdir)/sq.po $(srcdir)/sr.po $(srcdir)/sv.po $(srcdir)/ta.po $(srcdir)/te.po $(srcdir)/tet.po $(srcdir)/th.po $(srcdir)/tl.po $(srcdir)/tr.po $(srcdir)/ug.po $(srcdir)/uk.po $(srcdir)/uz.po $(srcdir)/vi.po $(srcdir)/wa.po $(srcdir)/zh_CN.po $(srcdir)/zh_TW.po $(srcdir)/zu.po
GMOFILES =  $(srcdir)/ach.gmo $(srcdir)/af.gmo $(srcdir)/am.gmo $(srcdir)/an.gmo $(srcdir)/ar.gmo $(srcdir)/as_IN.gmo $(srcdir)/ast.gmo $(srcdir)/az.gmo $(srcdir)/be.gmo $(srcdir)/bg.gmo $(srcdir)/bn_IN.gmo $(srcdir)/bn.gmo $(srcdir)/br.gmo $(srcdir)/brx.gmo $(srcdir)/bs.gmo $(srcdir)/ca.gmo $(srcdir)/cgg.gmo $(srcdir)/ckb.gmo $(srcdir)/co.gmo $(srcdir)/cs.gmo $(srcdir)/cy.gmo $(srcdir)/da.gmo $(srcdir)/de.gmo $(srcdir)/el.gmo $(srcdir)/en_GB.gmo $(srcdir)/es.gmo $(srcdir)/et.gmo $(srcdir)/eu.gmo $(srcdir)/fa.gmo $(srcdir)/ff.gmo $(srcdir)/fi.gmo $(srcdir)/fr.gmo $(srcdir)/fur.gmo $(srcdir)/fy.gmo $(srcdir)/ga.gmo $(srcdir)/gd.gmo $(srcdir)/gl.gmo $(srcdir)/gu.gmo $(srcdir)/he.gmo $(srcdir)/hi.gmo $(srcdir)/hr.gmo $(srcdir)/hu.gmo $(srcdir)/hy.gmo $(srcdir)/ia.gmo $(srcdir)/id.gmo $(srcdir)/is.gmo $(srcdir)/it.gmo $(srcdir)/ja.gmo $(srcdir)/ka.gmo $(srcdir)/kk.gmo $(srcdir)/km.gmo $(srcdir)/kn.gmo $(srcdir)/ko.gmo $(srcdir)/ks_IN.gmo $(srcdir)/ky.gmo $(srcdir)/lg.gmo $(srcdir)/lt.gmo $(srcdir)/lv.gmo $(srcdir)/mai.gmo $(srcdir)/mk.gmo $(srcdir)/ml.gmo $(srcdir)/mn.gmo $(srcdir)/mr.gmo $(srcdir)/ms.gmo $(srcdir)/my.gmo $(srcdir)/nb.gmo $(srcdir)/ne.gmo $(srcdir)/nl.gmo $(srcdir)/nn.gmo $(srcdir)/oc.gmo $(srcdir)/or.gmo $(srcdir)/pa.gmo $(srcdir)/pl.gmo $(srcdir)/ps.gmo $(srcdir)/pt_BR.gmo $(srcdir)/pt_PT.gmo $(srcdir)/ro.gmo $(srcdir)/ru.gmo $(srcdir)/si.gmo $(srcdir)/sk.gmo $(srcdir)/sl.gmo $(srcdir)/sq.gmo $(srcdir)/sr.gmo $(srcdir)/sv.gmo $(srcdir)/ta.gmo $(srcdir)/te.gmo $(srcdir)/tet.gmo $(srcdir)/th.gmo $(srcdir)/tl.gmo $(srcdir)/tr.gmo $(srcdir)/ug.gmo $(srcdir)/uk.gmo $(srcdir)/uz.gmo $(srcdir)/vi.gmo $(srcdir)/wa.gmo $(srcdir)/zh_CN.gmo $(srcdir)/zh_TW.gmo $(srcdir)/zu.gmo
UPDATEPOFILES =  ach.po-update af.po-update am.po-update an.po-update ar.po-update as_IN.po-update ast.po-update az.po-update be.po-update bg.po-update bn_IN.po-update bn.po-update br.po-update brx.po-update bs.po-update ca.po-update cgg.po-update ckb.po-update co.po-update cs.po-update cy.po-update da.po-update de.po-update el.po-update en_GB.po-update es.po-update et.po-update eu.po-update fa.po-update ff.po-update fi.po-update fr.po-update fur.po-update fy.po-update ga.po-update gd.po-update gl.po-update gu.po-update he.po-update hi.po-update hr.po-update hu.po-update hy.po-update ia.po-update id.po-update is.po-update it.po-update ja.po-update ka.po-update kk.po-update km.po-update kn.po-update ko.po-update ks_IN.po-update ky.po-update lg.po-update lt.po-update lv.po-update mai.po-update mk.po-update ml.po-update mn.po-update mr.po-update ms.po-update my.po-update nb.po-update ne.po-update nl.po-update nn.po-update oc.po-update or.po-update pa.po-update pl.po-update ps.po-update pt_BR.po-update pt_PT.po-update ro.po-update ru.po-update si.po-update sk.po-update sl.po-update sq.po-update sr.po-update sv.po-update ta.po-update te.po-update tet.po-update th.po-update tl.po-update tr.po-update ug.po-update uk.po-update uz.po-update vi.po-update wa.po-update zh_CN.po-update zh_TW.po-update zu.po-update
DUMMYPOFILES =  ach.nop af.nop am.nop an.nop ar.nop as_IN.nop ast.nop az.nop be.nop bg.nop bn_IN.nop bn.nop br.nop brx.nop bs.nop ca.nop cgg.nop ckb.nop co.nop cs.nop cy.nop da.nop de.nop el.nop en_GB.nop es.nop et.nop eu.nop fa.nop ff.nop fi.nop fr.nop fur.nop fy.nop ga.nop gd.nop gl.nop gu.nop he.nop hi.nop hr.nop hu.nop hy.nop ia.nop id.nop is.nop it.nop ja.nop ka.nop kk.nop km.nop kn.nop ko.nop ks_IN.nop ky.nop lg.nop lt.nop lv.nop mai.nop mk.nop ml.nop mn.nop mr.nop ms.nop my.nop nb.nop ne.nop nl.nop nn.nop oc.nop or.nop pa.nop pl.nop ps.nop pt_BR.nop pt_PT.nop ro.nop ru.nop si.nop sk.nop sl.nop sq.nop sr.nop sv.nop ta.nop te.nop tet.nop th.nop tl.nop tr.nop ug.nop uk.nop uz.nop vi.nop wa.nop zh_CN.nop zh_TW.nop zu.nop
DISTFILES.common = Makefile.in.in remove-potcdate.sin \
$(DISTFILES.common.extra1) $(DISTFILES.common.extra2) $(DISTFILES.common.extra3)
DISTFILES = $(DISTFILES.common) Makevars POTFILES.in \
$(POFILES) $(GMOFILES) \
$(DISTFILES.extra1) $(DISTFILES.extra2) $(DISTFILES.extra3)

POTFILES = \
     ../../extras/package/win32/../../../include/vlc_access.h \
     ../../extras/package/win32/../../../include/vlc_actions.h \
     ../../extras/package/win32/../../../include/vlc_aout.h \
     ../../extras/package/win32/../../../include/vlc_arrays.h \
     ../../extras/package/win32/../../../include/vlc_bits.h \
     ../../extras/package/win32/../../../include/vlc_block.h \
     ../../extras/package/win32/../../../include/vlc_block_helper.h \
     ../../extras/package/win32/../../../include/vlc_charset.h \
     ../../extras/package/win32/../../../include/vlc_codec.h \
     ../../extras/package/win32/../../../include/vlc_codecs.h \
     ../../extras/package/win32/../../../include/vlc_common.h \
     ../../extras/package/win32/../../../include/vlc_config.h \
     ../../extras/package/win32/../../../include/vlc_config_cat.h \
     ../../extras/package/win32/../../../include/vlc_configuration.h \
     ../../extras/package/win32/../../../include/vlc_demux.h \
     ../../extras/package/win32/../../../include/vlc/deprecated.h \
     ../../extras/package/win32/../../../include/vlc_epg.h \
     ../../extras/package/win32/../../../include/vlc_es.h \
     ../../extras/package/win32/../../../include/vlc_es_out.h \
     ../../extras/package/win32/../../../include/vlc_events.h \
     ../../extras/package/win32/../../../include/vlc_filter.h \
     ../../extras/package/win32/../../../include/vlc_fixups.h \
     ../../extras/package/win32/../../../include/vlc_gcrypt.h \
     ../../extras/package/win32/../../../include/vlc_httpd.h \
     ../../extras/package/win32/../../../include/vlc_image.h \
     ../../extras/package/win32/../../../include/vlc_input.h \
     ../../extras/package/win32/../../../include/vlc_intf_strings.h \
     ../../extras/package/win32/../../../include/vlc_iso_lang.h \
     ../../extras/package/win32/../../../include/vlc_md5.h \
     ../../extras/package/win32/../../../include/vlc_messages.h \
     ../../extras/package/win32/../../../include/vlc_meta.h \
     ../../extras/package/win32/../../../include/vlc_modules.h \
     ../../extras/package/win32/../../../include/vlc_tick.h \
     ../../extras/package/win32/../../../include/vlc_network.h \
     ../../extras/package/win32/../../../include/vlc_objects.h \
     ../../extras/package/win32/../../../include/vlc_pgpkey.h \
     ../../extras/package/win32/../../../include/vlc_playlist.h \
     ../../extras/package/win32/../../../include/vlc_plugin.h \
     ../../extras/package/win32/../../../include/vlc_rand.h \
     ../../extras/package/win32/../../../include/vlc_services_discovery.h \
     ../../extras/package/win32/../../../include/vlc_sout.h \
     ../../extras/package/win32/../../../include/vlc_stream.h \
     ../../extras/package/win32/../../../include/vlc_strings.h \
     ../../extras/package/win32/../../../include/vlc_threads.h \
     ../../extras/package/win32/../../../include/vlc_tls.h \
     ../../extras/package/win32/../../../include/vlc_update.h \
     ../../extras/package/win32/../../../include/vlc_url.h \
     ../../extras/package/win32/../../../include/vlc_variables.h \
     ../../extras/package/win32/../../../include/vlc/vlc.h \
     ../../extras/package/win32/../../../include/vlc_vlm.h \
     ../../extras/package/win32/../../../include/vlc_vod.h \
     ../../extras/package/win32/../../../include/vlc_vout.h \
     ../../extras/package/win32/../../../include/vlc_vout_window.h \
     ../../extras/package/win32/../../../include/vlc_xml.h \
     ../../extras/package/win32/../../../src/audio_output/aout_internal.h \
     ../../extras/package/win32/../../../src/audio_output/common.c \
     ../../extras/package/win32/../../../src/audio_output/dec.c \
     ../../extras/package/win32/../../../src/audio_output/filters.c \
     ../../extras/package/win32/../../../src/audio_output/output.c \
     ../../extras/package/win32/../../../src/config/chain.c \
     ../../extras/package/win32/../../../src/config/cmdline.c \
     ../../extras/package/win32/../../../src/config/configuration.h \
     ../../extras/package/win32/../../../src/config/core.c \
     ../../extras/package/win32/../../../src/config/file.c \
     ../../extras/package/win32/../../../src/config/help.c \
     ../../extras/package/win32/../../../src/config/intf.c \
     ../../extras/package/win32/../../../src/darwin/error.c \
     ../../extras/package/win32/../../../src/extras/libc.c \
     ../../extras/package/win32/../../../src/input/access.c \
     ../../extras/package/win32/../../../src/input/control.c \
     ../../extras/package/win32/../../../src/input/decoder.c \
     ../../extras/package/win32/../../../src/input/decoder.h \
     ../../extras/package/win32/../../../src/input/demux.c \
     ../../extras/package/win32/../../../src/input/demux.h \
     ../../extras/package/win32/../../../src/input/es_out.c \
     ../../extras/package/win32/../../../src/input/es_out.h \
     ../../extras/package/win32/../../../src/input/input.c \
     ../../extras/package/win32/../../../src/input/input_internal.h \
     ../../extras/package/win32/../../../src/input/item.c \
     ../../extras/package/win32/../../../src/input/meta.c \
     ../../extras/package/win32/../../../src/input/stream.c \
     ../../extras/package/win32/../../../src/input/stream.h \
     ../../extras/package/win32/../../../src/input/stream_memory.c \
     ../../extras/package/win32/../../../src/input/subtitles.c \
     ../../extras/package/win32/../../../src/input/var.c \
     ../../extras/package/win32/../../../src/input/vlm.c \
     ../../extras/package/win32/../../../src/input/vlm_internal.h \
     ../../extras/package/win32/../../../src/input/vlmshell.c \
     ../../extras/package/win32/../../../src/interface/interface.c \
     ../../extras/package/win32/../../../src/libvlc.c \
     ../../extras/package/win32/../../../src/libvlc.h \
     ../../extras/package/win32/../../../src/libvlc-module.c \
     ../../extras/package/win32/../../../src/misc/actions.c \
     ../../extras/package/win32/../../../src/misc/block.c \
     ../../extras/package/win32/../../../src/misc/cpu.c \
     ../../extras/package/win32/../../../src/misc/error.c \
     ../../extras/package/win32/../../../src/misc/es_format.c \
     ../../extras/package/win32/../../../src/misc/events.c \
     ../../extras/package/win32/../../../src/misc/filter_chain.c \
     ../../extras/package/win32/../../../src/misc/image.c \
     ../../extras/package/win32/../../../src/misc/md5.c \
     ../../extras/package/win32/../../../src/misc/messages.c \
     ../../extras/package/win32/../../../src/misc/mtime.c \
     ../../extras/package/win32/../../../src/misc/objects.c \
     ../../extras/package/win32/../../../src/misc/rand.c \
     ../../extras/package/win32/../../../src/misc/threads.c \
     ../../extras/package/win32/../../../src/misc/update.c \
     ../../extras/package/win32/../../../src/misc/update.h \
     ../../extras/package/win32/../../../src/misc/variables.c \
     ../../extras/package/win32/../../../src/misc/variables.h \
     ../../extras/package/win32/../../../src/misc/xml.c \
     ../../extras/package/win32/../../../src/missing.c \
     ../../extras/package/win32/../../../src/modules/cache.c \
     ../../extras/package/win32/../../../src/modules/entry.c \
     ../../extras/package/win32/../../../src/modules/modules.c \
     ../../extras/package/win32/../../../src/modules/modules.h \
     ../../extras/package/win32/../../../src/network/getaddrinfo.c \
     ../../extras/package/win32/../../../src/network/httpd.c \
     ../../extras/package/win32/../../../src/network/io.c \
     ../../extras/package/win32/../../../src/network/rootbind.c \
     ../../extras/package/win32/../../../src/network/tcp.c \
     ../../extras/package/win32/../../../src/network/tls.c \
     ../../extras/package/win32/../../../src/network/udp.c \
     ../../extras/package/win32/../../../src/playlist/control.c \
     ../../extras/package/win32/../../../src/playlist/engine.c \
     ../../extras/package/win32/../../../src/playlist/item.c \
     ../../extras/package/win32/../../../src/playlist/loadsave.c \
     ../../extras/package/win32/../../../src/playlist/playlist_internal.h \
     ../../extras/package/win32/../../../src/playlist/search.c \
     ../../extras/package/win32/../../../src/playlist/sort.c \
     ../../extras/package/win32/../../../src/playlist/thread.c \
     ../../extras/package/win32/../../../src/playlist/tree.c \
     ../../extras/package/win32/../../../src/stream_output/sap.c \
     ../../extras/package/win32/../../../src/stream_output/sdp.c \
     ../../extras/package/win32/../../../src/stream_output/stream_output.c \
     ../../extras/package/win32/../../../src/stream_output/stream_output.h \
     ../../extras/package/win32/../../../src/text/iso-639_def.h \
     ../../extras/package/win32/../../../src/version.c \
     ../../extras/package/win32/../../../src/video_output/interlacing.c \
     ../../extras/package/win32/../../../src/video_output/video_output.c \
     ../../extras/package/win32/../../../src/video_output/video_text.c \
     ../../extras/package/win32/../../../src/video_output/video_widgets.c \
     ../../extras/package/win32/../../../src/video_output/vout_internal.h \
     ../../extras/package/win32/../../../src/video_output/vout_intf.c \
     ../../extras/package/win32/../../../src/video_output/vout_subpictures.c \
     ../../extras/package/win32/../../../src/win32/thread.c \
     ../../extras/package/win32/../../../lib/audio.c \
     ../../extras/package/win32/../../../lib/core.c \
     ../../extras/package/win32/../../../lib/event.c \
     ../../extras/package/win32/../../../lib/libvlc_internal.h \
     ../../extras/package/win32/../../../lib/log.c \
     ../../extras/package/win32/../../../lib/media.c \
     ../../extras/package/win32/../../../lib/media_discoverer.c \
     ../../extras/package/win32/../../../lib/media_library.c \
     ../../extras/package/win32/../../../lib/media_list.c \
     ../../extras/package/win32/../../../lib/media_list_path.h \
     ../../extras/package/win32/../../../lib/media_list_player.c \
     ../../extras/package/win32/../../../lib/media_player.c \
     ../../extras/package/win32/../../../lib/playlist.c \
     ../../extras/package/win32/../../../lib/video.c \
     ../../extras/package/win32/../../../modules/access/alsa.c \
     ../../extras/package/win32/../../../modules/access/avcapture.m \
     ../../extras/package/win32/../../../modules/access/avio.h \
     ../../extras/package/win32/../../../modules/access/bluray.c \
     ../../extras/package/win32/../../../modules/access/cdda.c \
     ../../extras/package/win32/../../../modules/access/concat.c \
     ../../extras/package/win32/../../../modules/access/dc1394.c \
     ../../extras/package/win32/../../../modules/access/dcp/dcp.cpp \
     ../../extras/package/win32/../../../modules/access/decklink.cpp \
     ../../extras/package/win32/../../../modules/access/dshow/dshow.cpp \
     ../../extras/package/win32/../../../modules/access/dsm/access.c \
     ../../extras/package/win32/../../../modules/access/dsm/sd.c \
     ../../extras/package/win32/../../../modules/access/dtv/access.c \
     ../../extras/package/win32/../../../modules/access/dv.c \
     ../../extras/package/win32/../../../modules/access/dvb/access.c \
     ../../extras/package/win32/../../../modules/access/dvb/scan.c \
     ../../extras/package/win32/../../../modules/access/dvdnav.c \
     ../../extras/package/win32/../../../modules/access/dvdread.c \
     ../../extras/package/win32/../../../modules/access/fs.c \
     ../../extras/package/win32/../../../modules/access/ftp.c \
     ../../extras/package/win32/../../../modules/access/http.c \
     ../../extras/package/win32/../../../modules/access/http/access.c \
     ../../extras/package/win32/../../../modules/access/idummy.c \
     ../../extras/package/win32/../../../modules/access/imem.c \
     ../../extras/package/win32/../../../modules/access/imem-access.c \
     ../../extras/package/win32/../../../modules/access/jack.c \
     ../../extras/package/win32/../../../modules/access/linsys/linsys_hdsdi.c \
     ../../extras/package/win32/../../../modules/access/linsys/linsys_sdi.c \
     ../../extras/package/win32/../../../modules/access/live555.cpp \
     ../../extras/package/win32/../../../modules/access/mms/mms.c \
     ../../extras/package/win32/../../../modules/access/mtp.c \
     ../../extras/package/win32/../../../modules/access/nfs.c \
     ../../extras/package/win32/../../../modules/access/oss.c \
     ../../extras/package/win32/../../../modules/access/pulse.c \
     ../../extras/package/win32/../../../modules/access/qtsound.m \
     ../../extras/package/win32/../../../modules/access/rdp.c \
     ../../extras/package/win32/../../../modules/access/rtp/rtp.c \
     ../../extras/package/win32/../../../modules/access/samba.c \
     ../../extras/package/win32/../../../modules/access/satip.c \
     ../../extras/package/win32/../../../modules/access/screen/screen.c \
     ../../extras/package/win32/../../../modules/access/screen/wayland.c \
     ../../extras/package/win32/../../../modules/access/screen/xcb.c \
     ../../extras/package/win32/../../../modules/access/sdp.c \
     ../../extras/package/win32/../../../modules/access/sftp.c \
     ../../extras/package/win32/../../../modules/access/shm.c \
     ../../extras/package/win32/../../../modules/access/smb_common.h \
     ../../extras/package/win32/../../../modules/access/smb2.c \
     ../../extras/package/win32/../../../modules/access/srt.c \
     ../../extras/package/win32/../../../modules/access/tcp.c \
     ../../extras/package/win32/../../../modules/access/timecode.c \
     ../../extras/package/win32/../../../modules/access/udp.c \
     ../../extras/package/win32/../../../modules/access/unc.c \
     ../../extras/package/win32/../../../modules/access/v4l2/controls.c \
     ../../extras/package/win32/../../../modules/access/v4l2/v4l2.c \
     ../../extras/package/win32/../../../modules/access/vcd/vcd.c \
     ../../extras/package/win32/../../../modules/access/vdr.c \
     ../../extras/package/win32/../../../modules/access/vnc.c \
     ../../extras/package/win32/../../../modules/access/wasapi.c \
     ../../extras/package/win32/../../../modules/access_output/dummy.c \
     ../../extras/package/win32/../../../modules/access_output/file.c \
     ../../extras/package/win32/../../../modules/access_output/http.c \
     ../../extras/package/win32/../../../modules/access_output/livehttp.c \
     ../../extras/package/win32/../../../modules/access_output/shout.c \
     ../../extras/package/win32/../../../modules/access_output/srt.c \
     ../../extras/package/win32/../../../modules/access_output/udp.c \
     ../../extras/package/win32/../../../modules/arm_neon/chroma_yuv.c \
     ../../extras/package/win32/../../../modules/arm_neon/volume.c \
     ../../extras/package/win32/../../../modules/arm_neon/yuv_rgb.c \
     ../../extras/package/win32/../../../modules/audio_filter/audiobargraph_a.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/dolby.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/headphone.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/mono.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/remap.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/simple.c \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/spatialaudio.cpp \
     ../../extras/package/win32/../../../modules/audio_filter/channel_mixer/trivial.c \
     ../../extras/package/win32/../../../modules/audio_filter/chorus_flanger.c \
     ../../extras/package/win32/../../../modules/audio_filter/compressor.c \
     ../../extras/package/win32/../../../modules/audio_filter/converter/format.c \
     ../../extras/package/win32/../../../modules/audio_filter/converter/tospdif.c \
     ../../extras/package/win32/../../../modules/audio_filter/equalizer.c \
     ../../extras/package/win32/../../../modules/audio_filter/equalizer_presets.h \
     ../../extras/package/win32/../../../modules/audio_filter/gain.c \
     ../../extras/package/win32/../../../modules/audio_filter/karaoke.c \
     ../../extras/package/win32/../../../modules/audio_filter/normvol.c \
     ../../extras/package/win32/../../../modules/audio_filter/param_eq.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/bandlimited.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/soxr.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/speex.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/src.c \
     ../../extras/package/win32/../../../modules/audio_filter/resampler/ugly.c \
     ../../extras/package/win32/../../../modules/audio_filter/scaletempo.c \
     ../../extras/package/win32/../../../modules/audio_filter/spatializer/spatializer.cpp \
     ../../extras/package/win32/../../../modules/audio_filter/stereo_widen.c \
     ../../extras/package/win32/../../../modules/audio_mixer/float.c \
     ../../extras/package/win32/../../../modules/audio_mixer/integer.c \
     ../../extras/package/win32/../../../modules/audio_output/adummy.c \
     ../../extras/package/win32/../../../modules/audio_output/alsa.c \
     ../../extras/package/win32/../../../modules/audio_output/amem.c \
     ../../extras/package/win32/../../../modules/audio_output/audiotrack.c \
     ../../extras/package/win32/../../../modules/audio_output/audiounit_ios.m \
     ../../extras/package/win32/../../../modules/audio_output/auhal.c \
     ../../extras/package/win32/../../../modules/audio_output/coreaudio_common.c \
     ../../extras/package/win32/../../../modules/audio_output/directsound.c \
     ../../extras/package/win32/../../../modules/audio_output/file.c \
     ../../extras/package/win32/../../../modules/audio_output/jack.c \
     ../../extras/package/win32/../../../modules/audio_output/kai.c \
     ../../extras/package/win32/../../../modules/audio_output/mmdevice.c \
     ../../extras/package/win32/../../../modules/audio_output/opensles_android.c \
     ../../extras/package/win32/../../../modules/audio_output/oss.c \
     ../../extras/package/win32/../../../modules/audio_output/pulse.c \
     ../../extras/package/win32/../../../modules/audio_output/sndio.c \
     ../../extras/package/win32/../../../modules/audio_output/vlcpulse.c \
     ../../extras/package/win32/../../../modules/audio_output/tizen_audio.c \
     ../../extras/package/win32/../../../modules/audio_output/volume.h \
     ../../extras/package/win32/../../../modules/audio_output/wasapi.c \
     ../../extras/package/win32/../../../modules/audio_output/waveout.c \
     ../../extras/package/win32/../../../modules/audio_output/windows_audio_common.h \
     ../../extras/package/win32/../../../modules/audio_output/winstore.c \
     ../../extras/package/win32/../../../modules/codec/a52.c \
     ../../extras/package/win32/../../../modules/codec/adpcm.c \
     ../../extras/package/win32/../../../modules/codec/aes3.c \
     ../../extras/package/win32/../../../modules/codec/aom.c \
     ../../extras/package/win32/../../../modules/codec/araw.c \
     ../../extras/package/win32/../../../modules/codec/audiotoolbox_midi.c \
     ../../extras/package/win32/../../../modules/codec/arib/aribsub.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/avcodec.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/avcodec.h \
     ../../extras/package/win32/../../../modules/codec/avcodec/d3d11va.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/dxva2.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/encoder.c \
     ../../extras/package/win32/../../../modules/codec/avcodec/vaapi.c \
     ../../extras/package/win32/../../../modules/codec/bpg.c \
     ../../extras/package/win32/../../../modules/codec/cc.c \
     ../../extras/package/win32/../../../modules/codec/cdg.c \
     ../../extras/package/win32/../../../modules/codec/cea708.c \
     ../../extras/package/win32/../../../modules/codec/cea708.h \
     ../../extras/package/win32/../../../modules/codec/crystalhd.c \
     ../../extras/package/win32/../../../modules/codec/cvdsub.c \
     ../../extras/package/win32/../../../modules/codec/daala.c \
     ../../extras/package/win32/../../../modules/codec/dca.c \
     ../../extras/package/win32/../../../modules/codec/ddummy.c \
     ../../extras/package/win32/../../../modules/codec/dmo/dmo.c \
     ../../extras/package/win32/../../../modules/codec/dvbsub.c \
     ../../extras/package/win32/../../../modules/codec/edummy.c \
     ../../extras/package/win32/../../../modules/codec/faad.c \
     ../../extras/package/win32/../../../modules/codec/fdkaac.c \
     ../../extras/package/win32/../../../modules/codec/flac.c \
     ../../extras/package/win32/../../../modules/codec/fluidsynth.c \
     ../../extras/package/win32/../../../modules/codec/g711.c \
     ../../extras/package/win32/../../../modules/codec/gstreamer/gstdecode.c \
     ../../extras/package/win32/../../../modules/codec/jpeg.c \
     ../../extras/package/win32/../../../modules/codec/kate.c \
     ../../extras/package/win32/../../../modules/codec/libass.c \
     ../../extras/package/win32/../../../modules/codec/libmpeg2.c \
     ../../extras/package/win32/../../../modules/codec/lpcm.c \
     ../../extras/package/win32/../../../modules/codec/mad.c \
     ../../extras/package/win32/../../../modules/codec/mft.c \
     ../../extras/package/win32/../../../modules/codec/mpg123.c \
     ../../extras/package/win32/../../../modules/codec/oggspots.c \
     ../../extras/package/win32/../../../modules/codec/omxil/mediacodec.c \
     ../../extras/package/win32/../../../modules/codec/omxil/omxil.c \
     ../../extras/package/win32/../../../modules/codec/opus.c \
     ../../extras/package/win32/../../../modules/codec/png.c \
     ../../extras/package/win32/../../../modules/codec/qsv.c \
     ../../extras/package/win32/../../../modules/codec/rawvideo.c \
     ../../extras/package/win32/../../../modules/codec/rtpvideo.c \
     ../../extras/package/win32/../../../modules/codec/schroedinger.c \
     ../../extras/package/win32/../../../modules/codec/scte18.c \
     ../../extras/package/win32/../../../modules/codec/scte18.h \
     ../../extras/package/win32/../../../modules/codec/scte27.c \
     ../../extras/package/win32/../../../modules/codec/sdl_image.c \
     ../../extras/package/win32/../../../modules/codec/shine.c \
     ../../extras/package/win32/../../../modules/codec/spdif.c \
     ../../extras/package/win32/../../../modules/codec/speex.c \
     ../../extras/package/win32/../../../modules/codec/spudec/spudec.c \
     ../../extras/package/win32/../../../modules/codec/stl.c \
     ../../extras/package/win32/../../../modules/codec/subsdec.c \
     ../../extras/package/win32/../../../modules/codec/subsusf.c \
     ../../extras/package/win32/../../../modules/codec/substx3g.c \
     ../../extras/package/win32/../../../modules/codec/svcdsub.c \
     ../../extras/package/win32/../../../modules/codec/svg.c \
     ../../extras/package/win32/../../../modules/codec/t140.c \
     ../../extras/package/win32/../../../modules/codec/telx.c \
     ../../extras/package/win32/../../../modules/codec/textst.c \
     ../../extras/package/win32/../../../modules/codec/theora.c \
     ../../extras/package/win32/../../../modules/codec/ttml/substtml.c \
     ../../extras/package/win32/../../../modules/codec/ttml/ttml.c \
     ../../extras/package/win32/../../../modules/codec/ttml/ttml.h \
     ../../extras/package/win32/../../../modules/codec/twolame.c \
     ../../extras/package/win32/../../../modules/codec/uleaddvaudio.c \
     ../../extras/package/win32/../../../modules/codec/videotoolbox.m \
     ../../extras/package/win32/../../../modules/codec/vorbis.c \
     ../../extras/package/win32/../../../modules/codec/vpx.c \
     ../../extras/package/win32/../../../modules/codec/webvtt/webvtt.c \
     ../../extras/package/win32/../../../modules/codec/wmafixed/wma.c \
     ../../extras/package/win32/../../../modules/codec/x264.c \
     ../../extras/package/win32/../../../modules/codec/x265.c \
     ../../extras/package/win32/../../../modules/codec/xwd.c \
     ../../extras/package/win32/../../../modules/codec/zvbi.c \
     ../../extras/package/win32/../../../modules/control/dbus/dbus.c \
     ../../extras/package/win32/../../../modules/control/dbus/dbus_root.c \
     ../../extras/package/win32/../../../modules/control/dummy.c \
     ../../extras/package/win32/../../../modules/control/gestures.c \
     ../../extras/package/win32/../../../modules/control/globalhotkeys/win32.c \
     ../../extras/package/win32/../../../modules/control/globalhotkeys/xcb.c \
     ../../extras/package/win32/../../../modules/control/hotkeys.c \
     ../../extras/package/win32/../../../modules/control/intromsg.h \
     ../../extras/package/win32/../../../modules/control/lirc.c \
     ../../extras/package/win32/../../../modules/control/motion.c \
     ../../extras/package/win32/../../../modules/control/netsync.c \
     ../../extras/package/win32/../../../modules/control/ntservice.c \
     ../../extras/package/win32/../../../modules/control/oldrc.c \
     ../../extras/package/win32/../../../modules/control/win_msg.c \
     ../../extras/package/win32/../../../modules/demux/adaptive/adaptive.cpp \
     ../../extras/package/win32/../../../modules/demux/aiff.c \
     ../../extras/package/win32/../../../modules/demux/asf/asf.c \
     ../../extras/package/win32/../../../modules/demux/au.c \
     ../../extras/package/win32/../../../modules/demux/avformat/avformat.c \
     ../../extras/package/win32/../../../modules/demux/avformat/avformat.h \
     ../../extras/package/win32/../../../modules/demux/avi/avi.c \
     ../../extras/package/win32/../../../modules/demux/avi/libavi.c \
     ../../extras/package/win32/../../../modules/demux/avi/libavi.h \
     ../../extras/package/win32/../../../modules/demux/caf.c \
     ../../extras/package/win32/../../../modules/demux/cdg.c \
     ../../extras/package/win32/../../../modules/demux/demuxdump.c \
     ../../extras/package/win32/../../../modules/demux/directory.c \
     ../../extras/package/win32/../../../modules/demux/filter/noseek.c \
     ../../extras/package/win32/../../../modules/demux/flac.c \
     ../../extras/package/win32/../../../modules/demux/gme.c \
     ../../extras/package/win32/../../../modules/demux/image.c \
     ../../extras/package/win32/../../../modules/demux/mjpeg.c \
     ../../extras/package/win32/../../../modules/demux/mkv/mkv.cpp \
     ../../extras/package/win32/../../../modules/demux/mod.c \
     ../../extras/package/win32/../../../modules/demux/mp4/libmp4.c \
     ../../extras/package/win32/../../../modules/demux/mp4/libmp4.h \
     ../../extras/package/win32/../../../modules/demux/mp4/meta.c \
     ../../extras/package/win32/../../../modules/demux/mp4/mp4.c \
     ../../extras/package/win32/../../../modules/demux/mpc.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/es.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/h26x.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/mpgv.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/ps.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/ts.c \
     ../../extras/package/win32/../../../modules/demux/mpeg/ts_descriptions.h \
     ../../extras/package/win32/../../../modules/demux/nsc.c \
     ../../extras/package/win32/../../../modules/demux/nsv.c \
     ../../extras/package/win32/../../../modules/demux/nuv.c \
     ../../extras/package/win32/../../../modules/demux/ogg.c \
     ../../extras/package/win32/../../../modules/demux/playlist/asx.c \
     ../../extras/package/win32/../../../modules/demux/playlist/b4s.c \
     ../../extras/package/win32/../../../modules/demux/playlist/dvb.c \
     ../../extras/package/win32/../../../modules/demux/playlist/ifo.c \
     ../../extras/package/win32/../../../modules/demux/playlist/itml.c \
     ../../extras/package/win32/../../../modules/demux/playlist/itml.h \
     ../../extras/package/win32/../../../modules/demux/playlist/m3u.c \
     ../../extras/package/win32/../../../modules/demux/playlist/playlist.c \
     ../../extras/package/win32/../../../modules/demux/playlist/playlist.h \
     ../../extras/package/win32/../../../modules/demux/playlist/pls.c \
     ../../extras/package/win32/../../../modules/demux/playlist/podcast.c \
     ../../extras/package/win32/../../../modules/demux/playlist/qtl.c \
     ../../extras/package/win32/../../../modules/demux/playlist/ram.c \
     ../../extras/package/win32/../../../modules/demux/playlist/sgimb.c \
     ../../extras/package/win32/../../../modules/demux/playlist/wpl.c \
     ../../extras/package/win32/../../../modules/demux/playlist/xspf.c \
     ../../extras/package/win32/../../../modules/demux/pva.c \
     ../../extras/package/win32/../../../modules/demux/rawaud.c \
     ../../extras/package/win32/../../../modules/demux/rawdv.c \
     ../../extras/package/win32/../../../modules/demux/rawvid.c \
     ../../extras/package/win32/../../../modules/demux/sid.cpp \
     ../../extras/package/win32/../../../modules/demux/smf.c \
     ../../extras/package/win32/../../../modules/demux/stl.c \
     ../../extras/package/win32/../../../modules/demux/subtitle.c \
     ../../extras/package/win32/../../../modules/demux/tta.c \
     ../../extras/package/win32/../../../modules/demux/ttml.c \
     ../../extras/package/win32/../../../modules/demux/ty.c \
     ../../extras/package/win32/../../../modules/demux/vc1.c \
     ../../extras/package/win32/../../../modules/demux/vobsub.c \
     ../../extras/package/win32/../../../modules/demux/voc.c \
     ../../extras/package/win32/../../../modules/demux/wav.c \
     ../../extras/package/win32/../../../modules/demux/webvtt.c \
     ../../extras/package/win32/../../../modules/demux/xa.c \
     ../../extras/package/win32/../../../modules/demux/xiph.h \
     ../../extras/package/win32/../../../modules/demux/xiph_metadata.c \
     ../../extras/package/win32/../../../modules/demux/xiph_metadata.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCAboutWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCAboutWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCAddonListItem.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCAddonListItem.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCAddonsWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCAddonsWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCApplication.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCApplication.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCAudioEffectsWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCAudioEffectsWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCBookmarksWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCBookmarksWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCBottomBarView.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCBottomBarView.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCControlsBarCommon.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCControlsBarCommon.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCConvertAndSaveWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCConvertAndSaveWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCCoreDialogProvider.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCCoreDialogProvider.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCCoreInteraction.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCCoreInteraction.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCDefaultValueSlider.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCDefaultValueSlider.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCDefaultValueSliderCell.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCDefaultValueSliderCell.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCDocumentController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCDocumentController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCErrorWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCErrorWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCExtensionsDialogProvider.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCExtensionsDialogProvider.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCExtensionsManager.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCExtensionsManager.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCFSPanelController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCFSPanelController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/helpers.h \
     ../../extras/package/win32/../../../modules/gui/macosx/macosx.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMain.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMain.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMain+OldPrefs.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMain+OldPrefs.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMain.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMain.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMainMenu.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMainMenu.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMainWindow.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMainWindow.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMainWindowControlsBar.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCMainWindowControlsBar.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCOpenWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCOpenWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCOutput.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCOutput.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPLItem.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPLItem.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPLModel.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPLModel.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPlaylist.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPlaylist.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPlaylistInfo.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPlaylistInfo.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPlaylistView.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPlaylistView.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPopupPanelController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCPopupPanelController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCRendererDiscovery.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCRendererDiscovery.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCRendererItem.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCRendererItem.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCRendererMenuController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCRendererMenuController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCResumeDialogController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCResumeDialogController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCScrollingClipView.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCScrollingClipView.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCSimplePrefsController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCSimplePrefsController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCSimplePrefsWindow.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCSimplePrefsWindow.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCSlider.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCSlider.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCSliderCell.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCSliderCell.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCStatusBarIcon.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCStatusBarIcon.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCStringUtility.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCStringUtility.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTextfieldPanelController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTextfieldPanelController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTimeField.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTimeField.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTimeSelectionPanelController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTimeSelectionPanelController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTrackSynchronizationWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCTrackSynchronizationWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCUIWidgets.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCUIWidgets.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVideoEffectsWindowController.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVideoEffectsWindowController.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVideoWindowCommon.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVideoWindowCommon.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVolumeSlider.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVolumeSlider.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVolumeSliderCell.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVolumeSliderCell.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVoutView.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVoutView.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVideoOutputProvider.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCVideoOutputProvider.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCWindow.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCWindow.m \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCWrappableTextField.h \
     ../../extras/package/win32/../../../modules/gui/macosx/VLCWrappableTextField.m \
     ../../extras/package/win32/../../../modules/gui/macosx/applescript.h \
     ../../extras/package/win32/../../../modules/gui/macosx/applescript.m \
     ../../extras/package/win32/../../../modules/gui/macosx/helpers.h \
     ../../extras/package/win32/../../../modules/gui/macosx/iTunes.h \
     ../../extras/package/win32/../../../modules/gui/macosx/macosx.m \
     ../../extras/package/win32/../../../modules/gui/macosx/misc.h \
     ../../extras/package/win32/../../../modules/gui/macosx/misc.m \
     ../../extras/package/win32/../../../modules/gui/macosx/prefs.h \
     ../../extras/package/win32/../../../modules/gui/macosx/prefs.m \
     ../../extras/package/win32/../../../modules/gui/macosx/prefs_widgets.h \
     ../../extras/package/win32/../../../modules/gui/macosx/prefs_widgets.m \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/VLCMinimalVoutWindow.h \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/VLCMinimalVoutWindow.m \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/intf.h \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/intf.m \
     ../../extras/package/win32/../../../modules/gui/minimal_macosx/macosx.c \
     ../../extras/package/win32/../../../modules/gui/ncurses.c \
     ../../extras/package/win32/../../../modules/gui/qt/actions_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/actions_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/adapters/chromaprint.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/adapters/chromaprint.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/adapters/seekpoints.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/adapters/seekpoints.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/adapters/variables.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/adapters/variables.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/complete_preferences.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/complete_preferences.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/controller.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/controller.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/controller_widget.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/controller_widget.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/custom_menus.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/custom_menus.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGChannels.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGChannels.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGItem.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGItem.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGProgram.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGProgram.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGRuler.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGRuler.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGView.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGView.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGWidget.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/epg/EPGWidget.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/extended_panels.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/extended_panels.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/info_panels.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/info_panels.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/info_widgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/info_widgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/interface_widgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/interface_widgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/open_panels.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/open_panels.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/playlist.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/playlist.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/playlist_item.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/playlist_item.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/playlist_model.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/playlist_model.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/selector.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/selector.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/sorting.h \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/standardpanel.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/standardpanel.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/views.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/views.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/vlc_model.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/playlist/vlc_model.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/preferences_widgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/preferences_widgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/simple_preferences.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/simple_preferences.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/sout/profile_selector.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/sout/profile_selector.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/sout/profiles.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/sout/sout_widgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/components/sout/sout_widgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/bookmarks.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/bookmarks.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/convert.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/convert.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/epg.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/epg.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/errors.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/errors.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/extended.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/extended.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/extensions.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/extensions.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/external.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/external.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/fingerprintdialog.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/fingerprintdialog.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/firstrun.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/firstrun.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/gototime.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/gototime.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/help.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/help.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/mediainfo.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/mediainfo.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/messages.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/messages.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/open.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/open.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/openurl.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/openurl.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/playlist.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/playlist.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/plugins.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/plugins.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/podcast_configuration.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/podcast_configuration.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/preferences.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/preferences.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/sout.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/sout.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/toolbar.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/toolbar.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/vlm.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs/vlm.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs_provider.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/dialogs_provider.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/extensions_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/extensions_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/input_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/input_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/main_interface.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/main_interface.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/main_interface_win32.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/main_interface_win32.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/managers/addons_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/managers/addons_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/menus.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/menus.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/qt.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/qt.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/recents.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/recents.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/styles/seekstyle.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/styles/seekstyle.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/animators.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/animators.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/buttons/BrowseButton.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/buttons/BrowseButton.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/buttons/DeckButtonsLayout.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/buttons/DeckButtonsLayout.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/buttons/RoundButton.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/buttons/RoundButton.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/customwidgets.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/customwidgets.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/imagehelper.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/imagehelper.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/input_slider.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/input_slider.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/pictureflow.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/pictureflow.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/qmenuview.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/qmenuview.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/qt_dirs.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/qt_dirs.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/qvlcapp.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/qvlcframe.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/registry.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/registry.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/searchlineedit.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/searchlineedit.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/singleton.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/timetooltip.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/timetooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/validators.cpp \
     ../../extras/package/win32/../../../modules/gui/qt/util/validators.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/async_queue.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/async_queue.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_add_item.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_add_item.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_audio.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_audio.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_callbacks.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_change_skin.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_change_skin.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_dialogs.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_dummy.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_dvd.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_dvd.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_fullscreen.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_fullscreen.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_generic.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_input.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_input.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_layout.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_layout.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_minimize.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_minimize.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_muxer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_muxer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_on_top.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_on_top.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_playlist.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_playlist.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_playtree.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_playtree.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_quit.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_quit.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_resize.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_resize.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_show_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_snapshot.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_snapshot.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_vars.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/commands/cmd_vars.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_button.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_button.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_checkbox.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_checkbox.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_flat.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_generic.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_generic.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_image.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_image.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_list.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_list.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_move.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_move.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_radialslider.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_radialslider.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_resize.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_resize.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_slider.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_slider.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_text.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_text.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_tree.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_tree.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_video.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/controls/ctrl_video.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_dragndrop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_enter.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_focus.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_generic.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_input.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_input.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_key.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_key.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_leave.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_menu.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_motion.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_mouse.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_mouse.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_refresh.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_scroll.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_scroll.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_special.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/events/evt_special.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/builder.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/builder_data.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/builder.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/expr_evaluator.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/expr_evaluator.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/interpreter.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/interpreter.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/skin_parser.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/skin_parser.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/xmlparser.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/parser/xmlparser.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/anchor.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/anchor.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/anim_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/anim_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/bitmap_font.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/bitmap_font.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/dialogs.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/dialogs.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/file_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/file_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ft2_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ft2_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ft2_font.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ft2_font.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_font.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_layout.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_layout.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/generic_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ini_file.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/ini_file.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/logger.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/logger.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_factory.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_factory.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_graphics.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_loop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_timer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/os_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/popup.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/scaled_bitmap.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/scaled_bitmap.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/skin_common.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/skin_main.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme_loader.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme_loader.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme_repository.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/theme_repository.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/tooltip.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/top_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/top_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/var_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/var_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/vlcproc.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/vlcproc.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/vout_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/vout_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/window_manager.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/src/window_manager.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/bezier.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/bezier.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/fsm.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/fsm.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/observer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/pointer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/position.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/position.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/ustring.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/ustring.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_bool.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_bool.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/variable.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_list.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_list.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_percent.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_percent.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_text.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_text.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_tree.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/utils/var_tree.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/equalizer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/equalizer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/playtree.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/playtree.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/time.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/time.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/volume.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/vars/volume.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_dragdrop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_dragdrop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_factory.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_factory.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_graphics.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_graphics.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_loop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_loop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_popup.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_timer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_timer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_tooltip.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/win32/win32_window.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_display.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_display.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_dragdrop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_dragdrop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_factory.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_factory.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_graphics.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_graphics.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_loop.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_loop.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_popup.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_popup.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_timer.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_timer.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_tooltip.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_tooltip.hpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_window.cpp \
     ../../extras/package/win32/../../../modules/gui/skins2/x11/x11_window.hpp \
     ../../extras/package/win32/../../../modules/hw/d3d11/d3d11_filters.c \
     ../../extras/package/win32/../../../modules/hw/d3d9/d3d9_filters.c \
     ../../extras/package/win32/../../../modules/hw/mmal/codec.c \
     ../../extras/package/win32/../../../modules/hw/mmal/deinterlace.c \
     ../../extras/package/win32/../../../modules/hw/mmal/vout.c \
     ../../extras/package/win32/../../../modules/hw/vaapi/filters.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/adjust.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/avcodec.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/chroma.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/deinterlace.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/display.c \
     ../../extras/package/win32/../../../modules/hw/vdpau/sharpen.c \
     ../../extras/package/win32/../../../modules/keystore/file.c \
     ../../extras/package/win32/../../../modules/keystore/keychain.m \
     ../../extras/package/win32/../../../modules/keystore/kwallet.c \
     ../../extras/package/win32/../../../modules/keystore/memory.c \
     ../../extras/package/win32/../../../modules/keystore/secret.c \
     ../../extras/package/win32/../../../modules/logger/android.c \
     ../../extras/package/win32/../../../modules/logger/console.c \
     ../../extras/package/win32/../../../modules/logger/file.c \
     ../../extras/package/win32/../../../modules/logger/journal.c \
     ../../extras/package/win32/../../../modules/logger/syslog.c \
     ../../extras/package/win32/../../../modules/lua/demux.c \
     ../../extras/package/win32/../../../modules/lua/extension.c \
     ../../extras/package/win32/../../../modules/lua/libs/gettext.c \
     ../../extras/package/win32/../../../modules/lua/intf.c \
     ../../extras/package/win32/../../../modules/lua/libs/configuration.c \
     ../../extras/package/win32/../../../modules/lua/libs.h \
     ../../extras/package/win32/../../../modules/lua/libs/httpd.c \
     ../../extras/package/win32/../../../modules/lua/vlc.c \
     ../../extras/package/win32/../../../modules/meta_engine/folder.c \
     ../../extras/package/win32/../../../modules/meta_engine/ID3Genres.h \
     ../../extras/package/win32/../../../modules/meta_engine/taglib.cpp \
     ../../extras/package/win32/../../../modules/misc/addons/fsstorage.c \
     ../../extras/package/win32/../../../modules/misc/addons/vorepository.c \
     ../../extras/package/win32/../../../modules/misc/audioscrobbler.c \
     ../../extras/package/win32/../../../modules/misc/fingerprinter.c \
     ../../extras/package/win32/../../../modules/misc/gnutls.c \
     ../../extras/package/win32/../../../modules/misc/inhibit/dbus.c \
     ../../extras/package/win32/../../../modules/misc/inhibit/wl-idle-inhibit.c \
     ../../extras/package/win32/../../../modules/misc/inhibit/xdg.c \
     ../../extras/package/win32/../../../modules/misc/medialibrary/medialib.cpp \
     ../../extras/package/win32/../../../modules/misc/playlist/export.c \
     ../../extras/package/win32/../../../modules/misc/playlist/html.c \
     ../../extras/package/win32/../../../modules/misc/playlist/m3u.c \
     ../../extras/package/win32/../../../modules/misc/playlist/xspf.c \
     ../../extras/package/win32/../../../modules/misc/rtsp.c \
     ../../extras/package/win32/../../../modules/misc/securetransport.c \
     ../../extras/package/win32/../../../modules/misc/stats.c \
     ../../extras/package/win32/../../../modules/misc/xml/libxml.c \
     ../../extras/package/win32/../../../modules/mux/asf.c \
     ../../extras/package/win32/../../../modules/mux/avi.c \
     ../../extras/package/win32/../../../modules/mux/dummy.c \
     ../../extras/package/win32/../../../modules/mux/mp4/libmp4mux.c \
     ../../extras/package/win32/../../../modules/mux/mp4/libmp4mux.h \
     ../../extras/package/win32/../../../modules/mux/mp4/mp4.c \
     ../../extras/package/win32/../../../modules/mux/mpeg/ps.c \
     ../../extras/package/win32/../../../modules/mux/mpeg/ts.c \
     ../../extras/package/win32/../../../modules/mux/mpjpeg.c \
     ../../extras/package/win32/../../../modules/mux/ogg.c \
     ../../extras/package/win32/../../../modules/mux/wav.c \
     ../../extras/package/win32/../../../modules/notify/osx_notifications.m \
     ../../extras/package/win32/../../../modules/notify/notify.c \
     ../../extras/package/win32/../../../modules/packetizer/a52.c \
     ../../extras/package/win32/../../../modules/packetizer/avparser.h \
     ../../extras/package/win32/../../../modules/packetizer/copy.c \
     ../../extras/package/win32/../../../modules/packetizer/dts.c \
     ../../extras/package/win32/../../../modules/packetizer/flac.c \
     ../../extras/package/win32/../../../modules/packetizer/h264.c \
     ../../extras/package/win32/../../../modules/packetizer/hevc.c \
     ../../extras/package/win32/../../../modules/packetizer/mlp.c \
     ../../extras/package/win32/../../../modules/packetizer/mpeg4audio.c \
     ../../extras/package/win32/../../../modules/packetizer/mpeg4video.c \
     ../../extras/package/win32/../../../modules/packetizer/mpegaudio.c \
     ../../extras/package/win32/../../../modules/packetizer/mpegvideo.c \
     ../../extras/package/win32/../../../modules/packetizer/vc1.c \
     ../../extras/package/win32/../../../modules/services_discovery/avahi.c \
     ../../extras/package/win32/../../../modules/services_discovery/bonjour.m \
     ../../extras/package/win32/../../../modules/services_discovery/mediadirs.c \
     ../../extras/package/win32/../../../modules/services_discovery/microdns.c \
     ../../extras/package/win32/../../../modules/services_discovery/mtp.c \
     ../../extras/package/win32/../../../modules/services_discovery/os2drive.c \
     ../../extras/package/win32/../../../modules/services_discovery/podcast.c \
     ../../extras/package/win32/../../../modules/services_discovery/pulse.c \
     ../../extras/package/win32/../../../modules/services_discovery/sap.c \
     ../../extras/package/win32/../../../modules/services_discovery/udev.c \
     ../../extras/package/win32/../../../modules/services_discovery/upnp.cpp \
     ../../extras/package/win32/../../../modules/services_discovery/windrive.c \
     ../../extras/package/win32/../../../modules/services_discovery/xcb_apps.c \
     ../../extras/package/win32/../../../modules/spu/audiobargraph_v.c \
     ../../extras/package/win32/../../../modules/spu/dynamicoverlay/dynamicoverlay.c \
     ../../extras/package/win32/../../../modules/spu/logo.c \
     ../../extras/package/win32/../../../modules/spu/marq.c \
     ../../extras/package/win32/../../../modules/spu/mosaic.c \
     ../../extras/package/win32/../../../modules/spu/remoteosd.c \
     ../../extras/package/win32/../../../modules/spu/rss.c \
     ../../extras/package/win32/../../../modules/spu/subsdelay.c \
     ../../extras/package/win32/../../../modules/stream_extractor/archive.c \
     ../../extras/package/win32/../../../modules/stream_filter/adf.c \
     ../../extras/package/win32/../../../modules/stream_filter/aribcam.c \
     ../../extras/package/win32/../../../modules/stream_filter/cache_block.c \
     ../../extras/package/win32/../../../modules/stream_filter/cache_read.c \
     ../../extras/package/win32/../../../modules/stream_filter/decomp.c \
     ../../extras/package/win32/../../../modules/stream_filter/hds/hds.c \
     ../../extras/package/win32/../../../modules/stream_filter/inflate.c \
     ../../extras/package/win32/../../../modules/stream_filter/prefetch.c \
     ../../extras/package/win32/../../../modules/stream_filter/record.c \
     ../../extras/package/win32/../../../modules/stream_filter/skiptags.c \
     ../../extras/package/win32/../../../modules/stream_out/autodel.c \
     ../../extras/package/win32/../../../modules/stream_out/bridge.c \
     ../../extras/package/win32/../../../modules/stream_out/chromaprint.c \
     ../../extras/package/win32/../../../modules/stream_out/chromecast/cast.cpp \
     ../../extras/package/win32/../../../modules/stream_out/chromecast/chromecast_demux.cpp \
     ../../extras/package/win32/../../../modules/stream_out/cycle.c \
     ../../extras/package/win32/../../../modules/stream_out/delay.c \
     ../../extras/package/win32/../../../modules/stream_out/description.c \
     ../../extras/package/win32/../../../modules/stream_out/display.c \
     ../../extras/package/win32/../../../modules/stream_out/dummy.c \
     ../../extras/package/win32/../../../modules/stream_out/duplicate.c \
     ../../extras/package/win32/../../../modules/stream_out/es.c \
     ../../extras/package/win32/../../../modules/stream_out/gather.c \
     ../../extras/package/win32/../../../modules/stream_out/mosaic_bridge.c \
     ../../extras/package/win32/../../../modules/stream_out/record.c \
     ../../extras/package/win32/../../../modules/stream_out/rtcp.c \
     ../../extras/package/win32/../../../modules/stream_out/rtp.c \
     ../../extras/package/win32/../../../modules/stream_out/rtpfmt.c \
     ../../extras/package/win32/../../../modules/stream_out/rtp.h \
     ../../extras/package/win32/../../../modules/stream_out/rtsp.c \
     ../../extras/package/win32/../../../modules/stream_out/setid.c \
     ../../extras/package/win32/../../../modules/stream_out/smem.c \
     ../../extras/package/win32/../../../modules/stream_out/stats.c \
     ../../extras/package/win32/../../../modules/stream_out/standard.c \
     ../../extras/package/win32/../../../modules/stream_out/transcode/transcode.c \
     ../../extras/package/win32/../../../modules/text_renderer/freetype/fonts/fontconfig.c \
     ../../extras/package/win32/../../../modules/text_renderer/freetype/freetype.c \
     ../../extras/package/win32/../../../modules/text_renderer/nsspeechsynthesizer.m \
     ../../extras/package/win32/../../../modules/text_renderer/sapi.cpp \
     ../../extras/package/win32/../../../modules/text_renderer/svg.c \
     ../../extras/package/win32/../../../modules/text_renderer/tdummy.c \
     ../../extras/package/win32/../../../modules/video_chroma/chain.c \
     ../../extras/package/win32/../../../modules/video_chroma/cvpx.c \
     ../../extras/package/win32/../../../modules/video_chroma/grey_yuv.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_nv12.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb16.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb8.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb_c.h \
     ../../extras/package/win32/../../../modules/video_chroma/i420_rgb.h \
     ../../extras/package/win32/../../../modules/video_chroma/i420_yuy2.c \
     ../../extras/package/win32/../../../modules/video_chroma/i420_yuy2.h \
     ../../extras/package/win32/../../../modules/video_chroma/i422_i420.c \
     ../../extras/package/win32/../../../modules/video_chroma/i422_yuy2.c \
     ../../extras/package/win32/../../../modules/video_chroma/i422_yuy2.h \
     ../../extras/package/win32/../../../modules/video_chroma/omxdl.c \
     ../../extras/package/win32/../../../modules/video_chroma/rv32.c \
     ../../extras/package/win32/../../../modules/video_chroma/swscale.c \
     ../../extras/package/win32/../../../modules/video_chroma/yuvp.c \
     ../../extras/package/win32/../../../modules/video_chroma/yuy2_i420.c \
     ../../extras/package/win32/../../../modules/video_chroma/yuy2_i422.c \
     ../../extras/package/win32/../../../modules/video_filter/adjust.c \
     ../../extras/package/win32/../../../modules/video_filter/alphamask.c \
     ../../extras/package/win32/../../../modules/video_filter/anaglyph.c \
     ../../extras/package/win32/../../../modules/video_filter/antiflicker.c \
     ../../extras/package/win32/../../../modules/video_filter/ball.c \
     ../../extras/package/win32/../../../modules/video_filter/blendbench.c \
     ../../extras/package/win32/../../../modules/video_filter/blend.cpp \
     ../../extras/package/win32/../../../modules/video_filter/bluescreen.c \
     ../../extras/package/win32/../../../modules/video_filter/canvas.c \
     ../../extras/package/win32/../../../modules/video_filter/ci_filters.m \
     ../../extras/package/win32/../../../modules/video_filter/colorthres.c \
     ../../extras/package/win32/../../../modules/video_filter/croppadd.c \
     ../../extras/package/win32/../../../modules/video_filter/deinterlace/algo_phosphor.h \
     ../../extras/package/win32/../../../modules/video_filter/deinterlace/deinterlace.c \
     ../../extras/package/win32/../../../modules/video_filter/deinterlace/deinterlace.h \
     ../../extras/package/win32/../../../modules/video_filter/edgedetection.c \
     ../../extras/package/win32/../../../modules/video_filter/erase.c \
     ../../extras/package/win32/../../../modules/video_filter/extract.c \
     ../../extras/package/win32/../../../modules/video_filter/fps.c \
     ../../extras/package/win32/../../../modules/video_filter/freeze.c \
     ../../extras/package/win32/../../../modules/video_filter/gaussianblur.c \
     ../../extras/package/win32/../../../modules/video_filter/gradfun.c \
     ../../extras/package/win32/../../../modules/video_filter/gradient.c \
     ../../extras/package/win32/../../../modules/video_filter/grain.c \
     ../../extras/package/win32/../../../modules/video_filter/hqdn3d.c \
     ../../extras/package/win32/../../../modules/video_filter/invert.c \
     ../../extras/package/win32/../../../modules/video_filter/magnify.c \
     ../../extras/package/win32/../../../modules/video_filter/mirror.c \
     ../../extras/package/win32/../../../modules/video_filter/motionblur.c \
     ../../extras/package/win32/../../../modules/video_filter/motiondetect.c \
     ../../extras/package/win32/../../../modules/video_filter/oldmovie.c \
     ../../extras/package/win32/../../../modules/video_filter/opencv_example.cpp \
     ../../extras/package/win32/../../../modules/video_filter/opencv_wrapper.c \
     ../../extras/package/win32/../../../modules/video_filter/posterize.c \
     ../../extras/package/win32/../../../modules/video_filter/postproc.c \
     ../../extras/package/win32/../../../modules/video_filter/psychedelic.c \
     ../../extras/package/win32/../../../modules/video_filter/puzzle.c \
     ../../extras/package/win32/../../../modules/video_filter/ripple.c \
     ../../extras/package/win32/../../../modules/video_filter/rotate.c \
     ../../extras/package/win32/../../../modules/video_filter/scale.c \
     ../../extras/package/win32/../../../modules/video_filter/scene.c \
     ../../extras/package/win32/../../../modules/video_filter/sepia.c \
     ../../extras/package/win32/../../../modules/video_filter/sharpen.c \
     ../../extras/package/win32/../../../modules/video_filter/transform.c \
     ../../extras/package/win32/../../../modules/video_filter/vhs.c \
     ../../extras/package/win32/../../../modules/video_filter/wave.c \
     ../../extras/package/win32/../../../modules/video_output/android/window.c \
     ../../extras/package/win32/../../../modules/video_output/caca.c \
     ../../extras/package/win32/../../../modules/video_output/caopengllayer.m \
     ../../extras/package/win32/../../../modules/video_output/decklink.cpp \
     ../../extras/package/win32/../../../modules/video_output/drawable.c \
     ../../extras/package/win32/../../../modules/video_output/fb.c \
     ../../extras/package/win32/../../../modules/video_output/glx.c \
     ../../extras/package/win32/../../../modules/video_output/ios.m \
     ../../extras/package/win32/../../../modules/video_output/kva.c \
     ../../extras/package/win32/../../../modules/video_output/macosx.m \
     ../../extras/package/win32/../../../modules/video_output/opengl/display.c \
     ../../extras/package/win32/../../../modules/video_output/opengl/egl.c \
     ../../extras/package/win32/../../../modules/video_output/opengl/vout_helper.h \
     ../../extras/package/win32/../../../modules/video_output/win32/direct3d9.c \
     ../../extras/package/win32/../../../modules/video_output/win32/direct3d11.c \
     ../../extras/package/win32/../../../modules/video_output/win32/directdraw.c \
     ../../extras/package/win32/../../../modules/video_output/win32/events.c \
     ../../extras/package/win32/../../../modules/video_output/win32/glwin32.c \
     ../../extras/package/win32/../../../modules/video_output/win32/wingdi.c \
     ../../extras/package/win32/../../../modules/video_output/win32/wgl.c \
     ../../extras/package/win32/../../../modules/video_output/vdummy.c \
     ../../extras/package/win32/../../../modules/video_output/vmem.c \
     ../../extras/package/win32/../../../modules/video_output/wayland/shm.c \
     ../../extras/package/win32/../../../modules/video_output/wayland/xdg-shell.c \
     ../../extras/package/win32/../../../modules/video_output/xcb/window.c \
     ../../extras/package/win32/../../../modules/video_output/xcb/x11.c \
     ../../extras/package/win32/../../../modules/video_output/xcb/xvideo.c \
     ../../extras/package/win32/../../../modules/video_output/yuv.c \
     ../../extras/package/win32/../../../modules/video_splitter/clone.c \
     ../../extras/package/win32/../../../modules/video_splitter/panoramix.c \
     ../../extras/package/win32/../../../modules/video_splitter/wall.c \
     ../../extras/package/win32/../../../modules/visualization/glspectrum.c \
     ../../extras/package/win32/../../../modules/visualization/goom.c \
     ../../extras/package/win32/../../../modules/visualization/projectm.cpp \
     ../../extras/package/win32/../../../modules/visualization/visual/visual.c \
     ../../extras/package/win32/../../../modules/visualization/visual/window_presets.h \
     ../../extras/package/win32/../../../modules/visualization/vsxu.cpp \
     ../../extras/package/win32/../../../share/vlc.appdata.xml.in.in \
     ../../extras/package/win32/../../../share/lua/http/dialogs/batch_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/browse_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/create_stream.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/equalizer_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/error_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/mosaic_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/offset_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/stream_config_window.html \
     ../../extras/package/win32/../../../share/lua/http/dialogs/stream_window.html \
     ../../extras/package/win32/../../../share/lua/http/index.html \
     ../../extras/package/win32/../../../share/lua/http/mobile_browse.html \
     ../../extras/package/win32/../../../share/lua/http/mobile_equalizer.html \
     ../../extras/package/win32/../../../share/lua/http/mobile.html \
     ../../extras/package/win32/../../../share/lua/http/mobile_view.html

CATALOGS =  ach.gmo af.gmo am.gmo an.gmo ar.gmo as_IN.gmo ast.gmo az.gmo be.gmo bg.gmo bn_IN.gmo bn.gmo br.gmo brx.gmo bs.gmo ca.gmo cgg.gmo ckb.gmo co.gmo cs.gmo cy.gmo da.gmo de.gmo el.gmo en_GB.gmo es.gmo et.gmo eu.gmo fa.gmo ff.gmo fi.gmo fr.gmo fur.gmo fy.gmo ga.gmo gd.gmo gl.gmo gu.gmo he.gmo hi.gmo hr.gmo hu.gmo hy.gmo ia.gmo id.gmo is.gmo it.gmo ja.gmo ka.gmo kk.gmo km.gmo kn.gmo ko.gmo ks_IN.gmo ky.gmo lg.gmo lt.gmo lv.gmo mai.gmo mk.gmo ml.gmo mn.gmo mr.gmo ms.gmo my.gmo nb.gmo ne.gmo nl.gmo nn.gmo oc.gmo or.gmo pa.gmo pl.gmo ps.gmo pt_BR.gmo pt_PT.gmo ro.gmo ru.gmo si.gmo sk.gmo sl.gmo sq.gmo sr.gmo sv.gmo ta.gmo te.gmo tet.gmo th.gmo tl.gmo tr.gmo ug.gmo uk.gmo uz.gmo vi.gmo wa.gmo zh_CN.gmo zh_TW.gmo zu.gmo

POFILESDEPS_ = $(srcdir)/$(DOMAIN).pot
POFILESDEPS_yes = $(POFILESDEPS_)
POFILESDEPS_no =
POFILESDEPS = $(POFILESDEPS_$(PO_DEPENDS_ON_POT))

DISTFILESDEPS_ = update-po
DISTFILESDEPS_yes = $(DISTFILESDEPS_)
DISTFILESDEPS_no =
DISTFILESDEPS = $(DISTFILESDEPS_$(DIST_DEPENDS_ON_UPDATE_PO))

# Makevars gets inserted here. (Don't remove this line!)
# Makefile variables for PO directory in any package using GNU gettext.

VPATH += ../modules/gui ../modules/gui/qt ../modules/gui/qt/ui

# Usually the message domain is the same as the package name.
DOMAIN = $(PACKAGE)

# These two variables depend on the location of this directory.
subdir = po
top_builddir = ..

# These options get passed to xgettext.
XGETTEXT_OPTIONS = --directory=.. --keyword=_ --keyword=N_ --keyword=_NS --keyword=_ANS --keyword=qtr --keyword=Q_ --language=C++ --keyword=vlc_ngettext:1,2 --keyword=vlc_pgettext:1c,2 --add-comments=xgettext: --from-code=UTF-8

# This is the copyright holder that gets inserted into the header of the
# $(DOMAIN).pot file.  Set this to the copyright holder of the surrounding
# package.  (Note that the msgstr strings, extracted from the package's
# sources, belong to the copyright holder of the package.)  Translators are
# expected to transfer the copyright for their translations to this person
# or entity, or to disclaim their copyright.  The empty string stands for
# the public domain; in this case the translators are expected to disclaim
# their copyright.
COPYRIGHT_HOLDER = VideoLAN

# This is the email address or URL to which the translators shall report
# bugs in the untranslated strings:
# - Strings which are not entire sentences, see the maintainer guidelines
#   in the GNU gettext documentation, section 'Preparing Strings'.
# - Strings which use unclear terms or require additional context to be
#   understood.
# - Strings which make invalid assumptions about notation of date, time or
#   money.
# - Pluralisation problems.
# - Incorrect English spelling.
# - Incorrect formatting.
# It can be your email address, or a mailing list address where translators
# can write to without being subscribed, or the URL of a web page through
# which the translators can contact you.
MSGID_BUGS_ADDRESS = vlc-devel@videolan.org

# This is the list of locale categories, beyond LC_MESSAGES, for which the
# message catalogs shall be used.  It is usually empty.
EXTRA_LOCALE_CATEGORIES =

.SUFFIXES:
.SUFFIXES: .po .gmo .mo .sed .sin .nop .po-create .po-update

.po.mo:
	@echo "$(MSGFMT) -c -o $@ $<"; \
	$(MSGFMT) -c -o t-$@ $< && mv t-$@ $@

.po.gmo:
	@lang=`echo $* | sed -e 's,.*/,,'`; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o $${lang}.gmo $${lang}.po"; \
	cd $(srcdir) && rm -f $${lang}.gmo && $(GMSGFMT) -c --statistics --verbose -o t-$${lang}.gmo $${lang}.po && mv t-$${lang}.gmo $${lang}.gmo

.sin.sed:
	sed -e '/^#/d' $< > t-$@
	mv t-$@ $@


all: all-yes

all-yes: stamp-po
all-no:

# Ensure that the gettext macros and this Makefile.in.in are in sync.
CHECK_MACRO_VERSION = \
	test "$(GETTEXT_MACRO_VERSION)" = "0.19" \
	  || { echo "*** error: gettext infrastructure mismatch: using a Makefile.in.in from gettext version $(GETTEXT_MACRO_VERSION) but the autoconf macros are from gettext version 0.19" 1>&2; \
	       exit 1; \
	     }

# $(srcdir)/$(DOMAIN).pot is only created when needed. When xgettext finds no
# internationalized messages, no $(srcdir)/$(DOMAIN).pot is created (because
# we don't want to bother translators with empty POT files). We assume that
# LINGUAS is empty in this case, i.e. $(POFILES) and $(GMOFILES) are empty.
# In this case, stamp-po is a nop (i.e. a phony target).

# stamp-po is a timestamp denoting the last time at which the CATALOGS have
# been loosely updated. Its purpose is that when a developer or translator
# checks out the package via CVS, and the $(DOMAIN).pot file is not in CVS,
# "make" will update the $(DOMAIN).pot and the $(CATALOGS), but subsequent
# invocations of "make" will do nothing. This timestamp would not be necessary
# if updating the $(CATALOGS) would always touch them; however, the rule for
# $(POFILES) has been designed to not touch files that don't need to be
# changed.
stamp-po: $(srcdir)/$(DOMAIN).pot
	@$(CHECK_MACRO_VERSION)
	test ! -f $(srcdir)/$(DOMAIN).pot || \
	  test -z "$(GMOFILES)" || $(MAKE) $(GMOFILES)
	@test ! -f $(srcdir)/$(DOMAIN).pot || { \
	  echo "touch stamp-po" && \
	  echo timestamp > stamp-poT && \
	  mv stamp-poT stamp-po; \
	}

# Note: Target 'all' must not depend on target '$(DOMAIN).pot-update',
# otherwise packages like GCC can not be built if only parts of the source
# have been downloaded.

# This target rebuilds $(DOMAIN).pot; it is an expensive operation.
# Note that $(DOMAIN).pot is not touched if it doesn't need to be changed.
# The determination of whether the package xyz is a GNU one is based on the
# heuristic whether some file in the top level directory mentions "GNU xyz".
# If GNU 'find' is available, we avoid grepping through monster files.
$(DOMAIN).pot-update: $(POTFILES) $(srcdir)/POTFILES.in remove-potcdate.sed
	package_gnu="$(PACKAGE_GNU)"; \
	test -n "$$package_gnu" || { \
	  if { if (LC_ALL=C find --version) 2>/dev/null | grep GNU >/dev/null; then \
		 LC_ALL=C find -L $(top_srcdir) -maxdepth 1 -type f \
			       -size -10000000c -exec grep 'GNU vlc' \
			       /dev/null '{}' ';' 2>/dev/null; \
	       else \
		 LC_ALL=C grep 'GNU vlc' $(top_srcdir)/* 2>/dev/null; \
	       fi; \
	     } | grep -v 'libtool:' >/dev/null; then \
	     package_gnu=yes; \
	   else \
	     package_gnu=no; \
	   fi; \
	}; \
	if test "$$package_gnu" = "yes"; then \
	  package_prefix='GNU '; \
	else \
	  package_prefix=''; \
	fi; \
	if test -n '$(MSGID_BUGS_ADDRESS)' || test '$(PACKAGE_BUGREPORT)' = '@'PACKAGE_BUGREPORT'@'; then \
	  msgid_bugs_address='$(MSGID_BUGS_ADDRESS)'; \
	else \
	  msgid_bugs_address='$(PACKAGE_BUGREPORT)'; \
	fi; \
	case `$(XGETTEXT) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	  '' | 0.[0-9] | 0.[0-9].* | 0.1[0-5] | 0.1[0-5].* | 0.16 | 0.16.[0-1]*) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	  *) \
	    $(XGETTEXT) --default-domain=$(DOMAIN) --directory=$(top_srcdir) \
	      --add-comments=TRANSLATORS: $(XGETTEXT_OPTIONS)  \
	      --files-from=$(srcdir)/POTFILES.in \
	      --copyright-holder='$(COPYRIGHT_HOLDER)' \
	      --package-name="$${package_prefix}vlc" \
	      --package-version='4.0.0-dev' \
	      --msgid-bugs-address="$$msgid_bugs_address" \
	    ;; \
	esac
	test ! -f $(DOMAIN).po || { \
	  if test -f $(srcdir)/$(DOMAIN).pot-header; then \
	    sed -e '1,/^#$$/d' < $(DOMAIN).po > $(DOMAIN).1po && \
	    cat $(srcdir)/$(DOMAIN).pot-header $(DOMAIN).1po > $(DOMAIN).po; \
	    rm -f $(DOMAIN).1po; \
	  fi; \
	  if test -f $(srcdir)/$(DOMAIN).pot; then \
	    sed -f remove-potcdate.sed < $(srcdir)/$(DOMAIN).pot > $(DOMAIN).1po && \
	    sed -f remove-potcdate.sed < $(DOMAIN).po > $(DOMAIN).2po && \
	    if cmp $(DOMAIN).1po $(DOMAIN).2po >/dev/null 2>&1; then \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(DOMAIN).po; \
	    else \
	      rm -f $(DOMAIN).1po $(DOMAIN).2po $(srcdir)/$(DOMAIN).pot && \
	      mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	    fi; \
	  else \
	    mv $(DOMAIN).po $(srcdir)/$(DOMAIN).pot; \
	  fi; \
	}

# This rule has no dependencies: we don't need to update $(DOMAIN).pot at
# every "make" invocation, only create it when it is missing.
# Only "make $(DOMAIN).pot-update" or "make dist" will force an update.
$(srcdir)/$(DOMAIN).pot:
	$(MAKE) $(DOMAIN).pot-update

# This target rebuilds a PO file if $(DOMAIN).pot has changed.
# Note that a PO file is not touched if it doesn't need to be changed.
$(POFILES): $(POFILESDEPS)
	@lang=`echo $@ | sed -e 's,.*/,,' -e 's/\.po$$//'`; \
	if test -f "$(srcdir)/$${lang}.po"; then \
	  test -f $(srcdir)/$(DOMAIN).pot || $(MAKE) $(srcdir)/$(DOMAIN).pot; \
	  test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	  echo "$${cdcmd}$(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot"; \
	  cd $(srcdir) \
	    && { case `$(MSGMERGE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	           '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) $${lang}.po $(DOMAIN).pot;; \
	           *) \
	             $(MSGMERGE_UPDATE) $(MSGMERGE_OPTIONS) --lang=$${lang} $${lang}.po $(DOMAIN).pot;; \
	         esac; \
	       }; \
	else \
	  $(MAKE) $${lang}.po-create; \
	fi


install: install-exec install-data
install-exec:
install-data: install-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    $(INSTALL_DATA) $(srcdir)/$$file \
			    $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	  for file in Makevars; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
install-data-no: all
install-data-yes: all
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  if test -r $$cat; then realcat=$$cat; else realcat=$(srcdir)/$$cat; fi; \
	  $(INSTALL_DATA) $$realcat $(DESTDIR)$$dir/$(DOMAIN).mo; \
	  echo "installing $$realcat as $(DESTDIR)$$dir/$(DOMAIN).mo"; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	      rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      ln -s ../LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      ln $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo 2>/dev/null || \
	      cp -p $(DESTDIR)$(localedir)/$$lang/LC_MESSAGES/$(DOMAIN).mo $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	      echo "installing $$realcat link as $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo"; \
	    fi; \
	  done; \
	done

install-strip: install

installdirs: installdirs-exec installdirs-data
installdirs-exec:
installdirs-data: installdirs-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  $(mkdir_p) $(DESTDIR)$(gettextsrcdir); \
	else \
	  : ; \
	fi
installdirs-data-no:
installdirs-data-yes:
	@catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  dir=$(localedir)/$$lang/LC_MESSAGES; \
	  $(mkdir_p) $(DESTDIR)$$dir; \
	  for lc in '' $(EXTRA_LOCALE_CATEGORIES); do \
	    if test -n "$$lc"; then \
	      if (cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc 2>/dev/null) | grep ' -> ' >/dev/null; then \
	        link=`cd $(DESTDIR)$(localedir)/$$lang && LC_ALL=C ls -l -d $$lc | sed -e 's/^.* -> //'`; \
	        mv $(DESTDIR)$(localedir)/$$lang/$$lc $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	        mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        (cd $(DESTDIR)$(localedir)/$$lang/$$lc.old && \
	         for file in *; do \
	           if test -f $$file; then \
	             ln -s ../$$link/$$file $(DESTDIR)$(localedir)/$$lang/$$lc/$$file; \
	           fi; \
	         done); \
	        rm -f $(DESTDIR)$(localedir)/$$lang/$$lc.old; \
	      else \
	        if test -d $(DESTDIR)$(localedir)/$$lang/$$lc; then \
	          :; \
	        else \
	          rm -f $(DESTDIR)$(localedir)/$$lang/$$lc; \
	          mkdir $(DESTDIR)$(localedir)/$$lang/$$lc; \
	        fi; \
	      fi; \
	    fi; \
	  done; \
	done

# Define this as empty until I found a useful application.
installcheck:

uninstall: uninstall-exec uninstall-data
uninstall-exec:
uninstall-data: uninstall-data-yes
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  for file in $(DISTFILES.common) Makevars.template; do \
	    rm -f $(DESTDIR)$(gettextsrcdir)/$$file; \
	  done; \
	else \
	  : ; \
	fi
uninstall-data-no:
uninstall-data-yes:
	catalogs='$(CATALOGS)'; \
	for cat in $$catalogs; do \
	  cat=`basename $$cat`; \
	  lang=`echo $$cat | sed -e 's/\.gmo$$//'`; \
	  for lc in LC_MESSAGES $(EXTRA_LOCALE_CATEGORIES); do \
	    rm -f $(DESTDIR)$(localedir)/$$lang/$$lc/$(DOMAIN).mo; \
	  done; \
	done

check: all

info dvi ps pdf html tags TAGS ctags CTAGS ID:

mostlyclean:
	rm -f remove-potcdate.sed
	rm -f stamp-poT
	rm -f core core.* $(DOMAIN).po $(DOMAIN).1po $(DOMAIN).2po *.new.po
	rm -fr *.o

clean: mostlyclean

distclean: clean
	rm -f Makefile Makefile.in POTFILES *.mo

maintainer-clean: distclean
	@echo "This command is intended for maintainers to use;"
	@echo "it deletes files that may require special tools to rebuild."
	rm -f stamp-po $(GMOFILES)

distdir = $(top_builddir)/$(PACKAGE)-$(VERSION)/$(subdir)
dist distdir:
	test -z "$(DISTFILESDEPS)" || $(MAKE) $(DISTFILESDEPS)
	@$(MAKE) dist2
# This is a separate target because 'update-po' must be executed before.
dist2: stamp-po $(DISTFILES)
	dists="$(DISTFILES)"; \
	if test "$(PACKAGE)" = "gettext-tools"; then \
	  dists="$$dists Makevars.template"; \
	fi; \
	if test -f $(srcdir)/$(DOMAIN).pot; then \
	  dists="$$dists $(DOMAIN).pot stamp-po"; \
	fi; \
	if test -f $(srcdir)/ChangeLog; then \
	  dists="$$dists ChangeLog"; \
	fi; \
	for i in 0 1 2 3 4 5 6 7 8 9; do \
	  if test -f $(srcdir)/ChangeLog.$$i; then \
	    dists="$$dists ChangeLog.$$i"; \
	  fi; \
	done; \
	if test -f $(srcdir)/LINGUAS; then dists="$$dists LINGUAS"; fi; \
	for file in $$dists; do \
	  if test -f $$file; then \
	    cp -p $$file $(distdir) || exit 1; \
	  else \
	    cp -p $(srcdir)/$$file $(distdir) || exit 1; \
	  fi; \
	done

update-po: Makefile
	$(MAKE) $(DOMAIN).pot-update
	test -z "$(UPDATEPOFILES)" || $(MAKE) $(UPDATEPOFILES)
	$(MAKE) update-gmo

# General rule for creating PO files.

.nop.po-create:
	@lang=`echo $@ | sed -e 's/\.po-create$$//'`; \
	echo "File $$lang.po does not exist. If you are a translator, you can create it through 'msginit'." 1>&2; \
	exit 1

# General rule for updating PO files.

.nop.po-update:
	@lang=`echo $@ | sed -e 's/\.po-update$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools" && test "$(CROSS_COMPILING)" != "yes"; then PATH=`pwd`/../src:$$PATH; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	test "$(srcdir)" = . && cdcmd="" || cdcmd="cd $(srcdir) && "; \
	echo "$${cdcmd}$(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang $$lang.po $(DOMAIN).pot -o $$lang.new.po"; \
	cd $(srcdir); \
	if { case `$(MSGMERGE) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	       '' | 0.[0-9] | 0.[0-9].* | 0.1[0-7] | 0.1[0-7].*) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	       *) \
	         $(MSGMERGE) $(MSGMERGE_OPTIONS) --lang=$$lang -o $$tmpdir/$$lang.new.po $$lang.po $(DOMAIN).pot;; \
	     esac; \
	   }; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "msgmerge for $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "msgmerge for $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

$(DUMMYPOFILES):

update-gmo: Makefile $(GMOFILES)
	@:

# Recreate Makefile by invoking config.status. Explicitly invoke the shell,
# because execution permission bits may not work on the current file system.
# Use /bin/bash, which is the shell determined by autoconf for the use by its
# scripts, not $(SHELL) which is hardwired to /bin/sh and may be deficient.
Makefile: Makefile.in.in Makevars $(top_builddir)/config.status POTFILES.in LINGUAS
	cd $(top_builddir) \
	  && /bin/bash ./config.status $(subdir)/$@.in po-directories

force:

# Tell versions [3.59,3.63) of GNU make not to export all variables.
# Otherwise a system limit (for SysV at least) may be exceeded.
.NOEXPORT:
# This file, Rules-quot, can be copied and used freely without restrictions.
# Special Makefile rules for English message catalogs with quotation marks.

DISTFILES.common.extra1 = quot.sed boldquot.sed en@quot.header en@boldquot.header insert-header.sin Rules-quot

.SUFFIXES: .insert-header .po-update-en

en@quot.po-create:
	$(MAKE) en@quot.po-update
en@boldquot.po-create:
	$(MAKE) en@boldquot.po-update

en@quot.po-update: en@quot.po-update-en
en@boldquot.po-update: en@boldquot.po-update-en

.insert-header.po-update-en:
	@lang=`echo $@ | sed -e 's/\.po-update-en$$//'`; \
	if test "$(PACKAGE)" = "gettext-tools" && test "$(CROSS_COMPILING)" != "yes"; then PATH=`pwd`/../src:$$PATH; GETTEXTLIBDIR=`cd $(top_srcdir)/src && pwd`; export GETTEXTLIBDIR; fi; \
	tmpdir=`pwd`; \
	echo "$$lang:"; \
	ll=`echo $$lang | sed -e 's/@.*//'`; \
	LC_ALL=C; export LC_ALL; \
	cd $(srcdir); \
	if $(MSGINIT) $(MSGINIT_OPTIONS) -i $(DOMAIN).pot --no-translator -l $$lang -o - 2>/dev/null \
	   | $(SED) -f $$tmpdir/$$lang.insert-header | $(MSGCONV) -t UTF-8 | \
	   { case `$(MSGFILTER) --version | sed 1q | sed -e 's,^[^0-9]*,,'` in \
	     '' | 0.[0-9] | 0.[0-9].* | 0.1[0-8] | 0.1[0-8].*) \
	       $(MSGFILTER) $(SED) -f `echo $$lang | sed -e 's/.*@//'`.sed \
	       ;; \
	     *) \
	       $(MSGFILTER) `echo $$lang | sed -e 's/.*@//'` \
	       ;; \
	     esac } 2>/dev/null > $$tmpdir/$$lang.new.po \
	     ; then \
	  if cmp $$lang.po $$tmpdir/$$lang.new.po >/dev/null 2>&1; then \
	    rm -f $$tmpdir/$$lang.new.po; \
	  else \
	    if mv -f $$tmpdir/$$lang.new.po $$lang.po; then \
	      :; \
	    else \
	      echo "creation of $$lang.po failed: cannot move $$tmpdir/$$lang.new.po to $$lang.po" 1>&2; \
	      exit 1; \
	    fi; \
	  fi; \
	else \
	  echo "creation of $$lang.po failed!" 1>&2; \
	  rm -f $$tmpdir/$$lang.new.po; \
	fi

en@quot.insert-header: insert-header.sin
	sed -e '/^#/d' -e 's/HEADER/en@quot.header/g' $(srcdir)/insert-header.sin > en@quot.insert-header

en@boldquot.insert-header: insert-header.sin
	sed -e '/^#/d' -e 's/HEADER/en@boldquot.header/g' $(srcdir)/insert-header.sin > en@boldquot.insert-header

mostlyclean: mostlyclean-quot
mostlyclean-quot:
	rm -f *.insert-header
