PORTNAME=	kdepim-runtime
DISTVERSION=	${KDE_APPLICATIONS_VERSION}
PORTREVISION=	1
CATEGORIES=	deskutils kde kde-applications

MAINTAINER=	kde@FreeBSD.org
COMMENT=	KDE PIM tools and services

LICENSE=	LGPL21

LIB_DEPENDS=	libboost_date_time.so:devel/boost-libs \
		libcurl.so:ftp/curl \
		libkolabxml.so:textproc/libkolabxml \
		libsasl2.so:security/cyrus-sasl2 \
		libxerces-c-3.2.so:textproc/xerces-c3 \
		libqt5keychain.so:security/qtkeychain

USES=		cmake:noninja compiler:c++11-lib gettext kde:5 qca qt:5 \
		shared-mime-info tar:xz
USE_KDE=	auth bookmarks codecs completion config configwidgets \
		coreaddons crash dbusaddons guiaddons holidays i18n iconthemes \
		itemmodels itemviews jobwidgets kcmutils kdav kdelibs4support kio \
		kross notifications notifyconfig parts service solid sonnet \
		textwidgets unitconversion wallet widgetsaddons windowsystem \
		xmlgui
# pim components
USE_KDE+=	akonadi akonadicontacts akonadimime akonadinotes \
		akonadicalendar akonadisearch alarmcalendar calendarcore \
		calendarutils contacts gapi grantleetheme identitymanagement imap \
		kontactinterface ldap libkdepim mailtransport mbox mime pimcommon \
		pimtextedit syndication
USE_QT=		concurrent core dbus declarative gui location network networkauth printsupport speech \
		script webchannel webengine widgets xml xmlpatterns \
		buildtools_build qmake_build
USE_LDCONFIG=	yes

DESCR=		${.CURDIR:H:H}/deskutils/kdepim/pkg-descr

OPTIONS_DEFINE=	DOCS

.include <bsd.port.mk>
