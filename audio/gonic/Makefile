PORTNAME=	gonic
PORTVERSION=	0.13.1
DISTVERSIONPREFIX=	v
PORTREVISION=	1
CATEGORIES=	audio net

MAINTAINER=	bapt@FreeBSD.org
COMMENT=	Music streaming server / subsonic server API implementation

LICENSE=	GPLv3
LICENSE_FILE=	${WRKSRC}/LICENSE

LIB_DEPENDS=	libtag.so:audio/taglib

USES=		go:modules openal pkgconfig

USE_RC_SUBR=	${PORTNAME}

USE_GITHUB=	yes
GH_ACCOUNT=	sentriz
GO_TARGET=	./cmd/gonic

.include "${.CURDIR}/go-mod.mk"

USERS=		${PORTNAME}
GROUPS=		${PORTNAME}

PLIST_FILES=	bin/gonic

.include <bsd.port.mk>
