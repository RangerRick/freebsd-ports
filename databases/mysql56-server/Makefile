# Created by: Alex Dupre <ale@FreeBSD.org>

PORTNAME?=	mysql
PORTVERSION=	5.6.51
PORTREVISION?=	0
CATEGORIES=	databases
MASTER_SITES=	MYSQL/MySQL-5.6
PKGNAMESUFFIX?=	56-server

MAINTAINER=	joneum@FreeBSD.org
COMMENT?=	Multithreaded SQL database (server)

LICENSE=	GPLv2

BROKEN_armv6=	qemu: uncaught target signal 11 (Segmentation fault) - core dumped

SLAVEDIRS=	databases/mysql56-client
USES=		bison:build cmake:noninja cpe groff:run libedit localbase \
		perl5 shebangfix ssl

CPE_VENDOR=	oracle

USE_PERL5=	run

MY_DBDIR=	/var/db/mysql
MY_SECDIR=	/var/db/mysql_secure
MY_TMPDIR=	/var/db/mysql_tmpdir

LIB_DEPENDS+=	libevent.so:devel/libevent \
		liblz4.so:archivers/liblz4

CMAKE_BUILD_TYPE=	Release

CMAKE_ARGS+=	-DINSTALL_LAYOUT=FREEBSD \
		-DINSTALL_LDCONFIGDIR="${LOCALBASE}/libdata/ldconfig" \
		-DINSTALL_PKGCONFIGDIR="${LOCALBASE}/libdata/pkgconfig" \
		-DINSTALL_DOCDIR="share/doc/mysql" \
		-DINSTALL_DOCREADMEDIR="share/doc/mysql" \
		-DINSTALL_INCLUDEDIR="include/mysql" \
		-DINSTALL_INFODIR="${INFO_PATH}" \
		-DINSTALL_LIBDIR="lib/mysql" \
		-DINSTALL_MANDIR="man" \
		-DINSTALL_MYSQLDATADIR="${MY_DBDIR}" \
		-DINSTALL_MYSQLKEYRINGDIR="etc/mysql/keyring" \
		-DINSTALL_MYSQLSHAREDIR="share/mysql" \
		-DINSTALL_MYSQLTESTDIR="share/mysql/tests" \
		-DINSTALL_PLUGINDIR="lib/mysql/plugin" \
		-DINSTALL_SBINDIR="libexec" \
		-DINSTALL_SCRIPTDIR="bin" \
		-DINSTALL_SECURE_FILE_PRIVDIR="${MY_SECDIR}" \
		-DINSTALL_SHAREDIR="share" \
		-DINSTALL_SQLBENCHDIR="share/mysql" \
		-DINSTALL_SUPPORTFILESDIR="share/mysql" \
		-DMYSQL_KEYRINGDIR="${ETCDIR}/keyring" \
		-DWITH_BOOST="${WRKSRC}/boost" \
		-DWITH_EDITLINE=system \
		-DWITH_LIBEVENT=system \
		-DWITH_LZ4=system \
		-DWITH_ZLIB=system \
		-DWITH_SSL=${OPENSSLBASE} \
		-DCRYPTO_LIBRARY=${OPENSSLLIB}/libcrypto.so \
		-DOPENSSL_LIBRARY=${OPENSSLLIB}/libssl.so \
		-DINSTALL_MYSQLTESTDIR=0

