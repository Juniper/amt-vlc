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


srcdir = /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../po
top_srcdir = /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../..
VPATH = /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../po

prefix = /Users/nlandsberg/Desktop/development/vlc/build/vlc_install_dir
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
# ${SHELL} /Users/nlandsberg/Desktop/development/vlc/autotools/install-sh does not start with $(SHELL), so we add it.
# In automake >= 1.10, $(MKDIR_P) is derived from ${MKDIR_P}, which is defined
# either as "/path/to/mkdir -p" or ".../install-sh -c -d". For these automake
# versions, $(mkinstalldirs) and $(install_sh) are unused.
mkinstalldirs = $(SHELL) ${SHELL} /Users/nlandsberg/Desktop/development/vlc/autotools/install-sh -d
install_sh = $(SHELL) ${SHELL} /Users/nlandsberg/Desktop/development/vlc/autotools/install-sh
MKDIR_P = /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../autotools/install-sh -c -d
mkdir_p = $(MKDIR_P)

# When building gettext-tools, we prefer to use the built programs
# rather than installed programs.  However, we can't do that when we
# are cross compiling.
CROSS_COMPILING = @CROSS_COMPILING@

GMSGFMT_ = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/msgfmt
GMSGFMT_no = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/msgfmt
GMSGFMT_yes = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/msgfmt
GMSGFMT = $(GMSGFMT_$(USE_MSGCTXT))
MSGFMT_ = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/msgfmt
MSGFMT_no = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/msgfmt
MSGFMT_yes = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/msgfmt
MSGFMT = $(MSGFMT_$(USE_MSGCTXT))
XGETTEXT_ = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/xgettext
XGETTEXT_no = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/xgettext
XGETTEXT_yes = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/xgettext
XGETTEXT = $(XGETTEXT_$(USE_MSGCTXT))
MSGMERGE = msgmerge
MSGMERGE_UPDATE = /Users/nlandsberg/Desktop/development/vlc/extras/tools/build/bin/msgmerge --update
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
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_access.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_actions.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_aout.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_arrays.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_bits.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_block.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_block_helper.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_charset.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_codec.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_codecs.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_common.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_config.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_config_cat.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_configuration.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_demux.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc/deprecated.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_epg.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_es.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_es_out.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_events.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_filter.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_fixups.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_gcrypt.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_httpd.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_image.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_input.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_intf_strings.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_iso_lang.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_md5.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_messages.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_meta.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_modules.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_tick.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_network.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_objects.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_pgpkey.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_playlist.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_plugin.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_rand.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_services_discovery.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_sout.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_stream.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_strings.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_threads.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_tls.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_update.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_url.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_variables.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc/vlc.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_vlm.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_vod.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_vout.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_vout_window.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../include/vlc_xml.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/audio_output/aout_internal.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/audio_output/common.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/audio_output/dec.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/audio_output/filters.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/audio_output/output.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/config/chain.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/config/cmdline.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/config/configuration.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/config/core.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/config/file.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/config/help.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/config/intf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/darwin/error.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/extras/libc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/access.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/control.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/decoder.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/decoder.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/demux.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/demux.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/es_out.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/es_out.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/input.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/input_internal.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/item.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/meta.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/stream.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/stream.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/stream_memory.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/subtitles.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/var.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/vlm.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/vlm_internal.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/input/vlmshell.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/interface/interface.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/libvlc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/libvlc.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/libvlc-module.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/actions.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/block.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/cpu.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/error.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/es_format.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/events.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/filter_chain.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/image.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/md5.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/messages.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/mtime.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/objects.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/rand.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/threads.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/update.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/update.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/variables.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/variables.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/misc/xml.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/missing.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/modules/cache.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/modules/entry.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/modules/modules.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/modules/modules.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/network/getaddrinfo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/network/httpd.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/network/io.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/network/rootbind.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/network/tcp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/network/tls.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/network/udp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/control.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/engine.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/item.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/loadsave.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/playlist_internal.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/search.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/sort.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/thread.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/playlist/tree.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/stream_output/sap.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/stream_output/sdp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/stream_output/stream_output.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/stream_output/stream_output.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/text/iso-639_def.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/version.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/video_output/interlacing.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/video_output/video_output.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/video_output/video_text.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/video_output/video_widgets.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/video_output/vout_internal.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/video_output/vout_intf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/video_output/vout_subpictures.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../src/win32/thread.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/audio.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/core.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/event.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/libvlc_internal.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/log.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/media.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/media_discoverer.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/media_library.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/media_list.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/media_list_path.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/media_list_player.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/media_player.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/playlist.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../lib/video.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/alsa.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/avcapture.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/avio.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/bluray.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/cdda.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/concat.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dc1394.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dcp/dcp.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/decklink.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dshow/dshow.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dsm/access.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dsm/sd.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dtv/access.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dvb/access.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dvb/scan.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dvdnav.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/dvdread.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/fs.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/ftp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/http.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/http/access.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/idummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/imem.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/imem-access.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/jack.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/linsys/linsys_hdsdi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/linsys/linsys_sdi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/live555.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/mms/mms.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/mtp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/nfs.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/oss.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/pulse.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/qtsound.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/rdp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/rtp/rtp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/samba.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/satip.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/screen/screen.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/screen/wayland.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/screen/xcb.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/sdp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/sftp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/shm.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/smb_common.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/smb2.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/srt.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/tcp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/timecode.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/udp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/unc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/v4l2/controls.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/v4l2/v4l2.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/vcd/vcd.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/vdr.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/vnc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access/wasapi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access_output/dummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access_output/file.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access_output/http.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access_output/livehttp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access_output/shout.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access_output/srt.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/access_output/udp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/arm_neon/chroma_yuv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/arm_neon/volume.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/arm_neon/yuv_rgb.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/audiobargraph_a.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/channel_mixer/dolby.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/channel_mixer/headphone.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/channel_mixer/mono.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/channel_mixer/remap.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/channel_mixer/simple.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/channel_mixer/spatialaudio.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/channel_mixer/trivial.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/chorus_flanger.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/compressor.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/converter/format.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/converter/tospdif.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/equalizer.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/equalizer_presets.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/gain.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/karaoke.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/normvol.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/param_eq.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/resampler/bandlimited.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/resampler/soxr.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/resampler/speex.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/resampler/src.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/resampler/ugly.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/scaletempo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/spatializer/spatializer.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_filter/stereo_widen.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_mixer/float.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_mixer/integer.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/adummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/alsa.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/amem.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/audiotrack.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/audiounit_ios.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/auhal.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/coreaudio_common.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/directsound.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/file.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/jack.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/kai.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/mmdevice.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/opensles_android.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/oss.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/pulse.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/sndio.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/vlcpulse.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/tizen_audio.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/volume.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/wasapi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/waveout.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/windows_audio_common.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/audio_output/winstore.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/a52.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/adpcm.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/aes3.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/aom.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/araw.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/audiotoolbox_midi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/arib/aribsub.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/avcodec/avcodec.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/avcodec/avcodec.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/avcodec/d3d11va.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/avcodec/dxva2.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/avcodec/encoder.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/avcodec/vaapi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/bpg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/cc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/cdg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/cea708.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/cea708.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/crystalhd.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/cvdsub.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/daala.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/dca.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/ddummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/dmo/dmo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/dvbsub.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/edummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/faad.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/fdkaac.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/flac.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/fluidsynth.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/g711.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/gstreamer/gstdecode.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/jpeg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/kate.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/libass.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/libmpeg2.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/lpcm.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/mad.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/mft.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/mpg123.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/oggspots.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/omxil/mediacodec.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/omxil/omxil.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/opus.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/png.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/qsv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/rawvideo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/rtpvideo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/schroedinger.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/scte18.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/scte18.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/scte27.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/sdl_image.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/shine.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/spdif.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/speex.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/spudec/spudec.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/stl.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/subsdec.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/subsusf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/substx3g.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/svcdsub.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/svg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/t140.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/telx.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/textst.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/theora.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/ttml/substtml.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/ttml/ttml.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/ttml/ttml.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/twolame.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/uleaddvaudio.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/videotoolbox.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/vorbis.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/vpx.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/webvtt/webvtt.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/wmafixed/wma.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/x264.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/x265.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/xwd.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/codec/zvbi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/dbus/dbus.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/dbus/dbus_root.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/dummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/gestures.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/globalhotkeys/win32.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/globalhotkeys/xcb.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/hotkeys.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/intromsg.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/lirc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/motion.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/netsync.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/ntservice.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/oldrc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/control/win_msg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/adaptive/adaptive.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/aiff.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/asf/asf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/au.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/avformat/avformat.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/avformat/avformat.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/avi/avi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/avi/libavi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/avi/libavi.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/caf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/cdg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/demuxdump.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/directory.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/filter/noseek.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/flac.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/gme.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/image.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mjpeg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mkv/mkv.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mod.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mp4/libmp4.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mp4/libmp4.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mp4/meta.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mp4/mp4.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mpc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mpeg/es.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mpeg/h26x.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mpeg/mpgv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mpeg/ps.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mpeg/ts.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/mpeg/ts_descriptions.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/nsc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/nsv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/nuv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/ogg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/asx.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/b4s.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/dvb.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/ifo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/itml.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/itml.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/m3u.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/playlist.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/playlist.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/pls.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/podcast.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/qtl.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/ram.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/sgimb.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/wpl.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/playlist/xspf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/pva.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/rawaud.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/rawdv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/rawvid.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/sid.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/smf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/stl.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/subtitle.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/tta.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/ttml.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/ty.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/vc1.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/vobsub.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/voc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/wav.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/webvtt.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/xa.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/xiph.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/xiph_metadata.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/demux/xiph_metadata.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCAboutWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCAboutWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCAddonListItem.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCAddonListItem.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCAddonsWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCAddonsWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCApplication.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCApplication.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCAudioEffectsWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCAudioEffectsWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCBookmarksWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCBookmarksWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCBottomBarView.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCBottomBarView.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCControlsBarCommon.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCControlsBarCommon.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCConvertAndSaveWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCConvertAndSaveWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCCoreDialogProvider.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCCoreDialogProvider.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCCoreInteraction.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCCoreInteraction.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCDefaultValueSlider.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCDefaultValueSlider.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCDefaultValueSliderCell.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCDefaultValueSliderCell.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCDocumentController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCDocumentController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCErrorWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCErrorWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCExtensionsDialogProvider.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCExtensionsDialogProvider.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCExtensionsManager.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCExtensionsManager.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCFSPanelController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCFSPanelController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/helpers.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/macosx.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMain.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMain.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMain+OldPrefs.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMain+OldPrefs.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMain.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMain.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMainMenu.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMainMenu.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMainWindow.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMainWindow.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMainWindowControlsBar.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCMainWindowControlsBar.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCOpenWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCOpenWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCOutput.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCOutput.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPLItem.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPLItem.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPLModel.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPLModel.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPlaylist.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPlaylist.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPlaylistInfo.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPlaylistInfo.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPlaylistView.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPlaylistView.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPopupPanelController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCPopupPanelController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCRendererDiscovery.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCRendererDiscovery.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCRendererItem.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCRendererItem.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCRendererMenuController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCRendererMenuController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCResumeDialogController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCResumeDialogController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCScrollingClipView.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCScrollingClipView.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCSimplePrefsController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCSimplePrefsController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCSimplePrefsWindow.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCSimplePrefsWindow.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCSlider.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCSlider.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCSliderCell.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCSliderCell.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCStatusBarIcon.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCStatusBarIcon.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCStringUtility.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCStringUtility.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCTextfieldPanelController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCTextfieldPanelController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCTimeField.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCTimeField.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCTimeSelectionPanelController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCTimeSelectionPanelController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCTrackSynchronizationWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCTrackSynchronizationWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCUIWidgets.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCUIWidgets.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVideoEffectsWindowController.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVideoEffectsWindowController.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVideoWindowCommon.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVideoWindowCommon.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVolumeSlider.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVolumeSlider.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVolumeSliderCell.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVolumeSliderCell.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVoutView.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVoutView.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVideoOutputProvider.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCVideoOutputProvider.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCWindow.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCWindow.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCWrappableTextField.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/VLCWrappableTextField.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/applescript.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/applescript.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/helpers.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/iTunes.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/macosx.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/misc.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/misc.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/prefs.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/prefs.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/prefs_widgets.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/macosx/prefs_widgets.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/minimal_macosx/VLCMinimalVoutWindow.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/minimal_macosx/VLCMinimalVoutWindow.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/minimal_macosx/intf.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/minimal_macosx/intf.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/minimal_macosx/macosx.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/ncurses.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/actions_manager.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/actions_manager.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/adapters/chromaprint.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/adapters/chromaprint.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/adapters/seekpoints.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/adapters/seekpoints.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/adapters/variables.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/adapters/variables.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/complete_preferences.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/complete_preferences.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/controller.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/controller.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/controller_widget.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/controller_widget.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/custom_menus.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/custom_menus.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGChannels.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGChannels.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGItem.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGItem.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGProgram.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGProgram.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGRuler.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGRuler.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGView.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGView.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGWidget.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/epg/EPGWidget.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/extended_panels.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/extended_panels.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/info_panels.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/info_panels.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/info_widgets.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/info_widgets.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/interface_widgets.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/interface_widgets.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/open_panels.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/open_panels.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/playlist.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/playlist.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/playlist_item.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/playlist_item.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/playlist_model.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/playlist_model.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/selector.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/selector.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/sorting.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/standardpanel.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/standardpanel.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/views.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/views.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/vlc_model.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/playlist/vlc_model.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/preferences_widgets.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/preferences_widgets.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/simple_preferences.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/simple_preferences.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/sout/profile_selector.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/sout/profile_selector.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/sout/profiles.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/sout/sout_widgets.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/components/sout/sout_widgets.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/bookmarks.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/bookmarks.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/convert.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/convert.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/epg.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/epg.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/errors.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/errors.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/extended.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/extended.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/extensions.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/extensions.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/external.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/external.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/fingerprintdialog.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/fingerprintdialog.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/firstrun.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/firstrun.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/gototime.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/gototime.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/help.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/help.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/mediainfo.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/mediainfo.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/messages.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/messages.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/open.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/open.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/openurl.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/openurl.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/playlist.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/playlist.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/plugins.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/plugins.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/podcast_configuration.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/podcast_configuration.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/preferences.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/preferences.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/sout.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/sout.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/toolbar.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/toolbar.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/vlm.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs/vlm.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs_provider.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/dialogs_provider.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/extensions_manager.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/extensions_manager.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/input_manager.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/input_manager.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/main_interface.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/main_interface.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/main_interface_win32.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/main_interface_win32.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/managers/addons_manager.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/managers/addons_manager.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/menus.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/menus.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/qt.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/qt.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/recents.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/recents.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/styles/seekstyle.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/styles/seekstyle.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/animators.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/animators.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/buttons/BrowseButton.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/buttons/BrowseButton.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/buttons/DeckButtonsLayout.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/buttons/DeckButtonsLayout.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/buttons/RoundButton.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/buttons/RoundButton.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/customwidgets.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/customwidgets.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/imagehelper.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/imagehelper.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/input_slider.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/input_slider.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/pictureflow.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/pictureflow.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/qmenuview.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/qmenuview.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/qt_dirs.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/qt_dirs.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/qvlcapp.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/qvlcframe.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/registry.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/registry.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/searchlineedit.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/searchlineedit.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/singleton.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/timetooltip.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/timetooltip.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/validators.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/qt/util/validators.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/async_queue.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/async_queue.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_add_item.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_add_item.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_audio.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_audio.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_callbacks.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_change_skin.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_change_skin.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_dialogs.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_dummy.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_dvd.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_dvd.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_fullscreen.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_fullscreen.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_generic.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_input.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_input.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_layout.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_layout.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_minimize.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_minimize.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_muxer.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_muxer.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_on_top.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_on_top.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_playlist.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_playlist.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_playtree.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_playtree.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_quit.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_quit.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_resize.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_resize.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_show_window.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_snapshot.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_snapshot.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_vars.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/commands/cmd_vars.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_button.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_button.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_checkbox.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_checkbox.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_flat.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_generic.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_generic.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_image.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_image.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_list.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_list.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_move.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_move.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_radialslider.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_radialslider.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_resize.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_resize.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_slider.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_slider.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_text.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_text.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_tree.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_tree.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_video.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/controls/ctrl_video.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_dragndrop.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_enter.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_focus.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_generic.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_input.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_input.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_key.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_key.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_leave.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_menu.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_motion.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_mouse.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_mouse.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_refresh.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_scroll.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_scroll.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_special.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/events/evt_special.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/builder.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/builder_data.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/builder.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/expr_evaluator.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/expr_evaluator.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/interpreter.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/interpreter.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/skin_parser.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/skin_parser.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/xmlparser.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/parser/xmlparser.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/anchor.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/anchor.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/anim_bitmap.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/anim_bitmap.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/bitmap_font.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/bitmap_font.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/dialogs.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/dialogs.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/file_bitmap.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/file_bitmap.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/ft2_bitmap.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/ft2_bitmap.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/ft2_font.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/ft2_font.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/generic_bitmap.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/generic_bitmap.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/generic_font.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/generic_layout.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/generic_layout.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/generic_window.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/generic_window.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/ini_file.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/ini_file.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/logger.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/logger.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/os_factory.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/os_factory.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/os_graphics.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/os_loop.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/os_popup.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/os_timer.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/os_tooltip.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/os_window.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/popup.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/popup.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/scaled_bitmap.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/scaled_bitmap.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/skin_common.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/skin_main.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/theme.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/theme.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/theme_loader.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/theme_loader.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/theme_repository.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/theme_repository.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/tooltip.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/tooltip.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/top_window.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/top_window.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/var_manager.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/var_manager.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/vlcproc.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/vlcproc.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/vout_window.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/vout_window.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/window_manager.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/src/window_manager.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/bezier.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/bezier.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/fsm.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/fsm.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/observer.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/pointer.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/position.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/position.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/ustring.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/ustring.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_bool.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_bool.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/variable.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_list.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_list.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_percent.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_percent.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_text.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_text.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_tree.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/utils/var_tree.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/vars/equalizer.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/vars/equalizer.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/vars/playtree.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/vars/playtree.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/vars/time.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/vars/time.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/vars/volume.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/vars/volume.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_dragdrop.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_dragdrop.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_factory.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_factory.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_graphics.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_graphics.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_loop.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_loop.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_popup.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_popup.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_timer.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_timer.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_tooltip.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_tooltip.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_window.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/win32/win32_window.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_display.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_display.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_dragdrop.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_dragdrop.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_factory.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_factory.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_graphics.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_graphics.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_loop.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_loop.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_popup.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_popup.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_timer.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_timer.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_tooltip.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_tooltip.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_window.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/gui/skins2/x11/x11_window.hpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/d3d11/d3d11_filters.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/d3d9/d3d9_filters.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/mmal/codec.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/mmal/deinterlace.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/mmal/vout.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/vaapi/filters.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/vdpau/adjust.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/vdpau/avcodec.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/vdpau/chroma.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/vdpau/deinterlace.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/vdpau/display.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/hw/vdpau/sharpen.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/keystore/file.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/keystore/keychain.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/keystore/kwallet.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/keystore/memory.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/keystore/secret.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/logger/android.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/logger/console.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/logger/file.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/logger/journal.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/logger/syslog.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/lua/demux.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/lua/extension.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/lua/libs/gettext.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/lua/intf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/lua/libs/configuration.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/lua/libs.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/lua/libs/httpd.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/lua/vlc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/meta_engine/folder.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/meta_engine/ID3Genres.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/meta_engine/taglib.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/addons/fsstorage.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/addons/vorepository.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/audioscrobbler.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/fingerprinter.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/gnutls.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/inhibit/dbus.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/inhibit/wl-idle-inhibit.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/inhibit/xdg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/medialibrary/medialib.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/playlist/export.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/playlist/html.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/playlist/m3u.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/playlist/xspf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/rtsp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/securetransport.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/stats.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/misc/xml/libxml.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/asf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/avi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/dummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/mp4/libmp4mux.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/mp4/libmp4mux.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/mp4/mp4.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/mpeg/ps.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/mpeg/ts.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/mpjpeg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/ogg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/mux/wav.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/notify/osx_notifications.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/notify/notify.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/a52.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/avparser.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/copy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/dts.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/flac.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/h264.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/hevc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/mlp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/mpeg4audio.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/mpeg4video.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/mpegaudio.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/mpegvideo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/packetizer/vc1.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/avahi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/bonjour.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/mediadirs.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/microdns.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/mtp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/os2drive.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/podcast.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/pulse.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/sap.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/udev.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/upnp.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/windrive.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/services_discovery/xcb_apps.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/spu/audiobargraph_v.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/spu/dynamicoverlay/dynamicoverlay.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/spu/logo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/spu/marq.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/spu/mosaic.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/spu/remoteosd.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/spu/rss.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/spu/subsdelay.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_extractor/archive.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/adf.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/aribcam.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/cache_block.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/cache_read.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/decomp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/hds/hds.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/inflate.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/prefetch.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/record.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_filter/skiptags.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/autodel.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/bridge.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/chromaprint.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/chromecast/cast.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/chromecast/chromecast_demux.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/cycle.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/delay.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/description.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/display.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/dummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/duplicate.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/es.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/gather.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/mosaic_bridge.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/record.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/rtcp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/rtp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/rtpfmt.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/rtp.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/rtsp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/setid.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/smem.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/stats.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/standard.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/stream_out/transcode/transcode.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/text_renderer/freetype/fonts/fontconfig.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/text_renderer/freetype/freetype.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/text_renderer/nsspeechsynthesizer.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/text_renderer/sapi.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/text_renderer/svg.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/text_renderer/tdummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/chain.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/cvpx.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/grey_yuv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i420_nv12.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i420_rgb16.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i420_rgb8.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i420_rgb.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i420_rgb_c.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i420_rgb.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i420_yuy2.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i420_yuy2.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i422_i420.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i422_yuy2.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/i422_yuy2.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/omxdl.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/rv32.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/swscale.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/yuvp.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/yuy2_i420.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_chroma/yuy2_i422.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/adjust.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/alphamask.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/anaglyph.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/antiflicker.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/ball.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/blendbench.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/blend.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/bluescreen.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/canvas.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/ci_filters.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/colorthres.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/croppadd.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/deinterlace/algo_phosphor.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/deinterlace/deinterlace.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/deinterlace/deinterlace.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/edgedetection.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/erase.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/extract.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/fps.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/freeze.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/gaussianblur.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/gradfun.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/gradient.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/grain.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/hqdn3d.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/invert.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/magnify.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/mirror.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/motionblur.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/motiondetect.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/oldmovie.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/opencv_example.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/opencv_wrapper.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/posterize.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/postproc.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/psychedelic.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/puzzle.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/ripple.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/rotate.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/scale.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/scene.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/sepia.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/sharpen.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/transform.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/vhs.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_filter/wave.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/android/window.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/caca.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/caopengllayer.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/decklink.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/drawable.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/fb.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/glx.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/ios.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/kva.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/macosx.m \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/opengl/display.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/opengl/egl.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/opengl/vout_helper.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/win32/direct3d9.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/win32/direct3d11.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/win32/directdraw.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/win32/events.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/win32/glwin32.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/win32/wingdi.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/win32/wgl.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/vdummy.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/vmem.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/wayland/shm.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/wayland/xdg-shell.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/xcb/window.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/xcb/x11.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/xcb/xvideo.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_output/yuv.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_splitter/clone.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_splitter/panoramix.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/video_splitter/wall.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/visualization/glspectrum.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/visualization/goom.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/visualization/projectm.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/visualization/visual/visual.c \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/visualization/visual/window_presets.h \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../modules/visualization/vsxu.cpp \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/vlc.appdata.xml.in.in \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/batch_window.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/browse_window.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/create_stream.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/equalizer_window.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/error_window.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/mosaic_window.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/offset_window.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/stream_config_window.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/dialogs/stream_window.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/index.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/mobile_browse.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/mobile_equalizer.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/mobile.html \
     /Users/nlandsberg/Desktop/development/vlc/extras/package/macosx/../../../share/lua/http/mobile_view.html

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
