# Created by: Josh Paetzel <josh@tcbug.org>

PORTNAME=	epic5
PORTVERSION=	2.1.7
CATEGORIES=	irc
MASTER_SITES=	http://ftp.epicsol.org/pub/epic/EPIC5-PRODUCTION/

MAINTAINER=	epic@dsllsn.net
COMMENT=	Enhanced Programmable IRC-II Client

LICENSE=	BSD3CLAUSE
LICENSE_FILE=	${WRKSRC}/COPYRIGHT

GNU_CONFIGURE=	yes
PLIST_SUB+=	PORTVERSION=${PORTVERSION}
CFLAGS:=	${CFLAGS:C/-O2/-O/g}

OPTIONS_DEFINE=	DOCS PERL RUBY TCL

CONFIGURE_ARGS+=--with-iconv=${ICONV_PREFIX}
USES=		iconv libarchive ncurses ssl tar:xz

PERL_USES=	perl5
PERL_CONFIGURE_WITH=	perl
RUBY_USE=	ruby=yes
RUBY_CONFIGURE_WITH=	ruby
TCL_USES=	tcl
TCL_CONFIGURE_ON=	--with-tcl=${TCL_LIBDIR}/tclConfig.sh
TCL_CONFIGURE_OFF=	--with-tcl=no

post-patch:
	@${REINPLACE_CMD} -e 's|-lcurses|-lncurses|' ${WRKSRC}/configure

post-install:
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/bin/epic5-${PORTVERSION}
	${STRIP_CMD} ${STAGEDIR}${PREFIX}/libexec/epic5-wserv4
	${MKDIR} ${STAGEDIR}${DOCSDIR}
.for i in BUG_FORM EPIC4-USERS-README FILES KNOWNBUGS README README-CRYPTO UPDATES WISHLIST
	${INSTALL_DATA} ${WRKSRC}/${i} ${STAGEDIR}${DOCSDIR}
.endfor
	(cd ${WRKSRC}/doc && ${COPYTREE_SHARE} . ${STAGEDIR}${DOCSDIR})

.include <bsd.port.mk>
