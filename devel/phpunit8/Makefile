PORTNAME=	phpunit
DISTVERSION=	8.5.25
CATEGORIES=	devel www
MASTER_SITES=	https://phar.phpunit.de/
PKGNAMESUFFIX=	8${PHP_PKGNAMESUFFIX}
EXTRACT_SUFX=	.phar

MAINTAINER=	joneum@FreeBSD.org
COMMENT=	Testing framework for unit tests

LICENSE=	BSD3CLAUSE

CONFLICTS_INSTALL=	phpunit7

USES=		cpe php:flavors
CPE_VENDOR=	phpunit_project
USE_PHP=	dom json spl pcre phar

NO_ARCH=	yes
NO_BUILD=	yes

PLIST_FILES=	bin/phpunit

# Download isn't compressed or aggregated, it's just the single file
do-extract:
	${CP} ${DISTDIR}/${DISTFILES} ${WRKDIR}/${PORTNAME}

do-install:
	${INSTALL_SCRIPT} ${WRKDIR}/${PORTNAME} \
		${STAGEDIR}${PREFIX}/bin/${PORTNAME}

.include <bsd.port.mk>
