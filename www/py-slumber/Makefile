# Created by: Kubilay Kocak <koobs@FreeBSD.org>

PORTNAME=	slumber
PORTVERSION=	0.7.1
CATEGORIES=	www python
PKGNAMEPREFIX=	${PYTHON_PKGNAMEPREFIX}

MAINTAINER=	bofh@FreeBSD.org
COMMENT=	Library that makes consuming a REST API easier and more convenient

LICENSE=	BSD2CLAUSE
LICENSE_FILE=	${WRKSRC}/LICENSE.txt

RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}requests>0:www/py-requests@${PY_FLAVOR}
TEST_DEPENDS=	${PYTHON_PKGNAMEPREFIX}mock>0:devel/py-mock@${PY_FLAVOR}

OPTIONS_DEFINE=	YAML

YAML_DESC=		YAML serializer support
YAML_RUN_DEPENDS=	${PYTHON_PKGNAMEPREFIX}yaml>0:devel/py-yaml@${PY_FLAVOR}

USES=		python:3.6+
USE_GITHUB=	yes
USE_PYTHON=	autoplist distutils

GH_ACCOUNT=	samgiles

NO_ARCH=	yes

do-test:
	@cd ${WRKSRC} && ${PYTHON_CMD} ${PYDISTUTILS_SETUP} test

.include <bsd.port.mk>