SHEBANG_FILES=	scripts/*.pl* scripts/*.sh

.ifdef USE_MYSQL
.error You have `USE_MYSQL' variable defined either in environment or in make(1) arguments. Please undefine and try again.
.endif

SUB_LIST=	MY_DBDIR=${MY_DBDIR} \
		MY_SECDIR=${MY_SECDIR} \
		MY_TMPDIR=${MY_TMPDIR}

PLIST_SUB=	MY_DBDIR=${MY_DBDIR} \
		MY_SECDIR=${MY_SECDIR} \
		MY_TMPDIR=${MY_TMPDIR}

# MySQL-Server part
.if !defined(CLIENT_ONLY)
USES+=		mysql:56

CONFLICTS_INSTALL=	mysql*-server \
			mysqlwsrep*-server \
			mariadb*-server \
			percona*-server

USE_RC_SUBR=	mysql-server

SUB_FILES=	my.cnf.sample pkg-message

USERS=		mysql
GROUPS=		mysql

USE_LDCONFIG+=	${PREFIX}/lib/mysql/plugin

MMAN1=		my_print_defaults.1 myisam_ftdump.1 myisamchk.1 myisamlog.1 myisampack.1 \
		mysql.server.1 mysql_convert_table_format.1 mysql_fix_extensions.1 \
		mysql_install_db.1 mysql_plugin.1 mysql_secure_installation.1 mysql_setpermission.1 \
		mysql_tzinfo_to_sql.1 mysql_upgrade.1 mysql_zap.1 mysqlbug.1 \
		mysqld_multi.1 mysqld_safe.1 mysqldumpslow.1 mysqlhotcopy.1 mysqlman.1 \
		mysqltest.1 perror.1 replace.1 resolve_stack_dump.1 resolveip.1

CMAKE_ARGS+=	-DWITH_EMBEDDED_SERVER="ON"

OPTIONS_GROUP=		STORAGE
OPTIONS_GROUP_STORAGE=	ARCHIVE BLACKHOLE EXAMPLE FEDERATED INNOBASE PARTITION PERFSCHEMA
OPTIONS_SUB=		YES
STORAGE_DESC=		Permissible "Storage Engines" (to compile statically into the server)
ARCHIVE_DESC=		Compile "Archive Storage" statically in server
BLACKHOLE_DESC=		Compile "Blackhole Storage" statically in server
EXAMPLE_DESC=		Compile "Example Storage" statically in server
FEDERATED_DESC=		Compile "Federated Storage" statically in server
INNOBASE_DESC=		Compile "InnoDB Storage" statically in server
PARTITION_DESC=		Compile "Partitioning support Storage" statically in server
PERFSCHEMA_DESC=	Compile "Performance Schema Storage" statically in server

ARCHIVE_CMAKE_ON=	-DWITH_ARCHIVE_STORAGE_ENGINE=1
BLACKHOLE_CMAKE_ON=	-DWITH_BLACKHOLE_STORAGE_ENGINE=1
EXAMPLE_CMAKE_ON=	-DWITH_EXAMPLE_STORAGE_ENGINE=1
FEDERATED_CMAKE_ON=	-DWITH_FEDERATED_STORAGE_ENGINE=1
INNOBASE_CMAKE_ON=	-DWITH_INNOBASE_STORAGE_ENGINE=1
PARTITION_CMAKE_ON=	-DWITH_PARTITION_STORAGE_ENGINE=1
PERFSCHEMA_CMAKE_ON=	-DWITH_PERFSCHEMA_STORAGE_ENGINE=1

OPTIONS_GROUP+=		FEATURES
OPTIONS_GROUP_FEATURES=	PERFSCHM
FEATURES_DESC=		Default features knobs
PERFSCHM_DESC=		Enable "Performance Schema" by default (High RAM usage)
OPTIONS_DEFAULT+=	PERFSCHM

PERFSCHM_SUB_LIST+=		PERFSCHEMRC=""
PERFSCHM_SUB_LIST_OFF+=		PERFSCHEMRC="--skip-performance-schema"
FEDERATED_SUB_LIST+=		FEDER="--federated"
FEDERATED_SUB_LIST_OFF+=	FEDER=""
.endif

.include <bsd.port.options.mk>

.if defined(PPC_ABI) && ${PPC_ABI} == ELFv2
USES+=		compiler:gcc-c++11-lib
USE_CXXSTD=	gnu++11
.else
USES+=		compiler:c++11-lib
USE_CXXSTD=	c++11
.endif

.include <bsd.port.pre.mk>

post-patch:
	@${REINPLACE_CMD} 's/*.1/${MMAN1}/' ${WRKSRC}/man/CMakeLists.txt

.if !defined(CLIENT_ONLY)
post-install:
	${MKDIR} ${STAGEDIR}${ETCDIR}
	${INSTALL_DATA} ${WRKDIR}/my.cnf.sample ${STAGEDIR}${ETCDIR}/my.cnf.sample
	${MKDIR} ${STAGEDIR}${ETCDIR}/keyring
	${MKDIR} ${STAGEDIR}${MY_SECDIR}
	${MKDIR} ${STAGEDIR}${MY_TMPDIR}
.endif

.if ${ARCH} == armv6 || ${ARCH} == armv7
EXTRA_PATCHES+=		${FILESDIR}/extra-patch-config.h.cmake
.endif

.include <bsd.port.post.mk>
