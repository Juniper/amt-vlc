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

SED = /usr/bin/sed
SHELL = /bin/sh


srcdir = ../../extras/package/macosx/../../../po
top_srcdir = ../../extras/package/macosx/../../..
VPATH = ../../extras/package/macosx/../../../po

prefix = /Users/nlandsberg/vlc/build/vlc_install_dir
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
# ${SHELL} /Users/nlandsberg/vlc/autotools/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, $(MKDIR_P) is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /Users/nlandsberg/vlc/autotools/install-sh -d
install_sh = $(SHELL) ${SHELL} /Users/nlandsberg/vlc/autotools/install-sh
MKDIR_P = ../../extras/package/macosx/../../../autotools/install-sh -c -d
mkdir_p = $(MKDIR_P)

# When building gettext-tools, we prefer to use the built programs
# rather than installed programs.  However, we can't do that when we
# are cross compiling.
CROSS_COMPILING = @CROSS_COMPILING@

GMSGFMT_ = /Users/nlandsberg/vlc/extras/tools/build/bin/msgfmt
GMSGFMT_no = /Users/nlandsberg/vlc/extras/tools/build/bin/msgfmt
GMSGFMT_yes = /Users/nlandsberg/vlc/extras/tools/build/bin/msgfmt
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
MSGFMT_ = /Users/nlandsberg/vlc/extras/tools/build/bin/msgfmt
MSGFMT_no = /Users/nlandsberg/vlc/extras/tools/build/bin/msgfmt
MSGFMT_yes = /Users/nlandsberg/vlc/extras/tools/build/bin/msgfmt
MSGFMT = $(MSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = /Users/nlandsberg/vlc/extras/tools/build/bin/xgettext
XGETTEXT_no = /Users/nlandsberg/vlc/extras/tools/build/bin/xgettext
XGETTEXT_yes = /Users/nlandsberg/vlc/extras/tools/build/bin/xgettext
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = msgmerge
MSGMERGE_UPDATE = /Users/nlandsberg/vlc/extras/tools/build/bin/msgmerge --update
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
     ../../extras/package/macosx/../../../include/vlc_access.h \
     ../../extras/package/macosx/../../../include/vlc_actions.h \
     ../../extras/package/macosx/../../../include/vlc_aout.h \
     ../../extras/package/macosx/../../../include/vlc_arrays.h \
     ../../extras/package/macosx/../../../include/vlc_bits.h \
     ../../extras/package/macosx/../../../include/vlc_block.h \
     ../../extras/package/macosx/../../../include/vlc_block_helper.h \
     ../../extras/package/macosx/../../../include/vlc_charset.h \
     ../../extras/package/macosx/../../../include/vlc_codec.h \
     ../../extras/package/macosx/../../../include/vlc_codecs.h \
     ../../extras/package/macosx/../../../include/vlc_common.h \
     ../../extras/package/macosx/../../../include/vlc_config.h \
     ../../extras/package/macosx/../../../include/vlc_config_cat.h \
     ../../extras/package/macosx/../../../include/vlc_configuration.h \
     ../../extras/package/macosx/../../../include/vlc_demux.h \
     ../../extras/package/macosx/../../../include/vlc/deprecated.h \
     ../../extras/package/macosx/../../../include/vlc_epg.h \
     ../../extras/package/macosx/../../../include/vlc_es.h \
     ../../extras/package/macosx/../../../include/vlc_es_out.h \
     ../../extras/package/macosx/../../../include/vlc_events.h \
     ../../extras/package/macosx/../../../include/vlc_filter.h \
     ../../extras/package/macosx/../../../include/vlc_fixups.h \
     ../../extras/package/macosx/../../../include/vlc_gcrypt.h \
     ../../extras/package/macosx/../../../include/vlc_httpd.h \
     ../../extras/package/macosx/../../../include/vlc_image.h \
     ../../extras/package/macosx/../../../include/vlc_input.h \
     ../../extras/package/macosx/../../../include/vlc_intf_strings.h \
     ../../extras/package/macosx/../../../include/vlc_iso_lang.h \
     ../../extras/package/macosx/../../../include/vlc_md5.h \
     ../../extras/package/macosx/../../../include/vlc_messages.h \
     ../../extras/package/macosx/../../../include/vlc_meta.h \
     ../../extras/package/macosx/../../../include/vlc_modules.h \
     ../../extras/package/macosx/../../../include/vlc_tick.h \
     ../../extras/package/macosx/../../../include/vlc_network.h \
     ../../extras/package/macosx/../../../include/vlc_objects.h \
     ../../extras/package/macosx/../../../include/vlc_pgpkey.h \
     ../../extras/package/macosx/../../../include/vlc_plugin.h \
     ../../extras/package/macosx/../../../include/vlc_rand.h \
     ../../extras/package/macosx/../../../include/vlc_services_discovery.h \
     ../../extras/package/macosx/../../../include/vlc_sout.h \
     ../../extras/package/macosx/../../../include/vlc_stream.h \
     ../../extras/package/macosx/../../../include/vlc_strings.h \
     ../../extras/package/macosx/../../../include/vlc_threads.h \
     ../../extras/package/macosx/../../../include/vlc_tls.h \
     ../../extras/package/macosx/../../../include/vlc_update.h \
     ../../extras/package/macosx/../../../include/vlc_url.h \
     ../../extras/package/macosx/../../../include/vlc_variables.h \
     ../../extras/package/macosx/../../../include/vlc/vlc.h \
     ../../extras/package/macosx/../../../include/vlc_vlm.h \
     ../../extras/package/macosx/../../../include/vlc_vod.h \
     ../../extras/package/macosx/../../../include/vlc_vout.h \
     ../../extras/package/macosx/../../../include/vlc_vout_window.h \
     ../../extras/package/macosx/../../../include/vlc_xml.h \
     ../../extras/package/macosx/../../../src/audio_output/aout_internal.h \
     ../../extras/package/macosx/../../../src/audio_output/common.c \
     ../../extras/package/macosx/../../../src/audio_output/dec.c \
     ../../extras/package/macosx/../../../src/audio_output/filters.c \
     ../../extras/package/macosx/../../../src/audio_output/output.c \
     ../../extras/package/macosx/../../../src/config/chain.c \
     ../../extras/package/macosx/../../../src/config/cmdline.c \
     ../../extras/package/macosx/../../../src/config/configuration.h \
     ../../extras/package/macosx/../../../src/config/core.c \
     ../../extras/package/macosx/../../../src/config/file.c \
     ../../extras/package/macosx/../../../src/config/help.c \
     ../../extras/package/macosx/../../../src/config/intf.c \
     ../../extras/package/macosx/../../../src/darwin/error.c \
     ../../extras/package/macosx/../../../src/extras/libc.c \
     ../../extras/package/macosx/../../../src/input/access.c \
     ../../extras/package/macosx/../../../src/input/decoder.c \
     ../../extras/package/macosx/../../../src/input/decoder.h \
     ../../extras/package/macosx/../../../src/input/demux.c \
     ../../extras/package/macosx/../../../src/input/demux.h \
     ../../extras/package/macosx/../../../src/input/es_out.c \
     ../../extras/package/macosx/../../../src/input/es_out.h \
     ../../extras/package/macosx/../../../src/input/input.c \
     ../../extras/package/macosx/../../../src/input/input_internal.h \
     ../../extras/package/macosx/../../../src/input/item.c \
     ../../extras/package/macosx/../../../src/input/meta.c \
     ../../extras/package/macosx/../../../src/input/stream.c \
     ../../extras/package/macosx/../../../src/input/stream.h \
     ../../extras/package/macosx/../../../src/input/stream_memory.c \
     ../../extras/package/macosx/../../../src/input/subtitles.c \
     ../../extras/package/macosx/../../../src/input/var.c \
     ../../extras/package/macosx/../../../src/input/vlm.c \
     ../../extras/package/macosx/../../../src/input/vlm_internal.h \
     ../../extras/package/macosx/../../../src/input/vlmshell.c \
     ../../extras/package/macosx/../../../src/interface/interface.c \
     ../../extras/package/macosx/../../../src/libvlc.c \
     ../../extras/package/macosx/../../../src/libvlc.h \
     ../../extras/package/macosx/../../../src/libvlc-module.c \
     ../../extras/package/macosx/../../../src/misc/actions.c \
     ../../extras/package/macosx/../../../src/misc/block.c \
     ../../extras/package/macosx/../../../src/misc/cpu.c \
     ../../extras/package/macosx/../../../src/misc/es_format.c \
     ../../extras/package/macosx/../../../src/misc/events.c \
     ../../extras/package/macosx/../../../src/misc/filter_chain.c \
     ../../extras/package/macosx/../../../src/misc/image.c \
     ../../extras/package/macosx/../../../src/misc/md5.c \
     ../../extras/package/macosx/../../../src/misc/messages.c \
     ../../extras/package/macosx/../../../src/misc/mtime.c \
     ../../extras/package/macosx/../../../src/misc/objects.c \
     ../../extras/package/macosx/../../../src/misc/rand.c \
     ../../extras/package/macosx/../../../src/misc/threads.c \
     ../../extras/package/macosx/../../../src/misc/update.c \
     ../../extras/package/macosx/../../../src/misc/update.h \
     ../../extras/package/macosx/../../../src/misc/variables.c \
     ../../extras/package/macosx/../../../src/misc/variables.h \
     ../../extras/package/macosx/../../../src/misc/xml.c \
     ../../extras/package/macosx/../../../src/missing.c \
     ../../extras/package/macosx/../../../src/modules/cache.c \
     ../../extras/package/macosx/../../../src/modules/entry.c \
     ../../extras/package/macosx/../../../src/modules/modules.c \
     ../../extras/package/macosx/../../../src/modules/modules.h \
     ../../extras/package/macosx/../../../src/network/getaddrinfo.c \
     ../../extras/package/macosx/../../../src/network/httpd.c \
     ../../extras/package/macosx/../../../src/network/io.c \
     ../../extras/package/macosx/../../../src/network/rootbind.c \
     ../../extras/package/macosx/../../../src/network/tcp.c \
     ../../extras/package/macosx/../../../src/network/tls.c \
     ../../extras/package/macosx/../../../src/network/udp.c \
     ../../extras/package/macosx/../../../src/player/osd.c \
     ../../extras/package/macosx/../../../src/player/player.c \
     ../../extras/package/macosx/../../../src/stream_output/sap.c \
     ../../extras/package/macosx/../../../src/stream_output/sdp.c \
     ../../extras/package/macosx/../../../src/stream_output/stream_output.c \
     ../../extras/package/macosx/../../../src/stream_output/stream_output.h \
     ../../extras/package/macosx/../../../src/text/iso-639_def.h \
     ../../extras/package/macosx/../../../src/version.c \
     ../../extras/package/macosx/../../../src/video_output/interlacing.c \
     ../../extras/package/macosx/../../../src/video_output/video_output.c \
     ../../extras/package/macosx/../../../src/video_output/video_text.c \
     ../../extras/package/macosx/../../../src/video_output/video_widgets.c \
     ../../extras/package/macosx/../../../src/video_output/vout_internal.h \
     ../../extras/package/macosx/../../../src/video_output/vout_intf.c \
     ../../extras/package/macosx/../../../src/video_output/vout_subpictures.c \
     ../../extras/package/macosx/../../../src/win32/thread.c \
     ../../extras/package/macosx/../../../lib/audio.c \
     ../../extras/package/macosx/../../../lib/core.c \
     ../../extras/package/macosx/../../../lib/event.c \
     ../../extras/package/macosx/../../../lib/libvlc_internal.h \
     ../../extras/package/macosx/../../../lib/log.c \
     ../../extras/package/macosx/../../../lib/media.c \
     ../../extras/package/macosx/../../../lib/media_discoverer.c \
     ../../extras/package/macosx/../../../lib/media_list.c \
     ../../extras/package/macosx/../../../lib/media_list_path.h \
     ../../extras/package/macosx/../../../lib/media_list_player.c \
     ../../extras/package/macosx/../../../lib/media_player.c \
     ../../extras/package/macosx/../../../lib/playlist.c \
     ../../extras/package/macosx/../../../lib/video.c \
     ../../extras/package/macosx/../../../modules/access/alsa.c \
     ../../extras/package/macosx/../../../modules/access/avaudiocapture.m \
     ../../extras/package/macosx/../../../modules/access/avcapture.m \
     ../../extras/package/macosx/../../../modules/access/avio.h \
     ../../extras/package/macosx/../../../modules/access/bluray.c \
     ../../extras/package/macosx/../../../modules/access/cdda.c \
     ../../extras/package/macosx/../../../modules/access/concat.c \
     ../../extras/package/macosx/../../../modules/access/dc1394.c \
     ../../extras/package/macosx/../../../modules/access/dcp/dcp.cpp \
     ../../extras/package/macosx/../../../modules/access/decklink.cpp \
     ../../extras/package/macosx/../../../modules/access/dshow/dshow.cpp \
     ../../extras/package/macosx/../../../modules/access/dsm/access.c \
     ../../extras/package/macosx/../../../modules/access/dsm/sd.c \
     ../../extras/package/macosx/../../../modules/access/dtv/access.c \
     ../../extras/package/macosx/../../../modules/access/dv.c \
     ../../extras/package/macosx/../../../modules/access/dvb/access.c \
     ../../extras/package/macosx/../../../modules/access/dvb/scan.c \
     ../../extras/package/macosx/../../../modules/access/dvdnav.c \
     ../../extras/package/macosx/../../../modules/access/dvdread.c \
     ../../extras/package/macosx/../../../modules/access/fs.c \
     ../../extras/package/macosx/../../../modules/access/ftp.c \
     ../../extras/package/macosx/../../../modules/access/http.c \
     ../../extras/package/macosx/../../../modules/access/http/access.c \
     ../../extras/package/macosx/../../../modules/access/idummy.c \
     ../../extras/package/macosx/../../../modules/access/imem.c \
     ../../extras/package/macosx/../../../modules/access/imem-access.c \
     ../../extras/package/macosx/../../../modules/access/jack.c \
     ../../extras/package/macosx/../../../modules/access/linsys/linsys_hdsdi.c \
     ../../extras/package/macosx/../../../modules/access/linsys/linsys_sdi.c \
     ../../extras/package/macosx/../../../modules/access/live555.cpp \
     ../../extras/package/macosx/../../../modules/access/mms/mms.c \
     ../../extras/package/macosx/../../../modules/access/mtp.c \
     ../../extras/package/macosx/../../../modules/access/nfs.c \
     ../../extras/package/macosx/../../../modules/access/oss.c \
     ../../extras/package/macosx/../../../modules/access/pulse.c \
     ../../extras/package/macosx/../../../modules/access/rdp.c \
     ../../extras/package/macosx/../../../modules/access/rist.h \
     ../../extras/package/macosx/../../../modules/access/rist.c \
     ../../extras/package/macosx/../../../modules/access/rtp/rtp.c \
     ../../extras/package/macosx/../../../modules/access/samba.c \
     ../../extras/package/macosx/../../../modules/access/satip.c \
     ../../extras/package/macosx/../../../modules/access/screen/screen.c \
     ../../extras/package/macosx/../../../modules/access/screen/wayland.c \
     ../../extras/package/macosx/../../../modules/access/screen/xcb.c \
     ../../extras/package/macosx/../../../modules/access/sdp.c \
     ../../extras/package/macosx/../../../modules/access/sftp.c \
     ../../extras/package/macosx/../../../modules/access/shm.c \
     ../../extras/package/macosx/../../../modules/access/smb_common.h \
     ../../extras/package/macosx/../../../modules/access/smb2.c \
     ../../extras/package/macosx/../../../modules/access/srt.c \
     ../../extras/package/macosx/../../../modules/access/srt_common.c \
     ../../extras/package/macosx/../../../modules/access/tcp.c \
     ../../extras/package/macosx/../../../modules/access/timecode.c \
     ../../extras/package/macosx/../../../modules/access/udp.c \
     ../../extras/package/macosx/../../../modules/access/unc.c \
     ../../extras/package/macosx/../../../modules/access/v4l2/controls.c \
     ../../extras/package/macosx/../../../modules/access/v4l2/v4l2.c \
     ../../extras/package/macosx/../../../modules/access/vcd/vcd.c \
     ../../extras/package/macosx/../../../modules/access/vdr.c \
     ../../extras/package/macosx/../../../modules/access/vnc.c \
     ../../extras/package/macosx/../../../modules/access/wasapi.c \
     ../../extras/package/macosx/../../../modules/access_output/dummy.c \
     ../../extras/package/macosx/../../../modules/access_output/file.c \
     ../../extras/package/macosx/../../../modules/access_output/http.c \
     ../../extras/package/macosx/../../../modules/access_output/livehttp.c \
     ../../extras/package/macosx/../../../modules/access_output/rist.c \
     ../../extras/package/macosx/../../../modules/access_output/shout.c \
     ../../extras/package/macosx/../../../modules/access_output/srt.c \
     ../../extras/package/macosx/../../../modules/access_output/udp.c \
     ../../extras/package/macosx/../../../modules/arm_neon/chroma_yuv.c \
     ../../extras/package/macosx/../../../modules/arm_neon/volume.c \
     ../../extras/package/macosx/../../../modules/arm_neon/yuv_rgb.c \
     ../../extras/package/macosx/../../../modules/audio_filter/audiobargraph_a.c \
     ../../extras/package/macosx/../../../modules/audio_filter/channel_mixer/dolby.c \
     ../../extras/package/macosx/../../../modules/audio_filter/channel_mixer/headphone.c \
     ../../extras/package/macosx/../../../modules/audio_filter/channel_mixer/mono.c \
     ../../extras/package/macosx/../../../modules/audio_filter/channel_mixer/remap.c \
     ../../extras/package/macosx/../../../modules/audio_filter/channel_mixer/simple.c \
     ../../extras/package/macosx/../../../modules/audio_filter/channel_mixer/spatialaudio.cpp \
     ../../extras/package/macosx/../../../modules/audio_filter/channel_mixer/trivial.c \
     ../../extras/package/macosx/../../../modules/audio_filter/chorus_flanger.c \
     ../../extras/package/macosx/../../../modules/audio_filter/compressor.c \
     ../../extras/package/macosx/../../../modules/audio_filter/converter/format.c \
     ../../extras/package/macosx/../../../modules/audio_filter/converter/tospdif.c \
     ../../extras/package/macosx/../../../modules/audio_filter/equalizer.c \
     ../../extras/package/macosx/../../../modules/audio_filter/equalizer_presets.h \
     ../../extras/package/macosx/../../../modules/audio_filter/gain.c \
     ../../extras/package/macosx/../../../modules/audio_filter/karaoke.c \
     ../../extras/package/macosx/../../../modules/audio_filter/normvol.c \
     ../../extras/package/macosx/../../../modules/audio_filter/param_eq.c \
     ../../extras/package/macosx/../../../modules/audio_filter/resampler/bandlimited.c \
     ../../extras/package/macosx/../../../modules/audio_filter/resampler/soxr.c \
     ../../extras/package/macosx/../../../modules/audio_filter/resampler/speex.c \
     ../../extras/package/macosx/../../../modules/audio_filter/resampler/src.c \
     ../../extras/package/macosx/../../../modules/audio_filter/resampler/ugly.c \
     ../../extras/package/macosx/../../../modules/audio_filter/scaletempo.c \
     ../../extras/package/macosx/../../../modules/audio_filter/spatializer/spatializer.cpp \
     ../../extras/package/macosx/../../../modules/audio_filter/stereo_widen.c \
     ../../extras/package/macosx/../../../modules/audio_mixer/float.c \
     ../../extras/package/macosx/../../../modules/audio_mixer/integer.c \
     ../../extras/package/macosx/../../../modules/audio_output/adummy.c \
     ../../extras/package/macosx/../../../modules/audio_output/alsa.c \
     ../../extras/package/macosx/../../../modules/audio_output/amem.c \
     ../../extras/package/macosx/../../../modules/audio_output/audiotrack.c \
     ../../extras/package/macosx/../../../modules/audio_output/audiounit_ios.m \
     ../../extras/package/macosx/../../../modules/audio_output/auhal.c \
     ../../extras/package/macosx/../../../modules/audio_output/coreaudio_common.c \
     ../../extras/package/macosx/../../../modules/audio_output/directsound.c \
     ../../extras/package/macosx/../../../modules/audio_output/file.c \
     ../../extras/package/macosx/../../../modules/audio_output/jack.c \
     ../../extras/package/macosx/../../../modules/audio_output/kai.c \
     ../../extras/package/macosx/../../../modules/audio_output/mmdevice.c \
     ../../extras/package/macosx/../../../modules/audio_output/opensles_android.c \
     ../../extras/package/macosx/../../../modules/audio_output/oss.c \
     ../../extras/package/macosx/../../../modules/audio_output/pulse.c \
     ../../extras/package/macosx/../../../modules/audio_output/sndio.c \
     ../../extras/package/macosx/../../../modules/audio_output/vlcpulse.c \
     ../../extras/package/macosx/../../../modules/audio_output/volume.h \
     ../../extras/package/macosx/../../../modules/audio_output/wasapi.c \
     ../../extras/package/macosx/../../../modules/audio_output/waveout.c \
     ../../extras/package/macosx/../../../modules/audio_output/windows_audio_common.h \
     ../../extras/package/macosx/../../../modules/audio_output/winstore.c \
     ../../extras/package/macosx/../../../modules/codec/a52.c \
     ../../extras/package/macosx/../../../modules/codec/adpcm.c \
     ../../extras/package/macosx/../../../modules/codec/aes3.c \
     ../../extras/package/macosx/../../../modules/codec/aom.c \
     ../../extras/package/macosx/../../../modules/codec/araw.c \
     ../../extras/package/macosx/../../../modules/codec/audiotoolbox_midi.c \
     ../../extras/package/macosx/../../../modules/codec/arib/aribsub.c \
     ../../extras/package/macosx/../../../modules/codec/avcodec/avcodec.c \
     ../../extras/package/macosx/../../../modules/codec/avcodec/avcodec.h \
     ../../extras/package/macosx/../../../modules/codec/avcodec/d3d11va.c \
     ../../extras/package/macosx/../../../modules/codec/avcodec/dxva2.c \
     ../../extras/package/macosx/../../../modules/codec/avcodec/encoder.c \
     ../../extras/package/macosx/../../../modules/codec/avcodec/vaapi.c \
     ../../extras/package/macosx/../../../modules/codec/bpg.c \
     ../../extras/package/macosx/../../../modules/codec/cc.c \
     ../../extras/package/macosx/../../../modules/codec/cdg.c \
     ../../extras/package/macosx/../../../modules/codec/cea708.c \
     ../../extras/package/macosx/../../../modules/codec/cea708.h \
     ../../extras/package/macosx/../../../modules/codec/crystalhd.c \
     ../../extras/package/macosx/../../../modules/codec/cvdsub.c \
     ../../extras/package/macosx/../../../modules/codec/daala.c \
     ../../extras/package/macosx/../../../modules/codec/dca.c \
     ../../extras/package/macosx/../../../modules/codec/ddummy.c \
     ../../extras/package/macosx/../../../modules/codec/dmo/dmo.c \
     ../../extras/package/macosx/../../../modules/codec/dvbsub.c \
     ../../extras/package/macosx/../../../modules/codec/edummy.c \
     ../../extras/package/macosx/../../../modules/codec/faad.c \
     ../../extras/package/macosx/../../../modules/codec/fdkaac.c \
     ../../extras/package/macosx/../../../modules/codec/flac.c \
     ../../extras/package/macosx/../../../modules/codec/fluidsynth.c \
     ../../extras/package/macosx/../../../modules/codec/g711.c \
     ../../extras/package/macosx/../../../modules/codec/gstreamer/gstdecode.c \
     ../../extras/package/macosx/../../../modules/codec/jpeg.c \
     ../../extras/package/macosx/../../../modules/codec/kate.c \
     ../../extras/package/macosx/../../../modules/codec/libass.c \
     ../../extras/package/macosx/../../../modules/codec/libmpeg2.c \
     ../../extras/package/macosx/../../../modules/codec/lpcm.c \
     ../../extras/package/macosx/../../../modules/codec/mad.c \
     ../../extras/package/macosx/../../../modules/codec/mft.c \
     ../../extras/package/macosx/../../../modules/codec/mpg123.c \
     ../../extras/package/macosx/../../../modules/codec/oggspots.c \
     ../../extras/package/macosx/../../../modules/codec/omxil/mediacodec.c \
     ../../extras/package/macosx/../../../modules/codec/omxil/omxil.c \
     ../../extras/package/macosx/../../../modules/codec/opus.c \
     ../../extras/package/macosx/../../../modules/codec/png.c \
     ../../extras/package/macosx/../../../modules/codec/qsv.c \
     ../../extras/package/macosx/../../../modules/codec/rawvideo.c \
     ../../extras/package/macosx/../../../modules/codec/rtpvideo.c \
     ../../extras/package/macosx/../../../modules/codec/schroedinger.c \
     ../../extras/package/macosx/../../../modules/codec/scte18.c \
     ../../extras/package/macosx/../../../modules/codec/scte18.h \
     ../../extras/package/macosx/../../../modules/codec/scte27.c \
     ../../extras/package/macosx/../../../modules/codec/sdl_image.c \
     ../../extras/package/macosx/../../../modules/codec/shine.c \
     ../../extras/package/macosx/../../../modules/codec/spdif.c \
     ../../extras/package/macosx/../../../modules/codec/speex.c \
     ../../extras/package/macosx/../../../modules/codec/spudec/spudec.c \
     ../../extras/package/macosx/../../../modules/codec/stl.c \
     ../../extras/package/macosx/../../../modules/codec/subsdec.c \
     ../../extras/package/macosx/../../../modules/codec/subsusf.c \
     ../../extras/package/macosx/../../../modules/codec/substx3g.c \
     ../../extras/package/macosx/../../../modules/codec/svcdsub.c \
     ../../extras/package/macosx/../../../modules/codec/svg.c \
     ../../extras/package/macosx/../../../modules/codec/t140.c \
     ../../extras/package/macosx/../../../modules/codec/telx.c \
     ../../extras/package/macosx/../../../modules/codec/textst.c \
     ../../extras/package/macosx/../../../modules/codec/theora.c \
     ../../extras/package/macosx/../../../modules/codec/ttml/substtml.c \
     ../../extras/package/macosx/../../../modules/codec/ttml/ttml.c \
     ../../extras/package/macosx/../../../modules/codec/ttml/ttml.h \
     ../../extras/package/macosx/../../../modules/codec/twolame.c \
     ../../extras/package/macosx/../../../modules/codec/uleaddvaudio.c \
     ../../extras/package/macosx/../../../modules/codec/videotoolbox.m \
     ../../extras/package/macosx/../../../modules/codec/vorbis.c \
     ../../extras/package/macosx/../../../modules/codec/vpx.c \
     ../../extras/package/macosx/../../../modules/codec/webvtt/webvtt.c \
     ../../extras/package/macosx/../../../modules/codec/x264.c \
     ../../extras/package/macosx/../../../modules/codec/x265.c \
     ../../extras/package/macosx/../../../modules/codec/xwd.c \
     ../../extras/package/macosx/../../../modules/codec/zvbi.c \
     ../../extras/package/macosx/../../../modules/control/dbus/dbus.c \
     ../../extras/package/macosx/../../../modules/control/dbus/dbus_root.c \
     ../../extras/package/macosx/../../../modules/control/dummy.c \
     ../../extras/package/macosx/../../../modules/control/gestures.c \
     ../../extras/package/macosx/../../../modules/control/globalhotkeys/win32.c \
     ../../extras/package/macosx/../../../modules/control/globalhotkeys/xcb.c \
     ../../extras/package/macosx/../../../modules/control/hotkeys.c \
     ../../extras/package/macosx/../../../modules/control/intromsg.h \
     ../../extras/package/macosx/../../../modules/control/lirc.c \
     ../../extras/package/macosx/../../../modules/control/ntservice.c \
     ../../extras/package/macosx/../../../modules/control/rc.c \
     ../../extras/package/macosx/../../../modules/control/win_msg.c \
     ../../extras/package/macosx/../../../modules/demux/adaptive/adaptive.cpp \
     ../../extras/package/macosx/../../../modules/demux/aiff.c \
     ../../extras/package/macosx/../../../modules/demux/asf/asf.c \
     ../../extras/package/macosx/../../../modules/demux/au.c \
     ../../extras/package/macosx/../../../modules/demux/avformat/avformat.c \
     ../../extras/package/macosx/../../../modules/demux/avformat/avformat.h \
     ../../extras/package/macosx/../../../modules/demux/avi/avi.c \
     ../../extras/package/macosx/../../../modules/demux/avi/libavi.c \
     ../../extras/package/macosx/../../../modules/demux/avi/libavi.h \
     ../../extras/package/macosx/../../../modules/demux/caf.c \
     ../../extras/package/macosx/../../../modules/demux/cdg.c \
     ../../extras/package/macosx/../../../modules/demux/demuxdump.c \
     ../../extras/package/macosx/../../../modules/demux/directory.c \
     ../../extras/package/macosx/../../../modules/demux/filter/noseek.c \
     ../../extras/package/macosx/../../../modules/demux/flac.c \
     ../../extras/package/macosx/../../../modules/demux/gme.c \
     ../../extras/package/macosx/../../../modules/demux/image.c \
     ../../extras/package/macosx/../../../modules/demux/mjpeg.c \
     ../../extras/package/macosx/../../../modules/demux/mkv/mkv.cpp \
     ../../extras/package/macosx/../../../modules/demux/mod.c \
     ../../extras/package/macosx/../../../modules/demux/mp4/libmp4.c \
     ../../extras/package/macosx/../../../modules/demux/mp4/libmp4.h \
     ../../extras/package/macosx/../../../modules/demux/mp4/meta.c \
     ../../extras/package/macosx/../../../modules/demux/mp4/mp4.c \
     ../../extras/package/macosx/../../../modules/demux/mpc.c \
     ../../extras/package/macosx/../../../modules/demux/mpeg/es.c \
     ../../extras/package/macosx/../../../modules/demux/mpeg/h26x.c \
     ../../extras/package/macosx/../../../modules/demux/mpeg/mpgv.c \
     ../../extras/package/macosx/../../../modules/demux/mpeg/ps.c \
     ../../extras/package/macosx/../../../modules/demux/mpeg/ts.c \
     ../../extras/package/macosx/../../../modules/demux/mpeg/ts_descriptions.h \
     ../../extras/package/macosx/../../../modules/demux/nsc.c \
     ../../extras/package/macosx/../../../modules/demux/nsv.c \
     ../../extras/package/macosx/../../../modules/demux/nuv.c \
     ../../extras/package/macosx/../../../modules/demux/ogg.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/asx.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/b4s.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/dvb.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/ifo.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/itml.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/itml.h \
     ../../extras/package/macosx/../../../modules/demux/playlist/m3u.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/playlist.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/playlist.h \
     ../../extras/package/macosx/../../../modules/demux/playlist/pls.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/podcast.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/qtl.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/ram.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/sgimb.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/wpl.c \
     ../../extras/package/macosx/../../../modules/demux/playlist/xspf.c \
     ../../extras/package/macosx/../../../modules/demux/pva.c \
     ../../extras/package/macosx/../../../modules/demux/rawaud.c \
     ../../extras/package/macosx/../../../modules/demux/rawdv.c \
     ../../extras/package/macosx/../../../modules/demux/rawvid.c \
     ../../extras/package/macosx/../../../modules/demux/sid.cpp \
     ../../extras/package/macosx/../../../modules/demux/smf.c \
     ../../extras/package/macosx/../../../modules/demux/stl.c \
     ../../extras/package/macosx/../../../modules/demux/subtitle.c \
     ../../extras/package/macosx/../../../modules/demux/tta.c \
     ../../extras/package/macosx/../../../modules/demux/ttml.c \
     ../../extras/package/macosx/../../../modules/demux/ty.c \
     ../../extras/package/macosx/../../../modules/demux/vc1.c \
     ../../extras/package/macosx/../../../modules/demux/vobsub.c \
     ../../extras/package/macosx/../../../modules/demux/voc.c \
     ../../extras/package/macosx/../../../modules/demux/wav.c \
     ../../extras/package/macosx/../../../modules/demux/webvtt.c \
     ../../extras/package/macosx/../../../modules/demux/xa.c \
     ../../extras/package/macosx/../../../modules/demux/xiph.h \
     ../../extras/package/macosx/../../../modules/demux/xiph_metadata.c \
     ../../extras/package/macosx/../../../modules/demux/xiph_metadata.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/coreinteraction/VLCHotkeysController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/coreinteraction/VLCHotkeysController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/coreinteraction/VLCVideoFilterHelper.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/coreinteraction/VLCVideoFilterHelper.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSColor+VLCAdditions.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSColor+VLCAdditions.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSFont+VLCAdditions.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSFont+VLCAdditions.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSScreen+VLCAdditions.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSScreen+VLCAdditions.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSSound+VLCAdditions.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSSound+VLCAdditions.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSString+Helpers.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSString+Helpers.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSView+VLCAdditions.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/NSView+VLCAdditions.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/VLCHexNumberFormatter.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/VLCHexNumberFormatter.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/VLCPositionFormatter.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/extensions/VLCPositionFormatter.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCInputItem.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCInputItem.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryAlbumTableCellView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryAlbumTableCellView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryAudioDataSource.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryAudioDataSource.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryCollectionViewItem.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryCollectionViewItem.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryCollectionViewSupplementaryElementView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryCollectionViewSupplementaryElementView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryDataTypes.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryDataTypes.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryMenuController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryMenuController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryModel.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryModel.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibrarySortingMenuController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibrarySortingMenuController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryTableCellView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryTableCellView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryVideoDataSource.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryVideoDataSource.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryWindow.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/library/VLCLibraryWindow.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/CompatibilityFixes.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/CompatibilityFixes.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/VLCApplication.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/VLCApplication.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/VLCMain+OldPrefs.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/VLCMain+OldPrefs.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/VLCMain.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/VLCMain.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/main/macosx.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSource.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSource.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceBaseDataSource.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceBaseDataSource.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceCollectionViewItem.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceCollectionViewItem.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceDataSource.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceDataSource.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceDeviceCollectionViewItem.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceDeviceCollectionViewItem.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceProvider.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/media-source/VLCMediaSourceProvider.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/VLCMainMenu.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/VLCMainMenu.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/VLCStatusBarIcon.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/VLCStatusBarIcon.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/renderers/VLCRendererDiscovery.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/renderers/VLCRendererDiscovery.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/renderers/VLCRendererItem.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/renderers/VLCRendererItem.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/renderers/VLCRendererMenuController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/menus/renderers/VLCRendererMenuController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/Spotify.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/VLCClickerManager.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/VLCClickerManager.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/VLCDocumentController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/VLCDocumentController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/VLCKeyboardBacklightControl.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/VLCKeyboardBacklightControl.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/VLCRemoteControlService.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/VLCRemoteControlService.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/applescript.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/applescript.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/os-integration/iTunes.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCAudioEffectsWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCAudioEffectsWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCBookmarksWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCBookmarksWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCInformationWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCInformationWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCTimeSelectionPanelController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCTimeSelectionPanelController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCTrackSynchronizationWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCTrackSynchronizationWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCVideoEffectsWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/VLCVideoEffectsWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCCoreDialogProvider.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCCoreDialogProvider.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCCustomCropArWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCCustomCropArWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCPopupPanelController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCPopupPanelController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCResumeDialogController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCResumeDialogController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCTextfieldPanelController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/panels/dialogs/VLCTextfieldPanelController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaybackContinuityController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaybackContinuityController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistDataSource.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistDataSource.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistItem.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistItem.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistMenuController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistMenuController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistModel.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistModel.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistSortingMenuController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistSortingMenuController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistTableCellView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistTableCellView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistTableView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/playlist/VLCPlaylistTableView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/VLCHotkeyChangeWindow.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/VLCHotkeyChangeWindow.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/VLCSimplePrefsController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/VLCSimplePrefsController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/VLCSimplePrefsWindow.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/VLCSimplePrefsWindow.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/prefs.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/prefs.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/prefs_widgets.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/preferences/prefs_widgets.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCBottomBarView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCBottomBarView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCDefaultValueSlider.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCDefaultValueSlider.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCDefaultValueSliderCell.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCDefaultValueSliderCell.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCDragDropView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCDragDropView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCFSPanelDraggableView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCFSPanelDraggableView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCHUDOutlineView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCHUDOutlineView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCHUDTableCornerView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCHUDTableCornerView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCHUDTableView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCHUDTableView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCImageButton.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCImageButton.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCImageView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCImageView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCLinearProgressIndicator.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCLinearProgressIndicator.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCRoundedCornerTextField.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCRoundedCornerTextField.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCScrollingClipView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCScrollingClipView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCSlider.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCSlider.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCSliderCell.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCSliderCell.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCTimeField.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCTimeField.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCTrackingView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCTrackingView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCVolumeSlider.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCVolumeSlider.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCVolumeSliderCell.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCVolumeSliderCell.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCWrappableTextField.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/views/VLCWrappableTextField.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCAboutWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCAboutWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCErrorWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCErrorWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCHelpWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCHelpWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCOpenInputMetadata.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCOpenInputMetadata.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCOpenWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/VLCOpenWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/addons/VLCAddonListItem.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/addons/VLCAddonListItem.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/addons/VLCAddonsWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/addons/VLCAddonsWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/convertandsave/VLCConvertAndSaveWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/convertandsave/VLCConvertAndSaveWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/convertandsave/VLCOutput.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/convertandsave/VLCOutput.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/extensions/VLCExtensionsDialogProvider.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/extensions/VLCExtensionsDialogProvider.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/extensions/VLCExtensionsManager.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/extensions/VLCExtensionsManager.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/extensions/VLCUIWidgets.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/extensions/VLCUIWidgets.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/logging/VLCLogMessage.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/logging/VLCLogMessage.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/logging/VLCLogWindowController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/logging/VLCLogWindowController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/mainwindow/VLCControlsBarCommon.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/mainwindow/VLCControlsBarCommon.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/mainwindow/VLCMainWindowControlsBar.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/mainwindow/VLCMainWindowControlsBar.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCDetachedVideoWindow.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCDetachedVideoWindow.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCFSPanelController.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCFSPanelController.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCVideoOutputProvider.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCVideoOutputProvider.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCVideoWindowCommon.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCVideoWindowCommon.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCVoutView.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCVoutView.m \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCWindow.h \
     ../../extras/package/macosx/../../../modules/gui/macosx/windows/video/VLCWindow.m \
     ../../extras/package/macosx/../../../modules/gui/minimal_macosx/VLCMinimalVoutWindow.h \
     ../../extras/package/macosx/../../../modules/gui/minimal_macosx/VLCMinimalVoutWindow.m \
     ../../extras/package/macosx/../../../modules/gui/minimal_macosx/intf.h \
     ../../extras/package/macosx/../../../modules/gui/minimal_macosx/intf.m \
     ../../extras/package/macosx/../../../modules/gui/minimal_macosx/macosx.c \
     ../../extras/package/macosx/../../../modules/gui/ncurses.c \
     ../../extras/package/macosx/../../../modules/gui/qt/adapters/chromaprint.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/adapters/chromaprint.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/complete_preferences.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/complete_preferences.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/controller.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/controller.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/controller_widget.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/controller_widget.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/custom_menus.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/custom_menus.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGChannels.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGChannels.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGItem.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGItem.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGProgram.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGProgram.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGRuler.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGRuler.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGView.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGView.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGWidget.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/epg/EPGWidget.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/extended_panels.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/extended_panels.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/info_panels.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/info_panels.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/info_widgets.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/info_widgets.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/interface_widgets.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/interface_widgets.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/open_panels.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/open_panels.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/preferences_widgets.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/preferences_widgets.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/simple_preferences.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/simple_preferences.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/sout/profile_selector.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/sout/profile_selector.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/sout/profiles.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/sout/sout_widgets.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/components/sout/sout_widgets.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/bookmarks.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/bookmarks.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/convert.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/convert.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/epg.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/epg.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/errors.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/errors.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/extended.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/extended.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/extensions.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/extensions.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/fingerprintdialog.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/fingerprintdialog.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/firstrun.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/firstrun.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/gototime.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/gototime.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/help.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/help.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/mediainfo.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/mediainfo.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/messages.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/messages.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/open.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/open.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/openurl.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/openurl.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/plugins.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/plugins.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/podcast_configuration.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/podcast_configuration.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/preferences.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/preferences.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/sout.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/sout.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/toolbar.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/toolbar.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/vlm.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs/vlm.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs_provider.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/dialogs_provider.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/extensions_manager.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/extensions_manager.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/main_interface.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/main_interface.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/main_interface_win32.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/main_interface_win32.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/managers/addons_manager.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/managers/addons_manager.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/menus.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/menus.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/qt.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/qt.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/recents.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/recents.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/styles/seekstyle.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/styles/seekstyle.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/animators.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/animators.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/buttons/BrowseButton.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/buttons/BrowseButton.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/buttons/DeckButtonsLayout.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/buttons/DeckButtonsLayout.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/buttons/RoundButton.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/buttons/RoundButton.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/customwidgets.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/customwidgets.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/imagehelper.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/imagehelper.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/input_slider.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/input_slider.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/qt_dirs.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/qt_dirs.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/qvlcapp.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/qvlcframe.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/registry.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/registry.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/searchlineedit.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/searchlineedit.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/singleton.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/timetooltip.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/timetooltip.hpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/validators.cpp \
     ../../extras/package/macosx/../../../modules/gui/qt/util/validators.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/async_queue.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/async_queue.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_add_item.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_add_item.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_audio.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_audio.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_callbacks.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_change_skin.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_change_skin.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_dialogs.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_dummy.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_dvd.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_dvd.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_fullscreen.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_fullscreen.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_generic.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_input.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_input.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_layout.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_layout.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_minimize.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_minimize.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_muxer.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_muxer.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_on_top.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_on_top.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_playlist.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_playlist.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_playtree.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_playtree.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_quit.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_quit.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_resize.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_resize.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_show_window.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_snapshot.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_snapshot.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_vars.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/commands/cmd_vars.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_button.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_button.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_checkbox.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_checkbox.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_flat.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_generic.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_generic.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_image.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_image.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_list.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_list.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_move.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_move.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_radialslider.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_radialslider.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_resize.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_resize.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_slider.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_slider.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_text.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_text.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_tree.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_tree.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_video.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_video.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_dragndrop.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_enter.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_focus.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_generic.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_input.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_input.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_key.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_key.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_leave.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_menu.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_motion.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_mouse.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_mouse.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_refresh.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_scroll.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_scroll.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_special.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/events/evt_special.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/builder.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/builder_data.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/builder.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/expr_evaluator.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/expr_evaluator.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/interpreter.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/interpreter.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/skin_parser.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/skin_parser.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/xmlparser.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/parser/xmlparser.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/anchor.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/anchor.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/anim_bitmap.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/anim_bitmap.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/bitmap_font.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/bitmap_font.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/dialogs.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/dialogs.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/file_bitmap.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/file_bitmap.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/ft2_bitmap.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/ft2_bitmap.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/ft2_font.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/ft2_font.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/generic_bitmap.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/generic_bitmap.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/generic_font.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/generic_layout.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/generic_layout.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/generic_window.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/generic_window.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/ini_file.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/ini_file.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/logger.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/logger.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/os_factory.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/os_factory.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/os_graphics.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/os_loop.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/os_popup.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/os_timer.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/os_tooltip.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/os_window.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/popup.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/popup.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/scaled_bitmap.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/scaled_bitmap.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/skin_common.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/skin_main.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/theme.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/theme.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/theme_loader.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/theme_loader.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/theme_repository.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/theme_repository.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/tooltip.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/tooltip.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/top_window.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/top_window.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/var_manager.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/var_manager.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/vlcproc.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/vlcproc.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/vout_window.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/vout_window.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/window_manager.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/src/window_manager.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/bezier.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/bezier.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/fsm.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/fsm.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/observer.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/pointer.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/position.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/position.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/ustring.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/ustring.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_bool.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_bool.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/variable.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_list.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_list.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_percent.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_percent.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_text.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_text.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_tree.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/utils/var_tree.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/vars/equalizer.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/vars/equalizer.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/vars/playtree.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/vars/playtree.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/vars/time.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/vars/time.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/vars/volume.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/vars/volume.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_dragdrop.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_dragdrop.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_factory.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_factory.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_graphics.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_graphics.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_loop.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_loop.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_popup.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_popup.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_timer.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_timer.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_tooltip.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_tooltip.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_window.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/win32/win32_window.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_display.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_display.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_dragdrop.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_dragdrop.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_factory.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_factory.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_graphics.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_graphics.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_loop.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_loop.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_popup.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_popup.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_timer.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_timer.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_tooltip.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_tooltip.hpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_window.cpp \
     ../../extras/package/macosx/../../../modules/gui/skins2/x11/x11_window.hpp \
     ../../extras/package/macosx/../../../modules/hw/d3d11/d3d11_filters.c \
     ../../extras/package/macosx/../../../modules/hw/d3d9/d3d9_filters.c \
     ../../extras/package/macosx/../../../modules/hw/mmal/codec.c \
     ../../extras/package/macosx/../../../modules/hw/mmal/deinterlace.c \
     ../../extras/package/macosx/../../../modules/hw/mmal/vout.c \
     ../../extras/package/macosx/../../../modules/hw/vaapi/filters.c \
     ../../extras/package/macosx/../../../modules/hw/vdpau/adjust.c \
     ../../extras/package/macosx/../../../modules/hw/vdpau/avcodec.c \
     ../../extras/package/macosx/../../../modules/hw/vdpau/chroma.c \
     ../../extras/package/macosx/../../../modules/hw/vdpau/deinterlace.c \
     ../../extras/package/macosx/../../../modules/hw/vdpau/display.c \
     ../../extras/package/macosx/../../../modules/hw/vdpau/sharpen.c \
     ../../extras/package/macosx/../../../modules/keystore/file.c \
     ../../extras/package/macosx/../../../modules/keystore/keychain.m \
     ../../extras/package/macosx/../../../modules/keystore/kwallet.c \
     ../../extras/package/macosx/../../../modules/keystore/memory.c \
     ../../extras/package/macosx/../../../modules/keystore/secret.c \
     ../../extras/package/macosx/../../../modules/logger/android.c \
     ../../extras/package/macosx/../../../modules/logger/console.c \
     ../../extras/package/macosx/../../../modules/logger/file.c \
     ../../extras/package/macosx/../../../modules/logger/journal.c \
     ../../extras/package/macosx/../../../modules/logger/syslog.c \
     ../../extras/package/macosx/../../../modules/lua/stream_filter.c \
     ../../extras/package/macosx/../../../modules/lua/extension.c \
     ../../extras/package/macosx/../../../modules/lua/libs/gettext.c \
     ../../extras/package/macosx/../../../modules/lua/intf.c \
     ../../extras/package/macosx/../../../modules/lua/libs/configuration.c \
     ../../extras/package/macosx/../../../modules/lua/libs.h \
     ../../extras/package/macosx/../../../modules/lua/libs/httpd.c \
     ../../extras/package/macosx/../../../modules/lua/vlc.c \
     ../../extras/package/macosx/../../../modules/meta_engine/folder.c \
     ../../extras/package/macosx/../../../modules/meta_engine/ID3Genres.h \
     ../../extras/package/macosx/../../../modules/meta_engine/taglib.cpp \
     ../../extras/package/macosx/../../../modules/misc/addons/fsstorage.c \
     ../../extras/package/macosx/../../../modules/misc/addons/vorepository.c \
     ../../extras/package/macosx/../../../modules/misc/audioscrobbler.c \
     ../../extras/package/macosx/../../../modules/misc/fingerprinter.c \
     ../../extras/package/macosx/../../../modules/misc/gnutls.c \
     ../../extras/package/macosx/../../../modules/misc/inhibit/dbus.c \
     ../../extras/package/macosx/../../../modules/misc/inhibit/iokit-inhibit.c \
     ../../extras/package/macosx/../../../modules/misc/inhibit/wl-idle-inhibit.c \
     ../../extras/package/macosx/../../../modules/misc/inhibit/xdg.c \
     ../../extras/package/macosx/../../../modules/misc/medialibrary/medialib.cpp \
     ../../extras/package/macosx/../../../modules/misc/playlist/export.c \
     ../../extras/package/macosx/../../../modules/misc/playlist/html.c \
     ../../extras/package/macosx/../../../modules/misc/playlist/m3u.c \
     ../../extras/package/macosx/../../../modules/misc/playlist/xspf.c \
     ../../extras/package/macosx/../../../modules/misc/rtsp.c \
     ../../extras/package/macosx/../../../modules/misc/securetransport.c \
     ../../extras/package/macosx/../../../modules/misc/stats.c \
     ../../extras/package/macosx/../../../modules/misc/xml/libxml.c \
     ../../extras/package/macosx/../../../modules/mux/asf.c \
     ../../extras/package/macosx/../../../modules/mux/avi.c \
     ../../extras/package/macosx/../../../modules/mux/dummy.c \
     ../../extras/package/macosx/../../../modules/mux/mp4/libmp4mux.c \
     ../../extras/package/macosx/../../../modules/mux/mp4/libmp4mux.h \
     ../../extras/package/macosx/../../../modules/mux/mp4/mp4.c \
     ../../extras/package/macosx/../../../modules/mux/mpeg/ps.c \
     ../../extras/package/macosx/../../../modules/mux/mpeg/ts.c \
     ../../extras/package/macosx/../../../modules/mux/mpjpeg.c \
     ../../extras/package/macosx/../../../modules/mux/ogg.c \
     ../../extras/package/macosx/../../../modules/mux/wav.c \
     ../../extras/package/macosx/../../../modules/notify/osx_notifications.m \
     ../../extras/package/macosx/../../../modules/notify/notify.c \
     ../../extras/package/macosx/../../../modules/packetizer/a52.c \
     ../../extras/package/macosx/../../../modules/packetizer/avparser.h \
     ../../extras/package/macosx/../../../modules/packetizer/av1.c \
     ../../extras/package/macosx/../../../modules/packetizer/copy.c \
     ../../extras/package/macosx/../../../modules/packetizer/dts.c \
     ../../extras/package/macosx/../../../modules/packetizer/flac.c \
     ../../extras/package/macosx/../../../modules/packetizer/h264.c \
     ../../extras/package/macosx/../../../modules/packetizer/hevc.c \
     ../../extras/package/macosx/../../../modules/packetizer/mlp.c \
     ../../extras/package/macosx/../../../modules/packetizer/mpeg4audio.c \
     ../../extras/package/macosx/../../../modules/packetizer/mpeg4video.c \
     ../../extras/package/macosx/../../../modules/packetizer/mpegaudio.c \
     ../../extras/package/macosx/../../../modules/packetizer/mpegvideo.c \
     ../../extras/package/macosx/../../../modules/packetizer/vc1.c \
     ../../extras/package/macosx/../../../modules/services_discovery/avahi.c \
     ../../extras/package/macosx/../../../modules/services_discovery/bonjour.m \
     ../../extras/package/macosx/../../../modules/services_discovery/microdns.c \
     ../../extras/package/macosx/../../../modules/services_discovery/mtp.c \
     ../../extras/package/macosx/../../../modules/services_discovery/os2drive.c \
     ../../extras/package/macosx/../../../modules/services_discovery/podcast.c \
     ../../extras/package/macosx/../../../modules/services_discovery/pulse.c \
     ../../extras/package/macosx/../../../modules/services_discovery/sap.c \
     ../../extras/package/macosx/../../../modules/services_discovery/udev.c \
     ../../extras/package/macosx/../../../modules/services_discovery/upnp.cpp \
     ../../extras/package/macosx/../../../modules/services_discovery/windrive.c \
     ../../extras/package/macosx/../../../modules/services_discovery/xcb_apps.c \
     ../../extras/package/macosx/../../../modules/spu/audiobargraph_v.c \
     ../../extras/package/macosx/../../../modules/spu/dynamicoverlay/dynamicoverlay.c \
     ../../extras/package/macosx/../../../modules/spu/logo.c \
     ../../extras/package/macosx/../../../modules/spu/marq.c \
     ../../extras/package/macosx/../../../modules/spu/mosaic.c \
     ../../extras/package/macosx/../../../modules/spu/rss.c \
     ../../extras/package/macosx/../../../modules/spu/subsdelay.c \
     ../../extras/package/macosx/../../../modules/stream_extractor/archive.c \
     ../../extras/package/macosx/../../../modules/stream_filter/adf.c \
     ../../extras/package/macosx/../../../modules/stream_filter/aribcam.c \
     ../../extras/package/macosx/../../../modules/stream_filter/cache_block.c \
     ../../extras/package/macosx/../../../modules/stream_filter/cache_read.c \
     ../../extras/package/macosx/../../../modules/stream_filter/decomp.c \
     ../../extras/package/macosx/../../../modules/stream_filter/hds/hds.c \
     ../../extras/package/macosx/../../../modules/stream_filter/inflate.c \
     ../../extras/package/macosx/../../../modules/stream_filter/prefetch.c \
     ../../extras/package/macosx/../../../modules/stream_filter/record.c \
     ../../extras/package/macosx/../../../modules/stream_filter/skiptags.c \
     ../../extras/package/macosx/../../../modules/stream_out/autodel.c \
     ../../extras/package/macosx/../../../modules/stream_out/bridge.c \
     ../../extras/package/macosx/../../../modules/stream_out/chromaprint.c \
     ../../extras/package/macosx/../../../modules/stream_out/chromecast/cast.cpp \
     ../../extras/package/macosx/../../../modules/stream_out/chromecast/chromecast_demux.cpp \
     ../../extras/package/macosx/../../../modules/stream_out/cycle.c \
     ../../extras/package/macosx/../../../modules/stream_out/delay.c \
     ../../extras/package/macosx/../../../modules/stream_out/description.c \
     ../../extras/package/macosx/../../../modules/stream_out/display.c \
     ../../extras/package/macosx/../../../modules/stream_out/dlna/dlna.hpp \
     ../../extras/package/macosx/../../../modules/stream_out/dummy.c \
     ../../extras/package/macosx/../../../modules/stream_out/duplicate.c \
     ../../extras/package/macosx/../../../modules/stream_out/es.c \
     ../../extras/package/macosx/../../../modules/stream_out/gather.c \
     ../../extras/package/macosx/../../../modules/stream_out/mosaic_bridge.c \
     ../../extras/package/macosx/../../../modules/stream_out/record.c \
     ../../extras/package/macosx/../../../modules/stream_out/renderer_common.hpp \
     ../../extras/package/macosx/../../../modules/stream_out/rtcp.c \
     ../../extras/package/macosx/../../../modules/stream_out/rtp.c \
     ../../extras/package/macosx/../../../modules/stream_out/rtpfmt.c \
     ../../extras/package/macosx/../../../modules/stream_out/rtp.h \
     ../../extras/package/macosx/../../../modules/stream_out/rtsp.c \
     ../../extras/package/macosx/../../../modules/stream_out/sdi/sdiout.cpp \
     ../../extras/package/macosx/../../../modules/stream_out/setid.c \
     ../../extras/package/macosx/../../../modules/stream_out/smem.c \
     ../../extras/package/macosx/../../../modules/stream_out/stats.c \
     ../../extras/package/macosx/../../../modules/stream_out/standard.c \
     ../../extras/package/macosx/../../../modules/stream_out/transcode/transcode.c \
     ../../extras/package/macosx/../../../modules/text_renderer/freetype/fonts/fontconfig.c \
     ../../extras/package/macosx/../../../modules/text_renderer/freetype/freetype.c \
     ../../extras/package/macosx/../../../modules/text_renderer/nsspeechsynthesizer.m \
     ../../extras/package/macosx/../../../modules/text_renderer/sapi.cpp \
     ../../extras/package/macosx/../../../modules/text_renderer/svg.c \
     ../../extras/package/macosx/../../../modules/text_renderer/tdummy.c \
     ../../extras/package/macosx/../../../modules/video_chroma/chain.c \
     ../../extras/package/macosx/../../../modules/video_chroma/cvpx.c \
     ../../extras/package/macosx/../../../modules/video_chroma/grey_yuv.c \
     ../../extras/package/macosx/../../../modules/video_chroma/i420_nv12.c \
     ../../extras/package/macosx/../../../modules/video_chroma/i420_rgb16.c \
     ../../extras/package/macosx/../../../modules/video_chroma/i420_rgb8.c \
     ../../extras/package/macosx/../../../modules/video_chroma/i420_rgb.c \
     ../../extras/package/macosx/../../../modules/video_chroma/i420_rgb_c.h \
     ../../extras/package/macosx/../../../modules/video_chroma/i420_rgb.h \
     ../../extras/package/macosx/../../../modules/video_chroma/i420_yuy2.c \
     ../../extras/package/macosx/../../../modules/video_chroma/i420_yuy2.h \
     ../../extras/package/macosx/../../../modules/video_chroma/i422_i420.c \
     ../../extras/package/macosx/../../../modules/video_chroma/i422_yuy2.c \
     ../../extras/package/macosx/../../../modules/video_chroma/i422_yuy2.h \
     ../../extras/package/macosx/../../../modules/video_chroma/omxdl.c \
     ../../extras/package/macosx/../../../modules/video_chroma/rv32.c \
     ../../extras/package/macosx/../../../modules/video_chroma/swscale.c \
     ../../extras/package/macosx/../../../modules/video_chroma/yuvp.c \
     ../../extras/package/macosx/../../../modules/video_chroma/yuy2_i420.c \
     ../../extras/package/macosx/../../../modules/video_chroma/yuy2_i422.c \
     ../../extras/package/macosx/../../../modules/video_filter/adjust.c \
     ../../extras/package/macosx/../../../modules/video_filter/alphamask.c \
     ../../extras/package/macosx/../../../modules/video_filter/anaglyph.c \
     ../../extras/package/macosx/../../../modules/video_filter/antiflicker.c \
     ../../extras/package/macosx/../../../modules/video_filter/ball.c \
     ../../extras/package/macosx/../../../modules/video_filter/blendbench.c \
     ../../extras/package/macosx/../../../modules/video_filter/blend.cpp \
     ../../extras/package/macosx/../../../modules/video_filter/bluescreen.c \
     ../../extras/package/macosx/../../../modules/video_filter/canvas.c \
     ../../extras/package/macosx/../../../modules/video_filter/ci_filters.m \
     ../../extras/package/macosx/../../../modules/video_filter/colorthres.c \
     ../../extras/package/macosx/../../../modules/video_filter/croppadd.c \
     ../../extras/package/macosx/../../../modules/video_filter/deinterlace/algo_phosphor.h \
     ../../extras/package/macosx/../../../modules/video_filter/deinterlace/deinterlace.c \
     ../../extras/package/macosx/../../../modules/video_filter/deinterlace/deinterlace.h \
     ../../extras/package/macosx/../../../modules/video_filter/edgedetection.c \
     ../../extras/package/macosx/../../../modules/video_filter/erase.c \
     ../../extras/package/macosx/../../../modules/video_filter/extract.c \
     ../../extras/package/macosx/../../../modules/video_filter/fps.c \
     ../../extras/package/macosx/../../../modules/video_filter/freeze.c \
     ../../extras/package/macosx/../../../modules/video_filter/gaussianblur.c \
     ../../extras/package/macosx/../../../modules/video_filter/gradfun.c \
     ../../extras/package/macosx/../../../modules/video_filter/gradient.c \
     ../../extras/package/macosx/../../../modules/video_filter/grain.c \
     ../../extras/package/macosx/../../../modules/video_filter/hqdn3d.c \
     ../../extras/package/macosx/../../../modules/video_filter/invert.c \
     ../../extras/package/macosx/../../../modules/video_filter/magnify.c \
     ../../extras/package/macosx/../../../modules/video_filter/mirror.c \
     ../../extras/package/macosx/../../../modules/video_filter/motionblur.c \
     ../../extras/package/macosx/../../../modules/video_filter/motiondetect.c \
     ../../extras/package/macosx/../../../modules/video_filter/oldmovie.c \
     ../../extras/package/macosx/../../../modules/video_filter/opencv_example.cpp \
     ../../extras/package/macosx/../../../modules/video_filter/opencv_wrapper.c \
     ../../extras/package/macosx/../../../modules/video_filter/posterize.c \
     ../../extras/package/macosx/../../../modules/video_filter/postproc.c \
     ../../extras/package/macosx/../../../modules/video_filter/psychedelic.c \
     ../../extras/package/macosx/../../../modules/video_filter/puzzle.c \
     ../../extras/package/macosx/../../../modules/video_filter/ripple.c \
     ../../extras/package/macosx/../../../modules/video_filter/rotate.c \
     ../../extras/package/macosx/../../../modules/video_filter/scale.c \
     ../../extras/package/macosx/../../../modules/video_filter/scene.c \
     ../../extras/package/macosx/../../../modules/video_filter/sepia.c \
     ../../extras/package/macosx/../../../modules/video_filter/sharpen.c \
     ../../extras/package/macosx/../../../modules/video_filter/transform.c \
     ../../extras/package/macosx/../../../modules/video_filter/vhs.c \
     ../../extras/package/macosx/../../../modules/video_filter/wave.c \
     ../../extras/package/macosx/../../../modules/video_output/android/window.c \
     ../../extras/package/macosx/../../../modules/video_output/caca.c \
     ../../extras/package/macosx/../../../modules/video_output/caopengllayer.m \
     ../../extras/package/macosx/../../../modules/video_output/decklink.cpp \
     ../../extras/package/macosx/../../../modules/video_output/drawable.c \
     ../../extras/package/macosx/../../../modules/video_output/fb.c \
     ../../extras/package/macosx/../../../modules/video_output/glx.c \
     ../../extras/package/macosx/../../../modules/video_output/ios.m \
     ../../extras/package/macosx/../../../modules/video_output/kva.c \
     ../../extras/package/macosx/../../../modules/video_output/macosx.m \
     ../../extras/package/macosx/../../../modules/video_output/opengl/display.c \
     ../../extras/package/macosx/../../../modules/video_output/opengl/egl.c \
     ../../extras/package/macosx/../../../modules/video_output/opengl/vout_helper.h \
     ../../extras/package/macosx/../../../modules/video_output/vulkan/display.c \
     ../../extras/package/macosx/../../../modules/video_output/win32/direct3d9.c \
     ../../extras/package/macosx/../../../modules/video_output/win32/direct3d11.c \
     ../../extras/package/macosx/../../../modules/video_output/win32/events.c \
     ../../extras/package/macosx/../../../modules/video_output/win32/glwin32.c \
     ../../extras/package/macosx/../../../modules/video_output/win32/window.c \
     ../../extras/package/macosx/../../../modules/video_output/win32/wingdi.c \
     ../../extras/package/macosx/../../../modules/video_output/win32/wgl.c \
     ../../extras/package/macosx/../../../modules/video_output/vdummy.c \
     ../../extras/package/macosx/../../../modules/video_output/vmem.c \
     ../../extras/package/macosx/../../../modules/video_output/wayland/shm.c \
     ../../extras/package/macosx/../../../modules/video_output/wayland/xdg-shell.c \
     ../../extras/package/macosx/../../../modules/video_output/xcb/render.c \
     ../../extras/package/macosx/../../../modules/video_output/xcb/window.c \
     ../../extras/package/macosx/../../../modules/video_output/xcb/x11.c \
     ../../extras/package/macosx/../../../modules/video_output/yuv.c \
     ../../extras/package/macosx/../../../modules/video_splitter/clone.c \
     ../../extras/package/macosx/../../../modules/video_splitter/panoramix.c \
     ../../extras/package/macosx/../../../modules/video_splitter/wall.c \
     ../../extras/package/macosx/../../../modules/visualization/glspectrum.c \
     ../../extras/package/macosx/../../../modules/visualization/goom.c \
     ../../extras/package/macosx/../../../modules/visualization/projectm.cpp \
     ../../extras/package/macosx/../../../modules/visualization/visual/visual.c \
     ../../extras/package/macosx/../../../modules/visualization/visual/window_presets.h \
     ../../extras/package/macosx/../../../modules/visualization/vsxu.cpp \
     ../../extras/package/macosx/../../../share/vlc.appdata.xml.in.in \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/batch_window.html \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/browse_window.html \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/create_stream.html \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/equalizer_window.html \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/error_window.html \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/mosaic_window.html \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/offset_window.html \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/stream_config_window.html \
     ../../extras/package/macosx/../../../share/lua/http/dialogs/stream_window.html \
     ../../extras/package/macosx/../../../share/lua/http/index.html \
     ../../extras/package/macosx/../../../share/lua/http/mobile_browse.html \
     ../../extras/package/macosx/../../../share/lua/http/mobile_equalizer.html \
     ../../extras/package/macosx/../../../share/lua/http/mobile.html \
     ../../extras/package/macosx/../../../share/lua/http/mobile_view.html

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
# Use /bin/sh, which is the shell determined by autoconf for the use by its
# scripts, not $(SHELL) which is hardwired to /bin/sh and may be deficient.
Makefile: Makefile.in.in Makevars $(top_builddir)/config.status POTFILES.in LINGUAS
	cd $(top_builddir) \
	  && /bin/sh ./config.status $(subdir)/$@.in po-directories

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
