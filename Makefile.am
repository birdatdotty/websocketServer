sbin_PROGRAMS = server
server_SOURCES = main.cc
server_LDFLAGS = -static
server_LDADD = CServer/libCServer.la log/liblog.la proxy/libproxy.la
# proxy/b64/libb64.la
# proxy/libb64.la
#server_LDADD = /tmp/qq/lib/libCServer.la log/liblog.la proxy/libproxy.la
#SUBDIRS = CServer log proxy
SUBDIRS = log proxy CServer
