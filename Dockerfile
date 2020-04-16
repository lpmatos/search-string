ARG ALPINE_VERSION=3.11

FROM alpine:${ALPINE_VERSION} as BASE

LABEL maintainer="Lucca Pessoa da Silva Matos - luccapsm@gmail.com" \
        org.label-schema.version="1.0.0" \
        org.label-schema.release-data="16-04-2020" \
        org.label-schema.url="https://github.com/lpmatos/search-string" \
        org.label-schema.alpine="https://alpinelinux.org/" \
        org.label-schema.gcc="https://gcc.gnu.org/" \
        org.label-schema.openmp="https://www.openmp.org/" \
        org.label-schema.name="Search String"

FROM BASE AS COMPILE

WORKDIR /tmp/compile

RUN set -ex && \
    apk update && \
    apk add --no-cache --update build-base gcc

COPY [ "./src", "." ]

RUN for FILE in $(find ./ -iname "*.c" ); do gcc -fopenmp -o ${FILE%.c} $FILE; done

FROM BASE

ENV HOME=/usr/src/code

RUN apk add --no-cache --update gcc

WORKDIR ${HOME}

COPY --from=COMPILE [ "/tmp/compile/", "." ]

RUN find ./ -iname "*.o" -type f -exec chmod a+x {} \; -exec echo {} \;;
