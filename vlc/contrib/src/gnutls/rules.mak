# GnuTLS

GNUTLS_VERSION := 3.6.7.1
GNUTLS_URL := https://www.gnupg.org/ftp/gcrypt/gnutls/v3.6/gnutls-$(GNUTLS_VERSION).tar.xz

ifdef BUILD_NETWORK
ifndef HAVE_DARWIN_OS
PKGS += gnutls
endif
endif
ifeq ($(call need_pkg,"gnutls >= 3.5.0"),)
PKGS_FOUND += gnutls
endif

$(TARBALLS)/gnutls-$(GNUTLS_VERSION).tar.xz:
	$(call download_pkg,$(GNUTLS_URL),gnutls)

.sum-gnutls: gnutls-$(GNUTLS_VERSION).tar.xz

# gnutls 3.6.7.1 unpacks into a dir named 3.6.7
gnutls: UNPACK_DIR=gnutls-3.6.7
gnutls: gnutls-$(GNUTLS_VERSION).tar.xz .sum-gnutls
	$(UNPACK)
	$(APPLY) $(SRC)/gnutls/gnutls-pkgconfig-static.patch
ifdef HAVE_WIN32
	$(APPLY) $(SRC)/gnutls/gnutls-win32.patch
endif
ifdef HAVE_ANDROID
	$(APPLY) $(SRC)/gnutls/no-create-time-h.patch
endif
	$(call pkg_static,"lib/gnutls.pc.in")
	$(UPDATE_AUTOCONFIG)
	$(MOVE)

GNUTLS_CONF := \
	--disable-gtk-doc \
	--without-p11-kit \
	--disable-cxx \
	--disable-srp-authentication \
	--disable-anon-authentication \
	--disable-openssl-compatibility \
	--disable-guile \
	--disable-nls \
	--without-libintl-prefix \
	--disable-doc \
	--disable-tests \
	--with-included-libtasn1 \
	--with-included-unistring \
	$(HOSTCONF)

GNUTLS_ENV := $(HOSTVARS)

DEPS_gnutls = nettle $(DEPS_nettle)

ifdef HAVE_ANDROID
GNUTLS_ENV += gl_cv_header_working_stdint_h=yes
endif
ifdef HAVE_WINSTORE
ifeq ($(ARCH),x86_64)
	GNUTLS_CONF += --disable-hardware-acceleration
endif
endif
ifdef HAVE_WIN32
	GNUTLS_CONF += --without-idn
ifeq ($(ARCH),aarch64)
	# Gnutls' aarch64 assembly unconditionally uses ELF specific directives
	GNUTLS_CONF += --disable-hardware-acceleration
endif
endif

ifdef HAVE_NACL
	GNUTLS_CONF += --disable-hardware-acceleration
endif

.gnutls: gnutls
	cd $< && $(GNUTLS_ENV) ./configure $(GNUTLS_CONF)
	cd $< && $(MAKE) -C gl install
	cd $< && $(MAKE) -C lib install
	touch $@
