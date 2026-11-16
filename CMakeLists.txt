set(CMAKE_REQUIRED_INCLUDES "/usr/local/include /usr/include")
find_package(PkgConfig REQUIRED)

include_directories(${CMAKE_SOURCE_DIR}/build/include)

find_library(COAP_LIB
    NAMES coap-3-openssl coap-3-gnutls coap-3-mbedtls coap-3 coap-3-notls
    PATHS ${CMAKE_SOURCE_DIR}/build
    PATH_SUFFIXES lib lib64 lib/x86_64-linux-gnu
    NO_DEFAULT_PATH
)

build_lib(
  LIBNAME cotas-dev
  SOURCE_FILES
    helper/cotas-helper.cc
    helper/broadcast-helper.cc
    model/context-provider.cc
    model/context-consumer.cc
    model/broadcast-consumer.cc
    model/broadcast-provider.cc
    model/cotas.cc
    model/encapsulated-coap.cc
    model/generic-server.cc
  HEADER_FILES
    helper/cotas-helper.h
    helper/broadcast-helper.h
    model/json.hpp
    model/httplib.h
    model/context-provider.h
    model/context-consumer.h
    model/broadcast-consumer.h
    model/broadcast-provider.h
    model/cotas.h
    model/encapsulated-coap.h
    model/generic-server.h
  LIBRARIES_TO_LINK 
    ${libinternet}
    ${COAP_LIB}
    ${libmobility}
    ${libenergy}
  TEST_SOURCES
)
