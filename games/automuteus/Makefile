PORTNAME=	automuteus
DISTVERSION=	7.1.1
CATEGORIES=	games

MAINTAINER=	nc@FreeBSD.org
COMMENT=	Discord Bot to automute Among Us players at round transitions

LICENSE=	MIT
LICENSE_FILE=	${WRKSRC}/LICENSE

USES=		go:modules
USE_GITHUB=	yes
GH_ACCOUNT=	denverquane

GH_TUPLE=	\
		BurntSushi:toml:v1.0.0:burntsushi_toml/vendor/github.com/BurntSushi/toml \
		automuteus:utils:v0.1.2:automuteus_utils/vendor/github.com/automuteus/utils \
		beorn7:perks:v1.0.1:beorn7_perks/vendor/github.com/beorn7/perks \
		bsm:redislock:v0.7.1:bsm_redislock/vendor/github.com/bsm/redislock \
		bwmarrin:discordgo:v0.24.0:bwmarrin_discordgo/vendor/github.com/bwmarrin/discordgo \
		cespare:xxhash:v2.1.1:cespare_xxhash_v2/vendor/github.com/cespare/xxhash/v2 \
		davecgh:go-spew:v1.1.1:davecgh_go_spew/vendor/github.com/davecgh/go-spew \
		dgryski:go-rendezvous:9f7001d12a5f:dgryski_go_rendezvous/vendor/github.com/dgryski/go-rendezvous \
		georgysavva:scany:v0.2.7:georgysavva_scany/vendor/github.com/georgysavva/scany \
		go-redis:redis:v8.8.0:go_redis_redis_v8/vendor/github.com/go-redis/redis/v8 \
		go-yaml:yaml:9f266ea9e77c:go_yaml_yaml/vendor/gopkg.in/yaml.v3 \
		golang:crypto:86341886e292:golang_crypto/vendor/golang.org/x/crypto \
		golang:protobuf:v1.4.3:golang_protobuf/vendor/github.com/golang/protobuf \
		golang:sys:3681064d5158:golang_sys/vendor/golang.org/x/sys \
		golang:text:v0.3.7:golang_text/vendor/golang.org/x/text \
		gorilla:mux:v1.8.0:gorilla_mux/vendor/github.com/gorilla/mux \
		gorilla:websocket:v1.5.0:gorilla_websocket/vendor/github.com/gorilla/websocket \
		jackc:chunkreader:v2.0.1:jackc_chunkreader_v2/vendor/github.com/jackc/chunkreader/v2 \
		jackc:pgconn:v1.8.1:jackc_pgconn/vendor/github.com/jackc/pgconn \
		jackc:pgio:v1.0.0:jackc_pgio/vendor/github.com/jackc/pgio \
		jackc:pgpassfile:v1.0.0:jackc_pgpassfile/vendor/github.com/jackc/pgpassfile \
		jackc:pgproto3:v2.0.6:jackc_pgproto3_v2/vendor/github.com/jackc/pgproto3/v2 \
		jackc:pgservicefile:2b9c44734f2b:jackc_pgservicefile/vendor/github.com/jackc/pgservicefile \
		jackc:pgtype:v1.7.0:jackc_pgtype/vendor/github.com/jackc/pgtype \
		jackc:pgx:v4.11.0:jackc_pgx_v4/vendor/github.com/jackc/pgx/v4 \
		jackc:puddle:v1.1.3:jackc_puddle/vendor/github.com/jackc/puddle \
		matttproud:golang_protobuf_extensions:v1.0.1:matttproud_golang_protobuf_extensions/vendor/github.com/matttproud/golang_protobuf_extensions \
		nicksnyder:go-i18n:v2.1.2:nicksnyder_go_i18n_v2/vendor/github.com/nicksnyder/go-i18n \
		open-telemetry:opentelemetry-go:v0.19.0:open_telemetry_opentelemetry_go/vendor/go.opentelemetry.io/otel \
		pkg:errors:v0.9.1:pkg_errors/vendor/github.com/pkg/errors \
		pmezard:go-difflib:v1.0.0:pmezard_go_difflib/vendor/github.com/pmezard/go-difflib \
		prometheus:client_golang:v1.10.0:prometheus_client_golang/vendor/github.com/prometheus/client_golang \
		prometheus:client_model:v0.2.0:prometheus_client_model/vendor/github.com/prometheus/client_model \
		prometheus:common:v0.18.0:prometheus_common/vendor/github.com/prometheus/common \
		prometheus:procfs:v0.6.0:prometheus_procfs/vendor/github.com/prometheus/procfs \
		protocolbuffers:protobuf-go:v1.25.0:protocolbuffers_protobuf_go/vendor/google.golang.org/protobuf \
		stretchr:objx:v0.2.0:stretchr_objx/vendor/github.com/stretchr/objx \
		stretchr:testify:v1.7.0:stretchr_testify/vendor/github.com/stretchr/testify

USE_RC_SUBR=	${PORTNAME}

GO_PKGNAME=	github.com/${GH_ACCOUNT}/${PORTNAME}
GO_TARGET=	.:${PORTNAME}

SUB_FILES=	pkg-message
PLIST_FILES=	bin/${PORTNAME} \
		"@sample etc/${PORTNAME}/automuteus.conf.sample" \
		"@dir /var/log/automuteus" \
		/var/log/${PORTNAME}/logs.txt

post-install:
	@${MKDIR} ${STAGEDIR}${ETCDIR}
	@${CP} ${FILESDIR}/automuteus.conf ${STAGEDIR}${ETCDIR}/automuteus.conf.sample
	@${MKDIR} ${STAGEDIR}/var/log/${PORTNAME}
	@${TOUCH} ${STAGEDIR}/var/log/${PORTNAME}/logs.txt

.include <bsd.port.mk>
