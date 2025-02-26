# Created by: Bruce M Simpson <bms@FreeBSD.org>

PORTNAME=	quagga
PORTVERSION=	1.2.4
PORTREVISION=	9
CATEGORIES=	net
MASTER_SITES=	https://github.com/Quagga/quagga/releases/download/${DISTNAME}/

MAINTAINER=	ports@FreeBSD.org
COMMENT=	Free RIPv1, RIPv2, OSPFv2, BGP4, IS-IS route software

LICENSE=	GPLv2+
LICENSE_FILE=	${WRKSRC}/COPYING

USES=		compiler:c11 cpe gmake libtool makeinfo \
		perl5 readline ssl

CONFLICTS=	frr7 openbgpd pimd zebra

GNU_CONFIGURE=	yes
CONFIGURE_ENV+=	GAWK=${AWK}

CFLAGS+=	-fcommon
INSTALL_TARGET=	install-strip
USE_LDCONFIG=	yes
USE_PERL5=	build

INFO=		quagga

OPTIONS_DEFINE=	ISISD PIMD PAM RTADV SNMP TCPSOCKETS DLMALLOC \
		NO_BGP_ANNOUNCE OSPF_NEXTHOP ISIS_TOPOLOGY EXAMPLES
# IRDP needs something freebsd does not seem to have:
# configure: error: 'IRDP requires in_pktinfo at the moment!'
OPTIONS_DEFAULT=	ISISD PIMD RTADV
OPTIONS_SUB=	yes

PIMD_DESC=		PIM-SSM multicast routing
IRDP_DESC=		Enable IRDP server support
ISISD_DESC=		Enable ISIS daemon (beta)
ISIS_TOPOLOGY_DESC=	Enable IS-IS topology generator
PAM_DESC=		PAM authentication for vtysh
RTADV_DESC=		IPv6 Router Advertisements
TCPSOCKETS_DESC=	Use TCP/IP sockets for protocol daemons
DLMALLOC_DESC=		Use dlmalloc (makes bgpd much faster)
NO_BGP_ANNOUNCE_DESC=	Turn off BGP route announcement
OSPF_NEXTHOP_DESC=	Set ip next-hop in OSPF route maps

ENABLE_USER?=	quagga
ENABLE_GROUP?=	quagga

USERS=		${ENABLE_USER}
GROUPS=		${ENABLE_GROUP}

SYSCONF_DIR?=	${ETCDIR}
LOCALSTATE_DIR?=/var/run/quagga

CONFIGURE_ARGS=	--enable-user=${ENABLE_USER} \
		--enable-group=${ENABLE_GROUP} \
		--sysconfdir=${SYSCONF_DIR} \
		--localstatedir=${LOCALSTATE_DIR} \
		--enable-vtysh

.if defined(ENABLE_VTY_GROUP)
CONFIGURE_ARGS+=--enable-vty-group=${ENABLE_VTY_GROUP}
.endif

EXAMPLES_CONFIGURE_ON=	--enable-exampledir=${PREFIX}/share/examples/quagga
EXAMPLES_CONFIGURE_OFF=	--disable-exampledir

ISISD_CONFIGURE_ENABLE=	isisd
ISIS_TOPOLOGY_CONFIGURE_ENABLE=	isis-topology
PIMD_CONFIGURE_ENABLE=	pimd
IRDP_CONFIGURE_ENABLE=	irdp
PAM_CONFIGURE_WITH=	libpam
RTADV_CONFIGURE_ENABLE=	rtadv
SNMP_CONFIGURE_ENABLE=	snmp
SNMP_LIB_DEPENDS=	libnetsnmp.so:net-mgmt/net-snmp
TCPSOCKETS_CONFIGURE_ENABLE=	tcp-zebra
DLMALLOC_LIB_DEPENDS=	libdlmalloc.so:devel/libdlmalloc
DLMALLOC_LIBS=		-L${LOCALBASE}/lib -ldlmalloc
OSPF_NEXTHOP_EXTRA_PATCHES=	${PATCHDIR}/extra-patch-ospf-nexthop
# inverse option.
NO_BGP_ANNOUNCE_CONFIGURE_ON=	--disable-bgp-announce
NO_BGP_ANNOUNCE_CONFIGURE_OFF=	--enable-bgp-announce

USE_RC_SUBR=	quagga watchquagga

SUB_LIST+=	LOCALSTATE_DIR=${LOCALSTATE_DIR} \
		SYSCONF_DIR=${SYSCONF_DIR}

PLIST_SUB+=	LOCALSTATE_DIR=${LOCALSTATE_DIR} \
		SYSCONF_DIR=${SYSCONF_DIR} \
		ENABLE_USER=${ENABLE_USER} \
		ENABLE_GROUP=${ENABLE_GROUP}

pre-everything::
	@${ECHO} "============================================================="
	@${ECHO}
	@${ECHO} "You can build ${PORTNAME} with the following options:"
	@${ECHO}
	@${ECHO} "ENABLE_USER       Specify user to run Quagga suite as"
	@${ECHO} "ENABLE_GROUP      Specify group to run Quagga suite as"
	@${ECHO} "ENABLE_VTY_GROUP  Specify group for vty socket ownership"
	@${ECHO} "SYSCONF_DIR       Specify directory for Quagga configuration files"
	@${ECHO} "LOCALSTATE_DIR    Specify directory for Quagga runtime files"

post-install:
	${MKDIR} ${STAGEDIR}${LOCALSTATE_DIR} ${STAGEDIR}${SYSCONF_DIR}

.include <bsd.port.mk>
